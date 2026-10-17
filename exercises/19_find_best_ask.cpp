/*
Exercise 19 - Find the best ask

Given a collection of buy and sell orders, return the lowest price among the
sell orders. Return std::nullopt if there are no sell orders.

Interview remarks:
- std::optional<int> represents either a valid price or the absence of a price.
- Short-circuit evaluation ensures that *bestAsk is accessed only when the
  optional contains a value.
- Negative prices are compared normally rather than being confused with a
  sentinel value.
- The algorithm takes O(n) time and O(1) additional space.
*/

#include <iostream>
#include <optional>
#include <vector>

enum class Side {
    Buy,
    Sell
};

struct Order {
    Side side;
    int priceTicks;
    int quantity;
};

std::optional<int> findBestAsk(const std::vector<Order>& orders) {
    std::optional<int> bestAsk;

    for (const auto& order : orders) {
        if (order.side == Side::Sell) {
            if (!bestAsk.has_value() || order.priceTicks < *bestAsk) {
                bestAsk = order.priceTicks;
            }
        }
    }

    return bestAsk;
}

int main() {
    const std::vector<Order> orders{
        {Side::Buy, 10120, 10},
        {Side::Sell, 10130, 5},
        {Side::Sell, 10125, 7},
        {Side::Sell, 10128, 12}
    };

    const auto bestAsk = findBestAsk(orders);

    if (bestAsk) {
        std::cout << "Best Ask Price: " << *bestAsk << '\n';
    } else {
        std::cout << "No sell orders available.\n";
    }

    const auto noAsk = findBestAsk({
        {Side::Buy, 10120, 10}
    });

    std::cout << std::boolalpha
              << noAsk.has_value()
              << '\n';

    // Expected output:
    // Best Ask Price: 10125
    // false
    return 0;
}

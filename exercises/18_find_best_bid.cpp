/*
Exercise 18 - Find the best bid

Given a collection of buy and sell orders, return the highest price among the
buy orders. Return std::nullopt if there are no buy orders.

Interview remarks:
- std::optional<int> represents either a valid price or the absence of a price;
  it avoids inventing an unsafe sentinel such as zero or -1.
- Assigning an int to an optional makes it contain that value; the variable's
  type remains std::optional<int>.
- In (!bestBid.has_value() || order.priceTicks > *bestBid), short-circuit
  evaluation ensures that *bestBid is used only when a value is present.
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

std::optional<int> findBestBid(
    const std::vector<Order>& orders
) {
    std::optional<int> bestBid;

    for (const auto& order : orders) {
        if (order.side == Side::Buy &&
            (!bestBid.has_value() || order.priceTicks > *bestBid)) {
            bestBid = order.priceTicks;
        }
    }

    return bestBid;
}

int main() {
    const std::vector<Order> orders{
        {Side::Buy, 10120, 10},
        {Side::Sell, 10118, 5},
        {Side::Buy, 10125, 7},
        {Side::Buy, 10122, 12}
    };

    const auto bestBid = findBestBid(orders);

    if (bestBid) {
        std::cout << *bestBid << '\n'; // 10125
    } else {
        std::cout << "No bid\n";
    }

    const auto noBid = findBestBid({
        {Side::Sell, 10130, 5}
    });

    std::cout << std::boolalpha
              << noBid.has_value()
              << '\n'; // false

    return 0;
}

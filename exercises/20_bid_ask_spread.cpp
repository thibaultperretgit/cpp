/*
Exercise 20 - Calculate the bid-ask spread

Given a collection of buy and sell orders, find the highest buy price and the
lowest sell price, then return best ask minus best bid. Return std::nullopt if
either side is missing.

Interview remarks:
- Separate optionals track the best bid and best ask without unsafe sentinels.
- Buy orders must update only the bid, and sell orders only the ask.
- The final presence check makes both optional dereferences safe.
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

std::optional<int> calculateSpread(const std::vector<Order>& orders) {
    std::optional<int> bestAsk;
    std::optional<int> bestBid;

    for (const auto& order : orders) {
        if (order.side == Side::Sell) {
            if (!bestAsk.has_value() || order.priceTicks < *bestAsk) {
                bestAsk = order.priceTicks;
            }
        } else if (order.side == Side::Buy) {
            if (!bestBid.has_value() || order.priceTicks > *bestBid) {
                bestBid = order.priceTicks;
            }
        }
    }

    if (!bestAsk.has_value() || !bestBid.has_value()) {
        return std::nullopt;
    }

    return *bestAsk - *bestBid;
}

int main() {
    const std::vector<Order> orders{
        {Side::Buy, 10120, 10},
        {Side::Sell, 10130, 5},
        {Side::Buy, 10125, 7},
        {Side::Sell, 10128, 12}
    };

    const auto spread = calculateSpread(orders);

    if (spread) {
        std::cout << "Spread: " << *spread << '\n';
    } else {
        std::cout << "Insufficient orders to calculate spread.\n";
    }

    const auto noBid = calculateSpread({
        {Side::Sell, 10130, 5}
    });
    const auto noAsk = calculateSpread({
        {Side::Buy, 10120, 10}
    });
    const auto empty = calculateSpread({});

    std::cout << std::boolalpha
              << noBid.has_value() << ' '
              << noAsk.has_value() << ' '
              << empty.has_value() << '\n';

    // Expected output:
    // Spread: 3
    // false false false
    return 0;
}

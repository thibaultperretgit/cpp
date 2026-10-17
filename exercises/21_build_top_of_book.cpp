/*
Exercise 21 - Build the top of the order book

Find the highest buy price and total quantity at that price, together with the
lowest sell price and total quantity at that price. Return std::nullopt if
either side is missing.

Interview remarks:
- A better price replaces both the current price and its accumulated quantity.
- Another order at the same best price adds to the accumulated quantity.
- Orders at worse prices do not affect the top of book.
- long long protects accumulated quantities from overflowing int.
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

struct TopOfBook {
    int bestBidTicks;
    long long bidQuantity;
    int bestAskTicks;
    long long askQuantity;
};

std::optional<TopOfBook> getTopOfBook(const std::vector<Order>& orders) {
    std::optional<int> bestBidTicks;
    long long bidQuantity = 0;
    std::optional<int> bestAskTicks;
    long long askQuantity = 0;

    for (const auto& order : orders) {
        if (order.side == Side::Buy) {
            if (!bestBidTicks || order.priceTicks > *bestBidTicks) {
                bestBidTicks = order.priceTicks;
                bidQuantity = order.quantity;
            } else if (order.priceTicks == *bestBidTicks) {
                bidQuantity += order.quantity;
            }
        } else if (order.side == Side::Sell) {
            if (!bestAskTicks || order.priceTicks < *bestAskTicks) {
                bestAskTicks = order.priceTicks;
                askQuantity = order.quantity;
            } else if (order.priceTicks == *bestAskTicks) {
                askQuantity += order.quantity;
            }
        }
    }

    if (!bestBidTicks || !bestAskTicks) {
        return std::nullopt;
    }

    return TopOfBook{
        *bestBidTicks,
        bidQuantity,
        *bestAskTicks,
        askQuantity
    };
}

int main() {
    const std::vector<Order> orders{
        {Side::Buy, 10120, 10},
        {Side::Buy, 10125, 7},
        {Side::Buy, 10125, 3},
        {Side::Sell, 10130, 5},
        {Side::Sell, 10128, 12},
        {Side::Sell, 10128, 8}
    };

    const auto topOfBook = getTopOfBook(orders);

    if (topOfBook.has_value()) {
        const auto& tob = topOfBook.value();
        std::cout << "Best Bid: " << tob.bestBidTicks
                  << ", quantity: " << tob.bidQuantity << '\n';
        std::cout << "Best Ask: " << tob.bestAskTicks
                  << ", quantity: " << tob.askQuantity << '\n';
    } else {
        std::cout << "Incomplete order book.\n";
    }

    const auto noBid = getTopOfBook({
        {Side::Sell, 10128, 8}
    });
    const auto noAsk = getTopOfBook({
        {Side::Buy, 10125, 7}
    });
    const auto empty = getTopOfBook({});

    std::cout << std::boolalpha
              << noBid.has_value() << ' '
              << noAsk.has_value() << ' '
              << empty.has_value() << '\n';

    // Expected output:
    // Best Bid: 10125, quantity: 10
    // Best Ask: 10128, quantity: 20
    // false false false
    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <optional>

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
    std::vector<Order> orders{
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
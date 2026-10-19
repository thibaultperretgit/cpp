/*
Exercise 22 - Is an incoming order marketable?

An incoming buy is marketable when at least one resting sell has a price less
than or equal to the incoming price. An incoming sell is marketable when at
least one resting buy has a price greater than or equal to the incoming price.

Interview remarks:
- Only orders on the opposite side can match.
- Equality is included because orders at the same price can trade.
- The function returns immediately after finding a compatible resting order.
- The algorithm takes O(n) time in the worst case and O(1) additional space.
*/

#include <iostream>
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

bool isMarketable(
    const Order& incomingOrder,
    const std::vector<Order>& restingOrders
) {
    if (incomingOrder.side == Side::Buy) {
        for (const auto& restingOrder : restingOrders) {
            if (restingOrder.side == Side::Sell &&
                incomingOrder.priceTicks >= restingOrder.priceTicks) {
                return true;
            }
        }
    } else if (incomingOrder.side == Side::Sell) {
        for (const auto& restingOrder : restingOrders) {
            if (restingOrder.side == Side::Buy &&
                incomingOrder.priceTicks <= restingOrder.priceTicks) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    const std::vector<Order> book{
        {Side::Buy, 10120, 10},
        {Side::Buy, 10118, 4},
        {Side::Sell, 10128, 5},
        {Side::Sell, 10130, 7}
    };

    std::cout << std::boolalpha;

    std::cout << isMarketable(
        {Side::Buy, 10128, 2}, book
    ) << '\n'; // true: equal to the lowest sell price

    std::cout << isMarketable(
        {Side::Buy, 10127, 2}, book
    ) << '\n'; // false: below every sell price

    std::cout << isMarketable(
        {Side::Sell, 10120, 2}, book
    ) << '\n'; // true: equal to the highest buy price

    std::cout << isMarketable(
        {Side::Sell, 10121, 2}, book
    ) << '\n'; // false: above every buy price

    const std::vector<Order> buysOnly{
        {Side::Buy, 10120, 10}
    };

    std::cout << isMarketable(
        {Side::Buy, 10130, 2}, buysOnly
    ) << '\n'; // false: no resting sell orders

    const std::vector<Order> emptyBook;

    std::cout << isMarketable(
        {Side::Sell, 10120, 2}, emptyBook
    ) << '\n'; // false

    // Expected output:
    // true
    // false
    // true
    // false
    // false
    // false
    return 0;
}

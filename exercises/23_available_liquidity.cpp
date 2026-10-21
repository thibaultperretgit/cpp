/*
Exercise 23 - Calculate available liquidity

Given an incoming order and a collection of resting orders, return the total
quantity available at prices that can match the incoming order.

An incoming buy can match resting sells priced less than or equal to its price.
An incoming sell can match resting buys priced greater than or equal to its
price. Orders on the same side are ignored.

Interview remarks:
- Equality is included because orders at the same price can trade.
- Only orders on the opposite side contribute to available liquidity.
- long long protects the accumulated quantity from overflowing int.
- This function reports all available liquidity; it does not cap the result at
  the incoming order's quantity.
- The algorithm takes O(n) time and O(1) additional space.
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

long long availableLiquidity(
    const Order& incomingOrder,
    const std::vector<Order>& restingOrders
) {
    long long quantity = 0;

    if (incomingOrder.side == Side::Buy) {
        for (const auto& restingOrder : restingOrders) {
            if (restingOrder.side == Side::Sell &&
                incomingOrder.priceTicks >= restingOrder.priceTicks) {
                quantity += restingOrder.quantity;
            }
        }
    } else if (incomingOrder.side == Side::Sell) {
        for (const auto& restingOrder : restingOrders) {
            if (restingOrder.side == Side::Buy &&
                incomingOrder.priceTicks <= restingOrder.priceTicks) {
                quantity += restingOrder.quantity;
            }
        }
    }

    return quantity;
}

int main() {
    const std::vector<Order> book{
        {Side::Buy, 10120, 10},
        {Side::Buy, 10118, 4},
        {Side::Sell, 10128, 5},
        {Side::Sell, 10130, 7},
        {Side::Sell, 10135, 20}
    };

    std::cout << availableLiquidity(
        {Side::Buy, 10130, 100}, book
    ) << '\n'; // 12

    std::cout << availableLiquidity(
        {Side::Sell, 10119, 100}, book
    ) << '\n'; // 10

    std::cout << availableLiquidity(
        {Side::Buy, 10127, 100}, book
    ) << '\n'; // 0

    std::cout << availableLiquidity(
        {Side::Sell, 10117, 100}, book
    ) << '\n'; // 14

    const std::vector<Order> emptyBook;

    std::cout << availableLiquidity(
        {Side::Buy, 10130, 100}, emptyBook
    ) << '\n'; // 0

    // Expected output:
    // 12
    // 10
    // 0
    // 14
    // 0
    return 0;
}

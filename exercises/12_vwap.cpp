/*
Exercise 12 - Volume-weighted average price (VWAP)

Compute sum(price * quantity) / sum(quantity). Return 0.0 for no volume.
Assume quantities represent non-negative volume. Use O(n) time and O(1) space.
*/

#include <iomanip>
#include <iostream>
#include <vector>

struct Trade {
    double price;
    int quantity;
};

double calculateVwap(const std::vector<Trade>& trades) {
    double totalNotional = 0.0;
    long long totalQuantity = 0;

    for (const Trade& trade : trades) {
        totalNotional += trade.price * trade.quantity;
        totalQuantity += trade.quantity;
    }

    if (totalQuantity == 0) {
        return 0.0;
    }
    return totalNotional / totalQuantity;
}

int main() {
    const std::vector<Trade> trades{
        {100.0, 10},
        {102.0, 20}
    };

    std::cout << std::fixed << std::setprecision(2);
    std::cout << calculateVwap(trades) << '\n'; // 101.33
    std::cout << calculateVwap({}) << '\n';     // 0.00
    return 0;
}

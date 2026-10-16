/*
Exercise 10 - Maximum one-trade profit

Given prices in chronological order, buy once and sell once later to maximize
profit. Returning 0 means making no trade. Use O(n) time and O(1) space.
*/

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

int maximumProfit(const std::vector<int>& prices) {
    if (prices.size() < 2) {
        return 0;
    }

    int minimumPrice = prices[0];
    int profit = 0;

    for (std::size_t i = 1; i < prices.size(); ++i) {
        if (prices[i] < minimumPrice) {
            minimumPrice = prices[i];
        } else {
            profit = std::max(profit, prices[i] - minimumPrice);
        }
    }

    return profit;
}

int main() {
    std::cout << maximumProfit({7, 1, 5, 3, 6, 4}) << '\n'; // 5
    std::cout << maximumProfit({7, 6, 4, 3, 1}) << '\n';    // 0
    std::cout << maximumProfit({5}) << '\n';                // 0
    std::cout << maximumProfit({}) << '\n';                 // 0
    return 0;
}

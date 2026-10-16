/*
Exercise 16 - Sort trades with a lambda

Sort trades using these rules:
1. Lower prices come first.
2. At the same price, larger quantities come first.

The comparator must return true only when the first trade should appear before
the second. std::sort runs in O(n log n) time.

Interview remarks:
- The lambda takes each Trade by const reference to avoid copies and mutation.
- Equal prices require a quantity tie-breaker.
- Approximate floating-point comparisons should not be used in a sorting
  comparator because they can violate the required strict weak ordering.
  Production trading systems often represent prices using integer ticks.
- std::sort is not stable: elements considered equivalent are not guaranteed
  to retain their original relative order.
*/

#include <algorithm>
#include <iostream>
#include <vector>

struct Trade {
    double price;
    int quantity;
};

void sortTrades(std::vector<Trade>& trades) {
    std::sort(
        trades.begin(),
        trades.end(),
        [](const Trade& first, const Trade& second) {
            if (first.price != second.price) {
                return first.price < second.price;
            }

            return first.quantity > second.quantity;
        }
    );
}

int main() {
    std::vector<Trade> trades{
        {102.0, 10},
        {100.0, 5},
        {101.0, 7},
        {100.0, 20}
    };

    sortTrades(trades);

    for (const Trade& trade : trades) {
        std::cout << trade.price
                  << ' '
                  << trade.quantity
                  << '\n';
    }

    // Expected output:
    // 100 20
    // 100 5
    // 101 7
    // 102 10
    return 0;
}

/*
Exercise 17 - Aggregate volume by price

Each trade contains an integer price in ticks and a quantity. Return a map from
each distinct price to the total quantity traded at that price.

Interview remarks:
- The map key is a price level; the value is its aggregated volume.
- Different trades remain separate executions even when their quantities are
  aggregated into the same price level.
- std::map stores unique keys in sorted order.
- operator[] creates a missing value using value-initialization, so a missing
  long long starts at zero before += adds the trade quantity.
- If m is the number of distinct prices, each map update is O(log m). Processing
  n trades therefore takes O(n log m) time and O(m) additional space.
- long long is used for aggregate volume because the sum may exceed int even
  when every individual quantity fits in int.
*/

#include <iostream>
#include <map>
#include <vector>

struct Trade {
    int priceTicks;
    int quantity;
};

std::map<int, long long> aggregateVolumeByPrice(
    const std::vector<Trade>& trades
) {
    std::map<int, long long> volumeByPrice;

    for (const auto& trade : trades) {
        volumeByPrice[trade.priceTicks] += trade.quantity;
    }

    return volumeByPrice;
}

int main() {
    const std::vector<Trade> trades{
        {10125, 10},
        {10120, 5},
        {10125, 7},
        {10130, 3},
        {10120, 2}
    };

    const auto volumes = aggregateVolumeByPrice(trades);

    for (const auto& [price, volume] : volumes) {
        std::cout << price << ' ' << volume << '\n';
    }

    // Expected output:
    // 10120 7
    // 10125 17
    // 10130 3
    return 0;
}

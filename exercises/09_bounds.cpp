/*
Exercise 9 - Lower and upper bounds

lowerBound returns the first index whose value is greater than or equal to
target. upperBound returns the first index whose value is strictly greater than
target. Return values.size() if no such position exists. Use O(log n) time.
*/

#include <cstddef>
#include <iostream>
#include <vector>

std::size_t lowerBound(
    const std::vector<int>& sortedValues,
    int target
) {
    std::size_t left = 0;
    std::size_t right = sortedValues.size();

    while (left < right) {
        const std::size_t middle = left + (right - left) / 2;
        if (sortedValues[middle] < target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}

std::size_t upperBound(
    const std::vector<int>& sortedValues,
    int target
) {
    std::size_t left = 0;
    std::size_t right = sortedValues.size();

    while (left < right) {
        const std::size_t middle = left + (right - left) / 2;
        if (sortedValues[middle] <= target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}

int main() {
    const std::vector<int> values{1, 3, 3, 3, 7};
    std::cout << lowerBound(values, 3) << '\n'; // 1
    std::cout << upperBound(values, 3) << '\n'; // 4
    std::cout << lowerBound(values, 4) << '\n'; // 4
    std::cout << lowerBound(values, 8) << '\n'; // 5
    return 0;
}

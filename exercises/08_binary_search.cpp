/*
Exercise 8 - Binary search

Return whether target occurs in a sorted vector. Use a half-open interval
[left, right). Target O(log n) time and O(1) additional space.
*/

#include <cstddef>
#include <iostream>
#include <vector>

bool binarySearch(
    const std::vector<int>& sortedValues,
    int target
) {
    std::size_t left = 0;
    std::size_t right = sortedValues.size();

    while (left < right) {
        const std::size_t middle = left + (right - left) / 2;
        const int middleValue = sortedValues[middle];

        if (middleValue == target) {
            return true;
        }
        if (middleValue < target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }

    return false;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << binarySearch({1, 3, 5, 7, 9}, 7) << '\n'; // true
    std::cout << binarySearch({1, 3, 5, 7, 9}, 6) << '\n'; // false
    std::cout << binarySearch({}, 4) << '\n';              // false
    std::cout << binarySearch({4}, 4) << '\n';             // true
    std::cout << binarySearch({4}, 2) << '\n';             // false
    return 0;
}

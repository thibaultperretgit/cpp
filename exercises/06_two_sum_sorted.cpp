/*
Exercise 6 - Two-sum in a sorted vector

Return true if two different elements add up to target. The input is sorted in
ascending order. Use two pointers in O(n) time and O(1) additional space.
*/

#include <cstddef>
#include <iostream>
#include <vector>

bool hasPairWithSum(
    const std::vector<int>& sortedValues,
    int target
) {
    if (sortedValues.size() < 2) {
        return false;
    }

    std::size_t left = 0;
    std::size_t right = sortedValues.size() - 1;

    while (left < right) {
        const long long sum =
            static_cast<long long>(sortedValues[left]) + sortedValues[right];

        if (sum == target) {
            return true;
        }
        if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }

    return false;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << hasPairWithSum({1, 2, 4, 7, 11}, 9) << '\n';  // true
    std::cout << hasPairWithSum({1, 2, 4, 7, 11}, 20) << '\n'; // false
    std::cout << hasPairWithSum({3}, 3) << '\n';               // false
    std::cout << hasPairWithSum({}, 5) << '\n';                // false
    return 0;
}

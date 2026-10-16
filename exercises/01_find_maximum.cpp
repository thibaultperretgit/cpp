/*
Exercise 1 - Find the maximum

Implement findMaximum(values), which returns the largest integer in a
non-empty vector. Target O(n) time and O(1) additional space.
*/

#include <cstddef>
#include <iostream>
#include <vector>

int findMaximum(const std::vector<int>& values) {
    int maximum = values[0];

    for (std::size_t i = 1; i < values.size(); ++i) {
        if (values[i] > maximum) {
            maximum = values[i];
        }
    }

    return maximum;
}

int main() {
    std::cout << findMaximum({4, 2, 9, 5}) << '\n';    // 9
    std::cout << findMaximum({-8, -3, -10}) << '\n';  // -3
    return 0;
}

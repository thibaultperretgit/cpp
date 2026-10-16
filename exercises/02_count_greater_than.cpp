/*
Exercise 2 - Count values greater than a threshold

Return the number of elements that are strictly greater than threshold.
Target O(n) time and O(1) additional space.
*/

#include <cstddef>
#include <iostream>
#include <vector>

std::size_t countGreaterThan(
    const std::vector<int>& values,
    int threshold
) {
    std::size_t count = 0;

    for (int value : values) {
        if (value > threshold) {
            ++count;
        }
    }

    return count;
}

int main() {
    const std::vector<int> values{4, 8, 2, 8, 1};

    std::cout << countGreaterThan(values, 3) << '\n';  // 3
    std::cout << countGreaterThan(values, 8) << '\n';  // 0
    std::cout << countGreaterThan(values, 0) << '\n';  // 5
    return 0;
}

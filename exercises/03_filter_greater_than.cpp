/*
Exercise 3 - Filter values greater than a threshold

Return a new vector containing every value that is strictly greater than
threshold, preserving the original order. Target O(n) time.
*/

#include <iostream>
#include <vector>

std::vector<int> filterGreaterThan(
    const std::vector<int>& values,
    int threshold
) {
    std::vector<int> result;

    for (int value : values) {
        if (value > threshold) {
            result.push_back(value);
        }
    }

    return result;
}

int main() {
    const std::vector<int> result =
        filterGreaterThan({4, 8, 2, 8, 1}, 3);

    for (int value : result) {
        std::cout << value << ' ';
    }
    std::cout << '\n'; // 4 8 8
    return 0;
}

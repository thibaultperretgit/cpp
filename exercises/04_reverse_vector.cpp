/*
Exercise 4 - Reverse a vector in place

Reverse the original vector without creating another vector. Use two indices.
Target O(n) time and O(1) additional space.
*/

#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

void reverseVector(std::vector<int>& values) {
    if (values.empty()) {
        return;
    }

    std::size_t left = 0;
    std::size_t right = values.size() - 1;

    while (left < right) {
        std::swap(values[left], values[right]);
        ++left;
        --right;
    }
}

int main() {
    std::vector<int> values{1, 2, 3, 4, 5};
    reverseVector(values);

    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n'; // 5 4 3 2 1
    return 0;
}

/*
Exercise 5 - Palindrome vector

Return true if the vector reads identically from left to right and right to
left. Do not modify the vector. Target O(n) time and O(1) additional space.
*/

#include <cstddef>
#include <iostream>
#include <vector>

bool isPalindrome(const std::vector<int>& values) {
    if (values.empty()) {
        return true;
    }

    std::size_t left = 0;
    std::size_t right = values.size() - 1;

    while (left < right) {
        if (values[left] != values[right]) {
            return false;
        }
        ++left;
        --right;
    }

    return true;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << isPalindrome({1, 2, 3, 2, 1}) << '\n'; // true
    std::cout << isPalindrome({4, 7, 7, 4}) << '\n';    // true
    std::cout << isPalindrome({1, 2, 3}) << '\n';       // false
    std::cout << isPalindrome({}) << '\n';              // true
    return 0;
}

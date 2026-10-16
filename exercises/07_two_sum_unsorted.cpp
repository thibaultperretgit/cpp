/*
Exercise 7 - Two-sum in an unsorted vector

Return true if two different elements add up to target. Use a hash set for
average O(n) time and O(n) additional space.
*/

#include <iostream>
#include <unordered_set>
#include <vector>

bool hasPairWithSumUnsorted(
    const std::vector<int>& values,
    int target
) {
    std::unordered_set<long long> seen;

    for (int value : values) {
        const long long complement =
            static_cast<long long>(target) - value;

        if (seen.contains(complement)) {
            return true;
        }
        seen.insert(value);
    }

    return false;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << hasPairWithSumUnsorted({7, 1, 11, 2, 4}, 9) << '\n';  // true
    std::cout << hasPairWithSumUnsorted({7, 1, 11, 2, 4}, 20) << '\n'; // false
    std::cout << hasPairWithSumUnsorted({4, 4}, 8) << '\n';            // true
    std::cout << hasPairWithSumUnsorted({4}, 8) << '\n';               // false
    return 0;
}

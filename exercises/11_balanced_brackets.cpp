/*
Exercise 11 - Balanced brackets

The input contains only (), [] and {} characters. Return true when every
opening bracket is closed with the correct type and nesting order. Use a stack.
*/

#include <iostream>
#include <stack>
#include <string>

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

bool hasBalancedBrackets(const std::string& text) {
    std::stack<char> openings;

    for (char character : text) {
        const bool isOpening =
            character == '(' || character == '[' || character == '{';

        if (isOpening) {
            openings.push(character);
            continue;
        }

        if (openings.empty() ||
            !isMatchingPair(openings.top(), character)) {
            return false;
        }
        openings.pop();
    }

    return openings.empty();
}

int main() {
    std::cout << std::boolalpha;
    std::cout << hasBalancedBrackets("([]{})") << '\n'; // true
    std::cout << hasBalancedBrackets("([)]") << '\n';   // false
    std::cout << hasBalancedBrackets("((({") << '\n';   // false
    std::cout << hasBalancedBrackets("") << '\n';       // true
    std::cout << hasBalancedBrackets(")") << '\n';      // false
    std::cout << hasBalancedBrackets("{[()]}") << '\n'; // true
    return 0;
}

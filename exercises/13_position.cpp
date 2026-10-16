/*
Exercise 13 - Basic Position class

Create a class that stores a net position. buy adds quantity, sell subtracts
quantity, and quantity returns the current value without modifying the object.
*/

#include <iostream>

class Position {
public:
    void buy(int quantity) {
        quantity_ += quantity;
    }

    void sell(int quantity) {
        quantity_ -= quantity;
    }

    int quantity() const {
        return quantity_;
    }

private:
    int quantity_ = 0;
};

int main() {
    Position position;
    std::cout << position.quantity() << '\n'; // 0
    position.buy(100);
    std::cout << position.quantity() << '\n'; // 100
    position.sell(30);
    std::cout << position.quantity() << '\n'; // 70
    position.sell(100);
    std::cout << position.quantity() << '\n'; // -30
    return 0;
}

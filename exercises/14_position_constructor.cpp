/*
Exercise 14 - Position constructor and market value

Add an explicit constructor with an optional initial quantity. Add a const
marketValue(price) member function that returns quantity multiplied by price.
*/

#include <iostream>

class Position {
public:
    explicit Position(int initialQuantity = 0)
        : quantity_(initialQuantity) {
    }

    void buy(int quantity) {
        quantity_ += quantity;
    }

    void sell(int quantity) {
        quantity_ -= quantity;
    }

    int quantity() const {
        return quantity_;
    }

    double marketValue(double price) const {
        return quantity_ * price;
    }

private:
    int quantity_;
};

int main() {
    Position emptyPosition;
    Position longPosition{100};
    Position shortPosition{-40};

    std::cout << emptyPosition.quantity() << '\n';         // 0
    std::cout << longPosition.marketValue(12.50) << '\n';  // 1250
    std::cout << shortPosition.marketValue(12.50) << '\n'; // -500

    const Position fixedPosition{20};
    std::cout << fixedPosition.marketValue(5.0) << '\n';   // 100
    return 0;
}

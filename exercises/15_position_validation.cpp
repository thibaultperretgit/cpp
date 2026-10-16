/*
Exercise 15 - Validated trade application

Reject non-positive trade quantities with std::invalid_argument. Represent the
trade direction with enum class Side, and apply buy/sell trades to a Position.
*/

#include <iostream>
#include <stdexcept>

enum class Side {
    Buy,
    Sell
};

class Position {
public:
    explicit Position(int initialQuantity = 0)
        : quantity_(initialQuantity) {
    }

    void applyTrade(Side side, int quantity) {
        if (quantity <= 0) {
            throw std::invalid_argument("quantity must be positive");
        }

        switch (side) {
            case Side::Buy:
                quantity_ += quantity;
                break;
            case Side::Sell:
                quantity_ -= quantity;
                break;
        }
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
    Position position;

    try {
        position.applyTrade(Side::Buy, 100);
        position.applyTrade(Side::Sell, 30);
        position.applyTrade(Side::Buy, -10);
    } catch (const std::invalid_argument& error) {
        std::cout << "Error: " << error.what() << '\n';
    }

    std::cout << position.quantity() << '\n'; // 70
    return 0;
}

#pragma once
#include <iosfwd>
using std::ostream;

enum Fruit {
    Watermelon,
    Melon,
    Empty
};

class Basket {
private:
    Fruit typeFruit_ = Empty;

public:
    Basket() = default;
    explicit Basket(Fruit typeFruit);

    bool set(Fruit typeFruit);
    Fruit getFruit() const noexcept { return typeFruit_; }

    bool putFruit(Fruit typeFruit);
    bool takeFruit(Fruit typeFruit);
};


std::ostream& operator<<(std::ostream& os, const Basket& basket);
bool input(Basket& basket);
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
    bool set(Fruit typeFruit);
    Fruit getFruit() const noexcept { return typeFruit_; }
    explicit Basket(Fruit typeFruit);
    bool putFruit(Fruit typeFruit);
    bool takeFruit(Fruit typeFruit);
};
std::ostream &operator<<(std::ostream &f, const Basket &p);
bool input(Basket &b);

void unload(Basket b[], int n);
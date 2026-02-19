#include "basket.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include "format"


Basket::Basket(Fruit typeFruit) : Basket() {
    set(typeFruit);
}

bool Basket::set(Fruit typeFruit) {
    typeFruit_ = typeFruit;
    return true;
}

bool Basket::putFruit(Fruit typeFruit) {
    if (getFruit() == Empty) {
        set(typeFruit);
        return true;
    }
    return false;
}

bool Basket::takeFruit(Fruit typeFruit) {
    if (getFruit() != Empty && getFruit() == typeFruit) {
        set(Empty);
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Basket& basket) {
    std::string fruitName;

    switch (basket.getFruit()) {
        case Empty:
            fruitName = "Empty";
            break;
        case Watermelon:
            fruitName = "Watermelon";
            break;
        case Melon:
            fruitName = "Melon";
            break;
        default:
            fruitName = "Empty";
            break;
    }
    std::string text = fruitName == "Empty" ? "Empty Basket" : "Basket with " + fruitName;
    os << text << "\n";
    return os;
}

bool input(Basket &basket) {
    std::string fruitType;
    std::cout << "Enter fruit type (Watermelon or Melon): ";
    std::cin >> fruitType;

    if (fruitType == "Watermelon") {
        basket = Basket(Watermelon);
    }
    else if (fruitType == "Melon") {
        basket = Basket(Melon);
    }
    else {

        throw std::invalid_argument("Invalid fruit type! Use Watermelon or Melon.");
    }
    return true;
}
void unload(Basket b[], int n) {
    std::cout << "Unloading basket...\n";
    auto watermelonCount = 0;
    auto melonCount = 0;
    for (int i = 0; i < n; i++) {
        std::cout<<std::format("{}:", i+1) << b[i];
        switch (b[i].getFruit()) {
            case Empty:
                break;
            case Watermelon:
                watermelonCount++;
                b[i].takeFruit(Watermelon);
                break;
            case Melon:
                b[i].takeFruit(Melon);
                melonCount++;
            default:
                break;
        }
    }
    std::cout << std::format("Unloaded {} Watermelons and {} Melons.", watermelonCount, melonCount);
}
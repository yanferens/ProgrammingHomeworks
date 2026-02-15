#include <iostream>
#include "animal.h"

int main() {
    // 1. Cat
    std::cout << "You hear ";
    Cat::make_sound();
    std::cout << "That is a ";
    Cat::print_animal();



    // 2. Dog
    std::cout << "You hear ";
    Dog::make_sound();
    std::cout << "That is a ";
    Dog::print_animal();



    // 3. Cow
    std::cout << "You hear ";
    Cow::make_sound();
    std::cout << "That is a ";
    Cow::print_animal();

    return 0;
}
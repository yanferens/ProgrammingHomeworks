#include <iostream>
#include "basket.h"

using namespace std;

int main() {
    Basket b[5];
    b[1].putFruit(Watermelon);
    b[2].putFruit(Watermelon);
    b[3].putFruit(Watermelon);
    b[4].putFruit(Melon);
    b[0].putFruit(Melon);
    unload(b, 5);
    unload(b, 5);
}
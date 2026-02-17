#pragma once
#include <string>

using std::string;

class Basket {
private:
    string fruitType;
public:

    explicit Basket(string fruitType);


    string getContent() { return fruitType; }

};


void unloadBaskets(Basket *baskets, int n);
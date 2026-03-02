#pragma once
#include "bar.h"
#include <string>

class Hole {
    int a, b;
    bool fits(int d1, int d2) const;
    std::string checkZ(int x, int y, int z) const;
    std::string checkY(int x, int y, int z) const;

public:
    Hole(int a, int b);
    std::string canPass(const Bar& bar) const;
};
#include "hole.h"

Hole::Hole(int a, int b) : a(a), b(b) {}

bool Hole::fits(int d1, int d2) const {
    return d1 <= a && d2 <= b;
}

std::string Hole::checkZ(int x, int y, int z) const {
    if (fits(y, z)) return "xy";
    if (fits(z, x)) return "xz";
    return "";
}

std::string Hole::checkY(int x, int y, int z) const {
    if (fits(z, y)) return "y";
    if (fits(y, x)) return "z";
    return checkZ(x, y, z);
}

std::string Hole::canPass(const Bar& bar) const {
    if (fits(bar.getX(), bar.getY())) return ".";
    if (fits(bar.getX(), bar.getZ())) return "x";
    return checkY(bar.getX(), bar.getY(), bar.getZ());
}
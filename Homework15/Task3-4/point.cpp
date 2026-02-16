#include "point.h"
#include <cmath>
#include <iostream>
using std::string, std::ostream;

bool Point::set(double x, double y) {
    x_ = x;
    y_ = y;
    return true;
}

Point::operator string() const {
    return "(" + std::to_string(getX()) + "; " + std::to_string(getY()) + ")";
}

void checkSides(double ab, double bc, double ac) {
    if (ab + bc <= ac || ac + bc <= ab || ac + ab <= bc) {
        throw std::invalid_argument("Triangle does not exist (invalid sides)");
    }
}

std::ostream &operator<<(std::ostream &f, const Point &p) {
    f << string(p);
    return f;
}
double distance(const Point &a, const Point &b) {
    return sqrt(pow((a.getX() - b.getX()), 2) + pow((a.getY() - b.getY()), 2));
}
double triangleArea(const Point &a, const Point &b, const Point &c) {
    double ab = distance(a, b);
    double bc = distance(b, c);
    double ac = distance(c, a);
    checkSides(ab, bc, ac);
    double p = (ab + bc + ac) * 0.5;
    return sqrt(p * (p - ab) * (p - bc) * (p -ac));
}
bool input(Point &p) {

    double x, y;
    std::cout << "Enter coordinates of the point: \n";
    std::cin >> x >> y;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        throw std::invalid_argument("Invalid input");
    }
    return p.set(x, y);
}
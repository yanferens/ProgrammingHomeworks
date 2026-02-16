#pragma once
#include <string>
using std::string, std::ostream;

class Point {
    private:
    double x_ = 0;
    double y_ = 0;
    public:
    bool set(double x, double y);
    double getX() const {return x_;};
    double getY() const {return y_;};
    explicit operator std::string() const;
};
bool input(Point &p);
std::ostream &operator<<(std::ostream &f, const Point &p);
double distance(const Point &a, const Point &b);
double triangleArea(const Point &a, const Point &b, const Point &c);
void checkSides(double ab, double bc, double ac);

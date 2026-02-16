#include <iostream>
#include <format>
#include "point.h"

using namespace std;

int main() {
    try {
        Point a;
        Point b;
        Point c;
        input(a);
        input(b);
        input(c);
        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
        cout << format("Distance between A and B {} \n", distance(a, b));
        cout << format("Triangle Area(A, B, C): {} \n", triangleArea(a, b, c));

    }
    catch (exception &e) {
        cout << e.what() << endl;
    }

}
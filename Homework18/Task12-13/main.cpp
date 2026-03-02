#include <iostream>
#include <string>
#include "bar.h"
#include "hole.h"




void printBar(const Bar& b, const std::string& state) {
    std::cout << state << ": X=" << b.getX() << " Y=" << b.getY() << " Z=" << b.getZ() << std::endl;
}

int main() {
    int a, b, x, y, z;
    std::cout << "Enter a, b, x, y, z: ";
    std::cin >> a >> b >> x >> y >> z;
    Hole hole(a, b);
    Bar myBar(x, y, z);

    std::cout << hole.canPass(myBar) << std::endl;

    std::cout << "\nTask 12" << std::endl;

    printBar(myBar, "Initial state");

    myBar.rotateX();
    printBar(myBar, "After rotateX()");

    myBar.rotateY();
    printBar(myBar, "After rotateY()");

    myBar.rotateZ();
    printBar(myBar, "After rotateZ()");


}
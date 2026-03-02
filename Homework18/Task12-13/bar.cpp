#include "bar.h"

#include <stdexcept>

Bar::Bar(int x, int y, int z) {
    if (!set(x, y, z)) {
        throw std::invalid_argument("Invalid argument");
    }
}
bool Bar::set(int x, int y, int z) {
    if (x > 100 || y > 100 || z > 100) {
        return false;
    }
    x_= x;
    y_= y;
    z_= z;
    return true;
}
void Bar::rotateX() {
    int temp = 0;
    temp = y_;
    y_ = z_;
    z_ = temp;
}
void Bar::rotateY() {
    int temp = 0;
    temp = x_;
    x_ = z_;
    z_ = temp;
}
void Bar::rotateZ() {
    int temp = 0;
    temp = x_;
    x_ = y_;
    y_ = temp;
}


#pragma once

class Bar {
    int x_ = 0;
    int y_= 0;
    int z_ = 0;
public:
    Bar(int x, int y, int z);
    bool set(int x, int y, int z);
    int getX() const {return x_;};
    int getY() const {return y_;};
    int getZ() const {return z_;};
    void rotateX();
    void rotateY();
    void rotateZ();
};
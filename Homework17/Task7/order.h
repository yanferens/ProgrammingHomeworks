#pragma once
#include <ostream>

class Order {
private:
    int orderCapacity_ = 0;
    int orderID_ = 0;
    int L_18_ = 0;
    int L_5_ = 0;
    int L_1_ = 0;

public:
    Order();
    Order(int capacity);


    int getCapacity() const { return orderCapacity_; }
    int getL_18() const { return L_18_; }
    int getL_5() const { return L_5_; }
    int getL_1() const { return L_1_; }
    int getID() const { return orderID_; }

    void calculateOrder();
    Order operator+(const Order &other) const;
};

std::ostream& operator<<(std::ostream &f, const Order &p);
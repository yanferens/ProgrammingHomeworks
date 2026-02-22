#include "order.h"
#include <format>
#include <ostream>

Order::Order() = default;

Order::Order(int capacity) : orderCapacity_(capacity) {
    if (capacity < 0) {
        orderCapacity_ = 0;
    }

    orderID_ = std::rand();
    calculateOrder();
}

void Order::calculateOrder() {
    int cap = orderCapacity_;

    L_18_ = cap / 18;
    cap %= 18;

    L_5_ = cap / 5;
    cap %= 5;

    L_1_ = cap;
}

Order Order::operator+(const Order &other) const {
    Order result;

    result.orderCapacity_ = this->orderCapacity_ + other.orderCapacity_;
    result.L_18_ = this->L_18_ + other.L_18_;
    result.L_5_  = this->L_5_  + other.L_5_;
    result.L_1_  = this->L_1_  + other.L_1_;

    return result;
}

std::ostream &operator<<(std::ostream &f, const Order &order) {
    std::string part18 = order.getL_18() > 0 ? std::format("{:2}x18L", order.getL_18()) : "      ";
    std::string part5  = order.getL_5() > 0  ? std::format("{:2}x5L", order.getL_5())   : "     ";
    std::string part1  = order.getL_1() > 0  ? std::format("{:2}x1L", order.getL_1())   : "";

    f << std::format("{}   {}   {}", part18, part5, part1);

    return f;
}
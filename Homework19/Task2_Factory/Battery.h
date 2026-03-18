#pragma once

class Battery {
    double _mAh = 0.0;
public:
    Battery(double mAh);

    Battery() = default;

    bool set(double mAh);

    double getMah() const {return _mAh;};
};
#pragma once

class Battery {
    double _weight = 0.0;
    double _mAh = 0.0;
public:
    Battery(double weight, double mAh);
    bool set(double weight, double mAh);
    double getWeight() const {return _weight;};
};
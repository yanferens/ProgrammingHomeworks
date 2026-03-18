#pragma once

class Camera {
    double _weight = 0.0;
    double _Mp = 0.0;

public:
    Camera(double weight, double Mp);
    bool set(double weight, double Mp);
    double getWeight() const {return _weight;};
};
#pragma once

class Camera {
    double _Mp = 0.0;

public:
    Camera(double Mp);

    Camera() = default;

    bool set(double Mp);

    double getMp() const {return _Mp;};

};
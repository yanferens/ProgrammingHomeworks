#pragma once
#include <string>
#include <ostream>
#include "Battery.h"
#include "Camera.h"
#include "Aerial.h"

class BasePhone {
    std::string _name;
    double _baseWeight = 0;
    Battery* _battery = nullptr;
    Camera* _camera = nullptr;
    Aerial* _aerial = nullptr;

public:
    BasePhone(std::string name, double baseWeight);


    BasePhone(const BasePhone&) = delete;
    BasePhone& operator=(const BasePhone&) = delete;

    std::string getName() const { return _name; }
    double getBaseWeight() const { return _baseWeight; }
    double getTotalWeight() const;

    bool checkBattery() const { return _battery != nullptr; }
    bool checkCamera() const { return _camera != nullptr; }
    bool checkAerial() const { return _aerial != nullptr; }
    Battery* add(Battery* newBattery);
    Camera* add(Camera* newCamera);
    Aerial* add(Aerial* newAerial);
    Battery* removeBattery();
    Camera* removeCamera();
    Aerial* removeAerial();

    void call() const;
    void photo() const;

    explicit operator std::string() const;
    ~BasePhone();
};

std::ostream& operator<<(std::ostream& f, const BasePhone &b1);
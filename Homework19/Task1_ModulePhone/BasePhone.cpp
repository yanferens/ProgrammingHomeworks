#include "BasePhone.h"
#include <iostream>
#include <stdexcept>
#include <format>

BasePhone::BasePhone(std::string name, double baseWeight) : _name(name), _baseWeight(baseWeight) {
    if (baseWeight < 0) {
        throw std::invalid_argument("Invalid weight (weight < 0)");
    }
}

double BasePhone::getTotalWeight() const {
    double total = _baseWeight;
    if (_battery) total += _battery->getWeight();
    if (_camera) total += _camera->getWeight();
    if (_aerial) total += _aerial->getWeight();
    return total;
}

Battery* BasePhone::add(Battery* newBattery) {
    if (!newBattery) {
        throw std::invalid_argument("You try to install nothing");
    }
    Battery* oldBattery = _battery;
    _battery = newBattery;
    return oldBattery;
}

Camera* BasePhone::add(Camera* newCamera) {
    if (!newCamera) {
        throw std::invalid_argument("You try to install nothing");
    }
    Camera* oldCamera = _camera;
    _camera = newCamera;
    return oldCamera;
}

Aerial* BasePhone::add(Aerial* newAerial) {
    if (!newAerial) {
        throw std::invalid_argument("You try to install nothing");
    }
    Aerial* oldAerial = _aerial;
    _aerial = newAerial;
    return oldAerial;
}

Battery* BasePhone::removeBattery() {
    Battery* removedBattery = _battery;
    _battery = nullptr;
    return removedBattery;
}

Camera* BasePhone::removeCamera() {
    Camera* removedCamera = _camera;
    _camera = nullptr;
    return removedCamera;
}

Aerial* BasePhone::removeAerial() {
    Aerial* removedAerial = _aerial;
    _aerial = nullptr;
    return removedAerial;
}

void BasePhone::call() const {
    if (!checkBattery()) {
        throw std::logic_error("Phone needs a battery to work");
    }
    if (!checkAerial()) {
        throw std::logic_error("You can't make a call without an aerial");
    }
    std::cout << "*Beep-Beep*\n";
}

void BasePhone::photo() const {
    if (!checkBattery()) {
        throw std::logic_error("Phone needs a battery to work");
    }
    if (!checkCamera()) {
        throw std::logic_error("You can't take a photo without a camera");
    }
    std::cout << "*Click*\n";
}

BasePhone::operator std::string() const {
    return std::format(
        "Name: {} | Total Weight: {} \n Installed modules:\n - Camera: {}\n - Aerial: {}\n - Battery: {}",
        _name, getTotalWeight(),
        checkCamera() ? "Yes" : "No",
        checkAerial() ? "Yes" : "No",
        checkBattery() ? "Yes" : "No"
    );
}

std::ostream& operator<<(std::ostream& f, const BasePhone &b1) {
    f << std::string(b1);
    return f;
}

BasePhone::~BasePhone() {
    delete _battery;
    delete _camera;
    delete _aerial;
}
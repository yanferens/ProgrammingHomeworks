#include "Phone.h"
#include <string>
#include <stdexcept>
#include <ostream>
#include <format>


void Phone::_PonM10(bool& returnResult) {
    _battery = new Battery(4000);
    _camera = new Camera(5);
    _aerial = new Aerial("3G");
    returnResult = true;
}
void Phone::_PonM10Pro(bool& returnResult) {
    _battery = new Battery(3000);
    _camera = new Camera(25);
    _aerial = new Aerial("4G");
    returnResult = true;
}
void Phone::_PonM10ProMax(bool& returnResult) {
    _battery = new Battery(2800);
    _camera = new Camera(40);
    _aerial = new Aerial("5G");
    returnResult = true;
}

Phone::Phone(const std::string &namePhone) : Phone() {
    if (!_set(namePhone)) {
        throw std::invalid_argument("Invalid phone name");
    }
}

bool Phone::_set(const std::string &namePhone) {
    bool returnResult = false;
    if (namePhone == "Pon M10") {
        _PonM10(returnResult);

    }
    if (namePhone == "Pon M10 Pro") {
        _PonM10Pro(returnResult);
    }
    if (namePhone == "Pon M10 Pro Max") {
        _PonM10ProMax(returnResult);
    }
    _name = namePhone;
    return returnResult;
}

Phone::operator std::string() const{
    return std::format("Phone: {} \n mAh: {} \n Mp: {} \n Aerial: {} \n", _name, _battery->getMah(),
        _camera->getMp(), _aerial->getSignal());
}

std::ostream& operator<<(std::ostream& f, const Phone &p) {
    f << std::string(p);
    return f;
}

Phone::~Phone() {
    delete _battery;
    delete _camera;
    delete _aerial;
}



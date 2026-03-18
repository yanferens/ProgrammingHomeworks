#include "Aerial.h"
#include <string>
#include <stdexcept>

Aerial::Aerial(const double weight, const std::string &typeSignal) {
    if (!set(weight, typeSignal)) {
        throw std::invalid_argument("Invalid argument");
    }
}

bool Aerial::set(double weight, std::string typeSignal) {
    if (weight < 0) {
        return false;
    }
    _weight = weight;
    _type = stringToSignal(typeSignal);
    return true;

}

Signal Aerial::stringToSignal(std::string typeSignal) {
    if (typeSignal == "2G") {
        return Signal::_2G;
    }
    else if (typeSignal == "3G") {
        return Signal::_3G;
    }
    else if (typeSignal == "4G") {
        return Signal::_4G;
    }
    else if (typeSignal == "5G") {
        return Signal::_5G;
    }

    return Signal::UnknownType;

}
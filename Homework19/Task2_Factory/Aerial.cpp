#include "Aerial.h"
#include <string>
#include <stdexcept>

Aerial::Aerial(const std::string &typeSignal) {
    _type = stringToSignal(typeSignal);
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
std::string Aerial::signalToString(Signal sig) const {
    switch (sig) {
        case _2G: return "2G";
        case _3G: return "3G";
        case _4G: return "4G";
        case _5G: return "5G";
        case UnknownType: return "Unknown";
        default: return "Unknown";
    }
}

std::string Aerial::getSignal() const {
    return signalToString(_type);
}

#pragma once
#include <string>
enum Signal {
    _2G,
    _3G,
    _4G,
    _5G,
    UnknownType
};

class Aerial {
    double _weight = 0.0;
    Signal _type = UnknownType;
public:
    Aerial(double weight, const std::string &typeSignal);
    bool set(double weight, std::string typeSignal);
    Signal stringToSignal(std::string typeSignal);
    double getWeight() const {return _weight;};

    //std::string signalToString();
    //std::string string();
};
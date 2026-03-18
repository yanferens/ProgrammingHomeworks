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
    Signal _type = UnknownType;
public:
    Aerial(const std::string &typeSignal);
    Signal stringToSignal(std::string typeSignal);
    std::string signalToString(Signal sig) const;

    std::string getSignal() const;


};
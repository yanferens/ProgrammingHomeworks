#pragma once
#include <string>
#include "Battery.h"
#include "Aerial.h"
#include "Camera.h"

class Phone {
    std::string _name;
    Battery* _battery = nullptr;
    Camera* _camera = nullptr;
    Aerial* _aerial = nullptr;
    bool _set(const std::string &name);
    void _PonM10(bool& returnResult);
    void _PonM10Pro(bool& returnResult);
    void _PonM10ProMax(bool& returnResult);

public:
    Phone() = default;
    Phone(const std::string &name);
    Phone(const Phone&) = delete;
    Phone& operator=(const Phone&) = delete;
    Phone& operator=(Phone&&) = delete;
    Phone(Phone&&) = delete;
    ~Phone();
    explicit operator std::string() const;


};

std::ostream& operator<<(std::ostream& f, const Phone& p);
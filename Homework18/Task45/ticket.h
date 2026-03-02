#pragma once
#include <string>
#include <ostream>

class Ticket {
    std::string name;
    int place = 0;
public:
    Ticket() = default;

    Ticket(const std::string &name, int place);

    std::string getName() const { return name; }
    int getPlace() const { return place; }
};

std::ostream& operator<<(std::ostream& os, const Ticket& ticket);
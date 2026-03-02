#include "ticket.h"

Ticket::Ticket(const std::string &name, int place) : name(name), place(place) {}

std::ostream& operator<<(std::ostream& os, const Ticket& ticket) {
    os << "Name: " << ticket.getName() << "Place: " << ticket.getPlace();
    return os;
}
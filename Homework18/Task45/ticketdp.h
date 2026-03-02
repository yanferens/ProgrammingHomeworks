#pragma once
#include "ticket.h"

class TicketDP {
    static const int MAX_SEATS = 60;
    Ticket tickets[MAX_SEATS];
    bool seatTaken[MAX_SEATS];

    int createdTicket = 0;

public:
    TicketDP();
    Ticket createTicket(const std::string& passengerName);
    int getCreatedTicket() const { return createdTicket; }
};
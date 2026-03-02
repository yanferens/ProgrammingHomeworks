#include "ticketdp.h"

#include <stdexcept>

TicketDP::TicketDP() {

    for (int i = 0; i < MAX_SEATS; i++) {
        seatTaken[i] = false;
    }
}

Ticket TicketDP::createTicket(const std::string& passengerName) {

    if (createdTicket >= MAX_SEATS) {
        throw std::logic_error("All seats are sold out!");
    }

    int randomSeat;


    do {
        randomSeat = rand() % MAX_SEATS + 1;
    } while (seatTaken[randomSeat - 1]);


    seatTaken[randomSeat - 1] = true;
    Ticket newTicket(passengerName, randomSeat);
    tickets[createdTicket] = newTicket;

    createdTicket++;

    return newTicket;
}
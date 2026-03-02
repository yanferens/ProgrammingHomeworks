#include <iostream>
#include <string>
#include <stdexcept>
#include "ticket.h"
#include "ticketdp.h"

int main() {

    try {
        TicketDP manager;

        for (int i = 1; i <= 5; ++i) {
            std::string name = "Passenger_" + std::to_string(i);
            Ticket t = manager.createTicket(name);


            std::cout << t << std::endl;
        }



        for (int i = 6; i <= 60; ++i) {
            std::string name = "Passenger_" + std::to_string(i);
            manager.createTicket(name);
        }

        std::cout << "All 60 seats successfully sold!" << std::endl;
        std::cout << "Total tickets created: " << manager.getCreatedTicket() << std::endl;



        Ticket extraTicket = manager.createTicket("Extra Passenger");
        std::cout << extraTicket << std::endl;

    } catch (const std::logic_error& e) {

        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
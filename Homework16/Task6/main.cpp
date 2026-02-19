#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ticket.h"

using namespace std;

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int n = 0;
    ExhibitionPrice exhibitions[10];

    try {
        inputExhibitions(exhibitions, n);

        Ticket ticket(exhibitions, n);
        ticket.printTicket();
    }
    catch(exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
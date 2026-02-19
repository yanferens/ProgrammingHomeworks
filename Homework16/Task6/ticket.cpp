#include "ticket.h"
#include <format>
#include <iostream>
#include <cstdlib>
#include <limits>


std::string getExhibitionName(ExhibitionPrice p) {
    switch (p) {
        case ExhibitionPrice::Geology: return "Geology";
        case ExhibitionPrice::Zoology: return "Zoology";
        case ExhibitionPrice::Archaeology: return "Archaeology";
        case ExhibitionPrice::Botany: return "Botany";
        case ExhibitionPrice::Paleontology: return "Paleontology";
        default: return "Unknown";
    }
}

void inputExhibitions(ExhibitionPrice exhibitions[], int& n) {
    std::cout << "Enter amount of exhibitions: ";
    while (!(std::cin >> n) || n <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid positive number: ";
    }

    for (int i = 0; i < n; ++i) {
        int choice;
        std::cout << "Choose exhibition for #" << i + 1 << ":\n"
                  << "1. Geology (25)\n"
                  << "2. Zoology (45)\n"
                  << "3. Archaeology (48)\n"
                  << "4. Botany (52)\n"
                  << "5. Paleontology (60)\n"
                  << "Your choice (enter number 1-5): ";


        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a NUMBER.\n";
            i--;
            continue;
        }

        switch (choice) {
            case 1: exhibitions[i] = ExhibitionPrice::Geology; break;
            case 2: exhibitions[i] = ExhibitionPrice::Zoology; break;
            case 3: exhibitions[i] = ExhibitionPrice::Archaeology; break;
            case 4: exhibitions[i] = ExhibitionPrice::Botany; break;
            case 5: exhibitions[i] = ExhibitionPrice::Paleontology; break;
            default:
                std::cout << "Invalid choice, setting to Geology by default.\n";
                exhibitions[i] = ExhibitionPrice::Geology;
        }
    }
}

// Конструктор
Ticket::Ticket(ExhibitionPrice const exhibitions[], int n) {
    this->count_ = n;
    this->activities_ = new ExhibitionPrice[n];

    int summ = 0;
    for (int i = 0; i < n; ++i) {
        this->activities_[i] = exhibitions[i];
        summ += static_cast<int>(exhibitions[i]);
    }
    this->price_ = summ;
    this->id_ = std::rand() % 201;
}


Ticket::~Ticket() {
    delete[] activities_;
}

void Ticket::printTicket() const {
    std::cout << std::format("TICKET ID: {}\n", this->id_);
    std::cout << "INCLUDED ACTIVITIES:\n";

    for (int i = 0; i < this->count_; ++i) {
        std::cout << std::format(" - {} ({})\n",
                     getExhibitionName(this->activities_[i]),
                     static_cast<int>(this->activities_[i]));
    }


    std::cout << std::format("TOTAL PRICE: {}\n", this->price_);

}
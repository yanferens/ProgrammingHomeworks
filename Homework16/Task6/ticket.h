#pragma once
#include <string>

enum class ExhibitionPrice {
    Geology = 25,
    Zoology = 45,
    Archaeology = 48,
    Botany = 52,
    Paleontology = 60
};

class Ticket {
private:
    int id_ = 0;
    int price_ = 0;
    int count_ = 0;
    ExhibitionPrice* activities_ = nullptr;

public:
    Ticket() = default;
    Ticket(ExhibitionPrice const exhibitions[], int n);
    ~Ticket();

    int getID() const { return id_; }
    int getPrice() const { return price_; }

    void printTicket() const;
};

void inputExhibitions(ExhibitionPrice exhibitions[], int& n);

std::string getExhibitionName(ExhibitionPrice p);
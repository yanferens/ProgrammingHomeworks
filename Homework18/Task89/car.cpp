#include "car.h"
#include <iostream>
#include <stdexcept>


// Конструктор з усіма параметрами
Car::Car(std::string nameCar, int engineSpeed, int seatsCount, TyreType type)
    : name(nameCar), engine(engineSpeed), seats(seatsCount), tyreType(type) {}

// --- Логіка двигуна ---
bool Car::setEngine(int newEngine) {
    if (newEngine < 10 || newEngine > 200) {
        return false;
    }
    engine = newEngine;
    return true;
}

bool Car::changeEngine() {
    int newEngine = 0;
    std::cout << "Enter new engine speed (10-200): ";
    std::cin >> newEngine;

    if (std::cin.fail() || !setEngine(newEngine)) {
        std::cin.clear();
        std::cin.ignore();
        throw std::invalid_argument("Invalid engine");
    }
    return true;
}

// --- Логіка сидінь ---
bool Car::setSeats(int newSeats) {
    if (newSeats < 1 || newSeats > 8) {
        return false;
    }
    seats = newSeats;
    return true;
}

bool Car::changeSeats() {
    int newSeats = 0;
    std::cout << "Enter new seats (1-8): ";
    std::cin >> newSeats;

    if (std::cin.fail() || !setSeats(newSeats)) {
        std::cin.clear();
        std::cin.ignore();
        throw std::invalid_argument("Invalid seats");
    }
    return true;
}

// --- Логіка шин ---
bool tyreTypeFromString(int tyreType, Car::TyreType &newTyreType) {
    switch (tyreType) {
        case 0:
            newTyreType = Car::SUMMER_TIRES;
            break;
        case 1:
            newTyreType = Car::WINTER_TIRES;
            break;
        case 2:
            newTyreType = Car::ALL_SEASON_TIRES;
            break;
        case 3:
            newTyreType = Car::RAIN_TIRES;
            break;
        default:
            return false;
    }
    return true;
}

bool Car::changeTyreType() {
    int tyreTypeLocal = 0;
    std::cout << "Enter new tyre type \n 0 - Summer \n 1 - Winter \n 2 - AllSeason \n 3 - Rain: ";
    Car::TyreType newTyreType;
    std::cin >> tyreTypeLocal;

    if (std::cin.fail() || !tyreTypeFromString(tyreTypeLocal, newTyreType)) {
        std::cin.clear();
        std::cin.ignore();
        throw std::invalid_argument("Invalid tyre type");
    }
    setTyreType(newTyreType);
    return true;
}

std::string tyreTypeToString(Car::TyreType tyreType) {
    switch (tyreType) {
        case Car::SUMMER_TIRES: return "summer tires";
        case Car::WINTER_TIRES: return "winter tires";
        case Car::ALL_SEASON_TIRES: return "all-season tires";
        case Car::RAIN_TIRES: return "rain tires";
        default: return "default tires";
    }
}


Car::RouteStatus Car::canTravel(const Route& r) const {

    if (r.people > seats) {
        return ROUTE_NO_SPACE;
    }


    double requiredSpeed = r.distance / r.time;
    if (requiredSpeed > engine) {
        return ROUTE_TOO_SLOW;
    }


    if (r.weather == "snow" && tyreType != WINTER_TIRES && tyreType != ALL_SEASON_TIRES) {
        return ROUTE_WRONG_TIRES;
    }
    if (r.weather == "rain" && tyreType != RAIN_TIRES && tyreType != ALL_SEASON_TIRES) {
        return ROUTE_WRONG_TIRES;
    }
    if (r.weather == "sun" && tyreType == WINTER_TIRES) {
        return ROUTE_WRONG_TIRES;
    }

    return ROUTE_OK;
}


std::ostream& operator<<(std::ostream &f, const Car &p) {
    f << "Car: \"" << p.getName() << "\" with speed of " << p.getEngine()
      << " km/h, " << p.getSeats() << " seats and " << tyreTypeToString(p.getTyreType()) << ".";
    return f;
}
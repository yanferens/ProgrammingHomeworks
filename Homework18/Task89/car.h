#pragma once
#include <string>
#include <ostream>


struct Route {
    double distance;
    double time;
    int people;
    std::string weather;
};

class Car {
public:

    enum TyreType {
        SUMMER_TIRES,
        WINTER_TIRES,
        ALL_SEASON_TIRES,
        RAIN_TIRES,
        DEFAULT_TIRES
    };

    enum RouteStatus {
        ROUTE_OK,
        ROUTE_NO_SPACE,
        ROUTE_TOO_SLOW,
        ROUTE_WRONG_TIRES
    };

private:
    std::string name;
    int engine = 0;
    int seats = 0;
    TyreType tyreType = DEFAULT_TIRES;

public:
    Car(std::string nameCar, int engineSpeed, int seatsCount, TyreType type);

    std::string getName() const { return name; }
    TyreType getTyreType() const { return tyreType; }
    int getEngine() const { return engine; }
    int getSeats() const { return seats; }

    bool changeEngine();
    bool setEngine(int newEngine);
    bool changeSeats();
    bool setSeats(int newSeats);
    bool changeTyreType();
    void setTyreType(const TyreType newTyreType) { this->tyreType = newTyreType; }

    RouteStatus canTravel(const Route& r) const;
};

std::ostream& operator<<(std::ostream &f, const Car &p);
std::string tyreTypeToString(Car::TyreType tyreType);
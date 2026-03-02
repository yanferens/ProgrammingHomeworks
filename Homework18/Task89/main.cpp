#include <iostream>
#include "car.h"

Route get_route() {
    Route r;
    std::cout << "Enter route length (in km): ";
    std::cin >> r.distance;
    
    std::cout << "Enter time (in h): ";
    std::cin >> r.time;
    
    std::cout << "Enter number of people: ";
    std::cin >> r.people;
    
    std::cout << "Enter weather conditions (sun, rain, or snow): ";
    std::cin >> r.weather;
    
    return r;
}

int main() {
    try {
        Car car("BMW", 100, 2, Car::WINTER_TIRES);
        std::cout << car << std::endl;


        Route r = get_route();


        int res = car.canTravel(r);

        if (res == Car::ROUTE_OK) {
            std::cout << "Car can travel the assigned route.\n";
        }
        else if (res == Car::ROUTE_NO_SPACE) {
            std::cout << "There is not enough space in the car.\n";
        }
        else if (res == Car::ROUTE_TOO_SLOW) {
            std::cout << "The car is too slow for this route.\n";
        }
        else if (res == Car::ROUTE_WRONG_TIRES) {
            std::cout << "The tires are not suitable for this weather.\n";
        }
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }


}
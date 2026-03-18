#include "Battery.h"
#include <stdexcept>
Battery::Battery(double weight, double mAh) {
    if (!set(weight, mAh)) {
        throw std::invalid_argument("Invalid arguments");
    }
}
bool Battery::set(double weight, double mAh) {
    if (weight < 0 || mAh < 0) {
        return false;
    }
    _weight = weight;
    _mAh = mAh;
    return true;

}
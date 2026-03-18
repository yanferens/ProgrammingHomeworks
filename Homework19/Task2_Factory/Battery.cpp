#include "Battery.h"
#include <stdexcept>
Battery::Battery(double mAh) : Battery() {
    if (!set(mAh)) {
        throw std::invalid_argument("Invalid argument");
    }
}
bool Battery::set(double mAh) {
    if (mAh < 0) {
        return false;
    }
    _mAh = mAh;
    return true;

}
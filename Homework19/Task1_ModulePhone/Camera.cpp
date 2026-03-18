#include "Camera.h"
#include <stdexcept>

Camera::Camera(double weight, double Mp) {
    if (!set(weight, Mp)) {
        throw std::invalid_argument("Invalid arguments");
    }
}
bool Camera::set(double weight, double Mp) {
    if (weight < 0 || Mp < 0) {
        return false;
    }
    _weight = weight;
    _Mp = Mp;
    return true;
}
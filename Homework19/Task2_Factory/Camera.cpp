#include "Camera.h"
#include <stdexcept>

Camera::Camera(double Mp) : Camera(){
    if (!set(Mp)) {
        throw std::invalid_argument("Invalid arguments");
    }
}
bool Camera::set(double Mp) {
    if (Mp < 0) {
        return false;
    }
    _Mp = Mp;
    return true;
}
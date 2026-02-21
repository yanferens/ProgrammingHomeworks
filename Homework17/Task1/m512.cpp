#include "m512.h"
#include <string>
#include <ostream>
#include <istream>


int M512::makeNormal(long long r) {
    auto res = r % M;
    res = res < 0 ? res + M : res;
    return res;
}

M512::M512(long long r) : num(makeNormal(r)) {}


M512 M512::operator+(const M512 &b) const{
    return M512(this->num + b.num);
}
M512 M512::operator-(const M512 &b) const{
    return M512(this->num - b.num);
}
M512 M512::operator*(const M512 &b) const{
    return M512(this->num * b.num);
}
bool M512::operator==(const M512 &b) const{
    return this->num == b.num;
}
bool M512::operator<(const M512 &b) const{
    return this->num < b.num;
}
bool M512::operator>(const M512 &b) const{
    return this->num > b.num;
}
bool M512::operator<=(const M512 &b) const{
    return this->num <= b.num;
}
bool M512::operator>=(const M512 &b) const{
    return this->num >= b.num;
}
M512& M512::operator=(const M512 &b) {
    this->num = b.num;
    return *this;
}
M512::operator std::string() const{
    return std::to_string(this->num);
}
M512::operator int() const{
    return this->num;
}
M512::operator bool() const{
    return bool(this->num);
}

M512& M512::operator+=(const M512 &b) {
    this->num = makeNormal((long long)this->num + b.num);
    return *this;
}

M512& M512::operator-=(const M512 &b) {
    this->num = makeNormal((long long)this->num - b.num);
    return *this;
}
M512 M512::operator+(int b) const{
    return M512(this->num + b);
}
M512 M512::operator-(int b) const{
    return M512(this->num - b);
}
M512 M512::operator*(int b) const{
    return M512(static_cast<long long>(this->num) * b);
}
std::ostream& operator<<(std::ostream &f, const M512 &p) {
    f << std::string(p);
    return f;
}
std::istream& operator>>(std::istream &f, M512 &p) {
    long long v;
    f >> v;
    p.set(v);
    return f;
}

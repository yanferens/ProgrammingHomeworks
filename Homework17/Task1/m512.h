#include <iostream>
#include <string>
#include <ostream>
#include <istream>

class M512 {
private:
    static const int M = 512;
    int num = 0;

    int makeNormal(long long r);
    public:
    M512() = default;
    void set(long long r) {num = makeNormal(r);};
    M512(long long r);
    M512 operator+(const M512 &b) const;
    M512 operator-(const M512 &b) const;
    M512 operator*(const M512 &b) const;
    bool operator==(const M512 &b) const;
    bool operator<(const M512 &b) const;
    bool operator>(const M512 &b) const;
    bool operator<=(const M512 &b) const;
    bool operator>=(const M512 &b) const;
    M512 &operator=(const M512 &b);
    operator std::string() const;
    operator int() const;
    operator bool() const;
    M512& operator +=(const M512 &b);
    M512& operator -=(const M512 &b);
    M512 operator+(int b) const;
    M512 operator-(int b) const;
    M512 operator*(int b) const;



};
std::ostream& operator<<(std::ostream& f, const M512& p);
std::istream& operator>>(std::istream& f, M512& p);





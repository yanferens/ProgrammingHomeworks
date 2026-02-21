#include <iostream>
#include "m512.h"
using namespace std;

int main() {
    M512 t;
    M512 m;
    cout << "Please enter two numbers: ";
    cin >> t >> m;
    cout << t << " " << m <<endl;
    cout << t + m << endl;
    cout << t - m << endl;
    cout << t * m << endl;
    cout << (t == m) << endl;
    cout << (t < m) << endl;
    cout << (t > m) << endl;
    cout << (m >= t) << endl;
    cout << (m <= t) << endl;
    cout << (m+=t) << endl;
    cout << (m-=t) << endl;
    cout << m*5 << endl;
    cout << t-5*5 << endl;
    cout << t+5*5 << endl;




}
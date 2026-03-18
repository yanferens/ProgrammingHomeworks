#include "Phone.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Enter the name of phone: ";
    getline(cin, name);
    try {
        Phone newPhone(name);
        cout << newPhone;
    }
    catch (exception &e) {
        cerr << e.what();
    }
}
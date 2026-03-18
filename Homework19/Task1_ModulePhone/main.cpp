#include <iostream>
#include "BasePhone.h"

using namespace std;

int main() {
    try {
        BasePhone p("Modular Phone 1", 120.5);


        p.add(new Battery(50.0, 1000));


        Battery* old_b = nullptr;
        old_b = p.add(new Battery(65.0, 2000));
        delete old_b;


        p.add(new Camera(15.0, 15));
        p.photo();

        try {
            p.call();
        }
        catch(const exception &e) {
            cout << e.what() << endl;
        }

        p.add(new Aerial(10.0, "5G"));
        p.call();

        cout << "\nPhone Info:\n" << p << endl;
    }
    catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

}
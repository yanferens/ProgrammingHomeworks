#include <iostream>
#include <format>

#include "student.h"
using namespace std;

int main() {
    try {
        Student user1 = createStudent();
        cout << user1 << endl;
        user1.Eat();
        cout << user1 << endl;
        user1.Sleep();
        cout << user1 << endl;
        user1.Study();
        cout << user1 << endl;
        user1.Study();
        cout << user1 << endl;
        user1.Study();
        cout << user1 << endl;
    }
    catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }


}
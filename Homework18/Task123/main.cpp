#include <iostream>
#include "counter.h"
#include "myclass.h"

using namespace std;

void printStats() {

    std::cout << "Created (default): " << Counter::getCreated() << endl;
    std::cout << "Copied:" << Counter::getCopied() << endl;
    std::cout << "Existed:        " << Counter::getExisting() << endl;
    std::cout << "All created:    " << Counter::getTotal() << endl;

}

int main() {
    MyClass obj1;
    MyClass obj2;
    printStats();
    {
        MyClass obj3 = obj1;
    }
    printStats();

}
#include "List.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    List myList;
    myList.push_back(10);
    myList.push_back(3);
    myList.push_back(30);
    myList.printList();
    cout << "Current list size: " << myList.getSize() << endl;

    myList.push_before(5);
    myList.push_before(1);
    myList.printList();
    cout << "Current list size: " << myList.getSize() << endl;
    myList.deleteAll3();
    myList.printList();

    myList.clear();
    cout << "Size after clearing: " << myList.getSize() << endl;

    try {

        myList.printList();
    } catch (const std::exception& e) {
        cout << e.what() << endl;
    }

}
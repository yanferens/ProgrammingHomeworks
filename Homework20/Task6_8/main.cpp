#include "List.h"
#include <iostream>

using namespace std;


int main() {
    try {
        List myList;


        myList.push_back(10);
        myList.push_back(20);
        myList.push_front(5);
        myList.push_front(25);
        myList.push_front(35);

        myList.printList();

        List newList(myList);

        newList.printList();
        newList.bubble_sort();
        newList.printList();
    }
    catch ( const std::exception &e) {
        std::cout << e.what();
    }


}
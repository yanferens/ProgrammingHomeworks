#include "SingleLinkedList.h"

#include <iostream>

using namespace std;

int main() {
    SingleLinkedList list;

    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);
    list.push_back(10);
    list.printList();
    list.pop_back();
    list.printList();

}
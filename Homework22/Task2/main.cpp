#include <iostream>
#include "List.h"
using namespace std;




void printList(List& l) {
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        List::datatype x = *it;
        cout << x << " ";

    }
}



int main() {
    using Container = List;
    Container list;
    list.push_back(9);
    list.push_back( 8);
    list.push_back(10);
    list.push_back(11);
    printList(list);
    cout << endl;
    cout << list.sumOfElementsSq() << "\n";
    cout << list.findMin() << endl;
    cout << list.findElTwoPrev() << endl;
    list.reduceElementsTwice();
    printList(list);
    cout << endl;
    list.makeNonPosNull();
    printList(list);


}
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "order.h"

using namespace std;

int main() {

    int n = 0;
    cout << "Enter number of orders: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid Input" << endl;
        return 1;
    }

    Order totalOrder;

    for (int i = 0; i < n; i++) {
        int capacity = 0;
        cout << "Enter order: ";
        cin >> capacity;


        Order currentOrder(capacity);


        cout << "Order #"
             << hex << setw(5) << setfill('0') << currentOrder.getID() << dec << setfill(' ')
             << ":  " << currentOrder << endl;


        totalOrder = totalOrder + currentOrder;
    }


    cout << "Total Order: " << totalOrder << endl;

    return 0;
}
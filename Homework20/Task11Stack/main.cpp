#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    try {
        Stack list;
        list.push(5);
        list.push(3);
        list.push(8);
        list.printList();
        list.pop();
        std::cout << std::endl;
        list.printList();
    }
    catch (const exception& e){
        cerr<<e.what();
    }
}
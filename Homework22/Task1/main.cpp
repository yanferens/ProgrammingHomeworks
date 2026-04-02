#include <iostream>
#include "List.h"
using namespace std;

void printList(List& l) {
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        List::datatype x = *it;
        cout << " " << x.name << " " << x.age;

    }
}
void changeAge(List& l) {
        for (auto it = l.begin(); it != l.end(); ++it) {
            List::datatype& x = *it;
            x.age = x.age < 18 ? 1 : 0;
        }
    }
int main() {
    List list;
    list.push_back({"Yan", 5});
    list.push_back({"Sergiy", 8});
    list.push_back({"Claude", 10});

    printList(list);
    cout << endl;
    changeAge(list);
    printList(list);

}
#include "Queue.h"


int main() {
    Queue list;
    list.enqueue(6);
    list.enqueue(7);
    list.enqueue(8);
    list.printList();
    list.dequeue();
    list.printList();
}
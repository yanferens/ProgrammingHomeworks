#include "ReplaceList.h"
#include <iostream>

using namespace std;


Node* findNode(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

int main() {
    Node* head = nullptr;

    head = push_back(head, 10);
    head = push_back(head, 20);
    head = push_back(head, 30);
    head = push_back(head, 40);
    head = push_back(head, 50);


    printList(head);




    Node* node10 = findNode(head, 10);
    Node* node20 = findNode(head, 20);
    Node* node30 = findNode(head, 30);
    Node* node40 = findNode(head, 40);
    Node* node50 = findNode(head, 50);

    node50->next = head;
    node10->prev = node50;
    head = swap(node10, node10, head);
    printList(head);
    head = swap(node10, node40, head);
    printList(head);
    head = swap(node10, node40, head);
    printList(head);
    head = swap(node10, node50, head);
    printList(head);
    head = swap(node10, node50, head);

    head = swap(node10, node20, head);
    printList(head);
    head = swap(node10, node20, head);

    head = swap(node20, node30, head);
    printList(head);
    head = swap(node20, node30, head);

    head = swap(node20, node40, head);
    printList(head);
    head = swap(node20, node40, head);

    head = swap(node20, node50, head);
    printList(head);
    head = swap(node20, node50, head);


    head = swap(node40, node50, head);
    printList(head);
    head = swap(node40, node50, head);


    clear(head);

    head = nullptr;



}
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


    Node* node20 = findNode(head, 20);

    head = replaceElements1(head, node20); 
    printList(head);


    Node* node10 = findNode(head, 10);
    Node* node40 = findNode(head, 40);
    head = replaceElements2(head, node10, node40);
    printList(head);



    Node* node40_curr = findNode(head, 40);
    Node* node50 = findNode(head, 50);
    head = replaceElements2(head, node40_curr, node50);
    printList(head);



    clear(head);
    head = nullptr;



}
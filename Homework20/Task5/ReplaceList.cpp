#include "ReplaceList.h"
#include <iostream>
#include <stdexcept>

Node* findLastEl(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* lastEl = head;
    while (lastEl->next != nullptr) {
        lastEl = lastEl->next;
    }
    return lastEl;
}

Node* push_back(Node* head, int data) {
    if (head == nullptr) {
        return new Node{data, nullptr, nullptr};
    }
    Node* lastEl = findLastEl(head);
    Node* newNode = new Node{data, nullptr, lastEl};
    lastEl->next = newNode;
    return head;
}

void printList(Node* head) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node* temp = head;
    while (temp) {
        std::cout << temp->data;
        if (temp->next) std::cout << " <-> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}


Node* replaceElements1(Node* head, Node* node1) {

    if (head == nullptr || node1 == nullptr || node1->next == nullptr) {
        return head;
    }

    Node* node2 = node1->next;
    Node* prev1 = node1->prev;
    Node* next2 = node2->next;


    node1->next = next2;
    if (next2 != nullptr) {
        next2->prev = node1;
    }


    node2->prev = prev1;
    if (prev1 != nullptr) {
        prev1->next = node2;
    } else {
        head = node2;
    }


    node2->next = node1;
    node1->prev = node2;

    return head;
}


Node* replaceElements2(Node* head, Node* node1, Node* node2) {
    if (head == nullptr || node1 == nullptr || node2 == nullptr || node1 == node2) {
        return head;
    }


    if (node1->next == node2) return replaceElements1(head, node1);
    if (node2->next == node1) return replaceElements1(head, node2);


    Node* prev1 = node1->prev;
    Node* next1 = node1->next;
    Node* prev2 = node2->prev;
    Node* next2 = node2->next;


    node1->prev = prev2;
    node1->next = next2;
    if (prev2 != nullptr) prev2->next = node1;
    else head = node1;

    if (next2 != nullptr) next2->prev = node1;


    node2->prev = prev1;
    node2->next = next1;
    if (prev1 != nullptr) prev1->next = node2;
    else head = node2;

    if (next1 != nullptr) next1->prev = node2;

    return head;
}


void clear(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
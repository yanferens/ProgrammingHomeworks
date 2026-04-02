#include "ReplaceList.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

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
    while (temp && temp->next != head) {

        std::cout << temp->data;
        if (temp->next) std::cout << " <-> ";
        temp = temp->next;
    }
    if (temp) {
        std::cout << temp->data;
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



Node* swap(Node* node1, Node* node2, Node* _head) {
    if (!(node1) || !(node2) || !(_head) || node1 == node2) {
        return _head;
    }


    if (node1 == _head) {
        _head = node2;
    }
    else if (node2 == _head) {
        _head = node1;
    }

    if (node2->next == node1) {
        std::swap(node1, node2);
    }

    if (node1 -> next == node2) {
        auto node1Prev = node1->prev;
        auto node2Next = node2->next;

        node2->next = node1;
        node2->prev = node1Prev;
        node1->prev = node2;
        node1->next = node2Next;
        if (node1Prev) {
            node1Prev->next = node2;
        }
        if (node2Next) {
            node2Next->prev = node1;
        }
        return _head;
    }

    auto node1Next = node1->next;
    auto node2Next = node2->next;
    auto node2Prev = node2->prev;
    auto node1Prev = node1->prev;

    node1->next = node2Next;
    node2->next = node1Next;
    node1->prev = node2Prev;
    node2->prev = node1Prev;

    if (node2Next) {
        node2Next->prev = node1;
    }
    if (node1Prev) {
        node1Prev->next = node2;
    }
    if (node1Next) {
        node1Next ->prev = node2;
    }
    if (node2Prev) {
        node2Prev->next = node1;
    }

    return _head;


}


void clear(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
#include "List.h"
#include <iostream>
#include <stdexcept>



List::List(const List& elem) {
    _head = elem._copyList();
    _size = elem._size;

    if (_head == nullptr) {
        _tail = nullptr;
    } else {
        Node* temp = _head;
        // Йдемо до останнього вузла
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        _tail = temp;
    }
}
List::Node* List::_copyList() const {
    if (_head == nullptr) {
        return nullptr;
    }

    Node* newHead = new Node{_head->data, nullptr, nullptr};
    Node* currentHead = _head->next;
    Node* currentDest = newHead;

    while (currentHead != nullptr) {
        Node* newNode = new Node{currentHead->data, nullptr, currentDest};
        currentDest->next = newNode;
        currentDest = newNode;
        currentHead = currentHead->next;
    }
    return newHead;
}

void List::push_back(int data) {
    if (_head == nullptr) {
        _tail = new Node{data, nullptr, nullptr};
        _head = _tail;
    } else {
        auto temp = _tail;
        _tail = new Node{data, nullptr, temp};
        temp->next = _tail;
    }
    _size++;
}

void List::push_front(int data) {
    if (_head == nullptr) {
        _head = new Node{data, nullptr, nullptr};
        _tail = _head;
    } else {
        auto temp = _head;
        _head = new Node{data, temp, nullptr};
        temp->prev = _head;
    }
    _size++;
}

void List::printList() {
    if (_head == nullptr) {
        throw std::out_of_range("List is empty");
    }
    auto temp = _head;
    while (temp) {
        std::cout << temp->data;
        if (temp->next) {
            std::cout << " <-> ";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}

void List::clear() {
    Node* tmp = nullptr;
    while (_head) {
        tmp = _head->next;
        delete _head;
        _head = tmp;
    }
    _tail = nullptr;
    _size = 0;
}

List::~List() {
    clear();
}
List::Node* List::_replaceElements(Node* node1, Node* node2) {
    if (_head == nullptr || node1 == nullptr || node2 == nullptr || node1 == node2) {
        return _head;
    }


    if (node1->next == node2) {
        node1->next = node2->next;
        node2->prev = node1->prev;

        if (node1->next != nullptr) node1->next->prev = node1;
        else _tail = node1;

        if (node2->prev != nullptr) node2->prev->next = node2;
        else _head = node2;

        node2->next = node1;
        node1->prev = node2;
        return _head;
    }

    if (node2->next == node1) {
        return _replaceElements(node2, node1);
    }



    Node* prev1 = node1->prev;
    Node* next1 = node1->next;
    Node* prev2 = node2->prev;
    Node* next2 = node2->next;


    node1->prev = prev2;
    node1->next = next2;
    if (prev2 != nullptr) {
        prev2->next = node1;
    }
    else {
        _head = node1;
    }

    if (next2 != nullptr) {
        next2->prev = node1;
    }
    else {
        _tail = node1;
    }


    node2->prev = prev1;
    node2->next = next1;
    if (prev1 != nullptr) {
        prev1->next = node2;
    }
    else {
        _head = node2;
    }

    if (next1 != nullptr) {
        next1->prev = node2;
    }
    else {
        _tail = node2;
    }

    return _head;
}
void List::bubble_sort() {
    if (_head == nullptr || _head->next == nullptr) {
        return;
    }

    bool changed = true;

    while (changed) {
        changed = false;
        Node* temp = _head;

        while (temp != nullptr && temp->next != nullptr) {

            if (temp->data > temp->next->data) {

                _replaceElements(temp, temp->next);
                changed = true;

            }
            else {

                temp = temp->next;
            }
        }
    }
}
#include "SingleLinkedList.h"
#include <stdexcept>
#include <iostream>

void SingleLinkedList::_push_back(Node* after, int data) {
    if (after == nullptr) {
        _head = new Node{data, _head};
    } else {
        Node* node = new Node{data, after->next};
        after->next = node;
    }
    _size++;
}

void SingleLinkedList::_pop_back(Node* after) {
    if (_head == nullptr) {
        throw std::logic_error("List is empty");
    }

    if (after == nullptr) {
        Node* temp = _head;
        _head = _head->next;
        delete temp;
    } else {
        if (after->next == nullptr) {
            throw std::out_of_range("'After' node is the last element, nothing to delete");
        }
        Node* temp = after->next;
        after->next = temp->next;
        delete temp;
    }
    _size--;
}


void SingleLinkedList::push_back(int data) {
    if (_head == nullptr) {
        _push_back(nullptr, data);
    } else {
        Node* temp = _head;
        // Йдемо до останнього вузла
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        _push_back(temp, data);
    }
}

// Справжнє видалення з кінця списку
void SingleLinkedList::pop_back() {
    if (_head == nullptr) {
        throw std::logic_error("List is empty");
    }
    if (_head->next == nullptr) {
        _pop_back(nullptr);
    } else {
        Node* temp = _head;

        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        _pop_back(temp);
    }
}


void SingleLinkedList::printList() {
    if (_size == 0) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node* temp = _head;
    while (temp != nullptr) {
        std::cout << temp->data;
        if (temp->next != nullptr) {
            std::cout << " -> ";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}

void SingleLinkedList::clear() {
    while (_head != nullptr) {
        Node* temp = _head;
        _head = _head->next;
        delete temp;
    }
    _size = 0;
}

SingleLinkedList::~SingleLinkedList() {
    clear();
}
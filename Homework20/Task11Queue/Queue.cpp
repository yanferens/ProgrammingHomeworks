#include "Queue.h"
#include <iostream>
#include <stdexcept>

void Queue::dequeue() {
    if (empty()) {
        throw std::logic_error("Queue is empty!");
    }

    if (getSize() == 1) {
        delete _tail;
        _tail = nullptr;
    } else {
        auto head = _tail->next;
        _tail->next = head->next;
        delete head;
    }
    --_size;
}

void Queue::enqueue(const int &elem) {
    if (empty()) {
        _tail = new Node{elem, nullptr};
        _tail->next = _tail;
    } else {

        auto newNode = new Node{elem, _tail->next};
        _tail->next = newNode;
        _tail = newNode;
    }
    ++_size;
}


void Queue::enqueue(int &&elem) {
    if (empty()) {
        _tail = new Node{std::move(elem), nullptr};
        _tail->next = _tail;
    } else {
        auto newNode = new Node{std::move(elem), _tail->next};
        _tail->next = newNode;
        _tail = newNode;
    }
    ++_size;
}

void Queue::clear() {
    if (empty()) return;

    Node* current = _tail->next;
    _tail->next = nullptr;


    while (current != nullptr) {
        Node* tmp = current->next;
        delete current;
        current = tmp;
    }
    _tail = nullptr;
    _size = 0;
}

void Queue::printList() {
    if (empty()) {
        return;
    }

    auto tmp = _tail->next;


    do {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    while (tmp != _tail->next);

         std::cout << std::endl;
}

Queue::~Queue() {
    clear();
}
#include "Stack.h"
#include <iostream>
#include <algorithm>


void Stack::pop() {
    if (empty()) {
        return;
    }
    auto tmp = _head->next;
    delete _head;
    _head = tmp;
    --_size;

}
void Stack::push(const int &elem) {
    _head = new Node{elem, _head};
    ++_size;
}
void Stack::push(int &&elem) {
    _head = new Node{std::move(elem), _head};
    ++_size;
}
void Stack::printList() {
    if (empty()) {
        return;
    }
    auto temp = _head;
    while (temp) {
        std::cout << temp->data;
        if (temp->next) {
            std::cout << "<->";
        }
        temp = temp->next;


    }

}
void Stack::clear() noexcept{
    Node* tmp;
    while (_head) {
        tmp = _head ->next;
        delete _head;
        _head = tmp;
    }
    _size = 0;
}

Stack::~Stack() {
    clear();
}
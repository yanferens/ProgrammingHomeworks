#include "List.h"
#include <iostream>
#include <stdexcept>


void List::_push_before(Node* before, int data) {

    if (!before) {
        if (!_head) {
            _head = new Node{data, nullptr, nullptr};
            _size++;
        }
        return;
    }


    Node* node = new Node{data, before, before->prev};

    if (before->prev) {
        before->prev->next = node;
    } else {
        _head = node;
    }
    before->prev = node;
    _size++;
}


void List::_push_after(Node* after, int data) {
    if (!after) {
        if (!_head) {
            _head = new Node{data, nullptr, nullptr};
            _size++;
        }
        return;
    }

    Node* node = new Node{data, after->next, after};

    if (after->next) {
        after->next->prev = node;
    }
    after->next = node;
    _size++;
}


void List::push_before(int data) {
    _push_before(_head, data);
}


void List::push_back(int data) {
    if (!_head) {
        _push_after(nullptr, data);
        return;
    }


    Node* temp = _head;
    while (temp->next) {
        temp = temp->next;
    }
    _push_after(temp, data);
}


void List::printList() {
    if (!_head) {
        throw std::logic_error("List is empty");
    }

    Node* temp = _head;
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
    while (_head) {
        Node* temp = _head;
        _head = _head->next;
        delete temp;
    }
    _size = 0;
}

List::~List() {
    clear();
}
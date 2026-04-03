#include "List.h"

List::Node* List::_add_after(Node* after, datatype data) {
    if (!(after)) {
        _head =_tail = new Node{nullptr, data};
        return _head;
    }
    Node* newNode = new Node{after->next, data};
    if (after == _tail) {
        _tail = newNode;
    }
    after->next = newNode;
    return _head;
}

void List::push_back(datatype student) {
    _add_after(_tail, student);
}
void List::clear() {
    if (!(_head)) {
        return;
    }
    while (_head) {
        auto temp = _head;
        _head = _head->next;
        delete temp;
    }
    _tail = nullptr;
}

bool List::iterator::operator==(iterator other) const{
    return this->curr == other.curr;
}

List::iterator& List::iterator::operator++() {
    curr = curr->next;
    return *this;
}


List::~List() {
    clear();
}
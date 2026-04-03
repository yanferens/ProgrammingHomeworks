#include "List.h"
#include <format>
#include <stdexcept>

List::const_iterator List::const_iterator::operator+(int n) const {
    auto newEl = curr;
    while (n > 0 && newEl) {
        newEl = newEl->next;
        n--;
    }
    return const_iterator(newEl);
}

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



List::iterator& List::iterator::operator++() {
    curr = curr->next;
    return *this;
}

List::const_iterator& List::const_iterator::operator++() {
    curr = curr->next;
    return *this;
}


int List::sumOfElementsSq() const {
    int summ = 0;
    for (auto const &x : *this) {
        summ+= x*x;
    }
    return summ;
}

int List::findMin() const {
    if (begin() == end()) {
        throw std::out_of_range("List is empty");
    }
    int minn = *this->begin();
    for (auto const&x : *this) {
        minn = x < minn ? x : minn;
    }
    return minn;
}
std::string List::findElTwoPrev() const {
    for (auto it = begin(); it != end(); ++it) {


        auto next1 = it + 1;
        auto next2 = it + 2;


        if (next1 != end() && next2 != end()) {


            if (*it < *next1 && *it < *next2) {
                return std::format("{}", *it);
            }
        }
    }
    return std::format("No elements that suit to condition");
}

void List::reduceElementsTwice() {
    for (auto it = begin(); it != end(); ++it) {
        if (*it % 2 == 0) {
            *it-=2;
        }
    }
}
void List::makeNonPosNull() {
    for (auto it = begin(); it != end(); ++it) {
        if (*it < 0) {
            *it = 0;
        }
    }
}

List::~List() {
    clear();
}
#pragma once
#include <cstddef>

class List {
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };
    Node* _head = nullptr;
    size_t _size = 0;
    void _push_before(Node* before, int data);
    void _push_after(Node* after, int data);
public:
    List() = default;
    List(const List &) = delete;
    List& operator=(const List &) = delete;
    List(List &&) = delete;
    List& operator=(List &) = delete;
    void push_before(int data);
    void push_back(int data);
    size_t getSize() const {return _size;};
    void printList();
    void clear();
    ~List();

};
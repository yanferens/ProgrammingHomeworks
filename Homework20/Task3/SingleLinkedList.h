#pragma once
#include <cstddef>

class SingleLinkedList {
    struct Node {
        int data = 0;
        Node* next = nullptr;
    };
    Node* _head = nullptr;
    size_t _size = 0;


    void _push_back(Node* after, int data);
    void _pop_back(Node* after);

public:
    SingleLinkedList() = default;
    SingleLinkedList(const SingleLinkedList &) = delete;
    SingleLinkedList& operator=(const SingleLinkedList &) = delete;
    SingleLinkedList(SingleLinkedList &&) = delete;
    SingleLinkedList& operator=(SingleLinkedList &) = delete;

    size_t getSize() const { return _size; }
    void push_back(int data);
    void pop_back();
    void printList();
    void clear();
    ~SingleLinkedList();
};
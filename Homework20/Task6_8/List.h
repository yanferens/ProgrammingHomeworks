#pragma once
#include <cstddef>
class List {
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };
    Node* _head = nullptr;
    Node* _tail = nullptr;
    size_t _size = 0;
    Node* _copyList() const;
    Node* _replaceElements(Node* node1, Node* node2);
public:
    List() = default;
    List(const List& elem);
    List& operator=(const List& elem) = delete;
    List(List&&) = delete;
    List& operator=(List&&) = delete;
    size_t getSize() const {return _size;};
    void push_back(int data);
    void push_front(int data);
    void printList();
    void clear();
    void bubble_sort();
    ~List();

};
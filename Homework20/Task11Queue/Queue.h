#pragma once
#include <cstddef>

class Queue {
    struct Node {
        int data;
        Node* next=nullptr;
    };
    Node* _tail = nullptr;
    size_t _size = 0;
public:
    Queue() = default;
    Queue(const Queue &) = delete;
    Queue(Queue &&) = delete;
    Queue &operator=(const Queue &) = delete;
    Queue &operator=(Queue &&) = delete;
    size_t getSize() const noexcept{return _size;};
    bool empty() const noexcept {return _size == 0;};
    void enqueue(const int &elem);
    void enqueue(int &&elem);
    void dequeue();
    const int& front() const {return _tail->next->data;};
    int &front(){return _tail->next->data;};
    void clear();
    void printList();
    ~Queue();
};



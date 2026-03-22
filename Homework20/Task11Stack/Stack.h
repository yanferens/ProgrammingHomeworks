#pragma once
#include <cstddef>
class Stack {
    struct Node {
        int data;
        Node* next = nullptr;
    };
    Node* _head = nullptr;
    size_t _size = 0;
public:
    Stack() = default;
    Stack(const Stack &) = delete;
    Stack(Stack &&) = delete;
    Stack &operator=(const Stack &) = delete;
    Stack &operator=(Stack &&) = delete;
    size_t getSize() const noexcept {return _size;};
    bool empty() const noexcept {return _size == 0;};
    void pop();
    void push(int &&elem);
    void push(const int &elem);
    const int& top() const {return _head->data; }
    void clear() noexcept;
    void printList();
    ~Stack();
};
#pragma once
#include <string>
class List {
public:
    using datatype = int;

private:
    struct Node {
        Node* next;
        datatype data;
    };

    Node* _head = nullptr;
    Node* _tail = nullptr;
    Node* _add_after(Node* after, datatype data);

public:
    List() = default;
    List(const List&) = delete;
    List(List&&) = delete;
    List& operator=(const List&) = delete;
    List& operator=(List&&) = delete;
    int sumOfElementsSq() const;
    int findMin() const;
    std::string findElTwoPrev() const;
    void reduceElementsTwice();
    void makeNonPosNull();
    void push_back(datatype data);
    void clear();
    ~List();
    class iterator {
        Node* curr = nullptr;
        iterator(Node* current) : curr(current) {};
        friend class List;
    public:
        using reference = datatype&;

        bool operator == (iterator other) const { return curr == other.curr; }
        bool operator != (iterator other) const { return curr != other.curr; }

        iterator& operator++();
        reference operator*() const { return curr->data; }
    };


    class const_iterator {
        const Node* curr = nullptr;
        const_iterator(const Node* current) : curr(current) {};
        friend class List;
    public:
        using reference = const datatype&;
        const_iterator operator+(int n) const;
        bool operator == (const_iterator other) const { return curr == other.curr; }
        bool operator != (const_iterator other) const { return curr != other.curr; }

        const_iterator& operator++();
        datatype operator*() const { return curr->data; }
    };

    iterator begin() noexcept { return {_head}; }
    iterator end() noexcept { return {nullptr}; }

    const_iterator begin() const noexcept { return {_head}; }
    const_iterator end() const noexcept { return {nullptr}; }

    const_iterator cbegin() const noexcept { return {_head}; }
    const_iterator cend() const noexcept { return {nullptr}; }
};
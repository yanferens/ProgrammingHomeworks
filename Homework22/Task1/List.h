#pragma once
#include <string>

struct Student {
    std::string name;
    int age;
};

class List {
public:
    using datatype = Student;
private:
    struct Node {
        Node* next = nullptr;
        datatype student;
    };
    Node* _head = nullptr;
    Node* _tail = nullptr;
    Node* _add_after(Node* after, datatype data);
public:
    List() = default;
    List(const List& ) = delete;
    List (List&&) = delete;
    List& operator=(const List&) = delete;
    List& operator=(List&&) = delete;
    void push_back(datatype student);
    void clear();
    ~List();
class iterator {
    Node* curr = nullptr;
    iterator(Node* current) : curr(current) {};
    friend class List;
public:
    using reference = datatype&;
    bool operator == (iterator other) const;
    iterator& operator++();
    reference operator*() const {return curr->student;};
};
    iterator begin(){return {_head};}
    iterator end(){return {nullptr};}
};

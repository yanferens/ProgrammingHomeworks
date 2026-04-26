#include <iostream>
#include <cstddef>
#include <concepts>
#include <stdexcept>

using namespace std;
template<typename T>

concept Numeric = integral<T> || floating_point<T>;

template <Numeric T>
class List {
private:
    struct Node {
        Node* next;
        T data;
    };
    Node* _head = nullptr;
    Node* _tail = nullptr;

    Node* _addAfter(Node* prevNode, T data) {
        if (!(prevNode)) {
            _head =_tail = new Node{nullptr, data};
            return _head;
        }
        Node* newNode = new Node{prevNode->next, data};
        if (prevNode == _tail) {
            _tail = newNode;
        }
        prevNode->next = newNode;
        return _head;
    }
    Node* _deleteNode(Node* node) {
        if (!node || !_head) {
            throw invalid_argument("Invalid argument");
        }


        if (node == _head) {
            auto temp = _head;
            _head = temp->next;


            if (_head == nullptr) {
                _tail = nullptr;
            }

            delete temp;
            return _head;
        }


        auto prev = _findPrev(node);
        prev->next = node->next;


        if (node == _tail) {
            _tail = prev;
        }

        delete node;

        return prev->next;
    }
    Node* _findPrev(Node* node) {
        if (!node || !_head) {
            throw invalid_argument("Invalid argument");
        }
        auto temp = _head;
        while (temp->next != node) {
            temp = temp->next;
        }
        return temp;
    }
public:
    List() = default;
    List(const List& ) = delete;
    List (List&&) = delete;
    List& operator=(const List&) = delete;
    List& operator=(List&&) = delete;
    void append(T data) {
        _addAfter(_tail, data);
    }
    void pop() {
        _deleteNode(_tail);
    }
    void clear() {
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
    ~List() {
        clear();
    }
    class iterator {
    private:
        Node* curr = nullptr;
        iterator(Node* current) : curr(current) {};
        friend class List;
    public:
        using reference = T&;
        iterator& operator++() {
            curr = curr->next;

            return *this;
        }
        bool operator==(iterator other) const {
            return this->curr == other.curr;
        }
        reference operator*() const {return curr->data;};
    };
    iterator begin(){return {_head};}
    iterator end(){return {nullptr};}



};

int main() {
    List<int> list;
    for (int i = 1; i <= 10; i++) {
        list.append(i);
    }
    list.append(11);
    cout << "Add 11:" << endl;
    for (const auto& it : list) {

        cout << it << " ";

    }
    cout << endl;
    list.append(12);
    cout << "Add 12:" << endl;
    for (const auto& it : list) {

        cout << it << " ";

    }
    cout << endl;
    list.pop();
    cout << "Pop last element:" << endl;
    for (const auto& it : list) {

        cout << it << " ";

    }
    cout << endl;
    list.pop();
    cout << "Pop last element:" << endl;
    for (const auto& it : list) {

        cout << it << " ";

    }
    cout << endl;
    list.pop();
    cout << "Pop last element:" << endl;
    for (const auto& it : list) {
        cout << it << " ";

    }
    cout << endl;
}

#include <iostream>
#include "BinaryTree.h"
#include "TreeIterator.h"

void BinaryTree::_add(Node* root, int data) {
    if (data < root->data) {
        if (!(root->left)) {
            root->left = new Node{data, nullptr, nullptr};

        }
        else {
            _add(root->left, data);
        }
    }
    else if (data > root->data) {
        if (!(root->right)) {
            root->right = new Node{data, nullptr, nullptr};
        }
        else {
            _add(root->right, data);
        }
    }
}
void BinaryTree::add(int newData) {
    if (!_root) {
        _root = new Node{newData, nullptr, nullptr};
    }
    else {
        _add(_root, newData);
    }
}
BinaryTree::Node::Node(int _data, Node* _left, Node* _right)
    : right(_right), left(_left), data(_data), state(0) {}

BinaryTree::Node::Node(const Node &other) : Node() {
    *this = other;
}

BinaryTree::Node &BinaryTree::Node::operator=(const Node &other) {
    if (this == &other)
        return *this;
    clear();
    data = other.data;
    if (other.left)
        left = new Node(*other.left);
    if (other.right)
        right = new Node(*other.right);
    return *this;
}

void BinaryTree::Node::clear() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
}

BinaryTree::BinaryTree() = default;

BinaryTree::BinaryTree(int data, BinaryTree &&left, BinaryTree &&right) {
    _root = new Node{data, left._root, right._root};
    left._root = nullptr;
    right._root = nullptr;
}

BinaryTree::BinaryTree(const BinaryTree &other) : BinaryTree() {
    *this = other;
}

BinaryTree::BinaryTree(BinaryTree &&other) noexcept : BinaryTree() {
    *this = std::move(other);
}

BinaryTree &BinaryTree::operator=(const BinaryTree &other) {
    if (this == &other)
        return *this;
    clear();
    if (other._root)
        _root = new Node(*other._root);
    return *this;
}
int BinaryTree::findMaxForward() {
    int maxx = begin();
    for (auto it = forward(); it != end(); ++it) {
        if (*it > maxx) maxx = *it;
    }
    return maxx;
}

bool BinaryTree::checkInward() {

    if (!_root) {
        return true;
    }
    auto it = inward();
    int prevValue = *it;
    ++it;
    for (; it; ++it) {

        if (prevValue > *it) {

            return false;
        }
        prevValue = *it;
    }


    return true;
}
BinaryTree& BinaryTree::operator=(BinaryTree &&other) noexcept {
    if (this != &other) {
        clear();
        _root = other._root;
        other._root = nullptr;
    }
    return *this;
}

BinaryTree::~BinaryTree() {
    clear();
}

void BinaryTree::clear() noexcept {
    auto i = backward();
    while (i) {
        auto tmp = i.getNode();
        ++i;
        tmp->left = nullptr;
        tmp->right = nullptr;
        delete tmp;
    }
    _root = nullptr;
}

BinaryTree::iterator BinaryTree::begin(){
    return inward();
}

BinaryTree::iterator BinaryTree::end(){
    return TreeIterator();
}

BinaryTree::iterator BinaryTree::forward() {
    return {_root, 1};
}

BinaryTree::iterator BinaryTree::inward()  {
    return {_root, 2};
}

BinaryTree::iterator BinaryTree::backward()  {
    return {_root, 3};
}

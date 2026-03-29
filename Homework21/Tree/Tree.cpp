#include "Tree.h"
#include <iostream>
#include <stdexcept>
#include <stdexcept>

Tree::Tree() = default;

Tree::Tree(int elem, Tree &&left, Tree &&right) {
    _root = new Node(elem, left._root, right._root);
    _size = 1 + left._size + right._size;
    left._root = nullptr;
    left._size = 0;
    right._root = nullptr;
    right._size = 0;
}

Tree::Tree(const Tree& other) : Tree() {
    *this = other;
}

Tree::Tree(Tree&& other) noexcept : Tree() {
    *this = std::move(other);
}

Tree::~Tree() {
    clear();
}


Tree& Tree::operator=(Tree&& other) noexcept {
    if (this != &other){
        clear();
        _root = other._root;
        _size = other._size;
        other._root = nullptr;
        other._size = 0;
    }
    return *this;
}

Tree& Tree::operator=(const Tree& other) {
    if (this != &other) {
        clear();


        if (other._root != nullptr) {
            _root = new Node(*(other._root));
        } else {
            _root = nullptr;
        }
        _size = other._size;
    }
    return *this;
}

void Tree::clear() noexcept {
    delete _root;
    _root = nullptr;
    _size = 0;
}


Tree::Node::Node(int _elem, Node* _left, Node* _right) : elem(_elem), left(_left), right(_right) {}


Tree::Node::Node(const Node& other) {
    elem = other.elem;
    left = (other.left != nullptr) ? new Node(*(other.left)) : nullptr;
    right = (other.right != nullptr) ? new Node(*(other.right)) : nullptr;
}

Tree::Node& Tree::Node::operator=(const Node& other) {
    if (this != &other) {
        delete left;
        delete right;

        elem = other.elem;
        left = (other.left != nullptr) ? new Node(*(other.left)) : nullptr;
        right = (other.right != nullptr) ? new Node(*(other.right)) : nullptr;
    }
    return *this;
}

void Tree::Node::clear() noexcept {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
}

Tree::Node::~Node() {
    clear();
}


void Tree::add(int elem) {
    if (!_root) {
        _root = new Node{elem, nullptr, nullptr};
        _size++;
    }
    else {
        _add(_root, elem);
    }
}

void Tree::_add(Node* root, int elem) {
    if (elem < root->elem) {
        if (!(root->left)) {
            root->left = new Node{elem, nullptr, nullptr};
            _size++;
        }
        else {
            _add(root->left, elem);
        }
    }
    else if (elem > root->elem) {
        if (!(root->right)) {
            root->right = new Node{elem, nullptr, nullptr};
            _size++;
        }
        else {
            _add(root->right, elem);
        }
    }
}


bool Tree::_is_in_tree(Node* root, int elem) const {
    if (root->elem > elem) {
        if (!(root->left)) return false;
        return _is_in_tree(root->left, elem);
    }
    if (root->elem < elem) {
        if (!(root->right)) return false;
        return _is_in_tree(root->right, elem);
    }
    return true;
}

bool Tree::is_in_tree(int elem) const {
    if (!(_root)) return false;
    return _is_in_tree(_root, elem);
}


void Tree::_printFor(Node* root) const {
    std::cout << root->elem << " ";
    if (root->left) {
        _printFor(root->left);
    }
    if (root->right) {
        _printFor(root->right);
    }
}

void Tree::printFor() const {
    if (!(_root)) {
        std::cout << "Tree is empty\n";
    }
    else {
        _printFor(_root);
        std::cout << "\n";
    }
}

void Tree::_printIn(Node* root) const {
    if (root->left) {
        _printIn(root->left);
    }
    std::cout << root->elem << " ";
    if (root->right) {
        _printIn(root->right);
    }
}

void Tree::printIn() const {
    if (!(_root)){
        std::cout << "Tree is empty\n";
    }
    else {
        _printIn(_root);
        std::cout << "\n";
    }
}

void Tree::_printBack(Node* root) const {
    if (root->left) {
        _printBack(root->left);
    }
    if (root->right) {
        _printBack(root->right);
    }
    std::cout << root->elem << " ";
}

void Tree::printBack() const {
    if (!(_root)) {
        std::cout << "Tree is empty\n";
    }
    else {
        _printBack(_root);
        std::cout << "\n";
    }
}
int Tree::next_to(int x) const {
    if (!(_root)) {
        throw std::out_of_range("Tree is empty");
    }
    return _next_to(_root, x);
}

int Tree::_next_to(Node* _root, int x) const {
    if (x < _root->elem) {
        if (_root->left) {
            try {
                return _next_to(_root->left, x);
            }
            catch (const std::out_of_range&) {
                return _root->elem;
            }
        }
        else {
            return _root->elem;
        }
    }
    else {
        if (_root->right) {
            return _next_to(_root->right, x);
        }
        throw std::out_of_range("don't have result ");
    }
}

int Tree::_CountAllLeafs(const Node* root) const {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return _CountAllLeafs(root->left) + _CountAllLeafs(root->right);
}

int Tree::amountLeafs() const {
    if (!(_root)) {
        std::cout << "Tree is empty\n";
        return 0;
    }
    return _CountAllLeafs(_root);
}

bool Tree::operator==(const Tree& other) const{
    if (size() != other._size) {
        return false;
    }
    return _isEqual(this->_root, other._root);
}
bool Tree::_isEqual(Node* a, Node* b) const {
    if (!(a) && !(b)) {
        return true;
    }
    if (!(a) || !(b)) {
        return false;
    }
    return (a->elem == b->elem) && _isEqual(a->left, b->left) && _isEqual(a->right, b->right);
}

int Tree::_findMax(Node* root) const{
    int tmp = root->elem;
    if (root->left) {
        tmp = std::max(tmp, _findMax(root->left));
    }
    if (root->right) {
        tmp = std::max(tmp, _findMax(root->right));
    }
    return tmp;
}

int Tree::findMax() const{
    if (!(_root)) {
        throw std::out_of_range("List is empty");
    }
    return _findMax(_root);
}

int Tree::_findMin(Node* root) const {
    int tmp = root->elem;
    if (root->left) {
        tmp = std::min(tmp, _findMin(root->left));
    }
    if (root->right) {
        tmp = std::min(tmp, _findMin(root->right));
    }
    return tmp;
}

int Tree::findMin() const{
    if (!(_root)) {
        throw std::out_of_range("List is empty");
    }
    return _findMin(_root);
}

int Tree::_height(Node* root) const {
    auto h_left = root->left ? _height(root->left) : -1;
    auto h_right = root->right ? _height(root->right) : -1;
    return std::max(h_left, h_right) + 1;
}

int Tree::findHeight() const {
    if (!(_root)) {
        return -1;
    }
    return _height(_root);
}
int Tree::findBinMax() const{
    if (!(_root)) {
        throw std::out_of_range("Lis is empty");
    }
    Node* cur = _root;
    while(cur->right) {
        cur = cur->right;
    }
    return cur->elem;
}
int Tree::findBinMin() const {
    if (!(_root)) {
        throw std::out_of_range("Lis is empty");
    }
    Node* cur = _root;
    while(cur->left) {
        cur = cur->left;
    }
    return cur->elem;
}
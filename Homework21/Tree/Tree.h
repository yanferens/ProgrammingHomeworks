#pragma once
#include <cstddef>
#include <string>

class Tree {
private:
    struct Node;
    size_t _size = 0;
    Node* _root = nullptr;

    int _findMin(Node* root) const;
    int _findMax(Node *root) const ;
    void _add(Node* root, int elem);
    void _printIn(Node* root) const;
    void _printFor(Node* root) const;
    void _printBack(Node* root) const;
    int _CountAllLeafs(const Node *root) const;
    bool _is_in_tree(Node* root, int elem) const;
    int _next_to(Node* root, int x) const;
    int _height(Node* root) const;
    bool _isEqual(Node* a, Node* b) const;
    Node* deleteRightNode(Node*& root);
    Node* findFather(Node* root, Node* node);
public:
    Tree();
    explicit Tree(int elem, Tree &&left = Tree(), Tree &&right = Tree());
    Tree(const Tree& other);
    Tree(Tree&& other) noexcept;
    Tree& operator=(const Tree& other);
    Tree& operator=(Tree&& other) noexcept;
    int findMin() const;
    int findMax() const;
    void add(int newElem);
    size_t size() const { return _size; }
    bool empty() const { return !(_size); }
    bool is_in_tree(int elem) const;
    void printFor() const;
    void printIn() const;
    void printBack() const;
    int amountLeafs() const;
    int findHeight() const;
    int findBinMax() const;
    int findBinMin() const;
    int next_to(int x) const;
    void clear() noexcept;

    bool operator==(const Tree& other) const;
    ~Tree();
};

struct Tree::Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int elem = 0;

    Node() = default;
    Node(int _elem, Node* _left, Node* _right);
    Node(const Node& other);
    Node(Node&&) = delete;
    Node& operator=(const Node& other);
    Node& operator=(Node&&) = delete;

    void clear() noexcept;
    ~Node();
};
#pragma once

class TreeIterator;

class BinaryTree {
    friend class TreeIterator;

public:
    BinaryTree();
    BinaryTree(int elem, BinaryTree &&left = BinaryTree(), BinaryTree &&right = BinaryTree());
    BinaryTree(const BinaryTree &other);
    BinaryTree(BinaryTree &&other) noexcept;
    BinaryTree &operator=(const BinaryTree &other);
    BinaryTree &operator=(BinaryTree &&other) noexcept;
    ~BinaryTree();

    void clear() noexcept;
    bool empty() const noexcept { return _root == nullptr; }
    void add(int newData);
    int findMaxForward();
    bool checkInward();
    using iterator = TreeIterator;
    iterator begin() ;

    iterator end();
    iterator forward() ;
    iterator backward();
    iterator inward() ;

private:
    struct Node;
    Node* _root = nullptr;
    void _add(Node* root, int data);
};

struct BinaryTree::Node {
    Node* right = nullptr;
    Node* left = nullptr;
    int data = 0;
    int state = 0;
    
    Node() = default;
    Node(int data, Node* left, Node* right);
    Node(const Node &other);
    Node &operator=(const Node &other);
    void clear();
};
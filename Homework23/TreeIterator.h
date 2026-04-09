#pragma once
#include "BinaryTree.h"
#include <stack>

class TreeIterator {
private:
    friend class BinaryTree;
    std::stack<BinaryTree::Node*> actions;
    int statusTraversal = 0;

    TreeIterator(BinaryTree::Node* root, int _statusTraversal);
    void changeState(BinaryTree::Node* current);
public:
    TreeIterator() = default;
    TreeIterator(int _statusTraversal);
    TreeIterator(const TreeIterator& ) = default;
    TreeIterator& operator= (const TreeIterator& ) = default;

    bool hasNext() const noexcept { return !actions.empty(); }
    operator bool() const noexcept { return !actions.empty(); }

    using iterator = TreeIterator;
    iterator operator++();
    bool operator !=(const TreeIterator& other) const;
    int& operator*();
    BinaryTree::Node* getNode() const;
};
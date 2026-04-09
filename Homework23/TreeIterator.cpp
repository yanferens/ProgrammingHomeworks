#include "TreeIterator.h"

TreeIterator::TreeIterator(int _statusTraversal) : statusTraversal(_statusTraversal) {}

TreeIterator::TreeIterator(BinaryTree::Node* root, int _statusTraversal) : statusTraversal(_statusTraversal) {
    if (root) {
        root->state = 1;
        actions.push(root);
        if (statusTraversal != 1) {
            operator++();
        }
    }
}

TreeIterator::iterator TreeIterator::operator++() {
    if (actions.empty()) {
        return *this;
    }

    auto current = actions.top();
    changeState(current);

    while (!actions.empty()) {
        current = actions.top();
        if (current->state == statusTraversal) {
            break;
        }
        changeState(current);
    }

    return *this;
}
void TreeIterator::changeState(BinaryTree::Node* current) {
    if (current->state == 1) {
        current->state = 2;
        if (current->left) {
            current->left->state = 1;
            actions.push(current->left);
        }
    } else if (current->state == 2) {
        current->state = 3;
        if (current->right) {
            current->right->state = 1;
            actions.push(current->right);
        }
    } else if (current->state == 3) {
        actions.pop();
    }
}

int& TreeIterator::operator*() {
    return actions.top()->data;
}

bool TreeIterator::operator!=(const TreeIterator& other) const {
    if (actions.empty() && other.actions.empty()) return false;
    if (actions.empty() || other.actions.empty()) return true;
    return actions.top() != other.actions.top();
}

BinaryTree::Node* TreeIterator::getNode() const {
    return actions.empty() ? nullptr : actions.top();
}
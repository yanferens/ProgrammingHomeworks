#include <iostream>
#include "BinaryTree.h"
#include "TreeIterator.h"

using namespace std;


int main() {
    BinaryTree tree;
    BinaryTree tree1 = BinaryTree(5,
        BinaryTree(6,
            BinaryTree(7)),
            BinaryTree(9,
                BinaryTree(8, BinaryTree(7))));
    tree.add(5);
    tree.add(6);
    tree.add(-10);
    tree.add(-1);
    tree.add(-8);

    for (auto it =  tree.backward(); it != tree.end() ; ++it) {
        cout << *it << " ";

    }
    cout << endl;
    cout << tree1.checkInward() << endl;
    cout << tree.findMaxForward();


}
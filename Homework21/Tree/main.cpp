#include <iostream>
#include "Tree.h"
using namespace std;

Tree newTree() {
    return Tree(5,
        Tree(6,
            Tree(7)),
            Tree(9,
                Tree(8, Tree(7))));
}

int main() {
    try {
        Tree tree;
        Tree TreeCons = newTree();
        Tree badTree;
        cout << tree.is_in_tree(5) << endl;

        tree.add(5);
        tree.add(3);
        tree.add(10);
        tree.add(7);
        tree.add(13);
        tree.add(16);
        tree.add(4);
        tree.add(2);
        cout << "5: " << tree.is_in_tree(5) << endl;
        cout << "3: " << tree.is_in_tree(3) << endl;
        cout << "1: " << tree.is_in_tree(1) << endl;
        cout << "4: " << tree.is_in_tree(4) << endl;
        cout << "7: " << tree.is_in_tree(7) << endl;
        cout << "10: " << tree.is_in_tree(10) << endl;
        cout << endl;

        cout << "New tree: \n";
        TreeCons.printFor();

        cout << "Max el: " << tree.findMax() << endl;
        cout << "Min el: " << tree.findMin() << endl;
        cout << "Height: " << tree.findHeight() << endl;
        cout << "Max Bin el: " << tree.findBinMax() << endl;
        cout << "Min Bin el: " << tree.findBinMin() << endl;
        cout << "Size: " << tree.size() << endl;
        cout << "Is empty " << tree.empty() << endl;
        cout << "Leafs: " << tree.amountLeafs() << endl;
        cout << "For: ";
        tree.printFor();
        cout << endl;
        cout << "Back: ";
        tree.printBack();
        cout << endl;
        cout << "In: ";
        tree.printIn();
        cout << endl;
        /* Завдання 8: Cередня складність дерева O(log2 n) це коли дерево ідеальне тобто у всіх верших крім листків є дві дитини, тоді пісял кожної операції
         ми зменшуємо загальну роботу вдвічі, верхня оцінка тобто O(n) досягається, коли дерево просто перетвор
         юється у список послідовних елементів. Тоді на пошук останнього треба n операцій*/
        badTree.add(1);
        badTree.add(2);
        badTree.add(3);
        badTree.add(4);
        badTree.add(5);
        badTree.printFor();
    }
    catch (exception& e) {
        cerr << e.what();
    }
}


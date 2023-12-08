#include <iostream>

#include "AVLTree.h"

using namespace std;

int main() {

    AVLTree tree;

    tree.Insert(12);
    tree.Insert(6);
    tree.Insert(30);
    tree.Insert(45);
    tree.Insert(60);

    tree.Print();

    if (tree.Search(12)) {
        cout << "12 in tree" << endl;
    }
    else {
        cout << "12 isn't in tree" << endl;
    }

    tree.Remove(12);

    cout << "remove 12 from tree" << endl;

    if (tree.Search(12)) {
        cout << "12 in tree" << endl;
    }
    else {
        cout << "12 isn't in tree" << endl;
    }

    tree.Print();

    return 0;
}
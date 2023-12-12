#include <iostream>

#include "BinaryTree.h"

using namespace std;

int main() {
    
    BinaryTree tree;

    int max = tree.FindABSMax();
    if (max == -1) {
        cout << "tree is empty" << endl;
    }
    else {
        cout << "abs max = " << max << endl;
    }

    tree.Insert(32);
    tree.Insert(-2);
    tree.Insert(-48);
    tree.Insert(54);
    tree.Insert(38);
    tree.Insert(56);
    
    max = tree.FindABSMax();
    if (max == -1) {
        cout << "tree is empty" << endl;
    }
    else {
        cout << "abs max = " << max << endl;
    }

    tree.Insert(-512);

    max = tree.FindABSMax();
    if (max == -1) {
        cout << "tree is empty" << endl;
    }
    else {
        cout << "abs max = " << max << endl;
    }

    tree.Remove(-512);
    tree.Remove(56);
    tree.Remove(54);
    tree.Remove(38);
    tree.Remove(-48);

    max = tree.FindABSMax();
    if (max == -1) {
        cout << "tree is empty" << endl;
    }
    else {
        cout << "abs max = " << max << endl;
    }

    return 0;
}
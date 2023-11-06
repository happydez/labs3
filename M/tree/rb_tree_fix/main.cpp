#include <iostream>

using namespace std;

#include "RBTree.h"

int main() {

    // 7, 4, 3, 2, 6, 11, 18, 9, 14, 12, 17, 19, 22, 20

    RBTree tree;

    for (auto vl : { 11, 2, 14, 1, 7, 5, 8, 15 }) {
        tree.insert(vl);
    }
    
    tree.insert(4);
    
    tree.inorderTraversal();

    tree.remove(7);

    cout << endl;

    tree.inorderTraversal();

    return 0;
}
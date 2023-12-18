#include <iostream>

#include "TrieTree.h"

using namespace std;

int main() {
    
    TrieTree tree;

    tree.Insert("okey");
    tree.Insert("sok");
    tree.Insert("okgg");
    tree.Insert("fff");

    cout << "Before: " << endl;
    tree.Show();
    cout << endl << endl;

    tree.RemoveWithSubstr("ok");

    cout << "After: " << endl;
    tree.Show();
    cout << endl << endl;

    return 0;
}
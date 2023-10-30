#include <iostream>

#include "RBTree.h"

using namespace std;


void insertExample() {
	RBTree tree;

	tree.insert(1);
	tree.insert(0);
	tree.insert(3);
	tree.insert(2);
	tree.insert(5);
	tree.insert(4);
	tree.insert(6);
	tree.insert(7);

	tree.inorderTraversal();
	cout << endl;
}

void removeExample() {
	RBTree tree;

	tree.insert(30);
	tree.insert(20);
	tree.insert(40);
	tree.insert(35);
	tree.insert(50);

	tree.inorderTraversal();
	cout << endl;

	cout << string(32, '-') << endl;

	tree.remove(20);

	tree.inorderTraversal();
	cout << endl;
}

int main() {

	/*
	*	http://rflinux.blogspot.com/2011/10/red-black-trees.html
	*	https://www.geeksforgeeks.org/deletion-in-red-black-tree/?ref=lbp
	*/

	//insertExample();
	removeExample();

	return 0;
}
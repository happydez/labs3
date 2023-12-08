#include <iostream>
#include <string>

#include <Windows.h>

#include "TrieTree.h"

using namespace std;

int main() {

	TrieTree tree = TrieTree();

	tree.Insert("cat");
	tree.Insert("cats");
	tree.Insert("calculator");
	tree.Insert("house");
	tree.Insert("cow");

	tree.Show();

	tree.Remove("cat");

	cout << endl;
	cout << string(32, '-') << endl;
	cout << endl;

	tree.Show();

	return 0;
}

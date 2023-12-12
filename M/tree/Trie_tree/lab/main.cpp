#include <iostream>
#include <string>

#include <Windows.h>

#include "TrieTree.h"

using namespace std;

/*
*   Дано Trie-дерево и некоторое слово. Вывести все формы
*	данного слова, содержащиеся в дереве. Формой слова считается
*	некоторое другое слово, отличающееся от заданого не более чем
*	на n последних символов, где n вводит пользователь.
*/

int main() {

	TrieTree tree;

	tree.Insert("caterpillar");
	tree.Insert("cathedral");
	tree.Insert("catalogue");
	tree.Insert("catalyst");
	tree.Insert("catamaran");
	tree.Insert("category");
	tree.Insert("cattle");
	tree.Insert("house");
	tree.Insert("cow");
	tree.Insert("car");
	tree.Insert("computer");

	queue<string> words = tree.TakeWith("cattle", 3);

	if (words.empty()) {
		cout << "nothing found" << endl;
	}
	else {
		while (!words.empty()) {
			cout << words.front() << endl;
			words.pop();
		}
	}

	return 0;
}

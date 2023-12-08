#pragma once

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class TrieTree {

	private:

		static const int AN = 26;

		struct TrieTreeNode {
			TrieTreeNode* children[AN];
			bool isTerminal;

			TrieTreeNode() {
				for (int i = 0; i < AN; i++) {
					children[i] = nullptr;
				}

				isTerminal = false;
			}
		};

		TrieTreeNode* root;

		void insertHelper(TrieTreeNode* root, string& word) {
			TrieTreeNode* currentNode = root;

			for (int i = 0; i < word.length(); i++) {
				int index = tolower(word[i]) - 'a';

				if (currentNode->children[index] == nullptr) {
					currentNode->children[index] = new TrieTreeNode();
				}

				currentNode = currentNode->children[index];
			}

			currentNode->isTerminal = true;
		}

		bool searchHelper(TrieTreeNode* root, string& word) {
			TrieTreeNode* currentNode = root;

			for (int i = 0; i < word.length(); i++) {
				int index = tolower(word[i]) - 'a';

				if (currentNode->children[index] == nullptr) {
					break;
				}

				currentNode = currentNode->children[index];
			}

			return currentNode->isTerminal;
		}

		void removeHelper(TrieTreeNode* root, string& word) {
			if (searchHelper(root, word)) {
				TrieTreeNode* currentNode = root;

				for (int i = 0; i < word.length(); i++) {
					int index = tolower(word[i]) - 'a';
					currentNode = currentNode->children[index];
				}

				currentNode->isTerminal = false;
			}
		}

		void inorder(TrieTreeNode* root, string wseq, queue<string>& words) {
			if (root != nullptr) {
				for (int i = 0; i < AN; i++) {
					if (root->children[i] != nullptr) {
						if (root->children[i]->isTerminal) {
							words.push(wseq + string(1, 'a' + i));
						}

						inorder(root->children[i], wseq + string(1, 'a' + i), words);
					}
				}
			}
		}

		void inorderHelper(TrieTreeNode* root) {
			queue<string> words;

			for (int i = 0; i < AN; i++) {
				if (root->children[i] != nullptr) {
					inorder(root->children[i], string(1, 'a' + i), words);
				}
			}

			while (!words.empty()) {
				cout << words.front() << endl;
				words.pop();
			}
		}

		void deleteHelper(TrieTreeNode* root) {
			if (root != nullptr) {
				for (int i = 0; i < AN; i++) {
					if (root->children[i] != nullptr) {
						deleteHelper(root->children[i]);
						delete root->children[i];
					}
				}
			}
		}

	public:

		TrieTree() {
			root = new TrieTreeNode();
		}

		~TrieTree() {
			deleteHelper(root);
		}

		void Insert(string word) {
			insertHelper(root, word);
		}

		void Remove(string word) {
			removeHelper(root, word);
		}

		bool Search(string word) {
			return searchHelper(root, word);
		}

		void Show() {
			inorderHelper(root);
		}
};


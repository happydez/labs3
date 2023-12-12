#pragma once

#include <iostream>

using namespace std;

class BinaryTree {

	private:

		struct BTNode {
			int data;
			BTNode *left, *right, *p;

			BTNode(int data = 0, BTNode* left = nullptr, BTNode* right = nullptr, BTNode* p = nullptr) {
				this->data = data;
				this->left = left;
				this->right = right;
				this->p = p;
			}
		};

		BTNode* root;

		BTNode* minimum(BTNode* root) {
			while (root->left != nullptr) {
				root = root->left;
			}

			return root;
		}

		BTNode* maximum(BTNode* root) {
			while (root->right != nullptr) {
				root = root->right;
			}

			return root;
		}

		BTNode* prev(BTNode* node) {
			if (node->left != nullptr) {
				return maximum(node->left);
			}

			BTNode* x = node->p;
			while ((x != nullptr) && (node == x->left)) {
				node = x;
				x = x->p;
			}

			return x;
		}

		BTNode* next(BTNode* node) {
			if (node->right != nullptr) {
				return minimum(node->right);
			}

			BTNode* x = node->p;
			while ((x != nullptr) && (node == x->right)) {
				node = x;
				x = x->p;
			}

			return x;
		}

		void insertHelper(BTNode* root, int data) {
			BTNode* temp = nullptr;

			while (root != nullptr) {
				temp = root;
				if (root->data < data) {
					root = root->right;
				}
				else if (root->data > data) {
					root = root->left;
				}
				else {
					return;
				}
			}

			BTNode* node = new BTNode(data);
			node->p = temp;
			
			if (temp == nullptr) {
				this->root = node;
			}
			else if (temp->data < data) {
				temp->right = node;
			}
			else {
				temp->left = node;
			}
		}

		BTNode* removeHelper(BTNode* root, int data) {
			if (root == nullptr) {
				return root;
			}

			if (root->data > data) {
				root->left = removeHelper(root->left, data);
			}
			else if (root->data < data) {
				root->right = removeHelper(root->right, data);
			}
			else if ((root->left != nullptr) && (root->right != nullptr)) {
				root->data = minimum(root->right)->data;
				root->right = removeHelper(root->right, root->data);
			}
			else {
				if (root->left != nullptr) {
					root = root->left;
				}
				else if (root->right != nullptr) {
					root = root->right;
				}
				else {
					delete root;
					root = nullptr;
				}
			}

			return root;
		}

		BTNode* searchHelper(BTNode* root, int data) {
			while (root != nullptr) {
				if (root->data == data) {
					return root;
				}
				else if (root->data < data) {
					root = root->right;
				}
				else {
					root = root->left;
				}
			}

			return nullptr;
		}

		void deleteHelper(BTNode* root) {
			if (root != nullptr) {
				deleteHelper(root->left);
				deleteHelper(root->right);
			}

			delete root;
			root = nullptr;
		}

		void inorderPrint(BTNode* root) {
			if (root != nullptr) {
				inorderPrint(root->left);
				cout << root->data << " ";
				inorderPrint(root->right);
			}
		}

		// Фунцкия находит максимальный по модулю
		// элемент в дереве
		int findABSMaxRec(BTNode* root, int mx = 0) {
			if (root == nullptr) {
				mx = -1;
			}
			else {
				mx = max(mx, abs(root->data));
				mx = max(mx, abs(findABSMaxRec(root->left, mx)));
				mx = max(mx, abs(findABSMaxRec(root->right, mx)));
			}

			return mx;
		}

	public:

		BinaryTree() {
			this->root = nullptr;
		}

		~BinaryTree() {
			deleteHelper(root);
		}

		void Insert(int data) {
			insertHelper(root, data);
		}

		void Remove(int data) {
			removeHelper(root, data);
		}

		bool Search(int data) {
			return searchHelper(root, data) == nullptr;
		}

		void Print() {
			inorderPrint(root);
			cout << endl;
		}

		int FindABSMax() {
			return findABSMaxRec(root);
		}
};

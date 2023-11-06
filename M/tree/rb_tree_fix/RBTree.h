#pragma once

#include <iostream>

using namespace std;

#define RED true
#define BLACK false

class RBTree {
	private:

		struct RBNode {
			int data;
			bool red;
			RBNode* left;
			RBNode* right;
			RBNode* p;

			RBNode(int data, bool red = true, RBNode* left = nullptr, RBNode* right = nullptr, RBNode* p = nullptr) {
				this->data = data;
				this->red = red;
				this->left = left;
				this->right = right;
				this->p = p;
			}
		};

		RBNode* nil;
		RBNode* root;

		void rotateLeft(RBNode* x) {
			RBNode* y = x->right;
			x->right = y->left;

			if (y->left != nil) {
				y->left->p = x;
			}

			y->p = x->p;

			if (x->p == nil) {
				root = y;
			}
			else if (x == x->p->left) {
				x->p->left = y;
			}
			else {
				x->p->right = y;
			}

			y->left = x;
			x->p = y;
		}

		void rotateRight(RBNode* x) {
			RBNode* y = x->left;
			x->left = y->right;

			if (y->right != nil) {
				y->right->p = x;
			}

			y->p = x->p;

			if (x->p == nil) {
				root = y;
			}
			else if (x == x->p->right) {
				x->p->right = y;
			}
			else {
				x->p->left = y;
			}

			y->right = x;
			x->p = y;
		}

		RBNode* minimum(RBNode* root) {
			while (root->left != nil) {
				root = root->left;
			}
			return root;
		}

		RBNode* maximum(RBNode* root) {
			while (root->right != nil) {
				root = root->right;
			}
			return root;
		}

		RBNode* prev(RBNode* x) {
			if (x->left != nil) {
				return maximum(x->left);
			}

			RBNode* y = x->p;
			
			while ((y != nil) && (x == y->left)) {
				x = y;
				y = y->p;
			}

			return y;
		}

		RBNode* next(RBNode* x) {
			if (x->right != nil) {
				return minimum(x->right);
			}

			RBNode* y = x->p;

			while ((y != nil) && (x == y->right)) {
				x = y;
				y = y->p;
			}

			return y;
		}

		void insertFixup(RBNode* x) {
			while (x->p->red) {
				if (x->p == x->p->p->left) {
					RBNode* uncle = x->p->p->right;
					if (uncle->red) {
						x->p->red = BLACK;
						uncle->red = BLACK;
						x->p->p->red = RED;
						x = x->p->p;
					}
					else {
						if (x == x->p->right) {
							x = x->p;
							rotateLeft(x);
						}

						x->p->red = BLACK;
						x->p->p->red = RED;
						rotateRight(x->p->p);
					}
				}
				else {
					RBNode* uncle = x->p->p->left;
					if (uncle->red) {
						x->p->red = BLACK;
						uncle->red = BLACK;
						x->p->p->red = RED;
						x = x->p->p;
					}
					else {
						if (x == x->p->left) {
							x = x->p;
							rotateRight(x);
						}

						x->p->red = BLACK;
						x->p->p->red = RED;
						rotateLeft(x->p->p);
					}
				}
			}

			root->red = BLACK;
		}

		void insertHelper(RBNode* root, int data) {
			RBNode* temp = nil;
			while (root != nil) {
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

			RBNode* x = new RBNode(data);
			x->p = temp;
			x->left = nil;
			x->right = nil;

			if (temp == nil) {
				this->root = x;
				this->root->red = BLACK;
			}
			else if (temp->data < data) {
				temp->right = x;
			}
			else {
				temp->left = x;
			}

			insertFixup(x);
		}

		void removeFixup(RBNode* x) {
			RBNode* w;
			while (x != root && x->red == BLACK) {
				if (x == x->p->left) {
					w = x->p->right;
					if (w->red == RED) { // Случай 1
						w->red = BLACK;
						x->p->red = RED;
						rotateLeft(x->p);
						w = x->p->right;
					}
					if (w->left->red == BLACK && w->right->red == BLACK) { // Случай 2
						w->red = RED;
						x = x->p;
					}
					else {
						if (w->right->red == BLACK) { // Случай 3
							w->left->red = BLACK;
							w->red = RED;
							rotateRight(w);
							w = x->p->right;
						}
						// Случай 4
						w->red = x->p->red;
						x->p->red = BLACK;
						w->right->red = BLACK;
						rotateLeft(x->p);
						x = root;
					}
				}
				else { // Случаи 1-4 для правого поддерева (симметричны слева направо)
					w = x->p->left;
					if (w->red == RED) {
						w->red = BLACK;
						x->p->red = RED;
						rotateRight(x->p);
						w = x->p->left;
					}
					if (w->right->red == BLACK && w->left->red == BLACK) {
						w->red = RED;
						x = x->p;
					}
					else {
						if (w->left->red == BLACK) {
							w->right->red = BLACK;
							w->red = RED;
							rotateLeft(w);
							w = x->p->left;
						}
						w->red = x->p->red;
						x->p->red = BLACK;
						w->left->red = BLACK;
						rotateRight(x->p);
						x = root;
					}
				}
			}

			x->red = BLACK;
		}

		RBNode* removeHelper(RBNode* root, RBNode* z) {
			RBNode* y;
			if ((z->left == nil) || (z->right == nil)) {
				y = z;
			}
			else {
				y = next(z);
			}

			RBNode* x;
			if (y->left != nil) {
				x = y->left;
			}
			else {
				x = y->right;
			}

			x->p = y->p;

			if (y->p == nil) {
				this->root = x;
			}
			else if (y == y->p->left) {
				y->p->left = x;
			}
			else {
				y->p->right = x;
			}

			if (y != z) {
				z->data = y->data;
			}

			if (y->red == BLACK) {
				removeFixup(x);
			}

			return y;
		}

		void inorderTraversalHelper(RBNode* root) {
			if (root != nil) {
				inorderTraversalHelper(root->left);
				cout << root->data << "(" << (root->red ? "R" : "B") << ")" << " ";
				inorderTraversalHelper(root->right);
			}
		}

		RBNode* searchHelper(RBNode* root, int data) {
			while (root != nil) {
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
			
			return nil;
		}

	public:

		RBTree() {
			this->nil = new RBNode(-1, BLACK, nil, nil, nil);
			this->root = nil;
		}

		void insert(int data) {
			insertHelper(root, data);
		}

		void remove(int data) {
			RBNode* x = search(data);

			if (x == nil) {
				return;
			}

			removeHelper(root, x);
		}

		RBNode* search(int data) {
			return searchHelper(root, data);
		}

		void inorderTraversal() {
			inorderTraversalHelper(root);
		}
};


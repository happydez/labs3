#pragma once

#include <iostream>
#include <functional>

using namespace std;

template<typename T>
class SortedSet {

	private:
		const bool RED = true;
		const bool BLACK = false;

		struct RBNode {
			T data;
			bool red;
			RBNode* left;
			RBNode* right;
			RBNode* p;

			RBNode(T data, bool red = true, RBNode* left = nullptr, RBNode* right = nullptr, RBNode* p = nullptr);
		};

		int count;
		RBNode* nil;
		RBNode* root;
		function<int(T, T)> cmp;

		void deleteHelper(RBNode* root);
		RBNode* copyTree(RBNode* otherRoot, RBNode* parent, RBNode* otherNil);

		void rotateLeft(RBNode* x);
		void rotateRight(RBNode* x);

		RBNode* minimum(RBNode* root) const;
		RBNode* maximum(RBNode* root) const;

		RBNode* prev(RBNode* x) const;
		RBNode* next(RBNode* x) const;

		void insertHelper(RBNode* root, int data);
		void insertFixup(RBNode* x);

		RBNode* removeHelper(RBNode* root, RBNode* z);
		void removeFixup(RBNode* x);

		RBNode* searchHelper(RBNode* root, int data) const;

		void inorderTraversalHelper(ostream& out, RBNode* root) const;

	public:
		SortedSet(const SortedSet<T>& other);
		SortedSet(function<int(T, T)> comparator);
		~SortedSet();

		int Count();

		void Insert(int data);
		bool Remove(int data);
		bool Contains(int data) const;

		SortedSet<T> Union(const SortedSet<T>& other);
		SortedSet<T> Intersect(const SortedSet<T>& other);
		SortedSet<T> Except(const SortedSet<T>& other);

		SortedSet<T>& operator=(const SortedSet<T>& s);

		friend ostream& operator<< <T>(ostream& out, const SortedSet<T>& set);
};

template<typename T>
SortedSet<T>::RBNode::RBNode(T data, bool red, RBNode* left, RBNode* right, RBNode* p) {
	this->data = data;
	this->red = red;
	this->left = left;
	this->right = right;
	this->p = p;
}

template<typename T>
void SortedSet<T>::rotateLeft(RBNode* x) {
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

template<typename T>
void SortedSet<T>::rotateRight(RBNode* x) {
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

template<typename T>
typename SortedSet<T>::RBNode* SortedSet<T>::minimum(RBNode* root) const {
	while (root->left != nil) {
		root = root->left;
	}

	return root;
}

template<typename T>
typename SortedSet<T>::RBNode* SortedSet<T>::maximum(RBNode* root) const {
	while (root->right != nil) {
		root = root->right;
	}
	return root;
}

template<typename T>
typename SortedSet<T>::RBNode* SortedSet<T>::prev(RBNode* x) const {
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

template<typename T>
typename SortedSet<T>::RBNode* SortedSet<T>::next(RBNode* x) const {
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

template<typename T>
void SortedSet<T>::insertHelper(RBNode* root, int data) {
	RBNode* temp = nil;
	while (root != nil) {
		temp = root;
		if (this->cmp(root->data, data) == -1) {
			root = root->right;
		}
		else if (this->cmp(root->data, data) == 1) {
			root = root->left;
		}
		else {
			return;
		}
	}

	this->count++;

	RBNode* x = new RBNode(data);
	x->p = temp;
	x->left = nil;
	x->right = nil;

	if (temp == nil) {
		this->root = x;
		this->root->red = BLACK;
	}
	else if (this->cmp(temp->data, data) == -1) {
		temp->right = x;
	}
	else {
		temp->left = x;
	}

	insertFixup(x);
}

template<typename T>
void SortedSet<T>::insertFixup(RBNode* x) {
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

template<typename T>
void SortedSet<T>::inorderTraversalHelper(ostream& out, RBNode* root) const {
	if (root != nil) {
		inorderTraversalHelper(out, root->left);
		out << root->data << " ";
		inorderTraversalHelper(out, root->right);
	}
}

template<typename T>
typename SortedSet<T>::RBNode* SortedSet<T>::removeHelper(RBNode* root, RBNode* z) {
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

	this->count--;

	return y;
}

template<typename T>
void SortedSet<T>::removeFixup(RBNode* x) {
	RBNode* w;
	while (x != root && x->red == BLACK) {
		if (x == x->p->left) {
			w = x->p->right;
			if (w->red == RED) {
				w->red = BLACK;
				x->p->red = RED;
				rotateLeft(x->p);
				w = x->p->right;
			}
			if (w->left->red == BLACK && w->right->red == BLACK) {
				w->red = RED;
				x = x->p;
			}
			else {
				if (w->right->red == BLACK) {
					w->left->red = BLACK;
					w->red = RED;
					rotateRight(w);
					w = x->p->right;
				}

				w->red = x->p->red;
				x->p->red = BLACK;
				w->right->red = BLACK;
				rotateLeft(x->p);
				x = root;
			}
		}
		else {
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

template<typename T>
typename SortedSet<T>::RBNode* SortedSet<T>::searchHelper(RBNode* root, int data) const {
	while (root != nil) {
		if (this->cmp(root->data, data) == 0) {
			return root;
		}
		else if (this->cmp(root->data, data) == -1) {
			root = root->right;
		}
		else {
			root = root->left;
		}
	}

	return nil;
}

template<typename T>
void SortedSet<T>::deleteHelper(RBNode* root) {
	if (root != nil) {
		deleteHelper(root->left);
		deleteHelper(root->right);
		delete root;
	}
}

template<typename T>
SortedSet<T>::SortedSet(function<int(T, T)> comparator) {
	this->count = 0;
	this->cmp = comparator;
	this->nil = new RBNode(-1, BLACK, nil, nil, nil);
	this->root = nil;
}

template<typename T>
SortedSet<T>::SortedSet(const SortedSet<T>& other) {
	this->count = other.count;
	this->cmp = other.cmp;
	this->nil = new RBNode(-1, BLACK, nil, nil, nil);
	this->root = copyTree(other.root, nil, other.nil);
}


template<typename T>
SortedSet<T>::~SortedSet() {
	deleteHelper(root);
	delete this->nil;
	this->nil = nullptr;
	this->root = nullptr;
}

template<typename T>
void SortedSet<T>::Insert(int data) {
	insertHelper(root, data);
}

template<typename T>
ostream& operator<<(ostream& out, const SortedSet<T>& set) {
	set.inorderTraversalHelper(out, set.root);
	return out;
}

template<typename T>
bool SortedSet<T>::Contains(int data) const {
	if (searchHelper(root, data) != nil) {
		return true;
	}

	return false;
}

template<typename T>
bool SortedSet<T>::Remove(int data) {
	RBNode* x = searchHelper(root, data);

	if (x == nil) {
		return false;
	}

	removeHelper(root, x);

	return true;
}

template<typename T>
int SortedSet<T>::Count() {
	return this->count;
}

template<typename T>
SortedSet<T> SortedSet<T>::Union(const SortedSet<T>& other) {
	SortedSet<T> result(this->cmp);

	for (RBNode* it = this->minimum(this->root); it != this->nil; it = this->next(it)) {
		result.Insert(it->data);
	}

	for (RBNode* it = other.minimum(other.root); it != other.nil; it = other.next(it)) {
		if (!this->Contains(it->data)) {
			result.Insert(it->data);
		}
	}

	return result;
}

template<typename T>
SortedSet<T> SortedSet<T>::Intersect(const SortedSet<T>& other) {
	SortedSet<T> result(this->cmp);

	for (RBNode* it = this->minimum(this->root); it != this->nil; it = this->next(it)) {
		if (other.Contains(it->data)) {
			result.Insert(it->data);
		}
	}

	return result;
}

template<typename T>
SortedSet<T> SortedSet<T>::Except(const SortedSet<T>& other) {
	SortedSet<T> result(this->cmp);

	for (RBNode* it = this->minimum(this->root); it != this->nil; it = this->next(it)) {
		if (!other.Contains(it->data)) {
			result.Insert(it->data);
		}
	}

	return result;
}

template<typename T>
typename SortedSet<T>::RBNode* SortedSet<T>::copyTree(RBNode* otherRoot, RBNode* parent,  RBNode* otherNil) {
	if (otherRoot == otherNil) {
		return nil;
	}

	RBNode* node = new RBNode(otherRoot->data);
	node->red = otherRoot->red;
	node->p = parent;

	node->left = copyTree(otherRoot->left, node, otherNil);
	node->right = copyTree(otherRoot->right, node, otherNil);

	return node;
}

template<typename T>
SortedSet<T>& SortedSet<T>::operator=(const SortedSet<T>& other) {
	if (this != &other) {
		deleteHelper(root);
		delete nil;
		nil = nullptr;
		root = nullptr;

		this->count = other.count;
		this->cmp = other.cmp;
		this->nil = new RBNode(-1, BLACK, nil, nil, nil);
		this->root = copyTree(other.root, nil, other.nil);
	}

	return *this;
}
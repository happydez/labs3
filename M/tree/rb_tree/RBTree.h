#include <iostream>

using namespace std;
const static bool RED = 0;
const static bool BLACK = 1;

struct Node {
    int data;
    bool color;
    Node* left, * right, * p;    

    Node(const int& v, const bool& c = RED, Node* l = nullptr, Node* r = nullptr, Node* _p = nullptr) : data(v), color(c), left(l), right(r), p(_p) {}
};

class RBTree {
    private:
        Node* root;
        Node* nil; 

        void rotateLeft(Node* x) {
            Node* y = x->right;
            x->right = y->left;

            if (y->left != nil) {
                y->left->p = x;
            }

            y->p = x->p;
            if (x->p == nil) {
                root = y;
            }
            else if (x->p->left == x) {
                x->p->left = y;
            }
            else {
                x->p->right = y;
            }

            x->p = y;
            y->left = x;
        }

        void rotateRight(Node* x) {
            Node* y = x->left;
            x->left = y->right;

            if (y->right != nil) {
                y->right->p = x;
            }

            y->p = x->p;
            if (x->p == nil) {
                root = y;
            }
            else if (x->p->left == x) {
                x->p->left = y;
            }
            else {
                x->p->right = y;
            }

            x->p = y;
            y->right = x;
        }

        void inorderTraversalHelper(Node* node) {
            if (node != nil) {
                inorderTraversalHelper(node->left);
                cout << node->data << ((node->color == RED) ? "(R) " : "(B) ");
                inorderTraversalHelper(node->right);
            }
        }

        void preorderTraversalHelper(Node* node) {
            if (node != nil) {
                cout << node->data << ((node->color == RED) ? "(R) " : "(B) ");
                preorderTraversalHelper(node->left);
                preorderTraversalHelper(node->right);
            }
        }

        void postorderTraversalHelper(Node* node) {
            if (node != nil) {
                postorderTraversalHelper(node->left);
                postorderTraversalHelper(node->right);
                cout << node->data << ((node->color == RED) ? "(R) " : "(B) ");
            }
        }

        Node* searchHelper(Node* r, const int& v) {
            if (r == nil) {
                return nil;
            }
            if (r->data == v) {
                return r;
            }
            else if (v < r->data) {
                return searchHelper(r->left, v);
            }
            else {
                return searchHelper(r->right, v);
            }
        }

        Node* insertBST(Node*& p, Node*& r, const int& v)
        {
            if (r == nil) {
                r = new Node(v, RED, nil, nil, p);

                if (p == nil) {
                    root = r;
                }
                if (v > p->data) {
                    p->right = r;
                }
                else {
                    p->left = r;
                }
            }
            else {
                if (v < r->data) {
                    return insertBST(r, r->left, v);
                }
                else {
                    return insertBST(r, r->right, v);
                }
            }

            return r;
        }

        Node* findMin(Node* r) {
            Node* p = r;
            while (r != nil)
            {
                p = r;
                r = r->left;
            }
            return p;
        }

        void transplant(Node*& u, Node*& v) {
            if (u->p == nil) {
                root = v;
            }
            else if (u == u->p->left) {
                u->p->left = v;
            }
            else {
                u->p->right = v;
            }

            v->p = u->p;
        }

        void removeHelper(Node* z) {
            Node* y = z;
            bool delcol = y->color;
            Node* x = z;

            // ≈сли 1 ребенок
            if (z->left == nil) {
                x = z->right;
                transplant(z, z->right);
            }
            else if (z->right == nil) {
                x = z->left;
                transplant(z, z->left);
            }
            else { // ≈сли 2 ребенка
                y = findMin(z->right);
                delcol = y->color;
                x = y->right;

                if (y->p == z) {
                    x->p = y;
                }
                else {
                    transplant(y, y->right);
                    y->right = z->right;
                    y->right->p = y;
                }

                transplant(z, y);

                y->left = z->left;
                y->left->p = y;
                y->color = z->color;
            }

            if (delcol == BLACK) {
                removeFixup(x);
            }
        }

        void removeFixup(Node* x)
        {
            while (x != root && x->color == BLACK)
            {
                if (x == x->p->left)
                {
                    Node* w = x->p->right;
                    if (w->color == RED) { // брат красный
                        w->color = BLACK;
                        x->p->color = RED;
                        rotateLeft(x->p);
                        w = x->p->right;
                    }

                    if (w->left->color == BLACK and w->right->color == BLACK) { // у брата 2 черных ребенка
                        w->color = RED;
                        x = x->p;
                    }
                    else {
                        // —лучаи когда 1 ребенок брата красный
                        if (w->right->color == BLACK) {
                            w->left->color = BLACK;
                            w->color = RED;
                            rotateRight(w);
                            w = x->p->right;
                        }

                        w->color = x->p->color;
                        x->p->color = BLACK;
                        w->right->color = BLACK;
                        rotateLeft(x->p);
                        x = root;
                    }
                }
                else { // аналогично в другую сторону
                    Node* w = x->p->left;
                    if (w->color == RED) {
                        w->color = BLACK;
                        x->p->color = RED;
                        rotateRight(x->p);
                        w = x->p->left;
                    }
                    if (w->right->color == BLACK && w->left->color == RED) {
                        w->color = RED;
                        x = x->p;
                    }
                    else {
                        if (w->left->color == BLACK) {
                            w->right->color = BLACK;
                            w->color = RED;
                            rotateLeft(w);
                            w = x->p->left;
                        }

                        w->color = x->p->color;
                        x->p->color = BLACK;
                        w->left->color = BLACK;
                        rotateRight(x->p);
                        x = root;
                    }
                }
            }

            x->color = BLACK;
        }

    public:
        RBTree() {
            nil = new Node(-1, BLACK, nil, nil, nil);
            root = nil;
        }

        void insert(const int& v)
        {
            Node* z = insertBST(nil, root, v);

            while (z->p->color == RED) {
                if (z->p->p->left == z->p) {
                    if (z->p->p->right->color == RED) {
                        z->p->color = BLACK;
                        z->p->p->color = RED;
                        z->p->p->right->color = BLACK;
                        z = z->p->p;
                    }
                    else {
                        if (z->p->right == z) {
                            z = z->p;
                            rotateLeft(z);
                        }

                        z->p->color = BLACK;
                        z->p->p->color = RED;
                        rotateRight(z->p->p);
                    }
                }
                else {
                    if (z->p->p->left->color == RED) {
                        z->p->color = BLACK;
                        z->p->p->color = RED;
                        z->p->p->left->color = BLACK;
                        z = z->p->p;
                    }
                    else {
                        if (z->p->left == z) {
                            z = z->p;
                            rotateRight(z);
                        }

                        z->p->color = BLACK;
                        z->p->p->color = RED;
                        rotateLeft(z->p->p);
                    }
                }
            }

            root->color = BLACK;                                   
        }

        Node* search(const int& v) {
            return searchHelper(root, v);
        }

        void remove(const int& v) {
            Node* z = searchHelper(root, v);

            if (z == nil) {
                return;
            }

            removeHelper(z);
        }

        void inorderTraversal() {
            inorderTraversalHelper(root);
        }

        void preorderTraversal() {
            preorderTraversalHelper(root);
        }

        void postorderTraversal() {
            postorderTraversalHelper(root);
        }
};
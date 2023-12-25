#include <iostream>
#include <iomanip>

using namespace std;

class AVLTree {
private:
    struct AVLNode {
        int data;
        int height;
        AVLNode* left;
        AVLNode* right;

        AVLNode(int data = 0, int height = 1, AVLNode* left = nullptr, AVLNode* right = nullptr) {
            this->data = data;
            this->height = height;
            this->left = left;
            this->right = right;
        }
    };

    AVLNode* root;

    int getHeight(AVLNode* node) {
        return (node == nullptr) ? 0 : node->height;
    }

    void fixHeight(AVLNode* node) {
        if (node != nullptr) {
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        }
    }

    int balanceFactor(AVLNode* p) {
        return getHeight(p->right) - getHeight(p->left);
    }

    void inorderPrint(AVLNode* root) {
        if (root != nullptr) {
            inorderPrint(root->left);
            cout << root->data << " ";
            inorderPrint(root->right);
        }
    }

    void deleteHelper(AVLNode* root) {
        if (root != nullptr) {
            deleteHelper(root->left);
            deleteHelper(root->right);
        }

        delete root;
    }

    AVLNode* rotateRight(AVLNode* p) {
        AVLNode* x = p->left;
        AVLNode* y = x->right;

        x->right = p;
        p->left = y;

        fixHeight(p);
        fixHeight(x);

        return x;
    }

    AVLNode* rotateLeft(AVLNode* p) {
        AVLNode* x = p->right;
        AVLNode* y = x->left;

        x->left = p;
        p->right = y;

        fixHeight(p);
        fixHeight(x);

        return x;
    }

    AVLNode* minimum(AVLNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }

        return root;
    }

    void balance(AVLNode*& p) {
        if (p == nullptr) {
            return;
        }

        fixHeight(p);

        int bf = balanceFactor(p);

        if (bf == -2) {
            if (balanceFactor(p->left) > 0) {
                p->left = rotateLeft(p->left);
            }

            p = rotateRight(p);
        }

        if (bf == 2) {
            if (balanceFactor(p->right) < 0) {
                p->right = rotateRight(p->right);
            }

            p = rotateLeft(p);
        }
    }

    AVLNode* removeHelper(AVLNode* root, int data) {
        if (root == nullptr) {
            return root;
        }

        if (root->data > data) {
            root->left = removeHelper(root->left, data);
        }
        else if (root->data < data) {
            root->right = removeHelper(root->right, data);
        }
        else if (root->left != nullptr && root->right != nullptr) {
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

        balance(root);

        return root;
    }

    void insertHelper(AVLNode*& root, int data) {
        if (root == nullptr) {
            root = new AVLNode(data);
        }
        else if (root->data != data) {
            if (root->data < data) {
                insertHelper(root->right, data);
            }
            else {
                insertHelper(root->left, data);
            }

            balance(root);
        }

    }

    bool isBalanced(AVLNode* node) {
        if (node == nullptr) {
            return true;
        }

        int bf = balanceFactor(node);
        if (abs(bf) == 2) {
            return false;
        }

        return isBalanced(node->left) && isBalanced(node->right);
    }

    void printHelper(AVLNode* node, int indent) {
        const int spacesPerLevel = 4;

        if (node == nullptr) {
            return;
        }

        printHelper(node->right, indent + spacesPerLevel);

        cout << string(indent, ' ') << " --- " << node->data << endl;

        printHelper(node->left, indent + spacesPerLevel);
    }

    AVLNode* searchHelper(AVLNode* root, int data) {
        if (root != nullptr) {
            if (root->data == data) {
                return root;
            }

            if (root->data > data) {
                return searchHelper(root->left, data);
            }
            else {
                return searchHelper(root->right, data);
            }
        }

        return nullptr;
    }

public:
    AVLTree() {
        this->root = nullptr;
    }

    AVLTree(int root) : AVLTree()
    {
        this->Insert(root);
    }

    ~AVLTree() {
        deleteHelper(root);
    }

    void Insert(int data) {
        insertHelper(root, data);
    }

    bool Remove(int data) {
        return (removeHelper(root, data) == nullptr) ? false : true;
    }

    bool Search(int data) {
        return (searchHelper(root, data) == nullptr) ? false : true;
    }

    void InorderPrint() {
        inorderPrint(root);
        cout << endl;
    }

    void Print() {
        printHelper(root, 0);
    }

    int Height() {
        return this->getHeight(root);
    }

    int Minimum() {
        return this->minimum(root)->data;
    }

    bool IsBalanced() {
        return isBalanced(root);
    }
};
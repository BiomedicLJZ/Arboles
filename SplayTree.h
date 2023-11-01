#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <memory>

class SplayTree {
private:
    struct Node {
        int key;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    std::shared_ptr<Node> root;

    std::shared_ptr<Node> rightRotate(std::shared_ptr<Node> x) {
        auto y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }

    std::shared_ptr<Node> leftRotate(std::shared_ptr<Node> x) {
        auto y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    std::shared_ptr<Node> splay(std::shared_ptr<Node> root, int key) {
        if (!root || root->key == key)
            return root;

        if (key < root->key) {
            if (!root->left)
                return root;

            root->left->left = (key < root->left->key) ? splay(root->left->left, key) : root->left->right;
            root = (root->left->left) ? rightRotate(root) : root;

            return (!root->left) ? root : rightRotate(root);
        }
        else {
            if (!root->right)
                return root;

            root->right->left = (key < root->right->key) ? splay(root->right->left, key) : root->right->right;
            root = (root->right->left) ? rightRotate(root) : root;

            return (!root->right) ? root : leftRotate(root);
        }
    }

    std::shared_ptr<Node> insert(std::shared_ptr<Node> root, int key) {
        if (!root)
            return std::make_shared<Node>(key);

        root = splay(root, key);

        auto newNode = std::make_shared<Node>(key);
        if (key < root->key) {
            newNode->left = root->left;
            newNode->right = root;
            root->left = nullptr;
        }
        else if (key > root->key) {
            newNode->right = root->right;
            newNode->left = root;
            root->right = nullptr;
        }
        return newNode;
    }

public:
    SplayTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    bool contains(int key) {
        root = splay(root, key);
        return (root != nullptr && root->key == key);
    }
};

#endif  // SPLAYTREE_H

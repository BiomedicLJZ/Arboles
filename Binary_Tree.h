#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>


struct Node {
    int key;
    Node* left;
    Node* right;
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    Node* newNode(int item) {
        Node* temp = new Node;
        temp->key = item;
        temp->left = temp->right = NULL;
        return temp;
    }

    void inorderTraversal(Node* node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            std::cout << node->key << " ";
            inorderTraversal(node->right);
        }
    }

    Node* insertNode(Node* node, int key) {
        if (node == NULL) return newNode(key);
        if (key < node->key)
            node->left = insertNode(node->left, key);
        else if (key > node->key)
            node->right = insertNode(node->right, key);
        return node;
    }
};

#endif // BINARY_TREE_H

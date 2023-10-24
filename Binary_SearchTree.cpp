#include "Binary_SearchTree.h"
#include <stdexcept>

using namespace std;

Node::Node(int val) : value(val), left(nullptr), right(nullptr) {}

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

bool BinarySearchTree::isEmpty() const {
    return (root == nullptr);
}

void BinarySearchTree::makeEmpty() {
    root = nullptr;
}

void BinarySearchTree::insert(int value) {
    root = insert(value, root);
}

void BinarySearchTree::remove(int value) {
    root = remove(value, root);
}

bool BinarySearchTree::contains(int value) const {
    return contains(value, root);
}

int BinarySearchTree::findMin() const {
    if(isEmpty()) throw runtime_error("The tree is empty.");
    return findMin(root)->value;
}

int BinarySearchTree::findMax() const {
    if(isEmpty()) throw runtime_error("The tree is empty.");
    return findMax(root)->value;
}

Node* BinarySearchTree::insert(int value, Node* node) {
    if(node == nullptr)
        return new Node(value);
    if(value < node->value)
        node->left = insert(value, node->left);
    else if(value > node->value)
        node->right = insert(value, node->right);
    else
        throw runtime_error("Duplicate value.");
    return node;
}

Node* BinarySearchTree::remove(int value, Node* node) {
    if(node == nullptr) return node;
    if(value < node->value)
        node->left = remove(value, node->left);
    else if(value > node->value)
        node->right = remove(value, node->right);
    else {
        if(node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMinNode(node->right);
        node->value = temp->value;
        node->right = remove(temp->value, node->right);
    }
    return node;
}

bool BinarySearchTree::contains(int value, Node* node) const {
    if(node == nullptr) return false;
    if(value < node->value) return contains(value, node->left);
    else if(value > node->value) return contains(value, node->right);
    else return true;
}

Node* BinarySearchTree::findMin(Node* node) const {
    return (node->left == nullptr) ? node : findMin(node->left);
}

Node* BinarySearchTree::findMax(Node* node) const {
    return (node->right == nullptr) ? node : findMax(node->right);
}

Node* BinarySearchTree::findMinNode(Node* node) const {
    while (node->left != nullptr) node = node->left;
    return node;
}

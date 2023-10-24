#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int value);
};

class BinarySearchTree {
public:
    Node* root;
    BinarySearchTree();
    bool isEmpty() const;
    void makeEmpty();
    void insert(int value);
    void remove(int value);
    bool contains(int value) const;
    int findMin() const;
    int findMax() const;

private:
    Node* insert(int value, Node* node);
    Node* remove(int value, Node* node);
    bool contains(int value, Node* node) const;
    Node* findMin(Node* node) const;
    Node* findMax(Node* node) const;
    Node* findMinNode(Node* node) const;
    Node* findMaxNode(Node* node) const;
};

#endif

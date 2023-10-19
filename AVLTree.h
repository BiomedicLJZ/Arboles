#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <iomanip>
#include <algorithm>

template <typename T>
class Node {
public:
    T data;
    int height;
    Node<T>* left;
    Node<T>* right;

    explicit Node(T data) : data(data), height(1), left(nullptr), right(nullptr) {}
};

template <typename T>
class AVLTree {
public:
    Node<T>* root;

    AVLTree() : root(nullptr) {}

    void add(T data);
    void remove(T data);
    void print(Node<T>* node, int indent = 0);

private:
    Node<T>* newNode(T data);
    Node<T>* rightRotate(Node<T>* y);
    Node<T>* leftRotate(Node<T>* x);
    int getBalance(Node<T>* N);
    Node<T>* insert(Node<T>* node, T data);
    Node<T>* minValueNode(Node<T>* node);
    Node<T>* deleteNode(Node<T>* root, T data);
    int height(Node<T>* N);
    int max(int a, int b);
};

#include "AVLTree.cpp"

#endif /* AVL_TREE_H */

// main.cpp
#include <iostream>

#include "BinaryTree.h"


int main() {
    BinaryTree tree;
    tree.root = tree.insertNode(tree.root, 50);
    tree.insertNode(tree.root, 30);
    tree.insertNode(tree.root, 20);
    tree.insertNode(tree.root, 40);
    tree.insertNode(tree.root, 70);
    tree.insertNode(tree.root, 60);
    tree.insertNode(tree.root, 80);

    tree.inorderTraversal(tree.root);

    std::cout << std::endl;

    tree.printTree(tree.root);

    return 0;
}

// main.cpp
#include <iostream>
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "BinaryTree.h"
#include <random>


int main() {
    BinarySearchTree *bst = new BinarySearchTree();
    bst->root = bst->insertNode(bst->root, 1000000);
    bst->insertNode(bst->root, 100000);
    bst->insertNode(bst->root, 80000);
    bst->insertNode(bst->root, 50000);
    bst->insertNode(bst->root, 34000);
    bst->insertNode(bst->root, 25323);
    bst->insertNode(bst->root, 16530);
    bst->insertNode(bst->root, 10000);
    bst->insertNode(bst->root, 5937);
    bst->insertNode(bst->root, 4444);
    bst->insertNode(bst->root, 4324);
    bst->insertNode(bst->root, 4000);
    bst->insertNode(bst->root, 3000);
    bst->insertNode(bst->root, 2000);
    bst->insertNode(bst->root, 1000);
    bst->insertNode(bst->root, 500);
    bst->insertNode(bst->root, 250);
    bst->insertNode(bst->root, 100);
    bst->insertNode(bst->root, 50);
    bst->insertNode(bst->root, 25);
    bst->insertNode(bst->root, 14);
    bst->insertNode(bst->root, 10);
    bst->insertNode(bst->root, 5);
    bst->insertNode(bst->root, 1);


    std::cout << "Inorder traversal of the given tree: ";
    bst->inorderTraversal(bst->root);

    std::cout << std::endl;
    bst->printTree(bst->root);

    AVLTree avl;

    avl.insert(1000000);
    avl.insert(100000);
    avl.insert(80000);
    avl.insert(50000);
    avl.insert(34000);
    avl.insert(25323);
    avl.insert(16530);
    avl.insert(10000);
    avl.insert(5937);
    avl.insert(4444);
    avl.insert(4324);
    avl.insert(4000);
    avl.insert(3000);
    avl.insert(2000);
    avl.insert(1000);
    avl.insert(500);
    avl.insert(250);
    avl.insert(100);
    avl.insert(50);
    avl.insert(25);
    avl.insert(14);
    avl.insert(10);
    avl.insert(5);
    avl.insert(1);
    avl.printTree();

    avl.printTree(avl.getRoot());

    float min = avl.findMin();
    float max = avl.findMax();
    std::cout << "Min: " << min << " Max: " << max << std::endl;
    bool found = avl.contains(5937);
    std::cout << "Found 5937: " << found << std::endl;
    found = avl.contains(5938);
    std::cout << "Found 5938: " << found << std::endl;

    std::vector<float> route = avl.searchPath(5937);
    std::cout <<  "Path to 5937: "; for(auto i:route) std::cout << i << " ";
    return 0;
}

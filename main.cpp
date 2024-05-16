// main.cpp
#include <iostream>
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "BinaryTree.h"
#include <random>
#include "SplayTree.h"

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
    //bst->inorderTraversal(bst->root);

    std::cout << std::endl;
  // bst->printTree(bst->root);

    AVLTree avl;
    avl.insert(210);
    avl.insert(200);
    avl.insert(190);
    avl.insert(180);
     avl.insert(170) ;
    avl.insert(160);
    avl.insert(150);
    avl.insert(140);
    avl.insert(130);
    avl.insert(120);
    avl.insert(110);
    avl.insert(100);
    avl.insert(90);
    avl.insert(80);
    avl.insert(70);
    avl.insert(60);
    avl.insert(50);
    avl.insert(40);
    avl.insert(30);
    avl.insert(20);
    avl.insert(10) ;
    avl.insert(1);
    avl.printTree();

    SplayTree splay;
    splay.insert(1000000);
    splay.insert(100000);
    splay.insert(80000);
    splay.insert(50000);
    splay.insert(34000);
    splay.insert(25323);
    splay.insert(16530);
    splay.insert(10000);
    splay.insert(5937);
    splay.insert(4444);
    splay.insert(4324);
    splay.insert(4000);
    splay.insert(3000);
    splay.insert(2000);
    splay.insert(1000);
    splay.insert(500);
    splay.insert(250);

    splay.printTree()


    return 0;
}

#include <iostream>
#include "Binary_Tree.h"

int main() {
BinaryTree tree;

// Test 1: Add and print 1 node.

tree.root = tree.insertNode(tree.root, 5);

std::cout << "After adding one node:" << std::endl;
tree.inorderTraversal(tree.root);
std::cout << "\n-------------------------\n";

// Test 2: Add and print multiple nodes.

tree.root = tree.insertNode(tree.root, 3);
tree.root = tree.insertNode(tree.root, 7);
tree.root = tree.insertNode(tree.root, 2);
tree.root = tree.insertNode(tree.root, 4);
tree.root = tree.insertNode(tree.root, 6);

std::cout << "After adding multiple nodes:" << std::endl;
tree.inorderTraversal(tree.root);
std::cout << "\n-------------------------\n";

// Now add nodes to the tree but not onthe root.

tree.root->left->left = tree.insertNode(tree.root->left->left, 1);
tree.root->left->right = tree.insertNode(tree.root->left->right, 9);
tree.root->right->left = tree.insertNode(tree.root->right->left, 8);
tree.inorderTraversal(tree.root);
return 0;
}

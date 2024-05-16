#include <iostream>
#include <vector>
#include "AVLTree.h"

void testInsertion(AVLTree& tree, const std::vector<int>& values) {
    for (int value : values) {
        tree.insert(value);
    }

    std::cout << "Inorder Traversal: ";
    tree.inorderTraversal(tree.root);
    std::cout << std::endl;
}

void testRemoval(AVLTree& tree, const std::vector<int>& values) {
    for (int value : values) {
        tree.remove(value);
    }

    std::cout << "Inorder Traversal after removal: ";
    tree.inorderTraversal(tree.root);
    std::cout << std::endl;
}

int main() {
    AVLTree tree;

    std::cout << "Test Case 1: Insert values and check tree balance" << std::endl;
    std::vector<int> insertValues = {10, 20, 30, 40, 50};
    testInsertion(tree, insertValues);

    std::cout << "\nTest Case 2: Remove values and check tree balance" << std::endl;
    std::vector<int> removeValues = {20, 40};
    testRemoval(tree, removeValues);

    std::cout << "\nTest Case 3: Test with duplicate values" << std::endl;
    AVLTree duplicateTree;
    std::vector<int> duplicateValues = {10, 10, 20, 20};
    testInsertion(duplicateTree, duplicateValues);

    return 0;
}

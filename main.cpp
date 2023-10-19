// main.cpp
#include <iostream>
#include "AVLTree.h"

int main() {
    AVLTree<int> tree;
    
    // Test 1: Add and print 1 node.
    tree.add(5);
    
    std::cout << "After adding one node:" << std::endl;
    tree.print();
    std::cout << "\n-------------------------\n";

    // Test 2: Add and print multiple nodes.
    tree.add(3);
    tree.add(7);
    tree.add(2);
    tree.add(4);
    tree.add(6);
    tree.add(8);

    std::cout << "After adding multiple nodes:" << std::endl;
    tree.print();
    std::cout << "\n-------------------------\n";
    return 0;
}

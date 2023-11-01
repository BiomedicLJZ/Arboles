// main.cpp
#include <iostream>
#include "AVLTree.h"
#include "Storage_Tree.h"
#include "SplayTree.h"

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

    // Test 3: Remove a node and print.
    tree.remove(5);
    std::cout << "\n-------------------------\n";
    std::cout << "After removing 3 and 8:" << std::endl;
    tree.print();

    // Test 4: Search for a node.
    std::cout << "\n-------------------------\n";
    std::cout << "Searching for 3: " << tree.search(tree.root, 3)->data << std::endl;
    std::cout << "Searching for 7: " << tree.search(tree.root, 7)->data << std::endl;
    std::cout << "Searching for 2: " << tree.search(tree.root, 2)->data << std::endl;
    return 0;
}

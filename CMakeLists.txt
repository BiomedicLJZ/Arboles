cmake_minimum_required(VERSION 3.26)
project(Arboles)

set(CMAKE_CXX_STANDARD 17)

add_executable(Arboles main.cpp
        AVLTree.h
        Binary_Tree.h
        Storage_Tree.h
        Binary_SearchTree.cpp
        Binary_SearchTree.h
        SplayTree.h
)

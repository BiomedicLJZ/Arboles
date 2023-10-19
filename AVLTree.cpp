#include "AVLTree.h"

template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template <typename T>
void AVLTree<T>::add(T data) {
    root = insert(root, data);
}

template <typename T>
void AVLTree<T>::remove(T data) {
    root = deleteNode(root, data);
}

template <typename T>
void AVLTree<T>::print() {
    if (root != nullptr) {
        print(root, 0);
    } else {
        std::cout << "The tree is empty." << std::endl;
    }
}

template <typename T>
void AVLTree<T>::print(Node<T>* node, int indent) {
    if (node != nullptr) {
        if (node->right) {
            print(node->right, indent + 4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (node->right) {
            std::cout << " /\n" << std::setw(indent) << ' ';
        }
        std::cout << node->data << "\n ";
        if (node->left) {
            std::cout << std::setw(indent) << ' ' << " \\\n";
            print(node->left, indent + 4);
        }
    }
}

template <typename T>
Node<T>* AVLTree<T>::newNode(T data) {
    Node<T>* node = new Node<T>(data);
    return node;
}

template <typename T>
Node<T>* AVLTree<T>::rightRotate(Node<T>* y) {
    Node<T>* x = y->left;
    Node<T>* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

template <typename T>
Node<T>* AVLTree<T>::leftRotate(Node<T>* x) {
    Node<T>* y = x->right;
    Node<T>* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

template <typename T>
int AVLTree<T>::getBalance(Node<T>* N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

template <typename T>
Node<T>* AVLTree<T>::insert(Node<T>* node, T data) {
    if (node == nullptr)
        return (newNode(data));

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template <typename T>
Node<T>* AVLTree<T>::minValueNode(Node<T>* node) {
    Node<T>* current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

template <typename T>
Node<T>* AVLTree<T>::deleteNode(Node<T>* root, T data) {
    if (root == nullptr)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node<T>* temp = root->left ? root->left :
                                       root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {
            Node<T>* temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

template <typename T>
int AVLTree<T>::height(Node<T>* N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

template <typename T>
int AVLTree<T>::max(int a, int b) {
    return (a > b) ? a : b;
}

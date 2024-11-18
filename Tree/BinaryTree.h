#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include "../Queue/Queue.h"

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class BinaryTree {
public:
    BinaryTreeNode<T>* root;

    BinaryTree() {
        root = nullptr;
    }

    void BFS() {
        // std::cout << root->left->data;
        Queue<BinaryTreeNode<T>*> queue(10);

        if (root == NULL) return;

        queue.enqueue(root);

        while (!queue.isEmpty()) {
            BinaryTreeNode<T>* dequeuedNode = queue.dequeue();
            std::cout << dequeuedNode->data << " ";

            if (dequeuedNode->left != nullptr) queue.enqueue(dequeuedNode->left); 
            if (dequeuedNode->right != nullptr) queue.enqueue(dequeuedNode->right);
            // std::cout  << "hehe " << queue.array[0]->data << queue.array[1]->data << queue.array[9]->data;
        }
        std::cout << std::endl;
    }

    // void insert(T data) {
    //     _insert(data, root);
    // }

// private:
    // void _insert(T data, BinaryTreeNode<T>*& rootNode) {
    //     if (rootNode == nullptr) {
    //         rootNode = new BinaryTreeNode<T>(data);
    //     } else {
    //         if (data > rootNode->data) {
    //             _insert(data, rootNode->right);
    //         } else {
    //             _insert(data, rootNode->left);
    //         }
    //     }
    // }
    void insert(T data) {
    if (root == nullptr) {
        root = new BinaryTreeNode<T>(data); // First node inserted
    } else {
        Queue<BinaryTreeNode<T>*> queue(10);
        queue.enqueue(root);

        while (!queue.isEmpty()) {
            BinaryTreeNode<T>* dequeuedNode = queue.dequeue();

            // Insert left child if empty
            if (dequeuedNode->left == nullptr) {
                dequeuedNode->left = new BinaryTreeNode<T>(data);
                break; // Break once the child is inserted
            } else {
                queue.enqueue(dequeuedNode->left); // Continue with left child
            }

            // Insert right child if empty
            if (dequeuedNode->right == nullptr) {
                dequeuedNode->right = new BinaryTreeNode<T>(data);
                break; // Break once the child is inserted
            } else {
                queue.enqueue(dequeuedNode->right); // Continue with right child
            }
        }
    }
}


};

#endif

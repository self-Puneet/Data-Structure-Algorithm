#include<iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
    BinaryTree<int> tree;
    tree.insert(23);
    tree.insert(34);
    tree.insert(9);
    tree.BFS();
    return 0;
}
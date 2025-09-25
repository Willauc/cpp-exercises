/*
========================================================================
  Fichier     : AVLTree.cpp
  Auteur      : William Turbide Auclair
  Date        : 16 septembre 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe AVLTree comme structure de donnee.

  Version     : 1.0
  ========================================================================
*/

#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree() : root(nullptr) {
}

AVLTree::~AVLTree() = default;

void AVLTree::insert(int value){
    auto toAdd = std::make_shared<Node>(value);
    if (root == nullptr) {
        root = toAdd;
        return;
    }
    insert(root, toAdd);
}

void AVLTree::insert(std::shared_ptr<Node> &root, std::shared_ptr<Node> &toAdd) {
    if (root->value > toAdd->value) {
        if (!root->left) {
            root->left = toAdd;
        } else {
            insert(root->left, toAdd);
        }
    }
    if (root->value < toAdd->value) {
        if (!root->right) {
            root->right = toAdd;
        }else {
            insert(root->right, toAdd);
        }
    }
    updateHeight(root);
}

bool AVLTree::find(int value) const {
    auto curent = root;

    while (true) {
        if (curent == nullptr) {
            return false;
        }
        if (curent->value == value) {
            return true;
        }
        if (curent->value < value) {
            if (curent->right == nullptr) { return false; }
            curent = curent->right;
        } else {
            if (curent->left == nullptr) { return false; }
            curent = curent->left;
        }
    }
}

void AVLTree::printTree() const {
    printTree(root);

}

void AVLTree::printTree(const std::shared_ptr<Node> &root) const {
    if (root == nullptr) {
        return;
    }

    std::cout<<root->toString()<<std::endl;

    printTree(root->left);
    printTree(root->right);
}

void AVLTree::updateHeight(std::shared_ptr<Node> &root) {
    if (!root->left && !root->right) {
        return;
    }
    if (!root->left && root->right) {
        root->height = root->right->height + 1;
        return;
    }
    if (root->left && !root->right) {
        root->height = root->left->height + 1;
        return;
    }


    root->height = std::max(root->left->height, root->right->height) + 1;

}

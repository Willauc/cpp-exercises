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
            return;
        }
        insert(root->left, toAdd);
    }
    if (root->value < toAdd->value) {
        if (!root->right) {
            root->right = toAdd;
            return;
        }
        insert(root->right, toAdd);
    }
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
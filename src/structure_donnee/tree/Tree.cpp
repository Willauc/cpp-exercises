/*
========================================================================
  Fichier     : tree.cpp
  Auteur      : William Turbide Auclair
  Date        : 29 aout 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe Tree comme structure de donnee.

  Version     : 1.0
  ========================================================================
*/

#include "Tree.h"
#include <iostream>

Tree::Tree() : root(nullptr) {
};

Tree::~Tree() = default;

void Tree::insert(int value) {
    auto to_add = std::make_shared<Node>(value);

    if (root == nullptr) {
        root = to_add;
    } else {
        auto curent = root;

        while (true) {
            if (value == curent->value) {
                break;
            } else if (value < curent->value) {
                if (curent->left == nullptr) {
                    curent->left = to_add;
                    break;
                }
                curent = curent->left;
            } else {
                if (curent->right == nullptr) {
                    curent->right = to_add;
                }
                curent = curent->right;
            }
        }
    }
}

bool Tree::find(int value) const {
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

void Tree::printTree() const {
    printNodes(root.get());
}

void Tree::printNodes(const Node *node) const {
    if (!node) return;

    std::cout << "  " << node->value << std::endl;

    if (node->right || node->left) {
        std::cout << (node->left ? std::to_string(node->left->value) : "null")
                << "   "
                << (node->right ? std::to_string(node->right->value) : "null")
                << std::endl;
    }

    if (node->left) {
        printNodes(node->left.get());
    }
    if (node->right) {
        printNodes(node->right.get());
    }
}

bool Tree::isEqual(const std::shared_ptr<Node> &root, const std::shared_ptr<Node> &otherRoot) {
    if (root == nullptr) {
        if (otherRoot == nullptr) {
            return true;
        }
        return false;
    }
    if (root->value == otherRoot->value &&
        isEqual(root->left, otherRoot->left) &&
        isEqual(root->right, otherRoot->right)) {
        return true;
    }
    return false;
}

bool Tree::isEqual(const Tree &other) {
    return isEqual(root, other.root);
}

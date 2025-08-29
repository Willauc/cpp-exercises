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

    if (root == nullptr) {
        root = std::make_unique<Node>(value);
    }else {
        insertUnder(root, value);
    }

}

void Tree::insertUnder( std::unique_ptr<Node>& node, int toAdd) {
    if (node->value > toAdd) {
        if (node->left == nullptr) {
            node->left = std::make_unique<Node>(toAdd);
        }else {
            insertUnder(node->left, toAdd);
        }

    }else if (node->value < toAdd) {
        if (node->right == nullptr) {
            node->right = std::make_unique<Node>(toAdd);
        }else {
            insertUnder(node->right, toAdd);
        }
    }
}

bool Tree::find(int value) const {
    return m_find (root.get(), value);
}

bool Tree::m_find(const Node *node, int value) const {
    if (!node) return false;

    if(node->value == value) return true;
    if (node->value < value) return m_find(node->right.get(), value);
    if (node->value > value) return m_find(node->left.get(), value);
    return false;
}

void Tree::printTree() const {
    printNodes(root.get());

}

void Tree::printNodes(const Node* node) const {
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


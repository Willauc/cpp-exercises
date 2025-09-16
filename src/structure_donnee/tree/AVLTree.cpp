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
    AVLTree::insert(Node(value));
}

void AVLTree::insert(Node toAdd) {
}

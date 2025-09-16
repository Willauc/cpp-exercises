/*
========================================================================
  Fichier     : AVLTree.h
  Auteur      : William Turbide Auclair
  Date        : 16 septembre 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe AVLTree comme structure de donnee.

  Version     : 1.0
  ========================================================================
*/

#ifndef CPP_EXERCISES_AVLTREE_H
#define CPP_EXERCISES_AVLTREE_H

#include <memory>


class AVLTree {

private:
    struct Node {
        int value;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

        explicit Node(int p_value) : value(p_value), left(nullptr), right(nullptr) {
        }
    };

    std::shared_ptr<Node> root;

    void insert(Node toAdd);

public:
    AVLTree();

    ~AVLTree();

    void insert(int value);
};


#endif //CPP_EXERCISES_AVLTREE_H
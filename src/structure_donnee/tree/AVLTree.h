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
#include <string>


class AVLTree {

private:
    struct Node {
        int value;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        int height = 0;

        explicit Node(int p_value) : value(p_value), left(nullptr), right(nullptr) {
        }

        std::string toString() const {
            return "Value = " + std::to_string(value) + " Height = " + std::to_string(height);
        }
    };

    std::shared_ptr<Node> root;

    void insert(std::shared_ptr<Node> &root, std::shared_ptr<Node> &toAdd);
    void printTree(const std::shared_ptr<Node> &root) const;
    void updateHeight(std::shared_ptr<Node> &root);

public:
    AVLTree();

    ~AVLTree();

    void insert(int value);

    bool find(int value) const;

    void printTree() const;
};


#endif //CPP_EXERCISES_AVLTREE_H
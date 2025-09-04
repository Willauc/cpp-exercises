/*
========================================================================
  Fichier     : tree.h
  Auteur      : William Turbide Auclair
  Date        : 29 aout 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe Tree comme structure de donnee.

  Version     : 1.0
  ========================================================================
*/

#ifndef TREE_H
#define TREE_H
#include <memory>


class Tree {
private:
    struct Node {
        int value;
        std::shared_ptr<Node> right;
        std::shared_ptr<Node> left;

        explicit Node(int p_value) : value(p_value), right(nullptr), left(nullptr) {
        }
    };

    std::shared_ptr<Node> root;


    void printNodes(const Node *node) const;

    bool isEqual(const std::shared_ptr<Node>& root, const std::shared_ptr<Node>& otherRoot );


public:
    Tree();

    ~Tree();

    void insert(int value);

    bool find(int value) const;

    void printTree() const;

    bool isEqual(const Tree& other);
};


#endif //TREE_H

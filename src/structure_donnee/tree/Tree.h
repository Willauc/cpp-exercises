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
        std::unique_ptr<Node> right;
        std::unique_ptr<Node> left;

        explicit Node(int p_value) : value(p_value), right(nullptr), left(nullptr) {
        }
    };

    std::unique_ptr<Node> root;

    void insertUnder(std::unique_ptr<Node> &node, int toAdd);

    void printNodes(const Node *node) const;

    bool m_find(const Node *node, int value) const;

public:
    Tree();

    ~Tree();

    void insert(int value);

    bool find(int value) const;

    void printTree() const;
};


#endif //TREE_H

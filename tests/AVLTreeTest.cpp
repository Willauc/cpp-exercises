/*
========================================================================
  Fichier     : AVLTree.cpp
  Auteur      : William Turbide Auclair
  Date        : 29 aout 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe AVLTree. Fichier test.

  Version     : 1.0
  ========================================================================
*/

#include <gtest/gtest.h>
#include <structure_donnee/tree/AVLTree.h>

TEST(AVLTreeTest, constructeur) {
    EXPECT_NO_THROW(AVLTree tree);
}

TEST(AVLTreeTest, insert) {
    AVLTree tree;

    EXPECT_FALSE(tree.find(10));
    tree.insert(10);
    EXPECT_TRUE(tree.find(10));

    EXPECT_FALSE(tree.find(11));
    tree.insert(11);
    EXPECT_TRUE(tree.find(11));

    EXPECT_FALSE(tree.find(9));
    tree.insert(9);
    EXPECT_TRUE(tree.find(9));

}
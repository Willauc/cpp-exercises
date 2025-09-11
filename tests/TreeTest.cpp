/*
========================================================================
  Fichier     : test_stack.cpp
  Auteur      : William Turbide Auclair
  Date        : 29 aout 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe Tree. Fichier test.

  Version     : 1.0
  ========================================================================
*/

#include <gtest/gtest.h>
#include <structure_donnee/tree/Tree.h>

TEST(TreeTest, constructeur) {
    EXPECT_NO_THROW(Tree tree);
}

TEST(TreeTest, insert) {
    Tree tree;

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

TEST(TreeTest, isEqual) {
    Tree tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(6);
    tree.insert(8);
    tree.insert(7);

    Tree tree2;
    tree2.insert(5);
    tree2.insert(4);
    tree2.insert(3);
    tree2.insert(6);
    tree2.insert(8);
    tree2.insert(7);

    EXPECT_TRUE(tree.isEqual(tree2));

    Tree tree3;
    tree3.insert(5);
    tree3.insert(11);
    tree3.insert(3);
    tree3.insert(6);
    tree3.insert(8);
    tree3.insert(54);

    EXPECT_FALSE(tree.isEqual(tree3));

    Tree tree4;

    EXPECT_FALSE(tree4.isEqual(tree3));

    Tree tree5;

    EXPECT_TRUE(tree4.isEqual(tree5));

}

TEST(TreeTest, isBinary) {
    Tree tree;

    EXPECT_TRUE(tree.isBinary());

    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(6);
    tree.insert(8);
    tree.insert(7);

    EXPECT_TRUE(tree.isBinary());

}
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

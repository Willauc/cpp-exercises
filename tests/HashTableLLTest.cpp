/*
========================================================================
  Fichier     : HashTableLLTest.cpp
  Auteur      : William Turbide Auclair
  Date        : 6 Aout 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe Hash Table untilisant des Link List pour gerer les colisions.
                Fichier Test.

  Version     : 1.0
  ========================================================================
*/

#include <gtest/gtest.h>
#include "structure_donnee/hash_table/HashTableLL.h"

TEST(HashTableLLTest, constructeur) {
    EXPECT_NO_THROW(HashTableLL table{});
    HashTableLL table{};
    EXPECT_EQ(table.getSize(), 11);

    EXPECT_NO_THROW(HashTableLL table2{21});
    HashTableLL table2{21};
    EXPECT_EQ(table2.getSize(), 23);
}

TEST(HashTableLLTest, putGet) {
    HashTableLL table{};

    table.put(11, "allo");
    table.put(5, "bye");
    table.put(2, "merci");
    table.put(22, "bonjour" );

    EXPECT_EQ(table.get(11), "allo");
    EXPECT_EQ(table.get(5), "bye");
    EXPECT_EQ(table.get(2), "merci");
    EXPECT_EQ(table.get(22), "bonjour");

    table.put(11, "montreal");
    EXPECT_EQ(table.get(11), "montreal");




    EXPECT_ANY_THROW(table.get(9));
}

TEST(HashTableLLTest, remove) {
    HashTableLL table{};

    table.put(11, "allo");
    table.put(5, "bye");
    table.put(2, "merci");
    table.put(22, "bonjour" );

    table.remove(11);
    EXPECT_ANY_THROW(table.get(11));
    EXPECT_ANY_THROW(table.remove(11));



}




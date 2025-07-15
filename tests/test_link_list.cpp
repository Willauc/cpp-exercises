/*
========================================================================
  Fichier     : test_link_list.cpp
  Auteur      : William Turbide Auclair
  Date        : 3 juillet 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe link list. Fichier test.

  Version     : 1.0
  ========================================================================
*/

#include <gtest/gtest.h>
#include <structure_donnee/link_list/Link_List.h>

TEST(LinkListTest, constructeur) {
    EXPECT_NO_THROW(link_list<int> lst{};);
}

TEST(LinkListTest, addFirst) {
    link_list<int> lst{};
    lst.addFirst(1);
    lst.addFirst(2);
    EXPECT_EQ(lst.indexOf(2), 0);
}


TEST(LinkListTest, addLast) {
    link_list<int> lst{};
    lst.addFirst(1);
    lst.addFirst(2);
    lst.addLast(3);
    EXPECT_EQ(lst.indexOf(3), 2);
}

TEST(LinkListTest, contains) {
    link_list<int> lst{};
    lst.addFirst(1);
    lst.addFirst(2);
    lst.addLast(3);
    EXPECT_TRUE(lst.contains(3));
    EXPECT_TRUE(lst.contains(2));
    EXPECT_FALSE(lst.contains(4));
}

TEST(LinkListTest, deleteFirstLast) {
    link_list<int> lst{};
    EXPECT_ANY_THROW(lst.deleteLast());
    EXPECT_ANY_THROW(lst.deleteFirst());
    lst.addFirst(1);
    lst.addFirst(2);
    lst.addLast(3);

    EXPECT_EQ(lst.indexOf(2), 0);
    lst.deleteFirst();
    EXPECT_EQ(lst.indexOf(1), 0);
    EXPECT_FALSE(lst.contains(2));

    EXPECT_EQ(lst.indexOf(3), 1);
    lst.deleteLast();
    EXPECT_FALSE(lst.contains(3));
}

TEST(LinkListTest, constructeurDeCopie) {
    link_list<int> original;

    original.addLast(10);
    original.addLast(20);
    original.addLast(30);

    link_list<int> copy(original);


    EXPECT_TRUE(copy.contains(10));
    EXPECT_TRUE(copy.contains(20));
    EXPECT_TRUE(copy.contains(30));

    EXPECT_EQ(copy.indexOf(10), 0);
    EXPECT_EQ(copy.indexOf(20), 1);
    EXPECT_EQ(copy.indexOf(30), 2);

    original.deleteFirst();
    EXPECT_TRUE(copy.contains(10));
    EXPECT_FALSE(original.contains(10));
}

TEST(LinkListTest, reverse) {
    link_list<int> lst;

    lst.addLast(10);
    lst.addLast(20);
    lst.addLast(30);
    lst.addLast(40);

    lst.reverse();

    EXPECT_EQ(lst.indexOf(10), 3);
    EXPECT_EQ(lst.indexOf(20), 2);
    EXPECT_EQ(lst.indexOf(30), 1);
    EXPECT_EQ(lst.indexOf(40), 0);
}

TEST(LinkListTest, getKthFromTheEnd) {
    link_list<int> lst;
    EXPECT_ANY_THROW(lst.getKthFromTheEnd(0));

    lst.addLast(10);
    lst.addLast(20);
    lst.addLast(30);
    lst.addLast(40);

    EXPECT_EQ(lst.getKthFromTheEnd(0), 40);
    EXPECT_EQ(lst.getKthFromTheEnd(1), 30);
    EXPECT_EQ(lst.getKthFromTheEnd(2), 20);
    EXPECT_EQ(lst.getKthFromTheEnd(3), 10);

    EXPECT_ANY_THROW(lst.getKthFromTheEnd(4));
}

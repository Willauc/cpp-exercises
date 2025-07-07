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
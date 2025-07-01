/*
========================================================================
  Fichier     : My_Array.cpp
  Auteur      : William Turbide Auclair
  Date        : 1 juillet 2025
  Description : Test pour la calsse My_Array.
  Version     : 1.0
  ========================================================================
*/
#include <gtest/gtest.h>
#include "structure_donnee/My_Array.h"

TEST(MyArrayTest, InsertAndGet) {
    My_Array arr(0);
    EXPECT_EQ(arr.get_count(), 0);
    EXPECT_EQ(arr.get_capacity(), 1);
    arr.insert(42);
    EXPECT_EQ(arr.get_count(), 1);
    EXPECT_EQ(arr.get_capacity(), 1);
    arr.insert(55);
    EXPECT_EQ(arr.get_count(), 2);
    EXPECT_EQ(arr.get_capacity(), 2);
    arr.insert(69);
    EXPECT_EQ(arr.get_count(), 3);
    EXPECT_EQ(arr.get_capacity(), 4);
    EXPECT_EQ(arr.get(0), 42);
    EXPECT_EQ(arr.get(1), 55);
    EXPECT_EQ(arr.get(2), 69);
}

TEST(MyArrayTest, InsertAndGetThrow) {
    My_Array arr(0);
    arr.insert(42);
    arr.insert(55);
    arr.insert(69);
    EXPECT_THROW(arr.get(-1), std::out_of_range);
    EXPECT_THROW(arr.get(3), std::out_of_range);
    EXPECT_THROW(arr.get(47), std::out_of_range);
}

TEST(MyArrayTest, removeAt) {
    My_Array arr(0);
    arr.insert(42);
    arr.insert(55);
    arr.insert(69);
    EXPECT_EQ(arr.get(0), 42);
    EXPECT_EQ(arr.get(1), 55);
    EXPECT_EQ(arr.get(2), 69);

    arr.removeAt(1);
    EXPECT_EQ(arr.get(0), 42);
    EXPECT_EQ(arr.get(1), 69);
    EXPECT_THROW(arr.get(2), std::out_of_range);
}

TEST(MyArrayTest, removeAtThrow) {
    My_Array arr(0);
    arr.insert(42);
    arr.insert(55);
    arr.insert(69);
    EXPECT_EQ(arr.get(0), 42);
    EXPECT_EQ(arr.get(1), 55);
    EXPECT_EQ(arr.get(2), 69);

    EXPECT_THROW(arr.removeAt(-1), std::out_of_range);
    EXPECT_THROW(arr.removeAt(3), std::out_of_range);
    EXPECT_THROW(arr.removeAt(69), std::out_of_range);
}

TEST(MyArrayTest, indexOf) {
    My_Array arr(0);
    arr.insert(42);
    arr.insert(55);
    arr.insert(69);
    EXPECT_EQ(arr.indexOf(42), 0);
    EXPECT_EQ(arr.indexOf(55), 1);
    EXPECT_EQ(arr.indexOf(69), 2);
    EXPECT_EQ(arr.indexOf(22), -1);
}

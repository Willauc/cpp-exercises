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
#include "structure_donnee/array/My_Array.h"

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

TEST(MyArrayTest, max) {
    My_Array arr(0);
    arr.insert(42);
    arr.insert(55);
    arr.insert(69);
    EXPECT_EQ(arr.max(), 69);
    arr.insert(132);
    arr.insert(2);
    EXPECT_EQ(arr.max(), 132);
}

TEST(MyArrayTest, reverse) {
    My_Array arr(0);
    arr.insert(42);
    arr.insert(55);
    arr.insert(69);
    arr.reverse();

    My_Array arr_reversed(0);
    arr_reversed.insert(69);
    arr_reversed.insert(55);
    arr_reversed.insert(42);

    EXPECT_EQ(arr.get(0), arr_reversed.get(0));
    EXPECT_EQ(arr.get(1), arr_reversed.get(1));
    EXPECT_EQ(arr.get(2), arr_reversed.get(2));
}

TEST(MyArrayTest, intersect) {
    My_Array arr(0);
    arr.insert(42);
    arr.insert(55);
    arr.insert(69);

    My_Array arr_2(0);
    arr_2.insert(69);
    arr_2.insert(52);
    arr_2.insert(32);

    My_Array arr_3(arr.intersect(arr_2));
    EXPECT_EQ(arr_3.get(0), 69);
    EXPECT_EQ(arr_3.get_count(), 1);
}

TEST(MyArrayTest, insertAt) {
    My_Array arr(0);
    arr.insert(42);
    arr.insert(55);
    arr.insert(69);

    arr.insertAt(132, 0);
    EXPECT_EQ(arr.get(0), 132);

    arr.insertAt(44, 3);
    EXPECT_EQ(arr.get(3), 44);

    arr.insertAt(44, 4);
    EXPECT_EQ(arr.get(4), 44);
    EXPECT_EQ(arr.get(5), 69);
}

TEST(MyArrayTest, insertAtThrow) {
    My_Array arr(0);
    arr.insert(42);
    arr.insert(55);
    arr.insert(69);

    EXPECT_ANY_THROW(arr.insertAt(123, -1));
    EXPECT_ANY_THROW(arr.insertAt(123, 3));
}

/*
========================================================================
  Fichier     : test_stack.cpp
  Auteur      : William Turbide Auclair
  Date        : 25 juillet 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe link list. Fichier test.

  Version     : 1.0
  ========================================================================
*/
#include <gtest/gtest.h>
#include <structure_donnee/stack/Stack.h>

TEST(StackTest, constructeur) {
EXPECT_NO_THROW(Stack<int> stack);
}

TEST(StackTest, getCountPeekIsEmpty) {
    Stack<int> stack;
    EXPECT_ANY_THROW(stack.peek());
    EXPECT_ANY_THROW(stack.pop());
    EXPECT_EQ(0, stack.getCount());
    EXPECT_TRUE(stack.isEmpty());
    EXPECT_EQ(5, stack.getCapacity());

    stack.push(1);
    EXPECT_EQ(1, stack.getCount());
    EXPECT_FALSE(stack.isEmpty());
    EXPECT_EQ(1, stack.peek());

    stack.push(15);
    EXPECT_EQ(2, stack.getCount());
    EXPECT_FALSE(stack.isEmpty());
    EXPECT_EQ(15, stack.peek());

    stack.push(25);
    EXPECT_EQ(3, stack.getCount());
    EXPECT_EQ(25, stack.peek());

    stack.push(15);
    EXPECT_EQ(4, stack.getCount());
    EXPECT_EQ(15, stack.peek());

    stack.push(95);
    EXPECT_EQ(5, stack.getCount());
    EXPECT_EQ(95, stack.peek());
    EXPECT_EQ(5, stack.getCapacity());

    stack.push(100);
    EXPECT_EQ(6, stack.getCount());
    EXPECT_EQ(100, stack.peek());
    EXPECT_EQ(10, stack.getCapacity());

    EXPECT_EQ(stack.pop(), 100);
    EXPECT_EQ(5, stack.getCount());
    EXPECT_EQ(10, stack.getCapacity());
    EXPECT_EQ(95, stack.peek());

    EXPECT_EQ(stack.pop(), 95);
    EXPECT_EQ(4, stack.getCount());
    EXPECT_EQ(10, stack.getCapacity());
    EXPECT_EQ(15, stack.peek());

    EXPECT_EQ(stack.pop(), 15);
    EXPECT_EQ(3, stack.getCount());
    EXPECT_EQ(10, stack.getCapacity());
    EXPECT_EQ(25, stack.peek());

    EXPECT_EQ(stack.pop(), 25);
    EXPECT_EQ(2, stack.getCount());
    EXPECT_EQ(5, stack.getCapacity());
    EXPECT_EQ(15, stack.peek());

    EXPECT_EQ(stack.pop(), 15);
    EXPECT_EQ(1, stack.getCount());
    EXPECT_EQ(5, stack.getCapacity());
    EXPECT_EQ(1, stack.peek());


}
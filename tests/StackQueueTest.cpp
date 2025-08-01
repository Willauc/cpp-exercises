/*
========================================================================
  Fichier     : StackQueueTest.cpp
  Auteur      : William Turbide Auclair
  Date        : 31 juillet 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est d'implementer un Queue en utilisant deux Stack. Fichier Test.

  Version     : 1.0
  ========================================================================
*/
#include <gtest/gtest.h>
#include "structure_donnee/queue/StackQueue.h"

TEST(StackQueueTest, constructeur) {
EXPECT_NO_THROW(StackQueue<int> queue(5));
    StackQueue<int> queue(5);
    EXPECT_TRUE(queue.isEmpty());
    EXPECT_FALSE(queue.isFull());
}

TEST(StackQueueTest, enqueueDequeue) {
    StackQueue<int> queue(5);
    EXPECT_ANY_THROW(queue.peek());
    queue.enqueue(10);
    EXPECT_EQ(queue.peek(), 10);
    queue.enqueue(20);
    EXPECT_EQ(queue.peek(), 10);
    queue.enqueue(30);
    EXPECT_EQ(queue.peek(), 10);
    queue.enqueue(40);
    EXPECT_EQ(queue.peek(), 10);
    queue.enqueue(50);
    EXPECT_EQ(queue.peek(), 10);
    EXPECT_ANY_THROW(queue.enqueue(60));
    EXPECT_FALSE(queue.isEmpty());
    EXPECT_TRUE(queue.isFull());
    queue.dequeue();
    EXPECT_EQ(queue.peek(), 20);
    queue.dequeue();
    EXPECT_EQ(queue.peek(), 30);
    queue.dequeue();
    EXPECT_EQ(queue.peek(), 40);
    queue.dequeue();
    EXPECT_EQ(queue.peek(), 50);
    queue.dequeue();
    EXPECT_ANY_THROW(queue.peek());
    EXPECT_ANY_THROW(queue.dequeue());
    EXPECT_FALSE(queue.isFull());
    EXPECT_TRUE(queue.isEmpty());
}

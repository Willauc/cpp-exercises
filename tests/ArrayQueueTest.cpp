/*
========================================================================
  Fichier     : ArrayQueueTest.cpp
  Auteur      : William Turbide Auclair
  Date        : 30 juillet 2025
  Description : Test pour la calsse ArrayQueue.
  Version     : 1.0
  ========================================================================
*/

#include <gtest/gtest.h>
#include "structure_donnee/queue/ArrayQueue.h"

TEST(ArrayQueuetest, constructeur) {
    ArrayQueue<int> queue(5);

    EXPECT_TRUE(queue.isEmpty());
    EXPECT_FALSE(queue.isFull());
}

TEST(ArrayQueuetest, enqueueDequeue) {
    ArrayQueue<int> queue(5);
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

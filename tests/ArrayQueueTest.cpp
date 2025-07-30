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
  EXPECT_NO_THROW(ArrayQueue<int> queue(5));
}
/*
========================================================================
  Fichier     : QueueExercise.cpp
  Auteur      : William Turbide Auclair
  Date        : 30 juillet 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de faire des exercises avec les Queue.

  Version     : 1.0
  ========================================================================
*/

#include <queue>
#include <iostream>
#include <stack>

static void reverse(std::queue<int> &queue) {
    std::stack<int> stack;
    while (!queue.empty()) {
        stack.push(queue.front());
        queue.pop();
    }
    while (!stack.empty()) {
        queue.push(stack.top());
        stack.pop();
    }
}

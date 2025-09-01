/*
========================================================================
  Fichier     : StackQueue.h
  Auteur      : William Turbide Auclair
  Date        : 31 juillet 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est d'implementer un Queue en utilisant deux Stack.

  Version     : 1.0
  ========================================================================
*/
#include "structure_donnee/stack/Stack.h"

#ifndef STACKQUEUE_H
#define STACKQUEUE_H

template<typename T>
class StackQueue {
private:
    int m_size;
    Stack<T> stackIn;
    Stack<T> stackOut;
    int m_count = 0;

    void moveToOut() {
        while (!stackIn.isEmpty()) {
            stackOut.push(stackIn.peek());
            stackIn.pop();
        }
    }

    void moveToIn() {
        while (!stackOut.isEmpty()) {
            stackIn.push(stackOut.peek());
            stackOut.pop();
        }
    }

public:
    explicit StackQueue(int size)
        : m_size(size), stackIn(size), stackOut(size) {
    }


    void enqueue(T value) {
        if (isFull()) {
            throw std::length_error("Queue full");
        }
        /*
        if (!stackOut.isEmpty()) {
            moveToIn();
        }*/
        stackIn.push(value);
        m_count++;
    }

    void dequeue() {
        if (isEmpty()) {
            throw std::length_error("Queue Empty");
        }
        if (stackOut.isEmpty()) {
            moveToOut();
        }
        stackOut.pop();
        m_count--;
    }

    const T &peek() {
        if (isEmpty()) {
            throw std::length_error("Queue Empty");
        }
        if (stackOut.isEmpty()) {
            moveToOut();
        }
        return stackOut.peek();
    }

    bool isEmpty() const {
        return m_count == 0;
    }

    bool isFull() const {
        return m_count == m_size;
    }
};
#endif //STACKQUEUE_H

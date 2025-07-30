/*
========================================================================
  Fichier     : ArrayQueue
  Auteur      : William Turbide Auclair
  Date        : 30 juillet 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est d'implementer un Queue en utilisant un Array.

  Version     : 1.0
  ========================================================================
*/

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

template<typename T>
class ArrayQueue {
private:
    int m_size;
    T *m_array;
    int m_start = 0;
    int m_end = 0;

public:
    explicit ArrayQueue(const int size): m_size(size), m_array(new T[size]) {
    }

    ~ArrayQueue() {
        delete[] m_array;
    }

    void enqueue() {
    }

    void dequeue() {
    }

    T peek() const {
    }

    bool isEmpty() const {
    }

    bool isFull() const {
    }
};


#endif //ARRAYQUEUE_H

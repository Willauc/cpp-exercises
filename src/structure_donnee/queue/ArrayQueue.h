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
protected:
    int m_end = 0;
    int m_start = 0;
    T *m_array;
    int m_count = 0;
    int m_size;

public:
    explicit ArrayQueue(const int size): m_size(size), m_array(new T[size]) {
    }

    ~ArrayQueue() {
        delete[] m_array;
    }

    void enqueue(const T &value) {
        if (isFull()) {
            throw std::length_error("Queue full");
        }
        m_array[m_end] = value;
        m_count++;
        m_end = (m_end + 1) % m_size;
    }

    void dequeue() {
        if (isEmpty()) {
            throw std::length_error("Queue Empty");
        }
        m_start = (m_start + 1) % m_size;
        m_count--;
    }

    const T &peek() const {
        if (isEmpty()) {
            throw std::length_error("Queue Empty");
        }
        return m_array[m_start];
    }

    bool isEmpty() const {
        return m_count == 0;
    }

    bool isFull() const {
        return m_count == m_size;
    }
    void print() const {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        int iter = m_start;
        for (int i = 0; i < m_count; ++i) {
            std::cout << m_array[iter] << std::endl;
            iter = (iter + 1) % m_size;
        }
    }
};


#endif //ARRAYQUEUE_H

/*
========================================================================
  Fichier     : PriorityQueue.h
  Auteur      : William Turbide Auclair
  Date        : 01 Aout 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est d'implementer une PriorityQueue.

  Version     : 1.0
  ========================================================================
*/

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "ArrayQueue.h"

class PriorityQueue : public ArrayQueue<int> {
public :
    explicit PriorityQueue(const int size): ArrayQueue(size) {
    }

    void enqueue(const int value) {
        if (isEmpty()) {
            ArrayQueue::enqueue(value);
            return;
        }
        if (isFull()) {
            throw std::length_error("Queue full");
        }

        if (m_count == 1) {
            if(m_array[m_start] > value) {
                m_array[(m_start+1)] = m_array[m_start];
                m_array[m_start] = value;
            }else {
                ArrayQueue::enqueue(value);
                return;
            }
        }else {
            int iter = (m_end - 1) % m_size;

            for (int i = 0; i <= m_count; i++) {
                if (m_array[iter] > value) {
                    m_array[((iter + 1) % m_size)] = m_array[iter];
                    iter = (iter - 1) % m_size;
                } else {
                    m_array[((iter + 1) % m_size)] = value;
                    break;
                }
            }
        }

        m_end = (m_end + 1) % m_size;
        m_count++;
    }
};
#endif //PRIORITYQUEUE_H

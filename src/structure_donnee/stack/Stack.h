/*
========================================================================
  Fichier     : stack.h
  Auteur      : William Turbide Auclair
  Date        : 21 juillet 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe stack a partir d'un array.

  Version     : 1.0
  ========================================================================
*/
#ifndef STACK_H
#define STACK_H

template<typename T>

class Stack {

private:
    int count;
    int m_capacity;
    T *data;

public:
    Stack(int capacity): count(0), m_capacity(capacity) {
        data = new T[m_capacity];
    };

    ~Stack() {
        delete[] data;
    }

    int getCount() const {
        return count;
    }

    bool isEmpty() const {
        return count == 0;
    }

    const T& peek() const {
        if (count == 0) {
            throw std::out_of_range("Stack is empty");
        }
        return data[count - 1];
    }

    T pop() {
        if (count ==0) {
            throw std::out_of_range("Stack is empty");
        }
        T top = data[count - 1];
        count--;
        if (count < m_capacity / 3) {
            if (m_capacity > 5) {
                resize(m_capacity / 2);
            }
        }

        return top;
    }

    void push(T value) {
        if (count == m_capacity) {
            resize(m_capacity * 2);
        }
        data[count++] = value;
    }

    void resize(int newCapacity) {
        m_capacity = newCapacity;
        T *temp = new T[m_capacity];
        for (int i = 0; i < count; i++) {
            temp[i] = data[i];
        }
        delete[] data;

        data = temp;
    }

    int getCapacity() const {
        return m_capacity;
    }
};
#endif //STACK_H

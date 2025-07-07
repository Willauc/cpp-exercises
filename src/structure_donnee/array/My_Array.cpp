/*
========================================================================
  Fichier     : My_Array.cpp
  Auteur      : William Turbide Auclair
  Date        : 30 juin 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe Array qui peut s'agrandir et rétrécir dynamiquement
                grâce à ses méthodes.
  Version     : 1.0
  ========================================================================
*/

#include "My_Array.h"
#include <iostream>

My_Array::My_Array(int capacity) : m_count(0), m_capacity(capacity) {
    if (capacity > 0) {
        m_array = new int[capacity];
    } else {
        m_array = new int[1];
        m_count = 0;
        m_capacity = 1;
    }
}

My_Array::My_Array(const My_Array &other) : m_count(other.get_count()), m_capacity(other.get_capacity()) {
    m_array = new int[m_capacity];
    for (int i = 0; i < other.get_count(); ++i) {
        m_array[i] = other.get(i);
    }
}

My_Array::~My_Array() {
    delete[] m_array;
}

// O(n)
void My_Array::insert(int value) {
    if (m_capacity == m_count) {
        m_capacity *= 2;
        auto *temp = new int[m_capacity];
        for (int i = 0; i < m_count; i++) {
            temp[i] = m_array[i];
        }
        delete[] m_array;
        m_array = temp;
    }

    m_array[m_count++] = value;
}

// O(n)
void My_Array::removeAt(int index) {
    if (index < 0 || index >= m_count) {
        throw std::out_of_range("Index hors tableau.");
    }

    for (int i = index; i < m_count - 1; i++) {
        m_array[i] = m_array[i + 1];
    }
    m_count--;

    if ((m_capacity / 2) > m_count) {
        m_capacity = m_capacity / 2;
        auto *temp = new int[m_capacity];
        for (int i = 0; i < m_count; i++) {
            temp[i] = m_array[i];
        }
        delete[] m_array;
        m_array = temp;
    }
}

// O(1)
int My_Array::get(int index) const {
    if (index < 0 || index >= m_count) {
        throw std::out_of_range("Index hors tableau.");
    }

    return m_array[index];
}

int My_Array::get_capacity() const {
    return m_capacity;
}

int My_Array::get_count() const {
    return m_count;
}

// O(n)
int My_Array::indexOf(int value) const {
    for (int i = 0; i < m_count; i++) {
        if (m_array[i] == value) {
            return i;
        }
    }
    return -1;
}

// O(n)
void My_Array::print() const {
    for (int i = 0; i < m_count; i++) {
        std::cout << m_array[i] << std::endl;
    }
}

// O(n)
int My_Array::max() const {
    int max = m_array[0];
    for (int i = 1; i < m_count; i++) {
        if (m_array[i] > max) {
            max = m_array[i];
        }
    }
    return max;
}

// O(n^2)
My_Array My_Array::intersect(const My_Array &second) const {
    My_Array commun(0);
    for (int i = 0; i < m_count; i++) {
        if (second.indexOf(m_array[i]) != -1) {
            commun.insert(m_array[i]);
        }
    }
    return commun;
}

// O(n)
void My_Array::reverse() {
    auto *temp = new int[m_capacity];
    int index = 0;
    for (int i = m_count - 1; i >= 0; i--) {
        temp[index] = m_array[i];
        index++;
    }
    delete[] m_array;
    m_array = temp;
}

// O(n)
void My_Array::insertAt(int value, int index) {
    if (index < 0 || index > m_count) {
        throw std::out_of_range("Index hors tableau.");
    }
    if (m_count == m_capacity) {
        m_capacity *= 2;
    }
    auto *temp = new int[m_capacity];
    bool value_inserted = false;
    int index2 = 0;

    for (int i = 0; i < m_count; i++) {
        if (i == index && not value_inserted) {
            temp[index2] = value;
            value_inserted = true;
            index2++;
        }

        temp[index2] = m_array[i];
        index2++;
    }

    if (!value_inserted) {
        temp[index2++] = value;
    }
    m_count++;
    delete[] m_array;
    m_array = temp;
}

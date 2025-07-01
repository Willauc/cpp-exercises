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

My_Array::My_Array(int capacity) {
    if (capacity > 0) {
        m_array = new int[capacity];
        m_count = 0;
        m_capacity = capacity;
    } else {
        m_array = new int[1];
        m_count = 0;
        m_capacity = 1;
    }
}

My_Array::~My_Array() {
    delete[] m_array;
}

void My_Array::insert(int value) {
    if (m_capacity == m_count) {
        m_capacity *= 2;
        int *temp = new int[m_capacity];
        for (int i = 0; i < m_count; i++) {
            temp[i] = m_array[i];
        }
        delete[] m_array;
        m_array = temp;
    }

    m_array[m_count++] = value;
}

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
        int *temp = new int[m_capacity];
        for (int i = 0; i < m_count; i++) {
            temp[i] = m_array[i];
        }
        delete[] m_array;
        m_array = temp;
    }
}

int My_Array::get(int index) {
    if (index < 0 || index >= m_count) {
        throw std::out_of_range("Index hors tableau.");
    }

    return m_array[index];
}

int My_Array::get_capacity() {
    return m_capacity;
}

int My_Array::get_count() {
    return m_count;
}

int My_Array::indexOf(int value) {
    for (int i = 0; i < m_count; i++) {
        if (m_array[i] == value) {
            return i;
        }
    }
    return -1;
}

void My_Array::print() {
    for (int i = 0; i < m_count; i++) {
        std::cout << m_array[i] << std::endl;
    }


}

int My_Array::max() {
    return -1;
}

My_Array My_Array::intersect() {
    return My_Array(0);
}

My_Array My_Array::reverse() {
}

void My_Array::insertAt() {
}

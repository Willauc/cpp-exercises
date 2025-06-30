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
    if (capacity >= 0) {
        m_array = new int[capacity];
        m_count = 0;
        m_capacity = capacity;
    } else {
        m_array = new int[0];
        m_count = 0;
        m_capacity = 0;
    }
}

My_Array::~My_Array() {
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
}

int My_Array::indexOf(int value) {
    return -1;
}

void My_Array::print() {
    for (int i = 0; i < m_count; i++) {
        std::cout << m_array[i] << std::endl;
    }
}

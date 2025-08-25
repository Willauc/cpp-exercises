/*
========================================================================
  Fichier     : HashTableLL.cpp
  Auteur      : William Turbide Auclair
  Date        : 6 aout 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe Hash Table untilisant des Link List pour gerer les colisions.

  Version     : 1.0
  ========================================================================
*/

#include "HashTableLL.h"
#include <cmath>


HashTableLL::~HashTableLL() = default;

void HashTableLL::put(int key, const std::string &value) {
    entry to_add(key, value);
    size_t index = key % m_lst.size();
    m_lst[index].addLast(to_add);
}

std::string HashTableLL::get(int key) const {
    size_t index = key % m_lst.size();
    size_t indexInterne = m_lst[index].indexOf(entry(key, ""));

    if (indexInterne == -1) {
        return "";
    }
    for ()


}

void HashTableLL::remove(int key) {
}

bool HashTableLL::is_prime(size_t n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (size_t i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

size_t HashTableLL::next_prime(size_t n) {
    while (!is_prime(n)) {
        ++n;
    }
    return n;
}

/*
========================================================================
  Fichier     : HashTableLL.h
  Auteur      : William Turbide Auclair
  Date        : 6 aout 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe Hash Table untilisant des Link List pour gerer les colisions.

  Version     : 1.0
  ========================================================================
*/

#ifndef HASHTABLELL_H
#define HASHTABLELL_H
#include <string>
#include "../link_list/Link_List.h"
#include <vector>


struct entry {
    int key;
    std::string value;

    entry(int p_key, const std::string &p_value) : key(p_key), value(p_value) {
    }

    bool operator==(const entry &other) const {
        return key == other.key;
    }

    bool operator==(const int other) const {
        return key == other;
    }
};

class HashTableLL {
private:
    std::vector<Link_List<entry> > m_vector;

    static bool is_prime(size_t n);

    static size_t next_prime(size_t n);

    int hash(int key) const;

public:
    HashTableLL(size_t size = 11)
        : m_vector(is_prime(size) ? size : next_prime(size)) {
    }

    ~HashTableLL();

    void put(int key, const std::string &value);

    std::string get(int key) const;

    void remove(int key);

    size_t getSize() const;
};


#endif //HASHTABLELL_H

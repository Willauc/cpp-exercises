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

struct entry {
    int key;
    std::string value;

    entry(int p_key, const std::string &p_value) : key(p_key), value(p_value) {

    }
};

class HashTableLL {

};



#endif //HASHTABLELL_H

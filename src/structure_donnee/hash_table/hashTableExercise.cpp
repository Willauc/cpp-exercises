/*
========================================================================
  Fichier     : exercise.cpp
  Auteur      : William Turbide Auclair
  Date        : 05 Aout 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Exercise impliquand une hash table

  Version     : 1.0
  ========================================================================
*/

#include "hashTableExercise.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <stdexcept>
/*
 *fonction qui trouve le premier caractére non répéter
 */
char hashTableExercise::noRepCar(const std::string &sentence) {
    std::unordered_map<char, int> freq;
    for (char c: sentence) {
        ++freq[c];
    }
    for (auto c: sentence) {
        if (freq[c] == 1) {
            return c;
        }
    }
    throw std::invalid_argument("Aucun caractère non répété trouvé.");
}

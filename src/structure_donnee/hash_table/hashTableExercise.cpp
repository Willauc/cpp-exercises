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


/*
 *fonction qui trouve le premier caractére non répéter
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <stdexcept>

char hashTableExercise::noRepCar(const std::string &sentence) {
    std::unordered_map<char, int> map;
    for (auto charactere: sentence) {
        if (map.find(charactere) != map.end()) {
            map[charactere] = ++map[charactere];
        } else {
            map[charactere] = 1;
        }
    }
    for (auto charactere: sentence) {
        if (map[charactere] == 1) {
            return charactere;
        }
    }
    throw std::invalid_argument("Mauvais argument");
}

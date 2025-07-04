/*
========================================================================
  Fichier     : main.cpp
  Auteur      : William Turbide Auclair
  Date        : 29 juin 2025
  Description : Fichier main.cpp pour tester les exercises.
  Version     : 1.0
  ========================================================================
*/
#include <iostream>
#include <vector>

#include "src/affichage_matrice.h"

int main() {
    std::vector<std::vector<std::string>> vector = {
        {"1", "2", "3", "4"},
        {"x", "y", "z"},
        {"9", "8", "7", "6"}
    };

    affichage_matrice_v2(vector);


    return 0;
}

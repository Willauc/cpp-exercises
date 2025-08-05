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
#include "src/structure_donnee/link_list/Link_List.h"
#include "src/affichage_matrice.h"
#include "src/structure_donnee/stack/Expression.h"
#include <queue>
#include "src/structure_donnee/queue/QueueExercise.cpp"
#include "src/structure_donnee/hash_table/hashTableExercise.h"
int main() {
    /*
    std::vector<std::vector<std::string>> vector = {
        {"1", "2", "3", "4"},
        {"x", "y", "z",},
        {"9", "8", "7", "6"}
    };

    affichage_matrice_v3(vector);
*/
std::string sentense = "a green apple";

    char result = hashTableExercise::noRepCar(sentense);

    std::cout<< result;


    return 0;
}

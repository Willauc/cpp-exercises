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
#include "src/structure_donnee/tree/Tree.h"
int main() {
    /*
    std::vector<std::vector<std::string>> vector = {
        {"1", "2", "3", "4"},
        {"x", "y", "z",},
        {"9", "8", "7", "6"}
    };

    affichage_matrice_v3(vector);
*/

Tree tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(6);
    tree.insert(8);
    tree.insert(7);
    tree.printTree();
    std::cout<<tree.find(6)<<std::endl;
    std::cout<<tree.find(1)<<std::endl;



    return 0;
}

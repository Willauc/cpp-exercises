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
int main() {
    /*
    std::vector<std::vector<std::string>> vector = {
        {"1", "2", "3", "4"},
        {"x", "y", "z",},
        {"9", "8", "7", "6"}
    };

    affichage_matrice_v3(vector);
*/
std::queue<int> queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);

    while (!queue.empty()) {
        std::cout << queue.front() << " ";
        queue.pop();
    }
    std::cout<<std::endl;
    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);

    reverse(queue);

    while (!queue.empty()) {
        std::cout << queue.front() << " ";
        queue.pop();
    }



    return 0;
}

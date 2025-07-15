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
#include <stack>

int main() {
    /*
    std::vector<std::vector<std::string>> vector = {
        {"1", "2", "3", "4"},
        {"x", "y", "z",},
        {"9", "8", "7", "6"}
    };

    affichage_matrice_v3(vector);
*/

    std::string line = "abcde";
    std::stack<char> stack;
    std::string newLine;

    for (auto car : line) {
        stack.push(car);
    }
    while (!stack.empty()) {
        newLine += stack.top();
        stack.pop();

    }

    std::cout << newLine << std::endl;


    return 0;
}

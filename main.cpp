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
#include <string>
#include "src/structure_donnee/link_list/Link_List.h"
#include "src/affichage_matrice.h"
#include "src/structure_donnee/stack/Expression.h"
#include <queue>
#include "src/structure_donnee/queue/QueueExercise.cpp"
#include "src/structure_donnee/hash_table/hashTableExercise.h"
#include "src/structure_donnee/tree/Tree.h"
#include "src/structure_donnee/tree/AVLTree.h"
#include "src/leetCode/stringProbleme.h"

using namespace std;
int main() {
    string word1 = "ABABABAB";
    string word2 = "ABAB";

    auto str = new stringProbleme();

    string newWord = str->gcdOfStrings(word1, word2);

    cout << newWord << endl;


    return 0;
}

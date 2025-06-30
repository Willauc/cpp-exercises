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
#include "src/structure_donnee/My_Array.h"

int main() {
    My_Array array(0);
    array.insert(10);
    array.insert(20);
    array.print();
    return 0;
}

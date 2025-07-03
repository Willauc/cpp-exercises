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
#include "src/structure_donnee/array/My_Array.h"

int main() {
    My_Array array(0);
    array.insert(10);
    array.insert(20);
    array.insert(30);
    array.insert(40);
    array.insert(50);

    My_Array second(0);
    second.insert(10);

    My_Array commun(array.intersect(second));
    commun.print();
    return 0;
}

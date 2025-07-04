/*
========================================================================
  Fichier     : affichage_matrice.h
  Auteur      : William Turbide Auclair
  Date        : 4 juillet 2025
  Description : Affiche toute les possibilité d'une matrice dans la console.
  Version     : 1.0
  ========================================================================
*/

#ifndef AFFICHAGE_MATRICE_H
#define AFFICHAGE_MATRICE_H

void affichage_matrice();

void affichage_matrice_v2(const std::vector<std::vector<std::string>>& vector);

void affichage_matrice_v3(const std::vector<std::vector<std::string> > &vector);

void prt_str_rec(std::string& val,int rangerInt,int  compteInt, const std::vector<std::vector<std::string> > &vectorInt);

#endif //AFFICHAGE_MATRICE_H

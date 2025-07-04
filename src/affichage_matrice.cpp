/*
========================================================================
  Fichier     : affichage_matrice.cpp
  Auteur      : William Turbide Auclair
  Date        : 4 juillet 2025
  Description : Affiche toute les possibilité d'une matrice dans la console.
  Version     : 1.0
  ========================================================================
*/

#include <iostream>
#include <vector>
#include <map>

void affichage_matrice() {
    const int ranger = 3;
    const int colonne = 4;
    std::string matrice[ranger][colonne] = {
        {"1", "2", "3", "4"},
        {"x", "y", "z"},
        {"9", "8", "7", "6"}
    };

    std::string str;
    for (auto i = 0; i < colonne; i++) {
        str.append(matrice[0][i]);
        for (auto u = 0; u < colonne; u++) {
            if (not matrice[1][u].empty()) {
                str.append(matrice[1][u]);
            }
            for (auto j = 0; j < colonne; j++) {
                if (not matrice[2][j].empty()) {
                    str.append(matrice[2][j]);
                }
                std::cout << str << std::endl;
                str.pop_back();
            }
            str.pop_back();
        }
        str.clear();
    }
}

void affichage_matrice_v2(const std::vector<std::vector<std::string> > &vector) {
    const int ranger = vector.size();
    //const int colonne = 4;

    std::string str;
    std::string str_fin = vector[0].back();
    str_fin.append(vector[ranger - 1].back());

    std::map<int, int> map_fin;
    for (auto m = 0; m < ranger; m++) {
        map_fin[m] = (vector[m].size() - 1);
    }
    std::map<int, int> map;
    for (auto m = 0; m < ranger; m++) {
        map[m] = 0;
    }


    while (not map.empty()) {
        for (auto i = 0; i < ranger; i++) {
            if (map[i] <= map_fin[i]) {
                str.append(vector[i][map[i]]);
            }
        }
        std::cout << str << std::endl;
        if (str == str_fin) {
            break;
        }
        str.clear();


        for (auto u = ranger; u >= 0; u--) {
            if (map[u] == map_fin[u]) {
                map[u] = 0;
                map[u - 1] += 1;
            } else if (map[u + 1] != map_fin[u + 1]) {
                map[u] += 1;
            }
        }
    }
}

void prt_str_rec(std::string &val, const int rangerInt, const int compteInt, const
                 std::vector<std::vector<std::string> > &vectorInt) {
    for (auto j = 0; j <= vectorInt[compteInt].size(); j++) {
        int val_initial = val.size();
        if (j < vectorInt[compteInt].size()) {
            val.append(vectorInt[compteInt][j]);
        }
        if (compteInt == rangerInt - 1) {
            if(val.size() == rangerInt) {
                std::cout << val << std::endl;
            }
        } else  {
            prt_str_rec(val, rangerInt, compteInt + 1, vectorInt);
        }
        val.resize(val_initial);
    }
}

void affichage_matrice_v3(const std::vector<std::vector<std::string> > &vector) {
    const int ranger = vector.size();


    std::string str;
    prt_str_rec(str, ranger, 0, vector);
}

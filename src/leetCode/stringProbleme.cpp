//
// Created by william on 25/11/2025.
//

#include "stringProbleme.h"

string stringProbleme::mergeAlternately(string word1, string word2) {
    string wordMerged;

    while (!word1.empty() || !word2.empty()) {
        if (!word1.empty()){
            wordMerged.push_back(word1[0]);
            word1.erase(0,1 );
        }

        if (!word2.empty()){
            wordMerged.push_back(word2[0]);
            word2.erase(0, 1);
        }
    }
    return wordMerged;
}
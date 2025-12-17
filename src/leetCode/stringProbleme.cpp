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

string stringProbleme::mergeAlternatelyBest(string word1, string word2) {
        std::string merged;
        int maxLength = std::max(word1.length(), word2.length());

        for (int i = 0; i < maxLength; i++) {
            if (i < word1.length()) {
                merged += word1[i];
            }

            if (i < word2.length()) {
                merged += word2[i];
            }
        }

        return merged;
    }

string stringProbleme::gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1)
        return "";

    int a = str1.size();
    int b = str2.size();
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return str1.substr(0, a);
}
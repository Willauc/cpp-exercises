/*
========================================================================
  Fichier     : Expression.cpp
  Auteur      : William Turbide Auclair
  Date        : 21 juillet 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe qui vérifie si une expression est balancer.

  Version     : 1.0
  ========================================================================
*/

#include "Expression.h"
#include <stack>
#include <algorithm>

bool Expression::balanceStr(const std::string &input) const {
    std::stack<char> stack;

    for (char letter: input) {
        if (isOpen(letter)) {
            stack.push(letter);
        } else if (isClose(letter)) {
            if (stack.empty()) return false;
            if (match(stack.top(), letter)) {
                stack.pop();
            } else return false;
        }
    }

    if (stack.empty()) {
        return true;
    }
    return false;
}


bool Expression::isOpen(char ch) const {
    return std::find(open.begin(), open.end(), ch) != open.end();
}

bool Expression::isClose(char ch) const {
    return std::find(close.begin(), close.end(), ch) != close.end();
}

int Expression::indexOf(char value, const std::array<char, 4>& array) const {
    int index = 0;
    for (char car: array ) {
        if (value == car) {
            return index;
        }
        index++;
    }
    return -1;
}

bool Expression::match(char premier, char second) const {
    return indexOf(premier,open)  == indexOf(second,close);
}



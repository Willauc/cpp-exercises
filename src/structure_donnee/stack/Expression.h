/*
========================================================================
  Fichier     : Expression.h
  Auteur      : William Turbide Auclair
  Date        : 21 juillet 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe qui vérifie si une expression est balancer.

  Version     : 1.0
  ========================================================================
*/

#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include <array>


class Expression {
private:
    const std::array<char, 4> open = {'(', '[', '{', '<'};
    const std::array<char, 4> close = {')', ']', '}', '>'};



    public:
    bool balanceStr(const std::string& expression) const;
    bool isOpen(char ch) const;
    bool isClose(char ch) const;
    bool match(char premier, char second) const;
    int indexOf(char value, const std::array<char, 4>& array) const;

};



#endif //EXPRESSION_H

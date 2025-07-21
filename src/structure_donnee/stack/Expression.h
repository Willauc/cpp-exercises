//
// Created by william on 21/07/25.
//

#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include <array>


class Expression {
private:
    std::array<char, 4> open = {'(', '[', '{', '<'};
    std::array<char, 4> close = {')', ']', '}', '>'};



    public:
    const bool balanceStr(const std::string& expression);
    const bool isOpen(char ch);

};



#endif //EXPRESSION_H

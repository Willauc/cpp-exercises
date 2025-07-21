//
// Created by william on 21/07/25.
//

#include "Expression.h"

#include <fcntl.h>
#include <stack>

bool balanceStr(const std::string& input) {
    std::stack<char> stack;

    for (char letter: input) {
        if (letter == '(' || letter == '[' || letter == '{') {
            stack.push(letter);
        } else if (letter == ')') {
            if (stack.top() == '(') {
                stack.pop();
            } else return false;
        } else if (letter == ']') {
            if (stack.top() == '[') {
                stack.pop();
            } else return false;
        } else if (letter == '}') {
            if (stack.top() == '{') {
                stack.pop();
            } else return false;
        }
    }
    if (stack.empty()) {
        return true;
    }
    return false;
}

bool Expression::isOpen(const std::string& ch) {
    return open
}



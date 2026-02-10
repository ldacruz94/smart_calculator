
#pragma once

#include <vector>
#include <string>

class Parser {

public:
    explicit Parser();
    int Prec(char op);
    std::vector<std::string> ToRPN(const std::string& expression);
    double EvaluateRPN(const std::vector<std::string>& rpn);
};
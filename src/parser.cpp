#include "parser.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#include <string>

Parser::Parser() {}

int Parser::Prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == 'x' || op == '/') return 2;
    return 0; 
}

std::vector<std::string> Parser::ToRPN(const std::string& expression) {
    std::stack<char> operators;
    std::vector<std::string> output;
    std::string number;

    auto flush_number = [&]() {
        if (!number.empty()) {
            output.push_back(number);
            number.clear();
        }
    };

    for (char c : expression) {

        if (std::isspace(static_cast<unsigned char>(c))) {
            continue;
        }
        if (std::isdigit(static_cast<unsigned char>(c))) {
            number += c;
        }
        else if (c == '(') {
            flush_number();
            operators.push(c);
        }
        else if (c == ')') {
            flush_number();
             while (!operators.empty() && operators.top() != '(') {
                output.push_back(std::string(1, operators.top()));
                operators.pop();
            }
            if (operators.empty()) {
                throw std::runtime_error("Missing open parantheses: (");
            }
            operators.pop();
        }

        else if (std::strchr("+-*x/", c)) {
            flush_number();

            while (!operators.empty() && operators.top() != '(' && Prec(operators.top()) >= Prec(c)) {
                output.push_back(std::string(1, operators.top()));
                operators.pop();
            }
            operators.push(c);
        }
    }

    flush_number();

    while (!operators.empty()) {
        output.push_back(std::string(1, operators.top()));
        operators.pop();
    }

    return output;
}

double Parser::EvaluateRPN(const std::vector<std::string>& rpn) {
    std::stack<double> values;
    
    for (const auto& token : rpn) {
        if (!token.empty() && std::isdigit(static_cast<unsigned char>(token[0]))) {
            values.push(std::stod(token));
        } 
        else {
            double b = values.top(); values.pop();
            double a = values.top(); values.pop(); 

            double result = 0.0;
            
            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case 'x': case '*': result = a * b; break;
                case '/': result = a / b; break;
                default: throw std::runtime_error("Uknown operator");
            }

            values.push(result);
        }
    }

    return values.top();
}

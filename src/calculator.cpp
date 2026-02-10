

#include <iostream>
#include <string>
#include "parser.hpp"


int main() {
    bool prompt = true;

    while (prompt) {
        std::cout << "Enter your math expression (or 'exit' to quit): ";
        std::string expression;

        std::getline(std::cin, expression);

        if (expression == "exit") {
            prompt = false;
        }

        Parser parser;
        std::vector<std::string> rpn = parser.ToRPN(expression);
        double result = parser.EvaluateRPN(rpn);
        std::cout << "Result: " << result << std::endl; 
    }
}

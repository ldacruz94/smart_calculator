#include <iostream>
#include <string>
#include <vector>

#include "calculator.hpp"
#include "parser.hpp"

static void PrintHelp() {
    std::cout
        << "\nCommands:\n"
        << "  help            Show this help\n"
        << "  exit | quit     Exit the calculator\n"
        << "\nMemory:\n"
        << "  M+ <number>     Add number to memory\n"
        << "  M- <number>     Subtract number from memory\n"
        << "  MR              Recall memory (prints it)\n"
        << "  MC              Clear memory\n"
        << "\nExamples:\n"
        << "  (3 + 5) * 2\n"
        << "  M+ 10\n"
        << "  MR\n\n";
}

static std::string Trim(std::string s) {
    const auto start = s.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    const auto end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

int main() {
    Calculator calculator;
    Parser parser;

    PrintHelp();
    std::cout << "Smart Calculator (type 'help' for commands, 'exit' to quit)\n";

    while (true) {
        std::cout << "\n> ";
        std::string input;
        if (!std::getline(std::cin, input)) {
            std::cout << "\nGoodbye.\n";
            break;
        }

        input = Trim(input);
        if (input.empty()) continue;

        if (input == "exit" || input == "quit") {
            std::cout << "Goodbye.\n";
            break;
        }

        if (input == "help") {
            PrintHelp();
            continue;
        }

        if (input == "MR") {
            std::cout << "Memory: " << calculator.MReturn() << "\n";
            continue;
        }

        if (input == "MC") {
            calculator.MClear();
            std::cout << "Memory cleared.\n";
            continue;
        }

        if (input.rfind("M+ ", 0) == 0 || input.rfind("M- ", 0) == 0) {
            const bool isAdd = input.rfind("M+ ", 0) == 0;
            const std::string numStr = Trim(input.substr(3));

            try {
                const double x = std::stod(numStr);
                if (isAdd) {
                    calculator.MPlus(x);
                    std::cout << "Added to memory. Memory: " << calculator.MReturn() << "\n";
                } else {
                    calculator.MMinus(x);
                    std::cout << "Subtracted from memory. Memory: " << calculator.MReturn() << "\n";
                }
            } catch (...) {
                std::cout << "Invalid number. Example: M+ 10  or  M- 2.5\n";
            }
            continue;
        }

        try {
            std::vector<std::string> rpn = parser.ToRPN(input);
            double result = parser.EvaluateRPN(rpn);
            std::cout << "Result: " << result << "\n";
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        } catch (...) {
            std::cout << "Error: invalid expression.\n";
        }
    }

    return 0;
}

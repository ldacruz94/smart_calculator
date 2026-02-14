
#include "history.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

HistoryHandler::HistoryHandler() {}

int HistoryHandler::SaveToHistory(std::string comm) {
    std::ofstream file(file_name, std::ios::app);

    if (!file) {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    file << comm << "\n";

    file.close();
    return 0;
}

int HistoryHandler::DisplayHistory() {
    std::ifstream file(file_name);

    if (!file) {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string contents = buffer.str();

    std::cout << contents;
    return 0;
}
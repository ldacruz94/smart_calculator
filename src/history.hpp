#pragma once

#include <string>

class HistoryHandler {

private:
    std::string const file_name = "calc_history.txt";

public:
    HistoryHandler();
    int SaveToHistory(std::string comm);
    int DisplayHistory();
};
#pragma once

class Calculator {
private:
    double memory = 0;

public:
    explicit Calculator();
    void MPlus(double x);
    void MMinus(double x);
    double MReturn();
    void MClear();
};

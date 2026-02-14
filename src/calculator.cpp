#pragma once

#include "calculator.hpp"

Calculator::Calculator(){}

void Calculator::MPlus(double x) { 
    memory += x; 
}

void Calculator::MMinus(double x) { 
    memory -= x; 
}

double Calculator::MReturn() { 
    return memory; 
}

void Calculator::MClear() {
    memory = 0;
}

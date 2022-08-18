#pragma once

const double allowance = 1e-9; //delta neighborhood size

typedef struct{
    double solutions[2];
    int numofSolutions;
} answEquation;

enum exitStatus{
    ERROR_IN_DEFINITION = -2,
    INFINITE_NUMOF_SOLUTIONS = -1,
    NO_SOLUTIONS = 0,
    ONE_SOLUTION = 1,
    TWO_SOLUTIONS = 2
};

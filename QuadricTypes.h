/// \file

#ifndef QUADRICTYPES_H
#define QUADRICTYPES_H

const double ALLOWANCE = 1e-15; ///< delta neighborhood size

/// the description of the answ struct
typedef struct {
    double solutions[2];///< array of solutions
    int numofSolutions;///< number of solutions
} answEquation;

/// const exit status - number of solutions of the equation
enum exitStatus {
    ERROR_IN_DEFINITION = -2,
    INFINITE_NUMOF_SOLUTIONS = -1,
    NO_SOLUTIONS = 0,
    ONE_SOLUTION = 1,
    TWO_SOLUTIONS = 2
};

#endif  // QuadraicTypes.h

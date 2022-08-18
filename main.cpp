#define _CRT_SECURE_NO_WARNINGS

#include "QuadricSolver.h"

int main (void) {
    double a = 0;
    double b = 0;
    double c = 0;

    answEquation answ = {0};

    inputEq(&a, &b, &c);
    solveEq(a, b, c, &answ);
    outputEq(&answ);
    return 0;
}

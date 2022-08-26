//#define _CRT_SECURE_NO_WARNINGS

/// \file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "QuadricTest.h"
#include "QuadricSolver.h"

int main (int argc, char* argv[]) {
    
#ifdef debugMode

    testEq();
    testEqQuad();
    testEqLin();

#else

    double a = NAN;
    double b = NAN;
    double c = NAN;

    answEquation answ = {0};

    inputEq(&a, &b, &c);
    solveEq(a, b, c, &answ);
    outputEq(&answ);

#endif// DebugMode

    return 0;
}

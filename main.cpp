//#define _CRT_SECURE_NO_WARNINGS

/// \file

//#define DebugMode

#ifdef DebugMode
    #include "QuadricTest.h"
#endif

#include "QuadricSolver.h"
#include <math.h>

int main (void) {
    double a = NAN;
    double b = NAN;
    double c = NAN;

    answEquation answ = {0};
    #ifdef DebugMode
        testEq();
    #else
        inputEq(&a, &b, &c);
        solveEq(a, b, c, &answ);
        outputEq(&answ);
    #endif
    return 0;
}

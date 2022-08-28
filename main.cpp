//#define _CRT_SECURE_NO_WARNINGS

/// \file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "QuadricTest.h"
#include "QuadricSolver.h"
#include "arg.h"

bool isUnColored = false;
bool isLog       = false;
bool isHelp      = false;
bool isDebug     = false;

int main (int argc, char* argv[]) {

    check_args(argc, argv);
    if (isHelp) {
        Help();
        return 0;
    }


    if (isDebug) {
        testEq(!isUnColored, isLog);
        testEqQuad(!isUnColored, isLog);
        testEqLin(!isUnColored, isLog);

        return 0;
    }

    double a = NAN;
    double b = NAN;
    double c = NAN;

    answEquation answ = {0};

    inputEq(&a, &b, &c);
    solveEq(a, b, c, &answ, isLog);
    outputEq(&answ, isLog);

    return 0;
}

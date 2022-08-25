/// \file

#include "QuadricSolver.h"

#include <math.h>
#include <assert.h>

void inputEq (double* const a, double* const b, double* const c) {
    assert(a != NULL && b != NULL && c != NULL && "All pointers mustn't be NULL");

    printf("Enter the polynomial in the form ax^2 + bx + c = 0\n");
    scanf("%lf%lf%lf", a, b, c);
}

void outputEq (answEquation* const answ) {
    assert(answ != NULL && "All pointers mustn't be NULL");

    int answer = answ->numofSolutions;

    switch (answer) {
        case ERROR_IN_DEFINITION:
             printf("error in definition\n");
             break;
        case INFINITE_NUMOF_SOLUTIONS:
            printf("infinite number of solutions\n");
            break;
        case NO_SOLUTIONS:
            printf("equation have %d solution.", answer);
            break;
        default:
            printf("equation have %d solution:", answer);
            for (int i = 0; i < answer; i++) {
                printf("\t%lg", answ->solutions[i]);
            }
    }
}

bool isEqual (const double a, const double b) {
    assert(isfinite(a)  && isfinite(b) && "All coficient mustn't be NaN");

    return fabs(a - b) < ALLOWANCE;
}

double getDisc (const double a, const double b, const double c) {
    assert(isfinite(a)  && isfinite(b) && isfinite(c) && "All coficient mustn't be NaN");

    return b * b - 4 * a * c;
}

void solveEq (const double a, const double b, const double c, answEquation* const answ) {
    assert(isfinite(a)  && isfinite(b) && isfinite(c) && "All coficient mustn't be NaN");

    assert(answ != NULL && "All pointers mustn't be NULL");

    if (isEqual(a, 0)) {
        solveEqLin(b, c, answ);
        return;
    }

    solveEqQuad(a, b, c, answ);
}

void solveEqLin (const double b, const double c, answEquation* const answ) {
    assert(isfinite(b) && isfinite(c) && "All coficient mustn't be NaN");

    assert(answ != NULL && "All pointers mustn't be NULL");

    if (isEqual(b, 0)) {
        if (!isEqual(c, 0)) {
            answ->numofSolutions = NO_SOLUTIONS;
            return;
        }

        answ->numofSolutions = INFINITE_NUMOF_SOLUTIONS;
        return;
    }

    answ->solutions[0] = - c / b;
    answ->numofSolutions = ONE_SOLUTION;
}

void solveEqQuad (const double a, const double b, const double c, answEquation* const answ) {
    assert(isfinite(a) && isfinite(b) && isfinite(c) && "All coficient mustn't be NaN");

    assert(answ != NULL && "All pointers mustn't be NULL");

    double Disc = 0;//discriminant
    Disc = getDisc(a, b, c);

    double twoa = 2 * a;

    if (isEqual(Disc, 0)) {
        answ->solutions[0] = - b / twoa;
        answ->numofSolutions = ONE_SOLUTION;
        return;
    }

    if (Disc < 0) {
        answ->numofSolutions = NO_SOLUTIONS;
        return;
    }

    Disc = sqrt(Disc);

    answ->solutions[0] = -(b + Disc) / twoa;
    answ->solutions[1] = -(b - Disc) / twoa;
    answ->numofSolutions = TWO_SOLUTIONS;
}
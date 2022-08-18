#include "QuadricSolver.h"

void inputEq (double* a, double* b, double* c) {
    printf("Enter the polynomial in the form ax^2 + bx + c = 0\n");
    scanf("%lg%lg%lg", a, b, c);
}

void outputEq (answEquation* answ) {
    assert(answ != NULL && "All pointers mustn't be NULL");

    int answer = answ->numofSolutions;

    if (answer == ERROR_IN_DEFINITION) {
        printf("error in definition\n");
        return;
    }

    if (answer == INFINITE_NUMOF_SOLUTIONS) {
        printf("infinite number of solutions\n");
        return;
    }

    printf("equation have %d solution", answer);

    if (answer == NO_SOLUTIONS) {
        printf(".");
    } else {
        printf(":");
    }

    for (int i = 0; i < answer; i++) {
        printf("\t%lg", answ->solutions[i]);
    }
}

bool isEqual(double a, double b) {
    assert(isnan(a)  && isnan(b) && "All coficient mustn't be NaN");

    return abs(a - b) < allowance;
}

double getDisc (double a, double b, double c) {
    assert(isnan(a)  && isnan(b) && isnan(c) && "All coficient mustn't be NaN");

    return b * b - 4 * a * c;
}

void solveEq (double a, double b, double c, answEquation* answ) {
    assert(isnan(a)  && isnan(b) && isnan(c) && "All coficient mustn't be NaN");

    assert(answ != NULL && "All pointers mustn't be NULL");

    if (isEqual(a, 0)) {
        solveEqLin(b, c, answ);
        return;
    }

    solveEqQuad(a, b, c, answ);
}

void solveEqLin (double b, double c, answEquation* answ) {
    assert(isnan(b) && isnan(c) && "All coficient mustn't be NaN");

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

void solveEqQuad (double a, double b, double c, answEquation* answ) {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(b));

    assert(answ != NULL);

    double D = 0;//discriminant
    D = getDisc(a, b, c);

    if (isEqual(D, 0)) {
        answ->solutions[0] = - b / (2 * a);
        answ->numofSolutions = ONE_SOLUTION;
        return;
    }

    if (D < 0) {
        answ->numofSolutions = NO_SOLUTIONS;
        return;
    }

    answ->solutions[0] = -(b + sqrt(D)) / (2 * a);
    answ->solutions[1] = -(b - sqrt(D)) / (2 * a);
    answ->numofSolutions = TWO_SOLUTIONS;
}

#include "QuadricTest.h"

#include "QuadricTypes.h"
#include "QuadricSolver.h"

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

const char filename[] = "test.txt";

static bool isAnswEqual(answEquation answ1, answEquation answ2){
    if (answ1.numofSolutions != answ2.numofSolutions) {
        return false;
    }
    switch (answ1.numofSolutions) {
        case 0:
            return true;
            break;
        case 1:
            return isEqual(answ1.solutions[0], answ2.solutions[0]);
            break;
        case 2:
            bool out1 = true;
            bool out2 = true;
            out1 = (isEqual(answ1.solutions[0], answ2.solutions[0]) && isEqual(answ1.solutions[1], answ2.solutions[1]));
            out2 = (isEqual(answ1.solutions[0], answ2.solutions[1]) && isEqual(answ1.solutions[1], answ2.solutions[0]));
            return out1 || out2;
    }
}

void testEq (void) {
    FILE* testFile = NULL;
    testFile = fopen(filename, "r");
    assert(testFile != NULL && "There is no test file");

    int testNum = 0;
    int testWA = 0;

    double a = 0;
    double b = 0;
    double c = 0;

    answEquation answ = {0};
    answEquation answTest = {0};

    while (fscanf(testFile, "%lf %lf %lf", &a, &b, &c) != EOF) {
        fscanf(testFile, "%d", &answTest.numofSolutions);

        solveEq(a, b, c, &answ);
        answ.numofSolutions = (answ.numofSolutions < 0) ? 0 : answ.numofSolutions;

        for (int i = 0; i < answTest.numofSolutions; i++){
            fscanf(testFile, "%lf", &answTest.solutions[i]);
        }

        if (!isAnswEqual(answ, answTest)){
            testWA++;
        }

        testNum++;
    }
    fclose(testFile);

    printf("Wrong tests: %d, total: %d\n", testWA, testNum);
}


#include "QuadricTest.h"

#include "QuadricTypes.h"
#include "QuadricSolver.h"
#include "printfColored.h"

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define defaultColor setColor(WHITE)

const char filenameEq[]     = "testEq.txt";
const char filenameEqLin[]  = "testEqLin.txt";
const char filenameEqQuad[] = "testEqQuad.txt";

const char BLACK[]  = "\x1b[30m";
const char RED[]    = "\x1b[31m";
const char GREEN[]  = "\x1b[32m";
const char YELLOW[] = "\x1b[33m";
const char BLUE[]   = "\x1b[34m";
const char WHITE[]  = "\x1b[37m";

static bool isAnswEqual (const answEquation answ1, const answEquation answ2) {
    if (answ1.numofSolutions != answ2.numofSolutions) {
        return false;
    }
    switch (answ1.numofSolutions) {
        case -1:
            return true;
            break;
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
    return false;
}

void testEq (bool iscol, bool isLog) {
    printf("testing %s\n", __func__);

    FILE* testFile = NULL;
    testFile = fopen(filenameEq, "r");
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

        solveEq(a, b, c, &answ, isLog);

        for (int i = 0; i < answTest.numofSolutions; i++){
            fscanf(testFile, "%lf", &answTest.solutions[i]);
        }

        if (!isAnswEqual(answ, answTest)){
            if (iscol)
                setColor(RED);

            printf("Err in test: %d\n", testNum);
            
            printf("\tIn answer %d solutions:", answ.numofSolutions);
            for (int i = 0; i < answ.numofSolutions; i++) {
                printf("\t%lg", answ.solutions[i]);
            }

            printf("\n");

            printf("\tIn real %d solutions:", answTest.numofSolutions);
            for (int i = 0; i < answTest.numofSolutions; i++) {
                printf("\t%lg", answTest.solutions[i]);
            }
            
            printf("\n");
            testWA++;
        } 
        defaultColor;

        testNum++;
    }
    fclose(testFile);

    printf("\n\nWrong tests: %d, total: %d\n", testWA, testNum);
}

void testEqQuad (bool iscol, bool isLog) {
    printf("testing %s\n", __func__);

    FILE* testFile = NULL;
    testFile = fopen(filenameEqQuad, "r");
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

        solveEqQuad(a, b, c, &answ, isLog);

        for (int i = 0; i < answTest.numofSolutions; i++){
            fscanf(testFile, "%lf", &answTest.solutions[i]);
        }

        if (!isAnswEqual(answ, answTest)){
            if (iscol)
                setColor(RED);
            
            printf("Err in test: %d\n", testNum);
            
            printf("\tIn answer %d solutions:", answ.numofSolutions);
            for (int i = 0; i < answ.numofSolutions; i++) {
                printf("\t%lg", answ.solutions[i]);
            }

            printf("\n");

            printf("\tIn real %d solutions:", answTest.numofSolutions);
            for (int i = 0; i < answTest.numofSolutions; i++) {
                printf("\t%lg", answTest.solutions[i]);
            }
            
            printf("\n");
            testWA++;
        } 

        defaultColor;

        testNum++;
    }
    fclose(testFile);

    printf("\n\nWrong tests: %d, total: %d\n", testWA, testNum);
}

void testEqLin (bool iscol, bool isLog) {
    printf("testing %s\n", __func__);

    FILE* testFile = NULL;
    testFile = fopen(filenameEqLin, "r");
    assert(testFile != NULL && "There is no test file");

    int testNum = 0;
    int testWA = 0;

    double a = 0;
    double b = 0;

    answEquation answ = {0};
    answEquation answTest = {0};

    while (fscanf(testFile, "%lf %lf", &a, &b) != EOF) {
        fscanf(testFile, "%d", &answTest.numofSolutions);

        solveEqLin(a, b, &answ, isLog);

        for (int i = 0; i < answTest.numofSolutions; i++){
            fscanf(testFile, "%lf", &answTest.solutions[i]);
        }

        if (!isAnswEqual(answ, answTest)){
            if (iscol)
                setColor(RED);

            printf("Err in test: %d\n", testNum);
            
            printf("\tIn answer %d solutions:", answ.numofSolutions);
            for (int i = 0; i < answ.numofSolutions; i++) {
                printf("\t%lg", answ.solutions[i]);
            }

            printf("\n");

            printf("\tIn real %d solutions:", answTest.numofSolutions);
            for (int i = 0; i < answTest.numofSolutions; i++) {
                printf("\t%lg", answTest.solutions[i]);
            }
            
            printf("\n");
            testWA++;
        }

        defaultColor;

        testNum++;
    }
    fclose(testFile);

    printf("\n\nWrong tests: %d, total: %d\n", testWA, testNum);
}



#ifndef QUADRICSOLVER_H
#define QUADRICSOLVER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#include "QuadricTypes.h"

void inputEq (double* a, double* b, double* c);//input coefficients

void outputEq (answEquation* answ);

bool isEqual (double a, double b);

void solveEq (double a, double b, double c, answEquation* answ);//get solutions

double getDisc (double a, double b, double c);//get discriminant

void solveEqLin (double b, double c, answEquation* answ);//solve linear

void solveEqQuad (double a, double b, double c, answEquation* answ);//solve quadric

#endif

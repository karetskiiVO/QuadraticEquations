/// \file

#ifndef QUADRICSOLVER_H
#define QUADRICSOLVER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "QuadricTypes.h"

/**
*   @brief this function performs the input
*
*   @param [out] a - pointer to the 1st coefficient of equation
*   @param [out] b - pointer to the 2nd coefficient of equation
*   @param [out] c - pointer to the 3rd coefficient of equation
*/
void inputEq (double* a, double* b, double* c);

/**
*   @brief this function output results
*
*   @param [in] answ - pointer to the struct with solution
*/
void outputEq (answEquation* answ);

/**
*   @brief this function checks for equality pair of double
*
*   @param [in] a - 1st double
*   @param [in] b - 2nd double
*
*   @param [out] true - the numbers are equal
*   @param [out] false - the numbers aren't equal
*/
bool isEqual (double a, double b);

/**
*   @brief this function solves the equation
*
*   @param [in] a - the 1st coefficient of equation
*   @param [in] b - the 2nd coefficient of equation
*   @param [in] c - the 3rd coefficient of equation
*
*   @param [out] answ - pointer to solution struct
*/
void solveEq (double a, double b, double c, answEquation* answ);//get solutions

/**
*   @brief this function get discriminant of the equation
*
*   @param [in] a - the 1st coefficient of equation
*   @param [in] b - the 2nd coefficient of equation
*   @param [in] c - the 3rd coefficient of equation
*
*   @param [out] double - discriminant of the equation
*/
double getDisc (double a, double b, double c);//get discriminant

/**
*   @brief this function solves the linear equation
*
*   @param [in] b - the 1st coefficient of equation
*   @param [in] c - the 2nd coefficient of equation
*
*   @param [out] answ - pointer to solution struct
*/
void solveEqLin (double b, double c, answEquation* answ);//solve linear

/**
*   @brief this function solves the quadric equation
*
*   @param [in] a - the 1st coefficient of equation
*   @param [in] b - the 2nd coefficient of equation
*   @param [in] c - the 3rd coefficient of equation
*
*   @param [out] answ - pointer to solution struct
*/
void solveEqQuad (double a, double b, double c, answEquation* answ);//solve quadric
#endif

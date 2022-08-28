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
*
*   @note equation has form ax^2 + bx + c = 0, where a - 1st coefficient of equation, b - 2nd coefficient of equation, c - 3rd coefficient of equation
*/
void inputEq (double* const a, double* const b, double* const c);

/**
*   @brief this function output results
*
*   @param [in] answ - pointer to the struct with solution
*
*   @note equation has form ax^2 + bx + c = 0, where a - 1st coefficient of equation, b - 2nd coefficient of equation, c - 3rd coefficient of equation
*/
void outputEq (answEquation* const answ, bool isLog);

/**
*   @brief this function checks for equality pair of double
*
*   @param [in] a - 1st double
*   @param [in] b - 2nd double
*
*   @return true - the numbers are equal
*   @return false - the numbers aren't equal
*
*   @note equation has form ax^2 + bx + c = 0, where a - 1st coefficient of equation, b - 2nd coefficient of equation, c - 3rd coefficient of equation
*/
bool isEqual (const double a, const double b);

/**
*   @brief this function solves the equation
*
*   @param [in] a - the 1st coefficient of equation
*   @param [in] b - the 2nd coefficient of equation
*   @param [in] c - the 3rd coefficient of equation
*
*   @param [out] answ - pointer to solution struct
*
*   @note equation has form ax^2 + bx + c = 0, where a - 1st coefficient of equation, b - 2nd coefficient of equation, c - 3rd coefficient of equation
*/
void solveEq (const double a, const double b, const double c, answEquation* const answ, bool isLog);//get solutions

/**
*   @brief this function get discriminant of the equation
*
*   @param [in] a - the 1st coefficient of equation
*   @param [in] b - the 2nd coefficient of equation
*   @param [in] c - the 3rd coefficient of equation
*
*   @return - discriminant of the equation
*
*   @note equation has form ax^2 + bx + c = 0, where a - 1st coefficient of equation, b - 2nd coefficient of equation, c - 3rd coefficient of equation
*/
double getDisc (const double a, const double b, const double c);//get discriminant

/**
*   @brief this function solves the linear equation
*
*   @param [in] b - the 1st coefficient of equation
*   @param [in] c - the 2nd coefficient of equation
*
*   @param [out] answ - pointer to solution struct
*
*   @note equation has form ax^2 + bx + c = 0, where a - 1st coefficient of equation, b - 2nd coefficient of equation, c - 3rd coefficient of equation
*/
void solveEqLin (const double b, const double c, answEquation* const answ, bool isLog);//solve linear

/**
*   @brief this function solves the quadric equation
*
*   @param [in] a - the 1st coefficient of equation
*   @param [in] b - the 2nd coefficient of equation
*   @param [in] c - the 3rd coefficient of equation
*
*   @param [out] answ - pointer to solution struct
*
*   @note equation has form ax^2 + bx + c = 0, where a - 1st coefficient of equation, b - 2nd coefficient of equation, c - 3rd coefficient of equation
*/
void solveEqQuad (const double a, const double b, const double c, answEquation* const answ, bool isLog);//solve quadric
#endif   // QuadraticSolver.h

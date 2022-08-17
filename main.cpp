#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

const double allowance = 1e-9; //delta neighborhood size

enum exitStatus{
    ERROR_IN_DEFINITION = -2,
    INFINITE_NUMOF_SOLUTIONS = -1,
    NO_SOLUTIONS = 0,
    ONE_SOLUTION = 1,
    TWO_SOLUTIONS = 2
};


void input(double* a, double* b, double* c);//input coefficients
void output(double a, double b, double c);
bool isEqual(double a, double b);
int solveEq(double a, double b, double c, double* x);//get solutions
double getDisc(double a, double b, double c);//get discriminant

int main(void){
    double a = 0;
    double b = 0;
    double c = 0;

    input(&a, &b, &c);
    output(a, b, c);
    return 0;
}

void input(double* a, double* b, double* c){
    printf("Enter the polynomial in the form ax^2 + bx + c = 0\n");
    scanf("%lg%lg%lg", a, b, c);
}

void output(double a, double b, double c){
    double x[2];// x - array of solution
    int answer = solveEq(a, b, c, x);

    if(answer == ERROR_IN_DEFINITION){
        printf("error in definition");
        return;
    }
    if(answer == INFINITE_NUMOF_SOLUTIONS){
        printf("infinite number of solutions");
        return;
    }
    printf("Equation have %d solution", answer);

    if(answer == NO_SOLUTIONS){
        printf(".");
    }else{
        printf(":");
    }

    for(int i = 0; i < answer; i++){
        printf("\t%lg", x[i]);
    }
}

bool isEqual(double a, double b){
    return abs(a - b) < allowance;
}

double getDisc(double a, double b, double c){
    return b * b - 4 * a * c;
}

int solveEq(double a, double b, double c, double* x){
    double D = 0;//discriminant
    if(isEqual(a, 0)){
        if(isEqual(b, 0)){
            if(!isEqual(c, 0)){
                return NO_SOLUTIONS;
            }
            return INFINITE_NUMOF_SOLUTIONS;
        }
        x[0] = - c / b;
        return ONE_SOLUTION;
    }
    D = getDisc(a, b, c);
    if(isEqual(D, 0)){
        x[0] = - b / (2 * a);
        return ONE_SOLUTION;
    }
    if(D < 0){
        return NO_SOLUTIONS;
    }

    x[0] = -(b + sqrt(D)) / (2 * a);
    x[1] = -(b - sqrt(D)) / (2 * a);
    return TWO_SOLUTIONS;
}

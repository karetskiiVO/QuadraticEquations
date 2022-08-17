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

struct answEquation{
    double solutions[2];
    int numofSolutions;
};

void inputEq(double* a, double* b, double* c, bool* usl);//input coefficients
void outputEq(struct answEquation answ, bool* usl);
bool isEqual(double a, double b);
bool isNullptrDouble(double* ptr);
bool isNullptrAnswSol(struct answEquation* ptr);
void solveEq(double a, double b, double c, struct answEquation* answ, bool* usl);//get solutions
double getDisc(double a, double b, double c);//get discriminant

int main(void){
    double a = 0;
    double b = 0;
    double c = 0;

    bool isErrorsOnLine = false;

    struct answEquation answ;

    inputEq(&a, &b, &c, &isErrorsOnLine);
    solveEq(a, b, c, &answ, &isErrorsOnLine);
    outputEq(answ, &isErrorsOnLine);
    return 0;
}

void inputEq(double* a, double* b, double* c, bool* usl){
    if(isNullptrDouble(a) || isNullptrDouble(b) || isNullptrDouble(c)){
        *usl = true;
        return;
    }
    printf("Enter the polynomial in the form ax^2 + bx + c = 0\n");
    scanf("%lg%lg%lg", a, b, c);
}

void outputEq(struct answEquation answ, bool* usl){
    int answer = answ.numofSolutions;

    if(answer == ERROR_IN_DEFINITION){
        printf("error in definition\n");
        return;
    }
    if(answer == INFINITE_NUMOF_SOLUTIONS){
        printf("infinite number of solutions\n");
        return;
    }
    printf("equation have %d solution", answer);

    if(answer == NO_SOLUTIONS){
        printf(".");
    }else{
        printf(":");
    }

    for(int i = 0; i < answer; i++){
        printf("\t%lg", answ.solutions[i]);
    }
}

bool isEqual(double a, double b){
    return abs(a - b) < allowance;
}

bool isNullptrDouble(double* ptr){
    return ptr == NULL;
}

bool isNullptrAnswSol(struct answEquation* ptr){
    return ptr == NULL;
}

double getDisc(double a, double b, double c){
    return b * b - 4 * a * c;
}

void solveEq(double a, double b, double c, struct answEquation* answ, bool* usl){
    if(*usl){
        (*answ).numofSolutions = ERROR_IN_DEFINITION;
        printf("aboba");
        return;
    }

    if(isNullptrAnswSol(answ)){
        *usl = true;
        return;
    }

    double D = 0;//discriminant
    if(isEqual(a, 0)){
        if(isEqual(b, 0)){
            if(!isEqual(c, 0)){
                (*answ).numofSolutions = NO_SOLUTIONS;
                return;
            }
            (*answ).numofSolutions = INFINITE_NUMOF_SOLUTIONS;
            return;
        }
        (*answ).solutions[0] = - c / b;
        (*answ).numofSolutions = ONE_SOLUTION;
        return;
    }
    D = getDisc(a, b, c);
    if(isEqual(D, 0)){
        (*answ).solutions[0] = - b / (2 * a);
        (*answ).numofSolutions = ONE_SOLUTION;
        return;
    }
    if(D < 0){
        (*answ).numofSolutions = NO_SOLUTIONS;
        return;
    }

    (*answ).solutions[0] = -(b + sqrt(D)) / (2 * a);
    (*answ).solutions[1] = -(b - sqrt(D)) / (2 * a);
    (*answ).numofSolutions = TWO_SOLUTIONS;
    return;
}

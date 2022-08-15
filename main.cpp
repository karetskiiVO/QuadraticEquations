#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

const double allowance = 1e-9; //delta neighborhood size

void input(double* a, double* b, double* c);//input coefficients
void output(double a, double b, double c);
bool isEqual(double a, double b);
int solveEq(double a, double b, double c, double* x);//get solutions
/*return -2 == error in definition
**return -1 == infinite number of solutions
**if N diffrent
**return N == number of solutions**/
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

    printf("%lg %lg %lg\n", a, b, c);

    if(answer == -2){
        printf("error in definition");
        return;
    }
    if(answer == -1){
        printf("infinite number of solutions");
        return;
    }
    printf("Equation have %d solution", answer);

    if(answer == 0){
        printf(".");
    }else{
        printf(":");
    }

    for(int i = 0; i < answer; i++){
        printf("\t%f", *(x + i));
    }
}

bool isEqual(double a, double b){
    return abs(a - b) < allowance;
}

double getDisc(double a, double b, double c){
    return pow(b, 2) - 4 * a * c;
}

int solveEq(double a, double b, double c, double* x){
    double D = 0;//discriminant
    if(isEqual(a, 0)){
        if(isEqual(b, 0)){
            if(!isEqual(c, 0)){
                return 0;
            }
            return -1;
        }
        *(x + 0) = - c / b;
        return 1;
    }
    D = getDisc(a, b, c);
    if(isEqual(D, 0)){
        *(x + 0) = - b / (2 * a);
        return 1;
    }
    if(D < 0){
        return 0;
    }
    for(int i = 0; i < 2; i++){
        *(x + i) = -(b + pow(-1, i) * sqrt(D)) / (2 * a);
    }
    return 2;
}

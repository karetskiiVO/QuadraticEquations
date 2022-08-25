# QuadricSolver
This is a test project (to study the code style)

Еhis is a program for finding the roots of an equation of the form $ax^2 + bx + c = 0$

```
main.cpp - main file of solution. To compile chose one mode(debug or release) 

QuadricSolver.cpp - contain function to input, output and solve equation

QuadricSolver.h - contain headers to QuadricSolver.cpp

QuadricTypes.h - contain addition types

QuadricTest.cpp - contain function to test program

QuadricTest.h - contain headers to QuadricTest.cpp
```

# To compile in REALEASE:
```bash
git clone https://github.com/karetskiiVO/QuadraticEquations

cd QuadraticEquations

make

./calc
```

# To compile in DEBUG:
```bash
git clone https://github.com/karetskiiVO/QuadraticEquations

cd QuadraticEquations

make debug

./calc
```

# To use documentation:

```bash
git clone https://github.com/karetskiiVO/QuadraticEquations

cd QuadraticEquations

doxygen Doxyfile

cd html

annotation.html
```
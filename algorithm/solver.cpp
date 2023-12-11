#include <iostream>
#include <stdio.h>
#include "solver.h"

using namespace std;

Vector solver (Matrix A, Vector b, double alpha, int number_of_iterations) {

    Vector x(3);
    Vector y(3);
    x = b;

    for(int n = 0; n < number_of_iterations; n++) {
        y = A.mult_vector(x);
        y = y - b;
        y = y*alpha;
        x = x.sum(y);
    }
    return x;
}

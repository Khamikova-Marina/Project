#include <iostream>
#include <stdio.h>
#include "vector.h"
#include "matrix.h"
#include "solver.h"

using namespace std;

double alpha = -0.01;
int number_of_iterations = 1000;

int main () {
    cout << "Hello! This is a solver for Ax = b\n" << endl;

    double values1[3] {2, -1, 0};
    double values2[3] {-1, 2, -1};
    double values3[3] {0, -1, 2};

    // double values1[3] {1, 0, 0};
    // double values2[3] {0, 2, 0};
    // double values3[3] {0, 0, 3};

    Vector rows1(3, values1);
    Vector rows2(3, values2);
    Vector rows3(3, values3);

    Vector rows[] = {rows1, rows2, rows3};

    Matrix A(3, 3, rows);
    cout << "A:\n";
    A.print_values();
    cout << endl;

    double values[3] = {1, 2, 3};
    Vector b(3, values);
    cout << "b:\n";
    b.print_values();
    cout << endl;

    Vector x;
    x = solver(A, b, alpha, number_of_iterations);
    cout << "The answer is:\n";
    x.print_values();
    return 0;
}

#include <iostream>
#include <stdio.h>
#include "vector.h"
#include "matrix.h"

using namespace std;

double alpha = -0.01;

int main () {
    cout << "Hello." << endl;
    double values1[3] {2, -1, 0};
    double values2[3] {-1, 2, -1};
    double values3[3] {0, -1, 2};
    // double values1[3] {1, 0, 0};
    // double values2[3] {0, 2, 0};
    // double values3[3] {0, 0, 3};
    Vector rows1(3, values1);
    Vector rows2(3, values2);
    Vector rows3(3, values3);
    // auto* rows = reinterpret_cast<Vector*>(new int[sizeof(Vector) * 3]);
    Vector rows[] = {rows1, rows2, rows3};
    // cout << "hehe" << endl;
    // rows[0] = &rows1;
    // rows[1] = &rows2;
    // rows[2] = &rows3;
    // (rows[1]).print_values();
    Matrix A(3, 3, rows);
    // cout << "OK\n";
    double values[3] = {1, 2, 3};
    Vector b(3, values);
    b = b.mult_number(-1.0);

    // b.print_values();
    // A.print_values();

    Vector x(3,values);
    Vector y(3);

    for(int n = 0; n < 1000; n++) {
        cout << n << endl;
        y = (A.mult_vector(x));
        // cout << "ok1 " << endl;
        y = (y + b);
        // cout << "ok2 ";
        // y.print_values();
        y = y.mult_number(alpha);
        // cout << "ok3 ";
        x = x.sum(y);
        // cout << "ok4\n";
        // x.print_values();
    }
    x.print_values();
    return 0;
}
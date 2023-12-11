#include <iostream>
#include "matrix.h"

using namespace std;

Matrix::Matrix (int size1, int size2, Vector* rows) {
    this->size1 = size1;
    this->size2 = size2;

    // for (int i = 0; i < size1; ++i) {
    //     this->rows[i] = new ;
    // }

    // this->rows = reinterpret_cast<Vector*>(new int[size1 * sizeof(Vector)]);
    // this->rows = new (Vector(size2)[size1]);
    this->rows = new Vector[size1];

    for (int i = 0; i < size1; ++i) {
        // cout << "uhuhu" << endl;
        this->rows[i] = rows[i];
    }

    // cout << " Matrix initialisation: size " << this->size1 << ", " << this->size2 << endl;
}

Matrix::~Matrix () {
    delete[] this->rows;
}

int Matrix::get_size1() const {
    return size1;
}

int Matrix::get_size2() const {
    return size2;
}

double Matrix::get_value(int i, int j) const {
    return this->rows[i].get_value(j);
}

void Matrix::print_values() const {
    for (int i = 0; i < size1; ++i) {
        rows[i].print_values();
//        cout << i << '\n';
    }
}

Vector Matrix::mult_vector(const Vector& a) const {
    Vector b(size1);
    for (int i = 0; i < size1; ++i) {
        b.set_value(i, rows[i].scalar_product(a));
    }
    return b;
}

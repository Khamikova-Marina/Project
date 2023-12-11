#pragma  once

#include "vector.h" 

class Matrix {

public:
    Matrix(int size1, int size2,  Vector* rows);
    ~Matrix();
    int get_size1() const;
    int get_size2() const;
    double get_value(int i, int j) const;
    void print_values() const;
    Vector mult_vector(const Vector& a) const;

protected:
    int size1, size2;
    Vector* rows;
};

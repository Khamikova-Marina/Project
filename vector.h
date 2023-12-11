#pragma once

class Vector {

public:
    Vector();
    Vector(int size);
    Vector(int size, const double* values);
    Vector(const Vector& other);
    // Vector(Vector&& other);
    ~Vector();
    int get_size() const;
    double get_value(int i) const;
    void print_values() const;
    void set_value(int i, double value);
    Vector sum(const Vector& a) const;
    double scalar_product(const Vector& a) const;
    Vector mult_number(double lambda) const;
    Vector& operator=(const Vector& a);
    // Vector& operator=(Vector&& a) noexcept;
    double operator*(const Vector& a) const;
    Vector operator+(const Vector& a) const;
protected:
    int size;
    double* values;
};


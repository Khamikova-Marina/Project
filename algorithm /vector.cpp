#include <iostream>
#include "vector.h"

using namespace std;

Vector::Vector() {
    this->size = 0;
    // cout << "no arguments constructor" << endl;
}

Vector::Vector(int size) {
    this->size = size;
    this->values = new double[size];
    for (int i = 0; i < size; ++i) {
        this->values[i] = 0;
    }
    // cout << "only size constructor" << endl;
}

Vector::Vector(int size, const double* values) {
    this->size = size;
    this->values = new double[size];
    for (int i = 0; i < size; ++i) {
        this->values[i] = values[i];
    }
    // cout << " Vector initialisation: size = " << size << '\n';
}

Vector::Vector(const Vector& other) {
    size = other.size;
    values = new double[size];
    for (int i = 0; i < size; ++i) {
        values[i] = other.values[i];
    }
    // cout << "copy constructor" << endl;
}

// Vector::Vector(Vector&& other) {
//     size = other.size;
//     values = other.values;
// }

Vector::~Vector () {
    delete[] values;
    // cout << "destructor" << endl;
}

int Vector::get_size() const {
    return size;
}

double Vector::get_value(int i) const {
    return values[i];
}

void Vector::print_values() const {
    for (int i = 0; i < size; ++i) {
        cout << values[i] << " ";
    }
    cout << '\n';
}

void Vector::set_value(int i, double value) {
    values[i] = value;
}

Vector Vector::operator+(const Vector& other) const {
    // cout << size << " " << other.get_size() << endl;
    if(size != other.get_size()) {
        cout << "Different sizes(sum)!" << '\n';
        throw 2;
    }
    else {
        Vector sum_vec(size);
        // sum_vec.print_values();
        for (int i = 0; i < size; i++) {
            sum_vec.set_value(i, this->values[i] + other.get_value(i));
            // sum_vec.print_values();
        }
        return sum_vec;
    }
}

Vector Vector::operator*(double lambda) const {
    Vector res_vec(size, values);
    for (int i = 0; i < size; ++i) {
        res_vec.set_value(i, res_vec.get_value(i) * lambda);
    }
    return res_vec;
}

Vector Vector::operator-(const Vector& other) const {
    // cout << size << " " << other.get_size() << endl;
    if(size != other.get_size()) {
        cout << "Different sizes(sum)!" << '\n';
        throw 2;
    }
    else {
        return *this + other*(-1);
    }
}

Vector Vector::sum(const Vector& a) const {
    return *this + a;
}

double Vector::operator*(const Vector& other) const {
    
    if(size != other.get_size()) {
        cout << "Different sizes(sc)!" << endl;
        throw 1;
    }
    else {
        double res = 0;
        for (int i = 0; i < size; ++i) {
            res += this->values[i] * other.get_value(i);
            
        }
        return res;
    }
}

double Vector::scalar_product(const Vector& a) const {
    return *this * a;
}

Vector Vector::mult_number(double lambda) const {
    Vector res_vec(size, values);
    for (int i = 0; i < size; ++i) {
        res_vec.set_value(i, res_vec.get_value(i) * lambda);
    }
    return res_vec;
}

// Vector& Vector::operator=(Vector&& other) noexcept {
//     values = other.values;
//     size = other.size;
//     return *this;
// }

Vector& Vector::operator=(const Vector& other) {
    // cout << "calling copy =" << endl;
    if (this != &other)
    {
        if(size != 0)
            delete[] values;

        size = other.size;
        values = new double[size]; // TODO: Потенциальная утечка памяти
        for (int i = 0; i < size; ++i) {
            values[i] = other.get_value(i);
        }
    }
    return *this;
}

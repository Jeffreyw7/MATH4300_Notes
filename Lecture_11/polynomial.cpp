#include "Polynomial.h"
#include <stdexcept>

//Default Constructor
Polynomial::Polynomial() {
    coeff = nullptr;
    size = 0;
}

//Deconstructor
Polynomial::~Polynomial() {
    delete[] coeff;
}

//Parameterized Constructor
Polynomial::Polynomial(const double* values, int power) {
    //
    if (power < 0 || values == nullptr) {
        throw std::invalid_argument("Power must be non-negative");
    }
    size = power + 1;

    if(size > 0){
        coeff = new double[size];
    } else {
        coeff = nullptr;
    }

    //Assigning the coefficient
    for (int i = 0; i < size; i++) {
        coeff[i] = values[i];
    }
}


//Copy Constructor
Polynomial::Polynomial(const Polynomial& other) {
    size = other.size;
    if(size > 0){
        coeff = new double[size];
    } else {
        coeff = nullptr;
    }
    //Copying the coefficients from the other polynomial
    for (int i = 0; i < size; i++) {
        coeff[i] = other.coeff[i];
    }
}

//Copy Assignment Operator
Polynomial& Polynomial::operator=(const Polynomial& other) {
    if(this != &other){
        delete[] coeff;
        size = other.size;
        if(size > 0){
            coeff = new double[size];
        } else {
            coeff = nullptr;
        }
        //
        for (int i = 0; i < size; i++) {
            coeff[i] = other.coeff[i];
        }
    }
    return *this;
}

//Move Constructor
Polynomial::Polynomial(Polynomial&& other) noexcept {
    coeff = other.coeff;
    size = other.size;
    other.coeff = nullptr;
    other.size = 0;
}

//Move Assignment Operator
Polynomial& Polynomial::operator=(Polynomial&& other) noexcept {
    if(this == &other){
        return *this;
    }

    delete[] coeff;

    coeff = other.coeff;
    size = other.size;
    other.coeff = nullptr;
    other.size = 0;
    
    return *this;
}

//Evaluate the polynomial at a given value of x
double Polynomial::solve(double x) const {
    double result = 0.0;

    //Evaluate the polynomial using Horner's method
    for (int i = 0; i < size; i++) {
        result += coeff[i] * pow(x, i);
    }
    return result;
}
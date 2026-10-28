#include "Polynomial.h"
#include <stdexcept>

//Default Constructor
Polynomial::Polynomial() {
    coefficients = nullptr;
    size = 0;
}

//Deconstructor
Polynomial::~Polynomial() {
    delete[] coefficients;
}

Polynomial::Polynomial(const Polynomial& other) {
    size = other.size;
    if(size > 0){
        new double[size]
    } else {
        nullptr;
    }


    for (int i = 0; i < size; i++) {
        coefficients[i] = other.coefficients[i];
    }
}

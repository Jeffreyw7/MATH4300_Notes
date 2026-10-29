#include <iostream>
#include "polynomial.h"

int main(){
    //Function: f(x) = 2x^2 + 3x + 4
    //Coefficients
    double coeffs[] = {4, 3, 2};
    Polynomial p(coeffs, 3);

    //Input 1 as x for the function
    std::cout << "f(1) = " << p.solve(1.0) << std::endl;


    //Testing the copy constructor
    Polynomial copiedPoly(p);
    std::cout << "f(1) of copied polynomial = " << copiedPoly.solve(1.0) << std::endl;

    //Testing the copy assignment operator
    Polynomial assignedPoly;
    assignedPoly = p;
    std::cout << "f(1) of assigned polynomial = " << assignedPoly.solve(1.0) << std::endl;

    //Testing the move constructor
    Polynomial movedPoly(std::move(p));
    std::cout << "f(1) of moved polynomial = " << movedPoly.solve(1.0) << std::endl;

    //Testing the move assignment operator
    Polynomial anotherPoly;
    anotherPoly = std::move(movedPoly);
    std::cout << "f(1) of another polynomial after move assignment = " << anotherPoly.solve(1.0) << std::endl;

    return 0;
}
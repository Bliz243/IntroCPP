#include <iostream>
#include "ex01-library.h"
using namespace std;

// Task 1(a).  Implement this function
Complex **createMatrix(unsigned int m, unsigned int n, Complex c) {
    
}

// Task 1(b).  Implement this function
void displayMatrix(Complex **A, unsigned int m, unsigned int n) {
    // Write your code here
}

// Task 1(c).  Implement this function
Complex **createIdentityMatrix(unsigned int n) {
    // Write your code here
}

// Task 1(d).  Implement this function
void multMatrix(Complex **A, Complex **B, Complex **C,
                unsigned int m, unsigned int n, unsigned int p) {
    // Write your code here
}

// Do not modify
Complex add(Complex c, Complex d) {
    Complex result = { c.re + d.re, c.im + d.im };
    return result;
}

// Do not modify
Complex mult(Complex c, Complex d) {
    Complex result;
    result.re = (c.re * d.re) - (c.im * d.im);
    result.im = (c.re * d.im) + (c.im * d.re);
    return result;
}

// Do not modify
void deleteMatrix(Complex **A, unsigned int nRows) {
    for (unsigned int i = 0; i < nRows; i++) { delete[] A[i]; }
    delete[] A;
}

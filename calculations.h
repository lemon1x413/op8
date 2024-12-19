#ifndef OP8_CALCULATIONS_H
#define OP8_CALCULATIONS_H

typedef struct {
    double real;
    double imaginary;
} complex;

complex divisionComplex(complex z1, complex z2) { //fix
    complex result;
    result.real = (z1.real * z2.real + z1.imaginary * z2.imaginary) / (z2.real * z2.real + z2.imaginary * z2.imaginary);
    result.imaginary = (z1.imaginary * z2.real - z1.real * z2.imaginary) / (z2.real * z2.real + z2.imaginary * z2.imaginary);
    return result;
}

#endif //OP8_CALCULATIONS_H

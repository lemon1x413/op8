#ifndef OP8_CALCULATIONS_H
#define OP8_CALCULATIONS_H

#include <math.h>

typedef struct {
    double real;
    double imaginary;
} complex;

complex divisionComplex(complex z1, complex z2) {
    complex result = {0, 0};
    result.real = (z1.real * z2.real + z1.imaginary * z2.imaginary) / (z2.real * z2.real + z2.imaginary * z2.imaginary);
    result.imaginary = (z1.imaginary * z2.real - z1.real * z2.imaginary) / (z2.real * z2.real + z2.imaginary * z2.imaginary);
    return result;
}

void calculateComplexResistance(double L, double C, double R1, double R2, double fMin, double fMax, double fStep,
                                char circuitChoice) {
    complex Z = {0, 0}, numerator = {0, 0}, denominator = {0, 0};
    double f0 = 1.0 / (2.0 * M_PI * sqrt(L * C));
    printf(DARK_BLUE"\nResonance frequency: %.7e\n"RESET, f0);
    double f = fMin;
    do {
        double omega = 2.0 * M_PI * f;
        switch (circuitChoice) {
            case '1':
                numerator.real = L / C;
                numerator.imaginary = -R1 / (omega * C);
                denominator.real = R1;
                denominator.imaginary = omega * L - 1.0 / (omega * C);
                Z = divisionComplex(numerator, denominator);
                break;
            case '2':
                numerator.real = L / C;
                numerator.imaginary = R1 / (omega * C);
                denominator.real = R1;
                denominator.imaginary = omega * L - 1.0 / (omega * C);
                Z = divisionComplex(numerator, denominator);
                break;
            case '3':
                numerator.real = R1 * R2;
                numerator.imaginary = R1 * (omega * L - 1.0 / (omega * C));
                denominator.real = R1 + R2;
                denominator.imaginary = omega * L - 1.0 / (omega * C);
                Z = divisionComplex(numerator, denominator);
                break;
            case '4':
                numerator.real = R1 * R2 + L / C;
                numerator.imaginary = omega * L * R1 - R2 / (omega * C);
                denominator.real = R1 + R2;
                denominator.imaginary = omega * L - 1.0 / (omega * C);
                Z = divisionComplex(numerator, denominator);
                break;
            default:
                printf(RED"Error. Invalid circuit choice.\n"RESET);
                break;
        }
        printf(BLUE"f = %.15lf, Z = %.15lf %c i * %.15lf \n"RESET, f, Z.real, Z.imaginary > 0
                                                                                            ? '+'
                                                                                            : '-', fabs(Z.imaginary));
        if (f == fMax) {
            break;
        }
        else if (f + fStep > fMax) {
            f = fMax;
        }
        else {
            f += fStep;
        }
        f += fStep;
    } while (f <= fMax);
}

#endif
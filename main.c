#include <stdio.h>
#include <math.h>

typedef struct {
    double real;
    double imaginary;
} complex;

int main() {
    complex z;
    z.real = 1.0;
    z.imaginary = 1.0;
    printf("%lf + %lfi\n", z.real, z.imaginary);

    return 0;
}

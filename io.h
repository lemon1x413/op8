#ifndef OP8_IO_H
#define OP8_IO_H
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include "colors.h"

bool conditionChoiceCircuit(char value, char choice1, char choice2, char choice3, char choice4) {
    return value != choice1 && value != choice2 && value != choice3 && value != choice4;
}

bool conditionDF(double value, double min, double max) {
    return value < min || value > max;
}

double validInputDouble(char *message, bool (*condition)(double)) {
    double value = 0;
    int validInput = 0;
    do {
        printf("%s", message);
        validInput = scanf("%lf", &value);
        if (validInput != 1 || condition(value)) {
            printf(RED"Invalid input\n"RESET);
        }
        fflush(stdin);
    } while (validInput != 1 || condition(value));
    return value;
}

char validInputChoice(char *message, bool (*condition)(char)) {
    char value = 0;
    do {
        printf("%s", message);
        value = getch();
        if (condition(value)) {
            printf(RED"Invalid input\n"RESET);
        }
    } while (condition(value));
    return value;
}

#endif //OP8_IO_H

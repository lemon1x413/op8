#ifndef OP8_IO_H
#define OP8_IO_H

#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include "colors.h"

#define FMIN_MIN 1e-3
#define FMIN_MAX 1e3
#define FMAX_MIN 1e-3
#define FMAX_MAX 1e3
#define VALUE_MIN 1e-3
#define VALUE_MAX 1e3

bool conditionChoiceCircuit(char value) {
    return value != '1' && value != '2' && value != '3' && value != '4';
}

bool conditionDouble(double value) {
    return value < VALUE_MIN || value > VALUE_MAX;
}

bool conditionFMin(double value) {
    return value < FMIN_MIN || value > FMIN_MAX;
}

bool conditionFMax(double value) {
    return value < FMAX_MIN || value > FMAX_MAX;
}

double validInputDouble(char *message, bool (*condition)(double)) {
    double value = 0;
    int validInput = 0;
    do {
        printf("%s", message);
        validInput = scanf("%lf", &value);
        if (validInput != 1 || condition(value)) {
            printf(RED"Invalid input.\n"RESET);
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
            printf(RED"Invalid input.\n"RESET);
        }
    } while (condition(value));
    return value;
}

void printCircuits() {
    printf("Circuit #1:\n"
           BLUE"●─┬─────────▆▆▆───────◠◠◠◠──┬─●\n"
           "  │          R          L   │\n"
           "  │                         │\n"
           "  │               C         │\n"
           "  └───────────────││────────┘\n"RESET);
    printf("Circuit #2:\n"
           BLUE"●─┬────────▆▆▆──────││──────┬─●\n"
           "  │         R       C       │\n"
           "  │                         │\n"
           "  │      L                  │\n"
           "  └────◠◠◠◠─────────────────┘\n"RESET);
    printf("Circuit #3:\n"
           BLUE"●─┬─────────▆▆▆──────││─────┐\n"
           "  │          R2      C      │\n"
           "  │                         │\n"
           "  █ R1     L                │\n"
           "●─┴──────◠◠◠◠───────────────┘\n"RESET);
    printf("Circuit #4:\n"
           BLUE"●─┬────────▆▆▆──────────────┐\n"
           "  █ R1      R2              │\n"
           "  ┴                         │\n"
           "  ┬ C       L               │\n"
           "●─┴───────◠◠◠◠──────────────┘\n"RESET);
}

void printChosenCircuit(char choice) {
    switch (choice) {
        case '1':
            printf(YELLOW"●─┬─────────▆▆▆───────◠◠◠◠──┬─●\n"
                   "  │          R          L   │\n"
                   "  │                         │\n"
                   "  │               C         │\n"
                   "  └───────────────││────────┘\n"RESET);
            break;
        case '2':
            printf(YELLOW"●─┬────────▆▆▆──────││──────┬─●\n"
                   "  │         R       C       │\n"
                   "  │                         │\n"
                   "  │      L                  │\n"
                   "  └────◠◠◠◠─────────────────┘\n"RESET);
            break;
        case '3':
            printf(YELLOW"●─┬─────────▆▆▆──────││─────┐\n"
                   "  │          R2      C      │\n"
                   "  │                         │\n"
                   "  █ R1     L                │\n"
                   "●─┴──────◠◠◠◠───────────────┘\n"RESET);
            break;
        case '4':
            printf(YELLOW"●─┬────────▆▆▆──────────────┐\n"
                   "  █ R1      R2              │\n"
                   "  ┴                         │\n"
                   "  ┬ C       L               │\n"
                   "●─┴───────◠◠◠◠──────────────┘\n"RESET);
            break;
        default:
            printf(RED"Wrong option. The option should be from 1 to 4.\n"RESET);
            break;
    }
}

#endif //OP8_IO_H
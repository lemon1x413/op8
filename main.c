#include <stdio.h>
#include <windows.h>
#include "io.h"
#include "calculations.h"
#include "colors.h"

#define ENTER 13

int main() {
    SetConsoleOutputCP(CP_UTF8);
    do {
        double L = 0.0, C = 0.0, R1 = 0.0, R2 = 0.0, fMin = 0.0, fMax = 0.0, fStep = 0.0, f = 0.0;
        char circuitChoice = 0;
        printf(GREEN"This program calculates complex resistance of a given oscillatory circuit depending on the current frequency.\n"RESET);
        printCircuits();
        circuitChoice = validInputChoice("Chose circuit: \n", conditionChoiceCircuit);
        printChosenCircuit(circuitChoice);

        L = validInputDouble(GREEN"Enter L[mHn] (from 1e-15 to 1e4): "RESET, conditionDouble);

        C = validInputDouble(GREEN"Enter C[mcF] (from 1e-15 to 1e4): "RESET, conditionDouble);

        switch (circuitChoice) {
            case '1':
            case '2':
                R1 = validInputDouble(GREEN"Enter R[Ohm] (from 1e-15 to 1e4): "RESET, conditionDouble);
                break;
            case '3':
            case '4':
                R1 = validInputDouble(GREEN"Enter R1[Ohm] (from 1e-15 to 1e4): "RESET, conditionDouble);
                R2 = validInputDouble(GREEN"Enter R2[Ohm] (from 1e-15 to 1e4): "RESET, conditionDouble);
                break;
            default:
                printf(RED"Error. Invalid circuit choice.\n"RESET);
                break;
        }

        fMin = validInputDouble(GREEN"Enter fMin (from 1e-15 to 1e4): "RESET, conditionFMin);
        do {
            fMax = validInputDouble(GREEN"Enter fMax (from 1e-15 to 1e4): "RESET, conditionFMax);
            if (fMin > fMax) {
                printf(RED"Error. fMax must be greater than fMin.\n"RESET);
            }
        } while (fMin > fMax);

        do {
            fStep = validInputDouble(ITALIC_GREEN"fStep must be less than fMax - fMin.\n"
                                     GREEN"Enter fStep (from 1e-15 to 1e4): "RESET, conditionDouble);
            if (fStep > fMax - fMin) {
                printf(RED"Error. fStep must be less than fMax - fMin.\n"RESET);
            }
        } while (fStep > fMax - fMin);

        calculateComplexResistance(L, C, R1, R2, fMin, fMax, fStep, circuitChoice);

        printf(GREEN"Press ENTER to continue, or any other key to exit.\n"RESET);
    } while (getch() == ENTER);
    return 0;
}
#ifndef OP8_COLORS_H
#define OP8_COLORS_H

#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define ITALIC_GREEN "\e[3;32m"
#define BLUE "\e[0;36m"
#define DARK_BLUE "\e[0;34m"
#define YELLOW  "\e[0;33m"
#define RESET "\e[0;0m"

void magicFunction() {
    int height = 7;
    printf(RED"M"GREEN"e"RED"r"GREEN"r"RED"y"GREEN" "RED"C"GREEN"h"RED"r"GREEN"i"RED"s"GREEN"t"RED"m"GREEN"a"RED"s"RESET"\n");
    for (int i = 1; i <= height; i++)
    {
        int starCount = (i * 2) - 1;
        int spaceCount = height - i + 1;
        for (int j = 0; j < spaceCount; j++)
            printf(GREEN" "RESET);
        for (int j = 0; j < starCount; j++)
            printf(GREEN"*"RESET);
        printf(GREEN"\n"RESET);
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < height; j++)
            printf(GREEN" "RESET);
        printf(GREEN"*\n"RESET);
    }
}

#endif //OP8_COLORS_H

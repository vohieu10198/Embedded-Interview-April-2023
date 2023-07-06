#include <stdio.h>

const char* digits[] = {
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine"
};

const char* teens[] = {
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

const char* tens[] = {
    "", "", "twenty", "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety"
};

typedef struct {
    int hundreds;
    int tens;
    int ones;
} NumberGroup;

void convertToText(NumberGroup group) {
    if (group.hundreds > 0) {
        printf("%s hundred ", digits[group.hundreds]);
    }

    if (group.tens >= 2) {
        printf("%s ", tens[group.tens]);
        if (group.ones > 0) {
            printf("%s ", digits[group.ones]);
        }
    } else if (group.tens == 1) {
        printf("%s ", teens[group.ones]);
    } else if (group.ones > 0) {
        printf("%s ", digits[group.ones]);
    }
}

void convertMillionsToText(int millions) {
    if (millions < 0) {
        printf("minus ");
        millions = -millions;
    }

    if (millions == 0) {
        printf("zero");
        return;
    }

    NumberGroup groups[4];
    int numGroups = 0;

    while (millions > 0) {
        NumberGroup group;
        group.ones = millions % 10;
        millions /= 10;
        group.tens = millions % 10;
        millions /= 10;
        group.hundreds = millions % 10;
        millions /= 10;

        groups[numGroups++] = group;
    }

    const char* scales[] = { "", "thousand", "million", "billion", "trillion" };

    for (int i = numGroups - 1; i >= 0; i--) {
        convertToText(groups[i]);
        if (groups[i].hundreds > 0 || groups[i].tens > 0 || groups[i].ones > 0) {
            printf("%s ", scales[i]);
        }
    }
}

int main() {
    int millions;

    printf("Enter a number: ");
    scanf("%d", &millions);

    printf("Textual representation: ");
    convertMillionsToText(millions);
    printf("\n");

    return 0;
}

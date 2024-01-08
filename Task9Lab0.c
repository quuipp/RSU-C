#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void printNewNumberSystem(long, unsigned short);

int main(int argc, const char* argv[]) {

    char* currentStr = malloc(sizeof(long));
    unsigned short notation;
    int isAnyValuesInput_Flag = 0;
    long currentValue, maxValue = 0; //минимальное возможное число - ноль, тк сравнение идет по модулю


    printf("Input notation from 2 to 36:\n");
    scanf("%hd", &notation);
    if (notation < 2 || notation>36) {
        printf("Incorrect notation. It must be from 2 to 36\n");
        return 1;
    }


    while (!strcmp(currentStr, "Stop")){
        printf("\nInput value from your notation (Input Stop to exit):\n");
        scanf("%s", currentStr);
        if (!strcmp(currentStr, "Stop")) break;

        currentValue = strtol(currentStr, NULL, notation);

        if (currentValue == 0) { //код ошибки
            printf("Incorrect value. Try again\n\n");
            continue;
        }

        isAnyValuesInput_Flag = 1;
        if (labs(currentValue) >= labs(maxValue)) maxValue = currentValue;
    }

    free(currentStr);


    if (isAnyValuesInput_Flag){
        printf("\nMax number in 10 notation: %ld\n", maxValue);


        //числа дробны 9 - можно обьединить в массив
        printf("This number in 9 notation: ");
        printNewNumberSystem(maxValue, 9);

        printf("This number in 18 notation: ");
        printNewNumberSystem(maxValue, 18);

        printf("This number in 27 notation: ");
        printNewNumberSystem(maxValue, 27);

        printf("This number in 36 notation: ");
        printNewNumberSystem(maxValue, 36);
    }
    else printf("You have not entered any values");


    return 0;
}







void printNewNumberSystem(long decimanNumber, unsigned short notation) {

    int i = 0;
    char* newNumber;
    static char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (decimanNumber < 0){
        printf("-");
        decimanNumber = labs(decimanNumber);
    }

    newNumber = malloc(sizeof(long));
    for (i = 0; decimanNumber > 0; i++){
        newNumber[i] = alphabet[decimanNumber % notation]; // статок от деления на систему с. дает индекс нужной буквы в массиве
        decimanNumber /= notation;
    }

    while (--i >= 0) {
        printf("%c", newNumber[i]);
    }

    free(newNumber);
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

void lessThanRequired(int *lengthOfText) {
    printf("The length of your text is less than specified, please update your text\n");
    printf("Length Before : %d\n", *lengthOfText);
    *lengthOfText += MIN_LENGTH - *lengthOfText + 78;  // Menggunakan operasi aritmatika
    printf("The Length is updated to %d\n", *lengthOfText);
}

void equalThanRequired(int *lengthOfText) {
    printf("Thank you, Your text length is correct\n");
}

void moreThanRequired(int *lengthOfText) {
    printf("Your text is too long, please reduce the text\n");
    printf("Length Before : %d\n", *lengthOfText);
    *lengthOfText -= *lengthOfText - MIN_LENGTH;  // Menggunakan operasi aritmatika
    printf("The Length is updated to %d\n", *lengthOfText);
}

int checkLenghtRequirement(char *text) {
    int length = strlen(text);
    return (length < MIN_LENGTH) ? 0 : ((length == MIN_LENGTH) ? 1 : 2);
}

int main() {
    int lengthOfText, selectOption;
    FILE *fptr = NULL;
    char text[MAX_LENGTH];

    fptr = fopen("file.txt", "r");

    if (fptr == NULL) {
        printf("Error");
        exit(1);
    }

    fgets(text, MAX_LENGTH, fptr);

    fclose(fptr);

    selectOption = checkLenghtRequirement(text);

    void (*functions[3])(int *) = {lessThanRequired, equalThanRequired, moreThanRequired};
    lengthOfText = strlen(text);
    functions[selectOption](&lengthOfText);

    return 0;
}

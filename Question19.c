#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main() {
    char string1[100];
    char string2[100];

    // Input strings
    printf("Enter string1: ");
    fgets(string1, sizeof(string1), stdin);
    printf("Enter string2: ");
    fgets(string2, sizeof(string2), stdin);

    // Remove newline characters from fgets input
    string1[strcspn(string1, "\n")] = '\0';
    string2[strcspn(string2, "\n")] = '\0';

    // Convert both strings to lowercase
    char temp1[100];
    char temp2[100];
    strcpy(temp1, string1);
    strcpy(temp2, string2);
    toLowerCase(temp1);
    toLowerCase(temp2);

    // Compare strings
    if (strcmp(temp1, temp2) == 0) {
        printf("same\n");
    } else {
        printf("not same\n");
    }

    return 0;
}

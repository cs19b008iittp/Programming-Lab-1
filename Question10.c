#include <stdio.h>
#include <string.h>

void encryptString(char *str) {
    // Iterate through each character of the string
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a') {
            str[i] = 'b'; // Replace 'a' with 'b'
        }
    }
}

int main() {
    char str[100];

    // Input the string
    printf("Enter the string:\n");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character if it's present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Encrypt the string
    encryptString(str);

    // Output the encrypted string
    printf("Encrypted string: %s\n", str);

    return 0;
}

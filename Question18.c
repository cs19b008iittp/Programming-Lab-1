#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to find the frequency of a keyword in a text
int findKeywordFrequency(const char *filename, const char *keyword) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read the entire file into a buffer
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buffer = (char *)malloc(fileSize + 1);
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return -1;
    }
    fread(buffer, 1, fileSize, file);
    buffer[fileSize] = '\0';
    fclose(file);

    // Convert the buffer to lowercase
    toLowerCase(buffer);

    // Convert keyword to lowercase
    char *lowerKeyword = strdup(keyword);
    toLowerCase(lowerKeyword);

    // Find the frequency of the keyword
    int keywordLength = strlen(lowerKeyword);
    int count = 0;
    char *pos = buffer;

    while ((pos = strstr(pos, lowerKeyword)) != NULL) {
        count++;
        pos += keywordLength;
    }

    free(buffer);
    free(lowerKeyword);

    return count;
}

int main() {
    char filename[100];
    char keyword[100];

    // Input filename and keyword
    printf("Enter the filename: ");
    scanf("%s", filename);
    printf("Enter the keyword: ");
    scanf("%s", keyword);

    int frequency = findKeywordFrequency(filename, keyword);
    if (frequency >= 0) {
        printf("Frequency of '%s': %d\n", keyword, frequency);
    }

    return 0;
}

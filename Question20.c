#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to compute the edit distance
int minDistance(char *s, char *t) {
    int m = strlen(s);
    int n = strlen(t);
    
    // Create a 2D array for storing results of subproblems
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    // Initialize base cases
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i; // Cost of deleting all characters from s
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j; // Cost of inserting all characters into s
    }

    // Fill dp array
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // Characters match
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j],    // Deletion
                                   min(dp[i][j - 1], // Insertion
                                       dp[i - 1][j - 1])); // Replacement
            }
        }
    }

    int result = dp[m][n];
    
    // Free allocated memory
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    char s[1000], t[1000];

    // Input strings
    printf("Enter string s: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Remove newline character

    printf("Enter string t: ");
    fgets(t, sizeof(t), stdin);
    t[strcspn(t, "\n")] = '\0'; // Remove newline character

    // Compute and print the minimum number of operations
    int result = minDistance(s, t);
    printf("Minimum number of operations: %d\n", result);

    return 0;
}

#include <stdio.h>

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to find the millionth permutation
void findMillionthPermutation() {
    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 10; // Number of digits
    unsigned long long k = 1000000 - 1; // 0-based index for the millionth permutation
    unsigned long long fact = factorial(n - 1); // (n-1)! for the first digit
    
    printf("The millionth permutation is: ");

    for (int i = 0; i < n; ++i) {
        int index = k / fact; // Determine the index of the current digit
        printf("%d", digits[index]);
        
        // Remove used digit and adjust k
        for (int j = index; j < n - 1; ++j) {
            digits[j] = digits[j + 1];
        }
        
        k %= fact; // Update k for the remaining positions
        if (i < n - 1) {
            fact /= (n - 1 - i); // Update factorial for the next position
        }
    }
    
    printf("\n");
}

int main() {
    findMillionthPermutation();
    return 0;
}

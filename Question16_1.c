#include <stdio.h>

#define NUM_DIGITS 10

// Function to calculate factorial of a number
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// Function to find the nth lexicographic permutation
void find_lexicographic_permutation(int n, int digits[], int size) {
    int permutation[size];
    int available_digits[size];
    int i, j;

    // Initialize available digits
    for (i = 0; i < size; i++) {
        available_digits[i] = digits[i];
    }

    n--; // Convert n to zero-indexed

    for (i = 0; i < size; i++) {
        unsigned long long fact = factorial(size - 1 - i);
        int index = n / fact;
        permutation[i] = available_digits[index];

        // Remove used digit from available_digits
        for (j = index; j < size - 1 - i; j++) {
            available_digits[j] = available_digits[j + 1];
        }

        n %= fact;
    }

    // Print the permutation
    for (i = 0; i < size; i++) {
        printf("%d", permutation[i]);
    }
    printf("\n");
}

int main() {
    int digits[NUM_DIGITS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 1000000; // The millionth permutation

    printf("The %dth lexicographic permutation is: ", n);
    find_lexicographic_permutation(n, digits, NUM_DIGITS);

    return 0;
}

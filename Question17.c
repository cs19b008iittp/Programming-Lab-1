#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10000

// Function to check if a number is prime
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to sort the digits of a number to get its canonical form
void sort_digits(char *digits) {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (digits[i] > digits[j]) {
                char temp = digits[i];
                digits[i] = digits[j];
                digits[j] = temp;
            }
        }
    }
}

// Function to check if two numbers are permutations of each other
bool is_permutation(int a, int b) {
    char digits_a[5], digits_b[5];
    sprintf(digits_a, "%d", a);
    sprintf(digits_b, "%d", b);
    sort_digits(digits_a);
    sort_digits(digits_b);
    return strcmp(digits_a, digits_b) == 0;
}

int main() {
    int primes[MAX], count = 0;

    // Generate all 4-digit prime numbers
    for (int i = 1000; i < 10000; i++) {
        if (is_prime(i)) {
            primes[count++] = i;
        }
    }

    // Find the required arithmetic sequence
    for (int i = 0; i < count - 2; i++) {
        for (int j = i + 1; j < count - 1; j++) {
            int k = 2 * primes[j] - primes[i]; // Calculate the third term
            if (k < 10000 && is_prime(k) && is_permutation(primes[i], primes[j]) && is_permutation(primes[i], k)) {
                if (primes[i] != 1487) { // Exclude the known sequence 1487, 4817, 8147
                    printf("The 12-digit number is: %d%d%d\n", primes[i], primes[j], k);
                    return 0;
                }
            }
        }
    }

    printf("No sequence found.\n");
    return 0;
}

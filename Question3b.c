#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int n = 28123;
int arr[28123];
int arrSize = 0;

// Function to calculate the sum of proper divisors
int sumOfDivisors(int x) {
    int sum = 1; // 1 is a proper divisor of all numbers
    for (int i = 2; i <= x / 2; ++i) {
        if (x % i == 0) {
            sum += i;
        }
    }
    return sum;
}

// Function to determine if a number is abundant
bool isAbundant(int x) {
    return sumOfDivisors(x) > x;
}

// Function to determine if a number can be written as the sum of two abundant numbers
bool sumofAbundant(int x) {
    if (x > n) return true; // If greater than n, it can be written as the sum
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] >= x) return false;
        int temp = x - arr[i];
        for (int j = 0; j < arrSize; ++j) {
            if (arr[j] == temp) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    bool canBeWritten[n + 1];
    for (int i = 0; i <= n; ++i) {
        canBeWritten[i] = false;
    }

    // Find all abundant numbers up to n
    for (int i = 12; i <= n; ++i) {
        if (isAbundant(i)) {
            arr[arrSize++] = i;
        }
    }

    // Mark all numbers that can be written as the sum of two abundant numbers
    for (int i = 1; i <= n; ++i) {
        if (sumofAbundant(i)) {
            canBeWritten[i] = true;
        }
    }

    // Calculate the sum of all numbers that cannot be written as the sum of two abundant numbers
    long long val = 0;
    for (int i = 1; i <= n; ++i) {
        if (!canBeWritten[i]) {
            val += i;
        }
    }

    printf("Sum of numbers which cannot be written as sum of 2 abundant numbers is: %lld\n", val);
    return 0;
}

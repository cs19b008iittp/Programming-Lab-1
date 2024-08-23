#include <stdio.h>
#include <math.h>

// Function to count the number of divisors of a number
int countDivisors(int num) {
    int count = 0;
    int root = (int)sqrt(num);

    for (int i = 1; i <= root; i++) {
        if (num % i == 0) {
            if (i * i == num) {
                count += 1; // Perfect square
            } else {
                count += 2; // Pair of divisors
            }
        }
    }
    return count;
}

// Function to find the first triangular number with over 500 divisors
int findTriangularNumberWithDivisors(int divisorLimit) {
    int i = 1;
    int triangularNumber;
    int numDivisors;

    while (1) {
        triangularNumber = i * (i + 1) / 2;
        numDivisors = countDivisors(triangularNumber);

        if (numDivisors > divisorLimit) {
            return triangularNumber;
        }

        i++;
    }
}

int main() {
    int divisorLimit = 500;
    int result = findTriangularNumberWithDivisors(divisorLimit);

    printf("The first triangular number with over %d divisors is: %d\n", divisorLimit, result);

    return 0;
}

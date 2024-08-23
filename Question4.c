#include <stdio.h>

int sumOfDivisors(int x) {
    int sum = 1; // 1 is a proper divisor of all numbers
    for (int i = 2; i <= x / 2; ++i) {
        if (x % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int a, b;
    printf("Enter Number 1: \n");
    scanf("%d", &a);
    printf("Enter Number 2: \n");
    scanf("%d", &b);
    int c = sumOfDivisors(a);
    int d = sumOfDivisors(b);
    if (c == b && d == a)
        printf("Amicable Numbers\n");
    else
        printf("Not Amicable Numbers\n");

    return 0;
}

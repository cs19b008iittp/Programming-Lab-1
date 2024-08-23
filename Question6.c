#include <stdio.h>

int factorial(int x) {
    int fact = 1;
    for (int i = 1; i <= x; i++) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    int n, r;
    printf("Enter n value:\n");
    scanf("%d", &n);
    printf("Enter r value:\n");
    scanf("%d", &r);

    float p, c;
    p = (float)factorial(n) / factorial(n - r);
    c = p / factorial(r);
    printf("Permutation: %.2f\n", p);
    printf("Combination: %.2f\n", c);

    return 0;
}

#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    printf("Enter 1st number  :\n");
    scanf("%d", &a);
    printf("Enter 2nd number  :\n");
    scanf("%d", &b);
    if (gcd(a, b) == 1)
        printf("Co-Prime\n");
    else
        printf("Not Co-Prime\n");
    return 0;
}

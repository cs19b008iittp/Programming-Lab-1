#include <stdio.h>

int main() {
    int n;
    printf("Enter number:\n");
    scanf("%d", &n);
    int sum = 0;
    int temp = n;
    int p;
    while (n != 0) {
        p = n % 10;
        sum += p;
        n = n / 10;
    }
    // printf("%d\n", sum);
    if (temp % sum == 0)
        printf("Harshad number\n");
    else
        printf("Not a Harshad number\n");

    return 0;
}

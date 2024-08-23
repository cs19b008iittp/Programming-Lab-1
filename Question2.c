#include <stdio.h>

int main() {
    int a, n, sum = 0;
    printf("Enter number :\n");
    scanf("%d", &a);
    int temp = a;
    while (a != 0) {
        n = a % 10;
        sum += n * n * n;
        a = a / 10;
    }

    if (sum == temp) {
        printf("Armstrong number\n");
    } else {
        printf("Not an Armstrong number\n");
    }
    return 0;
}

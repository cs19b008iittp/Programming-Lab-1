#include <stdio.h>

int main() {
    int n, sum = 1;
    printf("Enter number :");
    scanf("%d", &n);
    // a=n*n;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
        {
           printf("%d\n",i);
            sum += i;
        }

    }
    if (sum == n)
        printf("perfect number\n");
    else if (sum < n)
        printf("deficient number\n");
    else
        printf("abundant number\n");
    return 0;
}

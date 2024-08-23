#include <stdio.h>
#include <math.h>

int main() {
    int x, n;
    float temp, sum = 0.0, m = 1.0;

    printf("Enter x value:\n");
    scanf("%d", &x);
    printf("Enter n value:\n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        temp = pow(x, i);
        temp = temp / i;
        sum += temp * m;
        m = m * -1;
    }

    printf("Sum of provided series: %.2f\n", sum);
    return 0;
}

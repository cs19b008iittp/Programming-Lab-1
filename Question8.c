#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points
double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to check if three points are collinear
int areCollinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1);
}

int main() {
    int x1, y1, x2, y2, x3, y3;

    printf("Enter coordinates of the first point (x1, y1):\n");
    scanf("%d %d", &x1, &y1);
    printf("Enter coordinates of the second point (x2, y2):\n");
    scanf("%d %d", &x2, &y2);
    printf("Enter coordinates of the third point (x3, y3):\n");
    scanf("%d %d", &x3, &y3);

    if (areCollinear(x1, y1, x2, y2, x3, y3)) {
        printf("The points are collinear.\n");
    } else {
        double d1 = distance(x1, y1, x2, y2);
        double d2 = distance(x2, y2, x3, y3);
        double d3 = distance(x3, y3, x1, y1);

        if (d1 == d2 && d2 == d3) {
            printf("The points form an Equilateral triangle.\n");
        } else if (d1 == d2 || d2 == d3 || d3 == d1) {
            printf("The points form an Isosceles triangle.\n");
        } else {
            printf("The points form a Scalene triangle.\n");
        }
    }

    return 0;
}

#include <stdio.h>

// Function to identify the relationship between two lines
void checkLines(double m1, double c1, double m2, double c2) {
    int caseType;
    if (m1 == m2) {
        caseType = 1; // Parallel
    } else if (m1 * m2 == -1) {
        caseType = 2; // Perpendicular
    } else {
        caseType = 3; // Intersecting
    }

    switch (caseType) {
        case 1:
            printf("The lines are parallel.\n");
            break;
        case 2:
            printf("The lines are perpendicular.\n");
            break;
        case 3:
            printf("The lines are intersecting.\n");
            break;
        default:
            printf("Error in identifying the lines.\n");
    }
}

int main() {
    double m1, c1, m2, c2;

    // Input the equations of the first line
    printf("Enter the slope (m1) and y-intercept (c1) of the first line (y = m1*x + c1):\n");
    scanf("%lf %lf", &m1, &c1);

    // Input the equations of the second line
    printf("Enter the slope (m2) and y-intercept (c2) of the second line (y = m2*x + c2):\n");
    scanf("%lf %lf", &m2, &c2);

    // Check the relationship between the lines
    checkLines(m1, c1, m2, c2);

    return 0;
}

#include <stdio.h>

void findLargestAndSecondLargest(int arr[], int size, int *largest, int *secondLargest) {
    if (size < 2) {
        printf("Array must contain at least two elements.\n");
        return;
    }

    *largest = *secondLargest = -2147483648; // Initialize with the smallest possible integer value

    for (int i = 0; i < size; i++) {
        if (arr[i] > *largest) {
            *secondLargest = *largest; // Update second-largest
            *largest = arr[i];         // Update largest
        } else if (arr[i] > *secondLargest && arr[i] != *largest) {
            *secondLargest = arr[i];   // Update second-largest
        }
    }

    // Handle the case where all elements are the same
    if (*secondLargest == -2147483648) {
        printf("No distinct second-largest element found.\n");
    }
}

int main() {
    int arr[] = {203, 45, 1, 3, 200, 298};
    int size = sizeof(arr) / sizeof(arr[0]);
    int largest, secondLargest;

    findLargestAndSecondLargest(arr, size, &largest, &secondLargest);

    printf("Largest: %d\n", largest);
    if (secondLargest != -2147483648) {
        printf("Second-largest: %d\n", secondLargest);
    } else {
        printf("No distinct second-largest element found.\n");
    }

    return 0;
}

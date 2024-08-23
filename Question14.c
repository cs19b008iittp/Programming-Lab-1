#include <stdio.h>

// Function to rearrange the array based on the given condition
void rearrange(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int left = 2 * (i + 1);
        int right = left + 1;

        // Check if left child exists and if it's greater than the current element
        if (left < n && arr[i] < arr[left]) {
            int temp = arr[i];
            arr[i] = arr[left];
            arr[left] = temp;
        }
        
        // Check if right child exists and if it's greater than the current element
        if (right < n && arr[i] < arr[right]) {
            int temp = arr[i];
            arr[i] = arr[right];
            arr[right] = temp;
        }
    }
}

int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements
    printf("Enter %d distinct elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Rearrange the array
    rearrange(arr, n);

    // Output the rearranged array
    printf("The rearranged array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

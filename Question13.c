#include <stdio.h>

// Function to find the highest frequency element in an array
void findHighestFrequencyElement(int arr[], int size) {
    int freq[size];
    int maxFreq = 0;
    int highestFreqElement = arr[0];

    // Initialize frequency array
    for (int i = 0; i < size; i++) {
        freq[i] = -1; // Mark all elements as not counted yet
    }

    // Count frequencies of each element
    for (int i = 0; i < size; i++) {
        int count = 1;
        if (freq[i] == -1) { // If element is not counted
            for (int j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    freq[j] = 0; // Mark as counted
                }
            }
            // Update max frequency and element
            if (count > maxFreq) {
                maxFreq = count;
                highestFreqElement = arr[i];
            }
        }
    }

    // Print the result
    printf("Element: %d; Frequency: %d\n", highestFreqElement, maxFreq);
}

int main() {
    int arr[] = {1, 3, 5, 1, 7, 5, 4, 3, 1, 3, 5, 5, 4, 5, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    findHighestFrequencyElement(arr, size);

    return 0;
}

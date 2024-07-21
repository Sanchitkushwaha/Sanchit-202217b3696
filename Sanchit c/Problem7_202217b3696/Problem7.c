#include <stdio.h>

// Function to implement bubble sort
void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) { // Outer loop for all passes
        for (j = 0; j < n - i - 1; j++) { // Inner loop for comparison in each pass
            if (arr[j] > arr[j + 1]) { // Compare adjacent elements
                // Swap if the first element is greater than the second
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; // Unsorted array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements in the array
    bubble_sort(arr, n); // Call bubble sort function
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print sorted array
    }
    return 0;
}
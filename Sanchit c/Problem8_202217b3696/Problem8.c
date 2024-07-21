#include <stdio.h>

// Function to find the position of the smallest element in the subarray
int smallest(int arr[], int i, int n) {
    int pos = i;
    for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[pos]) {
            pos = j;
        }
    }
    return pos;
}

// Function to perform selection sort
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the smallest element in the remaining unsorted array
        int pos = smallest(arr, i, n);
        // Swap the found smallest element with the first element of the unsorted array
        if (pos != i) {
            int temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; // Unsorted array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements in the array
    selection_sort(arr, n); // Call selection sort function
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print sorted array
    }
    return 0;
}
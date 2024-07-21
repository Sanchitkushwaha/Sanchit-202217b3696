#include <stdio.h>

// Function to perform insertion sort
void insert(int a[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = a[i]; // Store the current element
        j = i - 1;

        // Move elements greater than temp to one position ahead
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp; // Insert the key in the correct position
    }
}

// Function to print the array
void printArr(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = { 12, 31, 25, 8, 32, 17 }; // Unsorted array
    int n = sizeof(a) / sizeof(a[0]); // Calculate number of elements in the array

    printf("Before sorting array elements are - \n");
    printArr(a, n);

    insert(a, n); // Call insertion sort function

    printf("After sorting array elements are - \n");
    printArr(a, n);

    return 0;
}
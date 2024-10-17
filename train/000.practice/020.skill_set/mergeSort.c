#include "stdio.h"
#include "stdbool.h"
#include "limits.h"
#include "math.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#include "sys/types.h"
#include "assert.h"

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp array
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Merge the temp arrays
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    // Copy the remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Finding mid element
        int m = l + (r - l) / 2;
        // Recursively sorting both the halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the array
        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }

    printf("\n");
}

int main() {
    int arr[] = {85, 24, 63, 45, 17, 31, 96, 50};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is n :");
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
    printf("nSorted array is n :");
    printArray(arr, arr_size);
    return 0;
}

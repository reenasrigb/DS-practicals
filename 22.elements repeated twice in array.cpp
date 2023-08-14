#include <stdio.h>

void removeDuplicates(int arr[], int size) {
    int i, j, k;
    
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                for (k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--;
                j--;
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 3, 5, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    removeDuplicates(arr, size);
    
    printf("\nArray after removing duplicates: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}


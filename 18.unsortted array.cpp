#include <stdio.h>

void displayMissingElement(int arr[], int size) {
    int max = arr[0];
    int min = arr[0];
 
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    int *present = (int *)calloc(max - min + 1, sizeof(int);
    
 
    for (int i = 0; i < size; i++) {
        present[arr[i] - min] = 1;
    }
    
    printf("Missing elements: ");
    for (int i = 0; i < max - min + 1; i++) {
        if (present[i] == 0) {
            printf("%d ", i + min);
        }
    }
    
    free(present);
}

int main() {
    int arr[] = {4, 2, 1, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    displayMissingElement(arr, size);
    
    return 0;
}


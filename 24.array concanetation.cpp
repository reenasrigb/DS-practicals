#include <stdio.h>

int main() {
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {6, 7, 8, 9, 10};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int newSize = size1 + size2;
    int newArray[newSize];

    for (int i = 0; i < size1; i++) {
        newArray[i] = array1[i];
    }

    for (int i = 0; i < size2; i++) {
        newArray[size1 + i] = array2[i];
    }

    printf("Concatenated Array: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", newArray[i]);
    }

    return 0;
}


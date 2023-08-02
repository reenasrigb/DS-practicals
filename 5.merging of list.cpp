#include <stdio.h>

void mergeLists(int list1[], int size1, int list2[], int size2, int mergedList[]) {
    int i = size1 - 1, j = size2 - 1, k = size1 + size2 - 1;

    while (i >= 0 && j >= 0) {
        if (list1[i] > list2[j]) {
            mergedList[k] = list1[i];
            i--;
        } else {
            mergedList[k] = list2[j];
            j--;
        }
        k--;
    }

    while (i >= 0) {
        mergedList[k] = list1[i];
        i--;
        k--;
    }

    while (j >= 0) {
        mergedList[k] = list2[j];
        j--;
        k--;
    }
}

int main() {
    int list1[] = {9, 7, 5, 3, 1};
    int size1 = sizeof(list1) / sizeof(list1[0]);

    int list2[] = {10, 8, 6, 4, 2};
    int size2 = sizeof(list2) / sizeof(list2[0]);

    int mergedList[size1 + size2];

    mergeLists(list1, size1, list2, size2, mergedList);

    printf("Merged List: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", mergedList[i]);
    }

    return 0;
}


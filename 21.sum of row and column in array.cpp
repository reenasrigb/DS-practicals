#include <stdio.h>

#define ROWS 3
#define COLS 3

void calculateSum(int arr[ROWS][COLS]) {
    int rowSum[ROWS] = {0};
    int colSum[COLS] = {0};

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            rowSum[i] += arr[i][j];
            colSum[j] += arr[i][j];
        }
    }

    printf("Sum of each row:\n");
    for (int i = 0; i < ROWS; i++) {
        printf("Row %d: %d\n", i + 1, rowSum[i]);
    }

    printf("Sum of each column:\n");
    for (int j = 0; j < COLS; j++) {
        printf("Column %d: %d\n", j + 1, colSum[j]);
    }
}

int main() {
    int arr[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    calculateSum(arr);

    return 0;
}


#include <stdio.h>

int search_reg_no(int reg_no_array[], int size, int target_reg_no) {
    for (int i = 0; i < size; i++) {
        if (reg_no_array[i] == target_reg_no) {
            return 1; // Found the registration number
        }
    }
    return 0; // Registration number not found
}

int main() {
    int registration_numbers[] = {101, 202, 303, 404, 505};
    int size = sizeof(registration_numbers) / sizeof(registration_numbers[0]);

    int target_registration_number = 303;

    if (search_reg_no(registration_numbers, size, target_registration_number)) {
        printf("Registration number %d found in the array.\n", target_registration_number);
    } else {
        printf("Registration number %d not found in the array.\n", target_registration_number);
    }

    return 0;
}


#include <stdio.h>


int square(int n) {
    return n * n;
}

int abs_difference(int x, int y) {
    if (x >= y) {
        return x - y;
    }

    return y - x;
}

long long to_binary(int decimal) {
    if (decimal == 1 || decimal == 0) {
        return decimal;
    }

    if (decimal == 2) {
        return 0;
    }

    int next_binary = to_binary(decimal / 2);
    int curr_binary = decimal % 2;

    return next_binary * 10 + curr_binary;
}

int largest_element(int *arr, int size) {
    int largest_element_index = 0;

    for (int i = 1; i < size; i++) {
        if (arr[largest_element_index] < arr[i]) {
            largest_element_index = i;
        }
    }

    return largest_element_index;
}


int main() {
    // This is The Solution of Question 2 of MCS 011 Problem Solving and Programming Assignment

    // Q2 (a)
    int squareOf5 = square(5);
    printf("Square of 5 is %d\n", squareOf5);
    int squareOf0 = square(0);
    printf("Square of 0 is %d\n", squareOf0);

    // Q2 (b)
    int x = 45, y = 130;
    int dif = abs_difference(x, y);
    printf("Difference between %d and %d is %d\n", x, y, dif);

    // Q2 (c)
    int binary_of_12 = to_binary(12); // 1100
    int binary_of_13 = to_binary(13); // 1101
    printf("binary_of_12 : %d \nbinary_of_13 : %d\n", binary_of_12, binary_of_13);

    // Q2 (d)
    int arr[] = {2, 5, 13, 7, 13, 1, 6};
    int max_index = largest_element(arr, sizeof(arr) / sizeof(int));
    printf("largest element is %d at index %d", arr[max_index], max_index);


    return 0;
}

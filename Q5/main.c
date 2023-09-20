#include <stdio.h>
#include <stdlib.h>

void print_message() {
    printf("Select an option:\n1. Print array\n2. Add element at the end\n3. Add element at a specific index\n0. Exit\n");
}

void print_wrong_input_message() {
    printf("Please enter a valid input\n");
}

void print_array(int *arr, int size) {
    printf("Elements currently present in the array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void add_element(int **arr, int *size, int new_element) {
    // reallocating memory for new big array 
    *arr = (int *)realloc(*arr, (*size + 1) * sizeof(int));
    (*arr)[*size] = new_element;
    (*size)++;
}

void insert_element(int **arr, int *size, int new_element, int index) {
    // this function will insert element at a specific position 
    if (index < 0 || index > *size) {
        printf("Error: Index out of range\n");
        return;
    }

    *arr = (int *)realloc(*arr, (*size + 1) * sizeof(int));

    for (int i = *size; i > index; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }

    (*arr)[index] = new_element;
    (*size)++;
}


int main() {
    // This is The Solution of Question 5 of MCS 011 Problem Solving and Programming Assignment
    int *arr = NULL;
    int size = 0;

    int index, elementToAdd;

    int choice = -1;

    while (choice != 0) {
        print_message();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (size == 0) {
                printf("There are 0 elements in the array\n\n");
                break;
            }

            print_array(arr, size);
            printf("\n");
            break;
        case 2:
            printf("Enter element to add : ");
            scanf("%d", &elementToAdd);
            printf("\n");

            add_element(&arr, &size, elementToAdd);
            printf("\nElement added successfully\n\n");
            break;
        case 3:
            printf("Enter element to add : ");
            scanf("%d", &elementToAdd);
            printf("\n");
            printf("Enter index : ");
            scanf("%d", &index);

            insert_element(&arr, &size, elementToAdd, index);
            printf("\nElement added successfully\n\n");
            break;
        case 0:
            printf("Thank you for using this tool\n");
            break;
        default:
            print_wrong_input_message();
            printf("\n");
        }
    }

    free(arr);


    return 0;
}

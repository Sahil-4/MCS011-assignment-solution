#include <stdio.h>


void print_menu() {
    // Function responsible to print the initial message/menu
    printf("Enter any number to continue \n1. Check equality of two numbers\n2. Check even or odd\n3. Check positive or negative numbers\n4. Quit\n\n");
}

void check_equality(int n1, int n2) {
    // Function responsible to check whether two numbers are equal or not
    n1 == n2 ? printf("Both numbers are equal\n") : printf("Both numbers are not equal\n");


    // here we're using equal to operator
    // to check whether the variable n1 and n2 has equal value or not
}

void check_even_odd(int n) {
    // Function to check whether the given number is odd or even
    n % 2 == 0 ? printf("Given number is even\n") : printf("Given number is odd\n");

    // here we're using modulo operator to get the remainder after dividing variable n by 2
    // then we're checking whether the remainder is equal to 0 or not
    // then if the remainder is equal to 0 we're printing "Given number is even"
    // if the remainder is not equal to 0 then we're printing "Given number is odd"
}

void check_positive_or_negative(int n) {
    // Function responsible to check whether the given number n is positive or negative
    n >= 0 ? printf("Given number is positive\n") :  printf("Given number is negative\n");

    // here we're checking whether the value of variable n is bigger then or equal to 0 is true or not
    // if it's true then we're printing "Given number is positive"
    // else we're printing "Given number is negative"
}

void print_wrong_input_message() {
    printf("Please enter correct input\n");
}


int main() {
    // This is The Solution of Question 1 of MCS 011 Problem Solving and Programming Assignment by Sahil (2300276879)
    int choice;

    while (choice != 4) {
        // printing menu
        print_menu();

        // taking input for choice
        scanf("%d", &choice);

        // for taking decision        
        switch (choice) {
            case 1: { // check equality of two numbers
                // initializing variable
                int x, y;

                // prompt for input
                printf("Enter two numbers : ");
                scanf("%d %d", &x, &y);

                // checking equality
                check_equality(x, y);
                break;
            }
            case 2: { // check even or odd
                //  initializing variable
                int evenOrOdd;

                // taking input
                printf("Enter a number : ");
                scanf("%d", &evenOrOdd);

                // checking for odd or even
                check_even_odd(evenOrOdd);
                break;
            }
            case 3: { // check positive or negative
                int posOrNeg;
                printf("Enter a number : ");
                scanf("%d", &posOrNeg);
                check_positive_or_negative(posOrNeg);
                break;
            }
            case 4:
                printf("Thank you for using this tool");
                break;
            default:
                print_wrong_input_message();
        }
        printf("\n\n");
    }


    return 0;
}

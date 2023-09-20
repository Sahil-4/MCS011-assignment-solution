#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int count_digit(int num) {
    // NOTE : This function is valid only for positive integers 
    if (num < 0) {
        return -1;
    }

    if (num < 10) {
        return 1;
    }

    return 1 + count_digit(num/10);
}

void reverse_string(char *str, int start_index, int last_index) {
    if (start_index == last_index || start_index < 0 || last_index < 0 || start_index > strlen(str) - 1 || last_index > strlen(str) - 1 || start_index >= last_index) {
        return;
    }

    char temp = str[start_index];
    str[start_index] = str[last_index];
    str[last_index] = temp;

    reverse_string(str, start_index+1, last_index-1);
}

int lcm(int n1, int n2) {
    if (n1 == n2) {
        return n1;
    }

    if (n1 == 0  || n2 == 0) {
        return 0;
    }

    if (n1 > n2) {
        return lcm(n1-n2, n2);
    }

    return lcm(n1, n2-n1);
}


int main() {
    // This is The Solutiion of Question 3 of MCS 011 Problem Solving and Programming Assignment 

    // Q3 (a)
    int count = count_digit(913);
    printf("Total digits : %d\n", count);

    // Q3 (b)
    char str[] = "ahplA";
    // char str[] = "ateb";
    reverse_string(str, 0, strlen(str) - 1);
    printf("%s\n", str);

    // Q3 (c)
    int x = 4,  y = 5;
    int lcmOfXY = lcm(x, y);
    printf("LCM of %d and %d is : %d", x, y, lcmOfXY);


    return 0;
}

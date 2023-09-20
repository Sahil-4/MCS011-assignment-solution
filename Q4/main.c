#include <conio.h>
#include <stdio.h>
#include <stdlib.h>


int string_length(char *str) {
    // Function to get length of string 
    int len = 0;

    while (str[len] != 0) {
        len++;
    }

    return len;
}

int compare_string(char *str, char *str2) {
    // Function to compare two strings 
    int i = 0, j = 0;

    while (str[i] != 0 || str2[j] != 0) {
        if (str[i++] != str2[j++]) {
            return 0;
        }
    }

    return 1;
}

struct counter {
    // Custom data structure to store count of vowel and consonent 

    int vowelCount;
    int consonantCount;
};


struct counter count_vowel_consonent(char *str) {
    // Function to compare two strings 
    struct counter ctr;
    ctr.vowelCount = ctr.consonantCount = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || 
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            ctr.vowelCount++;
        } else {
            ctr.consonantCount++;
        }

        i++;
    }

    return ctr;
}


int main() {
    // This is The Solutiion of Question 4 of MCS 011 Problem Solving and Programming Assignment 

    // Q4 (a)
    char str[] = "Alpha";
    int lenOfString = string_length(str);
    printf("Length of %s is %d\n", str, lenOfString);

    // Q4 (b)
    // char str2[] = "Alpha";
    char str2[] = "Alpha1";
    if (compare_string(str, str2)) {
        printf("Both strings are equal\n");
    } else {
        printf("Both strings are not equal\n");
    }

    // Q4 (c)
    struct counter ctr = count_vowel_consonent(str);
    printf("The string %s has %d vowels and %d consonents\n", str, ctr.vowelCount, ctr.consonantCount);


    return 0;
}

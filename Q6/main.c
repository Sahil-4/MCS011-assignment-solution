#include <stdio.h>

#define MAX_STUDENTS 10

// structure for student grade card
struct Student {
    int _id;
    char name[50];
    int roll_number;
    int marks_subject_computer_science;
    int marks_subject_mathematics;
    int total_marks;
    char grade;
};

// Function to calculate total marks and grades
void calculate_grades(struct Student students[]) {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        students[i].total_marks = students[i].marks_subject_computer_science + students[i].marks_subject_mathematics;

        if (students[i].total_marks >= 90)
            students[i].grade = 'A';
        else if (students[i].total_marks >= 80)
            students[i].grade = 'B';
        else if (students[i].total_marks >= 70)
            students[i].grade = 'C';
        else if (students[i].total_marks >= 60)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }
}

void print_pipes() {
    for (int i = 0; i < 45; i++) {
        printf("=");
    }
    printf("\n");
}


int main() {
    struct Student students[MAX_STUDENTS];

    // Input student data
    printf("Enter details for %d students:\n", MAX_STUDENTS);
    for (int i = 0; i < MAX_STUDENTS; i++) {
        students[i]._id = i;

        printf("Enter for Student %d\n", i + 1);
        printf("Name : ");
        scanf("%s", students[i].name);

        printf("Roll Number : ");
        scanf("%d", &students[i].roll_number);

        printf("Marks in Computer Science : ");
        scanf("%d", &students[i].marks_subject_computer_science);

        printf("Marks in Mathematics : ");
        scanf("%d", &students[i].marks_subject_mathematics);

        printf("\n");
    }

    // Calculate total marks and grades
    calculate_grades(students);

    // Display the mark-sheet and grade card
    print_pipes();
    printf("All Marksheets and Grade Cards : \n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        print_pipes();
        printf("ID : %d\n", students[i]._id);
        printf("Name : %s\n", students[i].name);
        printf("Roll Number : %d\n", students[i].roll_number);
        printf("Marks in Computer Science : %d\n", students[i].marks_subject_computer_science);
        printf("Marks in Mathematics : %d\n", students[i].marks_subject_mathematics);

        printf("Total Marks : %d\n", students[i].total_marks);
        printf("Grade : %c\n", students[i].grade);
        print_pipes();
        printf("\n");
    }


    return 0;
}

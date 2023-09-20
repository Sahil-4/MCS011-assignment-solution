#include <stdio.h>
#include <stdlib.h>


// Function to print the menu 
void print_menu() {
    printf("Select any option\n1. Print file\n2. Count line numbers\n3. Delete line\n4. Copy file to another file in another directory\n0. Exit\n");
}

// Function to print error message 
void print_wrong_input_message() {
    printf("Please enter a valid input\n");
}

// Function to print the contents of a file
void print_file_contents(FILE *fp) {
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    printf("\n");
}

// Function to find the number of lines in a text file
int find_number_of_lines(FILE *fp) {
    int count = 0;
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    return count;
}

// Function to delete a specific line from a text file
void delete_line(FILE *fp, int line_number) {
    FILE *temp_fp = fopen("temp.txt", "w");
    int count = 1;
    char ch;

    while ((ch = fgetc(fp)) != EOF) {
        if (count != line_number) {
            fputc(ch, temp_fp);
        }

        if (ch == '\n') {
            count++;
        }
    }

    fclose(fp);
    fclose(temp_fp);
    remove("data.txt");
    rename("temp.txt", "data.txt");
}


// Function to copy a file to another folder with a different file-name
void copy_file(FILE *source_fp, char *destination_folder, char *new_file_name) {
    char destination_path[100];
    snprintf(destination_path, sizeof(destination_path), "%s/%s", destination_folder, new_file_name);
    FILE *destination_fp = fopen(destination_path, "w");
    char ch;

    while ((ch = fgetc(source_fp)) != EOF) {
        fputc(ch, destination_fp);
    }

    fclose(source_fp);
    fclose(destination_fp);
}


int main() {
    FILE *fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    int choice = -1;

    while (choice != 0) {
        print_menu();

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_file_contents(fp);
                fseek(fp, 0, SEEK_SET);
                break;
            case 2: {
                int num_lines = find_number_of_lines(fp);
                fseek(fp, 0, SEEK_SET);
                printf("Number of Lines: %d\n", num_lines);
                break;
            }
            case 3: {
                int delete_line_number;
                printf("Enter the line number you want to delete: ");
                scanf("%d", &delete_line_number);
                delete_line(fp, delete_line_number);
                fp = fopen("data.txt", "r");
                break;
            }
            case 4: {
                char destination_folder[100];
                printf("Enter the destination folder: ");
                scanf("%s", destination_folder);

                char new_file_name[100];
                printf("Enter the new file name: ");
                scanf("%s", new_file_name);

                FILE *source_fp = fopen("data.txt", "r");
                copy_file(source_fp, destination_folder, new_file_name);
                printf("File copied successfully!\n");
                break;
            }
            case 0:
                printf("Exiting...\n");
                break;
            default:
                print_wrong_input_message();
                break;
        }
    }

    fclose(fp);


    return 0;
}

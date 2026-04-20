#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.txt"

struct Student {
    int id;
    char name[50];
    float marks;
};

void addStudent() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Student s;

    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf(" %[^
]", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, file);
    fclose(file);

    printf("Student added successfully!\n");
}

void viewStudents() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    struct Student s;
    printf("\n--- Student List ---\n");

    while (fread(&s, sizeof(s), 1, file)) {
        printf("ID: %d | Name: %s | Marks: %.2f\n", s.id, s.name, s.marks);
    }

    fclose(file);
}

void searchStudent() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    struct Student s;

    printf("Enter ID to search: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, file)) {
        if (s.id == id) {
            printf("Found: ID: %d | Name: %s | Marks: %.2f\n", s.id, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }

    fclose(file);
}

int main() {
    int choice;

    while (1) {
        printf("\n==== Student Management System ====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

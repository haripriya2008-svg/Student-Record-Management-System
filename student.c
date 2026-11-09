
#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float mark1, mark2, mark3;
};

struct Student s[50];
int count = 0;

void addStudent() {
    if (count >= 50) {
        printf("Student limit reached!\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &s[count].roll);

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", s[count].name);

    printf("Enter 3 Subject Marks: ");
    scanf("%f %f %f",
          &s[count].mark1,
          &s[count].mark2,
          &s[count].mark3);

    count++;

    printf("Student added successfully!\n");
}

void displayStudents() {
    int i;

    if (count == 0) {
        printf("No student records found!\n");
        return;
    }

    for (i = 0; i < count; i++) {
        float total = s[i].mark1 +
                      s[i].mark2 + s[i].mark3;

        printf("\nRoll Number: %d\n", s[i].roll);
        printf("Name: %s\n", s[i].name);
        printf("Total: %.2f\n", total);
        printf("Average: %.2f\n", total / 3);
    }
}

void searchStudent() {
    int roll, i, found = 0;

    printf("Enter Roll Number to Search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            printf("Student Found!\n");
            printf("Name: %s\n", s[i].name);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Student Not Found!\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n--- STUDENT MANAGEMENT SYSTEM ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                printf("Thank You!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}

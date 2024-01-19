// A student database program
// Allows to add,display and delete students

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
struct Student {
    int id;
    char name[50];
    int age;
};

// Function to add a new student
void addStudent(struct Student** database, int* numStudents) {
    // Increment the number of students
    (*numStudents)++;

    // Resize the database to accommodate the new student
    *database = realloc(*database, (*numStudents) * sizeof(struct Student));

    // Get information for the new student
    printf("Enter student ID: ");
    scanf("%d", &((*database)[*numStudents - 1].id));

    printf("Enter student name: ");
    scanf("%s", (*database)[*numStudents - 1].name);

    printf("Enter student age: ");
    scanf("%d", &((*database)[*numStudents - 1].age));

    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents(struct Student* database, int numStudents) {
    if (numStudents == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nID\tName\tAge\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
    }
}

// Function to delete a student
void deleteStudent(struct Student** database, int* numStudents, int idToDelete) {
    int found = 0;
    for (int i = 0; i < *numStudents; i++) {
        if ((*database)[i].id == idToDelete) {
            // Shift the remaining students to fill the gap
            for (int j = i; j < *numStudents - 1; j++) {
                (*database)[j] = (*database)[j + 1];
            }

            // Decrease the number of students
            (*numStudents)--;
            found = 1;
            break;
        }
    }

    if (found) {
        // Resize the database to free the memory of the deleted student
        *database = realloc(*database, (*numStudents) * sizeof(struct Student));
        printf("Student deleted successfully!\n");
    } else {
        printf("Student not found with ID %d.\n", idToDelete);
    }
}

int main() {
    struct Student* studentDatabase = NULL;
    int numStudents = 0;
    int choice, studentIdToDelete;

    // do {
    //     printf("\nStudent Database Management System\n");
    //     printf("1. Add Student\n");
    //     printf("2. Display Students\n");
    //     printf("3. Delete Student\n");
    //     printf("4. Exit\n");
    //     printf("Enter your choice: ");
    //     scanf("%d", &choice);

    //     switch (choice) {
    //         case 1:
    //             addStudent(&studentDatabase, &numStudents);
    //             break;
    //         case 2:
    //             displayStudents(studentDatabase, numStudents);
    //             break;
    //         case 3:
    //             printf("Enter the Student ID to delete: ");
    //             scanf("%d", &studentIdToDelete);
    //             deleteStudent(&studentDatabase, &numStudents, studentIdToDelete);
    //             break;
    //         case 4:
    //             printf("Exiting the program...\n");
    //             break;
    //         default:
    //             printf("Invalid choice. Please enter a valid option.\n");
    //     }

    // } while (choice != 4);
    addStudent(&studentDatabase,&numStudents);
    // Free dynamically allocated memory before exiting
    displayStudents(studentDatabase,numStudents);
    free(studentDatabase);

    return 0;
}

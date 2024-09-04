#include <stdio.h>
#include <string.h>
#include <cstdint>

typedef struct {
    char lastName[50];
    char firstName[50];
} Student;

int findStudent(Student students[], int size, const char* lastName, const char* firstName) {
    for (size_t i = 0; i < size; ++i) {
        if (strcmp(students[i].lastName, lastName) == 0 && strcmp(students[i].firstName, firstName) == 0) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    Student students[] = {
        {"Ivanov", "Ivan"},
        {"Petrov", "Petr"},
        {"Sidorov", "Sidr"}
    };

    int size = sizeof(students) / sizeof(students[0]);

    const char* searchFirstName = "Petr";
    const char* searchLastName = "Petrov";

    int index = findStudent(students, size, searchLastName, searchFirstName);

    if (index != -1) {
        printf("The student was found: %s %s\n", students[index].lastName, students[index].firstName);
    }
    else {
        printf("The student was not found.\n");
    }

    return 0;
}

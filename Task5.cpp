#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_FACULTY_LENGTH 100

typedef struct Student {
    char lastName[MAX_NAME_LENGTH];
    char firstName[MAX_NAME_LENGTH];
    int course;
    char faculty[MAX_FACULTY_LENGTH];
    struct Student* next;
} Student;

Student* createStudent(const char* lastName, const char* firstName, int course, const char* faculty) {
    Student* student = (Student*)malloc(sizeof(Student));
    strcpy(student->lastName, lastName);
    strcpy(student->firstName, firstName);
    student->course = course;
    strcpy(student->faculty, faculty);
    student->next = NULL;
    return student;
}

void printStudent(Student* student) {
    printf("Фамилия: %s\n", student->lastName);
    printf("Имя: %s\n", student->firstName);
    printf("Курс: %d\n", student->course);
    printf("Факультет: %s\n", student->faculty);
}

void addStudent(Student** head, Student* student) {
    if (*head == NULL) {
        *head = student;
    }
    else {
        Student* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = student;
    }
}

Student* findStudent(Student* head, const char* lastName, const char* firstName) {
    Student* current = head;
    while (current != NULL) {
        if (strcmp(current->lastName, lastName) == 0 && strcmp(current->firstName, firstName) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void freeList(Student* head) {
    Student* current = head;
    while (current != NULL) {
        Student* next = current->next;
        free(current);
        current = next;
    }
}

int main() {

    setlocale(LC_ALL, "Russian");

    Student* head = NULL;

    while (1) {
        char lastName[MAX_NAME_LENGTH];
        char firstName[MAX_NAME_LENGTH];
        int course;
        char faculty[MAX_FACULTY_LENGTH];

        printf("Введите фамилию студента (или '~' для завершения ввода): ");
        scanf("%s", lastName);
        if (strcmp(lastName, "~") == 0) {
            break;
        }

        printf("Введите имя студента: ");
        scanf("%s", firstName);
        printf("Введите курс студента: ");
        scanf("%d", &course);
        printf("Введите факультет студента: ");
        scanf("%s", faculty);

        Student* student = createStudent(lastName, firstName, course, faculty);
        addStudent(&head, student);
    }

    char searchLastName[MAX_NAME_LENGTH];
    char searchFirstName[MAX_NAME_LENGTH];

    printf("Введите фамилию студента для поиска: ");
    scanf("%s", searchLastName);
    printf("Введите имя студента для поиска: ");
    scanf("%s", searchFirstName);

    Student* foundStudent = findStudent(head, searchLastName, searchFirstName);

    if (foundStudent != NULL) {
        printf("Студент найден:\n");
        printStudent(foundStudent);
    }
    else {
        printf("Студент не найден.\n");
    }

    freeList(head);

    return 0;
}

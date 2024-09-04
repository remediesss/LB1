#if 0
//-----------TASK_1------------//
#include <cstdio>
#include <cstdint>
#include <climits>

int main() {

    uint32_t arr[] = { 1,2,3,4,5,6,7,8,9,10,213,12355,6,21 };
#define UINT32_MIN 0
    uint32_t max = UINT32_MIN;
#undef UINT32_MIN
    uint32_t min = UINT32_MAX;

    for (size_t i = 0; i < sizeof(arr) / 4; ++i) {
        if (min > arr[i]) { min = arr[i]; }
        if (max < arr[i]) { max = arr[i]; }
    }

    printf("%d\n", max);
    printf("%d\n", min);

    return 0;
}



//-----------TASK_2------------//
#include <cstdio>
#include <cstdint>
#include <climits>
#include <ctime>
#include <cstdlib>


int main() {

    uint32_t arr[20];
    //srand(time(NULL));
    for (size_t i = 0; i < sizeof(arr) / sizeof(uint32_t); ++i) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    return 0;
}



//-----------TASK_3------------//
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <climits>

int main() {

    uint32_t size;
    scanf("%d", &size);
    uint32_t* ptr_arr = (uint32_t*)malloc(size * sizeof(uint32_t));

    for (size_t i = 0; i < size; ++i) {
        scanf("%d", &ptr_arr[i]);
    }

    printf("\n\n\n");
    for (size_t i = 0; i < size; ++i) {
        printf("%d\n", ptr_arr[i]);
    }

    free(ptr_arr);

    return 0;
}



//-----------TASK_4------------//
#include <cstdio>
#include <cstdint>
#include <climits>
#include <ctime>
#include <cstdlib>

int main() {

    uint32_t arr[10][10];
    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            arr[i][j] = rand() % 250;
            printf("%u\t", arr[i][j]);

        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    printf("\n");

    uint32_t row_sum[10] = { 0 };
    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j)
            row_sum[i] += arr[i][j];
    }
    // Print all rows sums
    for (size_t i = 0; i < 10; ++i) {
        printf("%d\n", row_sum[i]);
    }

    printf("\n\n");

    // Print all cols sums
    uint32_t col_sum[10] = { 0 };
    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j)
            col_sum[j] += arr[i][j];
    }
    for (size_t i = 0; i < 10; ++i) {
        printf("%d\n", col_sum[i]);
    }

    return 0;
}

#endif



//-----------TASK_5------------//
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

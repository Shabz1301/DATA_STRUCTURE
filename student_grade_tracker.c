#include <stdio.h>

void insertionSort(float arr[], int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void displayGrades(float arr[], int n) {
    printf("Student Grades:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n\n");
}

int main() {
    float studentGrades[100];  // Assuming a maximum of 100 grades
    int n = 0;  // Number of grades entered

    while (1) {
        printf("1. Add Grade\n");
        printf("2. Display Grades\n");
        printf("3. Quit\n");

        int choice;
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the student's grade: ");
                scanf("%f", &studentGrades[n]);
                n++;
                insertionSort(studentGrades, n);
                printf("Grade added successfully!\n\n");
                break;
            case 2:
                displayGrades(studentGrades, n);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n\n");
        }
    }

    return 0;
}

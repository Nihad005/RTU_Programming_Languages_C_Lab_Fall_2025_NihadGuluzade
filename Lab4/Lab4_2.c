#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
    float grade;
};

int main() {
    struct Student s1, s2;

    printf("Enter first student name: ");
    fgets(s1.name, sizeof(s1.name), stdin);
    s1.name[strcspn(s1.name, "\n")] = 0;

    printf("Enter first student ID: ");
    scanf("%d", &s1.id);

    printf("Enter first student grade: ");
    scanf("%f", &s1.grade);

    getchar();

    printf("Enter second student name: ");
    fgets(s2.name, sizeof(s2.name), stdin);
    s2.name[strcspn(s2.name, "\n")] = 0;

    printf("Enter second student ID: ");
    scanf("%d", &s2.id);

    printf("Enter second student grade: ");
    scanf("%f", &s2.grade);

    printf("\nStudent 1: %s, ID: %d, Grade: %.1f\n", s1.name, s1.id, s1.grade);
    printf("Student 2: %s, ID: %d, Grade: %.1f\n", s2.name, s2.id, s2.grade);

    return 0;
}
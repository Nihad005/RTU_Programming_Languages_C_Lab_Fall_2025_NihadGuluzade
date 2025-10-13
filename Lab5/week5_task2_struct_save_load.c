#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float gpa;
};

int save_student(char *filename, struct Student s) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Could not open file to write.\n");
        return 1;
    }
    fprintf(f, "%s %d %.2f\n", s.name, s.age, s.gpa);
    fclose(f);
    return 0;
}

int load_student(char *filename, struct Student *s) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Could not open file to read.\n");
        return 1;
    }
    fscanf(f, "%s %d %f", s->name, &s->age, &s->gpa);
    fclose(f);
    return 0;
}

int main() {
    struct Student s1 = {"Alice", 21, 3.75};
    struct Student s2;
    char filename[] = "student.txt";

    printf("Saving student to file...\n");
    save_student(filename, s1);

    printf("Loading student from file...\n");
    load_student(filename, &s2);

    printf("Loaded student: %s, %d, GPA %.2f\n", s2.name, s2.age, s2.gpa);
    return 0;
}
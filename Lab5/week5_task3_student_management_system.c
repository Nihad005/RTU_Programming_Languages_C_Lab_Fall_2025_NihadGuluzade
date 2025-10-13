#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 200
#define NAME_LEN 50
#define DATA_FILE "students.txt"

struct Student {
    char name[NAME_LEN];
    int id;
    float gpa;
};

int load_students(char *filename, struct Student arr[], int *count);
int save_students(char *filename, struct Student arr[], int count);
void list_students(struct Student arr[], int count);
void add_student(struct Student arr[], int *count);

void trim_newline(char *s) {
    int n = strlen(s);
    if (n > 0 && s[n - 1] == '\n') s[n - 1] = '\0';
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    if (load_students(DATA_FILE, students, &count) != 0) {
        printf("No existing data. Starting fresh.\n");
        count = 0;
    }

    while (1) {
        printf("\n=== Student Management System ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");
        printf("Select an option: ");
        if (scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Try again.\n");
            continue;
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        if (choice == 1) {
            list_students(students, count);
        } else if (choice == 2) {
            add_student(students, &count);
        } else if (choice == 3) {
            save_students(DATA_FILE, students, count);
            printf("Data saved. Goodbye!\n");
            break;
        } else {
            printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}

int load_students(char *filename, struct Student arr[], int *count) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) return 1;

    char line[256];
    int loaded = 0;
    while (fgets(line, sizeof(line), f) != NULL) {
        struct Student s;
        if (sscanf(line, " %49[^|]|%d|%f", s.name, &s.id, &s.gpa) == 3) {
            if (loaded < MAX_STUDENTS) {
                arr[loaded++] = s;
            }
        }
    }
    fclose(f);
    *count = loaded;
    return 0;
}

int save_students(char *filename, struct Student arr[], int count) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Could not open file to save.\n");
        return 1;
    }
    for (int i = 0; i < count; i++) {
        fprintf(f, "%s|%d|%.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
    }
    fclose(f);
    return 0;
}

void list_students(struct Student arr[], int count) {
    if (count == 0) {
        printf("No students yet.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("%d. %s, ID: %d, GPA: %.2f\n", i + 1, arr[i].name, arr[i].id, arr[i].gpa);
    }
}

void add_student(struct Student arr[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("List is full.\n");
        return;
    }
    struct Student s;
    char buf[100];

    printf("Enter name: ");
    fgets(s.name, sizeof(s.name), stdin);
    trim_newline(s.name);

    printf("Enter ID: ");
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &s.id);

    printf("Enter GPA: ");
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%f", &s.gpa);

    arr[*count] = s;
    (*count)++;
    printf("Student added successfully!\n");
}
#include <stdio.h>

int main() {
    FILE *f;
    char line[200];
    char filename[] = "data.txt";

    printf("Writing lines to %s...\n", filename);
    f = fopen(filename, "w");
    if (f == NULL) {
        printf("Could not open file to write.\n");
        return 1;
    }
    fprintf(f, "Hello, file I/O in C!\n");
    fprintf(f, "This is another line.\n");
    fclose(f);

    printf("Reading contents:\n");
    f = fopen(filename, "r");
    if (f == NULL) {
        printf("Could not open file to read.\n");
        return 1;
    }
    while (fgets(line, sizeof(line), f) != NULL) {
        printf("%s", line);
    }
    fclose(f);

    return 0;
}
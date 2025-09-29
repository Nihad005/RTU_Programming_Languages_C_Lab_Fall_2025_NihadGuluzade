#include <stdio.h>

// Returns the number of characters in the string (excluding '\0')
int my_strlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Copies the string from src to dest (including the null terminator)
void my_strcpy(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

// Example usage
int main() {
    char text[] = "hello";
    int len = my_strlen(text);       // 5

    char buffer[100];
    my_strcpy(buffer, text);
    printf("Length: %d\n", len);
    printf("Copied string: %s\n", buffer); // hello

    return 0;
}
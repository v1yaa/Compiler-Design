#include <stdio.h>

int main() {
    char ch;
    int spaces = 0, newlines = 0;

    printf("Enter text (Press Ctrl+D to stop input in Linux/Mac, Ctrl+Z in Windows):\n");

    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\t') spaces++;
        if (ch == '\n') newlines++;
    }
    
    printf("Whitespaces: %d\nNewlines: %d\n", spaces, newlines);
    return 0;
}
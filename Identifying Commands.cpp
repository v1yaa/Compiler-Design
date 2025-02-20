#include <stdio.h>

int main() {
    int c, prev = 0;
    printf("Enter text (Press Ctrl+D to stop input in Linux/Mac, Ctrl+Z in Windows):\n");
    
    while ((c = getchar()) != EOF) {
        if (prev == '/' && c == '/') {
            printf("Single-line comment\n");
            while ((c = getchar()) != '\n' && c != EOF);
        } else if (prev == '/' && c == '*') {
            printf("Multi-line comment\n");
            while ((c = getchar()) != EOF) {
                if (c == '*' && (c = getchar()) == '/') break;
            }
        }
        prev = c;
    }
    
    return 0;
}
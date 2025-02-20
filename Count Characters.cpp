#include <stdio.h>
#include <ctype.h>

void count_elements(FILE *file) {
    char ch;
    int characters = 0, words = 0, lines = 0;
    int in_word = 0;
    
    while ((ch = fgetc(file)) != EOF) {
        characters++;
        if (ch == '\n') {
            lines++;
        }
        if (isspace(ch)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }
    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    count_elements(file);
    fclose(file);
    return 0;
}
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100

void analyze(const char *input) {
    char token[MAX_LEN];
    int i = 0, j = 0;

    while (input[i] != '\0') {
        if (isspace(input[i])) {
            i++;
            continue;
        }
        if (input[i] == '/') {
            if (input[i + 1] == '/') {
                while (input[i] != '\n' && input[i] != '\0') i++;
                continue;
            }
        }
        if (isalpha(input[i])) {
            while (isalnum(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            printf("Identifier: %s\n", token);
            j = 0;
        } else if (isdigit(input[i])) {
            while (isdigit(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            printf("Constant: %s\n", token);
            j = 0;
        } else {
            printf("Operator: %c\n", input[i]);
            i++;
        }
    }
}

int main() {
    const char *code = "int main() { // This is a comment\n int a = 5;\n return a; }";
    analyze(code);
    return 0;
}
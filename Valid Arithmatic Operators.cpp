#include <stdio.h>

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int main() {
    char input;
    printf("Enter a character: ");
    scanf(" %c", &input);

    if (isOperator(input))
        printf("'%c' is a valid arithmetic operator.\n", input);
    else
        printf("'%c' is NOT a valid arithmetic operator.\n", input);

    return 0;
}

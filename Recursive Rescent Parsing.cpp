#include <stdio.h>
#include <stdlib.h>

char *input; 
int pos = 0;

void match(char c) { 
    if (input[pos] == c) pos++; 
    else { 
        printf("Error at %c\n", input[pos]); 
        exit(1); 
    } 
}

void E(), T(), F();
void E() { T(); if (input[pos] == '+') { match('+'); E(); } }
void T() { F(); if (input[pos] == '*') { match('*'); T(); } }
void F() { 
    if (input[pos] == '(') { match('('); E(); match(')'); } 
    else if (input[pos] == 'i') match('i'); 
    else { 
        printf("Error at %c\n", input[pos]); 
        exit(1); 
    } 
}

int main() {
    char expr[100];
    scanf("%s", expr);
    input = expr;
    E();
    if (input[pos] == '\0') 
        printf("Parsing successful!\n"); 
    else 
        printf("Error at %c\n", input[pos]);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int temp_var_count = 1;

void generate_TAC(char *expr) {
    char op1, op2, oper;
    int i, len = strlen(expr);
    printf("Three Address Code:\n");
    
    for (i = 0; i < len; i++) {
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            op1 = expr[i - 1];
            op2 = expr[i + 1];
            oper = expr[i];
            printf("t%d = %c %c %c\n", temp_var_count, op1, oper, op2);
            expr[i - 1] = 't'; 
            expr[i] = '0' + temp_var_count; 
            expr[i + 1] = ' '; 
            temp_var_count++;
        }
    }
}

int main() {
    char expr[100];
    printf("Enter an arithmetic expression (e.g., a+b*c): ");
    scanf("%99s", expr);
    generate_TAC(expr);
    return 0;
}
#include <stdio.h>
#include <string.h>

void generate_assembly(char *tac[], int count) {
    printf("\nGenerated Assembly Code:\n");
    for (int i = 0; i < count; i++) {
        char op1[10], op2[10], res[10], op;
        if (sscanf(tac[i], "%s = %s %c %s", res, op1, &op, op2) == 4) {
            printf("MOV R0, %s\n", op1);
            switch (op) {
                case '+': printf("ADD R0, %s\n", op2); break;
                case '-': printf("SUB R0, %s\n", op2); break;
                case '*': printf("MUL R0, %s\n", op2); break;
                case '/': printf("DIV R0, %s\n", op2); break;
            }
            printf("MOV %s, R0\n", res);
        }
    }
}

int main() {
    char *tac[] = {
        "t1 = a + b",
        "t2 = c * d",
        "t3 = t1 - t2",
        NULL
    };
    
    printf("Three Address Code:\n");
    for (int i = 0; tac[i] != NULL; i++) {
        printf("%s\n", tac[i]);
    }
    
    generate_assembly(tac, 3);
    return 0;
}
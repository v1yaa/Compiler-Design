#include <stdio.h>
#include <string.h>
#define MAX_EXP 10

typedef struct { char expr[50], temp[10]; } Expr;

Expr exps[MAX_EXP];
int count = 0;
int find_expr(char *expr) {
    for (int i = 0; i < count; i++)
        if (!strcmp(exps[i].expr, expr)) return i;
    return -1;
}

void optimize(char *input[]) {
    for (int i = 0; input[i]; i++) {
        int idx = find_expr(input[i]);
        if (idx == -1) {
            snprintf(exps[count].temp, 10, "t%d", count + 1);
            strcpy(exps[count].expr, input[i]);
            printf("%s = %s\n", exps[count].temp, input[i]);
            count++;
        } else {
            printf("Using %s = %s\n", exps[idx].temp, exps[idx].expr);
        }
    }
}

int main() {
    char *input[] = {"a + b", "c + d", "a + b", "e * f", "c + d", NULL};
    printf("Optimized Code:\n");
    optimize(input);
    return 0;
}
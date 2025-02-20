#include <stdio.h>
#include <string.h>

void eliminateLeftRecursion(char nt, char alpha[], char beta[]) {
    printf("%c -> %s%c'\n%c' -> %s%c' | ε\n", nt, beta, nt, nt, alpha, nt);
}

int main() {
    char input[100], nt, alpha[100], beta[100];
    int i = 3, j = 0, k = 0;

    printf("Enter grammar (e.g., A->Aa|b): ");
    scanf("%s", input);
    
    nt = input[0];
    if (input[2] == nt) {
        while (input[i] != '|' && input[i] != '\0') alpha[j++] = input[i++];
        alpha[j] = '\0';
        if (input[i] == '|') while (input[++i] != '\0') beta[k++] = input[i];
        beta[k] = '\0';
        eliminateLeftRecursion(nt, alpha, beta);
    } else {
        printf("No left recursion detected: %s\n", input);
    }
    
    return 0;
}

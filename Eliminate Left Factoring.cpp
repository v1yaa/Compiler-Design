#include <stdio.h>
#include <string.h>

void leftFactor(char production[]) {
    char A = production[0]; 
    char alpha[10], beta[10];
    int i = 3, j = 0, k = 0;

    while (production[i] != '|' && production[i] != '\0') {
        alpha[j++] = production[i++];
    }
    alpha[j] = '\0';

    if (production[i] == '|') {
        i++; 
        while (production[i] != '\0') {
            beta[k++] = production[i++];
        }
        beta[k] = '\0';

        printf("%c -> %cX\n", A, A);
        printf("X -> %s | e\n", beta);
    } else {
        printf("No left factoring needed.\n");
    }
}

int main() {
    char production[50];

    printf("Enter a production (e.g., A->abc|abd): ");
    scanf("%s", production);

    leftFactor(production);
    return 0;
}
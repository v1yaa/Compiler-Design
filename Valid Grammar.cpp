#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidGrammar(char *str) {
    int len = strlen(str);
    if (!isupper(str[0])) return 0; 
    if (str[len - 1] != '.') return 0; 
    for (int i = 1; i < len - 1; i++) {
        if (!isalpha(str[i]) && str[i] != ' ') return 0; 
    }
    return 1;
}

int main() {
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; 
    
    if (isValidGrammar(str))
        printf("Valid sentence.\n");
    else
        printf("Invalid sentence.\n");
    
    return 0;
}
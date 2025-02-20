#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char *keywords[] = {"int", "float", "char", "double", "if", "else", "return", "for", "while"};

int isKeyword(char *word) { 
    for (int i = 0; i < 9; i++)
        if (!strcmp(word, keywords[i]))
            return 1;
    return 0;
}

int isValidIdentifier(char *id) {
    if (isKeyword(id) || !(isalpha(id[0]) || id[0] == '_')) 
        return 0;
    for (int i = 1; id[i]; i++)
        if (!isalnum(id[i]) && id[i] != '_')
            return 0;
    return 1;
}

int main() {
    char id[50];
    printf("Enter an identifier: ");
    scanf("%s", id);
    printf("\"%s\" is %svalid identifier.\n", id, isValidIdentifier(id) ? "" : "not a ");
    return 0;
}

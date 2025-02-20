#include <stdio.h>
#include <string.h>

struct Symbol { char name[50], type[10]; } table[100];
int count = 0;

int search(char *name) {
    for (int i = 0; i < count; i++)
        if (!strcmp(table[i].name, name)) return i;
    return -1;
}

void insert(char *name, char *type) {
    if (search(name) == -1 && count < 100) {
        strcpy(table[count].name, name);
        strcpy(table[count++].type, type);
        printf("Inserted: %s, %s\n", name, type);
    } else printf("Symbol exists or table full\n");
}

int main() {
    insert("x", "int"); insert("y", "float"); insert("x", "char");
    for (int i = 0; i < count; i++) printf("%s : %s\n", table[i].name, table[i].type);
    return 0;
}

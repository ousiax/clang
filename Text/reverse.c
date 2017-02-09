#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

int main()
{
    char *s = malloc(MAX_SIZE);
    int i, ch, len;
    fgets(s, MAX_SIZE, stdin);
    if (strlen(s) > 0 && s[strlen(s) - 1] == '\n') {
        s[strlen(s) - 1] = '\0';
    }
    printf("%s\n", s);

    len = strlen(s);
    for (i = 0; i < len / 2; i++) {
        ch = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = ch;
    }
    printf("%s\n", s);

    free(s);

    exit(0);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void comb(const char *s, const char *bef) {
    if (*s == 0) {
        printf("\"%s\"\n", bef);
        return;
    }
    char *next = (char *) malloc(strlen(bef) + 2);
    strcpy(next, bef);
    int n = strlen(bef);
    next[n+1] = 0;
    next[n] = *s;
    comb(s+1, bef);
    comb(s+1, next);
    free(next);
}

int main(int argc, char **argv) {
    if (argc > 2) {
        printf("Usage: %s [str]\n", argv[0]);
        exit(1);
    }

    char *s = "string";
    if (argc > 1) s = argv[1];

    comb(s, "");
}



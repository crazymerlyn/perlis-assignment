#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc > 2) {
        printf("Usage: %s [n]\n", argv[0]);
        exit(1);
    }

    long n = 10;
    if (argc > 1) n = atoi(argv[1]);

    int *is_prime = (int*) malloc(sizeof(int) * (n+1));
    for (long i = 2; i <= n; i++) {
        is_prime[i] = 1;
    }

    for (long i = 2; i <= n; i++) {
        if (!is_prime[i]) continue;
        for (long j = i*i; j <= n; j += i) is_prime[j] = 0;
    }

    for (long i = 2; i <= n; ++i) {
        if (is_prime[i]) printf("%ld\n", i);
    }

    free(is_prime);
}


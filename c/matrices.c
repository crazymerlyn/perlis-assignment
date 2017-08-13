#include <stdio.h>
#include <stdlib.h>

double *mat_mul(double *a, double *b, int m, int k, int n) {
    double *c = malloc(sizeof(double) * m * n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i*m + j] = 0;
            for (int id = 0; id < k; ++id) {
                c[i*m + j] += a[i*m + id] * b[id*k + j];
            }
        }
    }
    return c;
}

void mat_print(double *mat, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%lf ", mat[i*m+j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    int m = 2, k = 2, n = 2;
    double a[] = {1, 1, 1, 0};
    double b[] = {1, 1, 1, 0};
    void *c = mat_mul(a, b, m, k, n);
    mat_print(c, m, n);
    free(c);
}


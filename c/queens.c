#include <stdio.h>
#include <stdlib.h>

void print_ans(int ans[]) {
    for (int i = 0; i < 8; ++i) {
        for(int j = 1; j < ans[i]; j++) printf(".");
        printf("X");
        for(int j = ans[i]+1; j < 9; j++) printf(".");
        printf("\n");
    }
    printf("\n");
}

int check(int ans[], int i) {
    for (int j = 0; j < i; ++j) {
        if (ans[j] == ans[i]) return 0;
        if (abs(ans[j] - ans[i]) == abs(j - i)) return 0;
    }
    return 1;
}

void solve8queens(int ans[], int i) {
    if (i == 8) {
        print_ans(ans);
        return;
    }
    for (int j = 1; j <= 8; ++j) {
        ans[i] = j;
        if (check(ans, i)) {
            solve8queens(ans, i + 1);
            for (int k = i; k < 8; ++k) ans[k] = 0;
        }
    }
}

int main(int argc, char **argv) {
    int ans[8] = {0};
    solve8queens(ans, 0);
}



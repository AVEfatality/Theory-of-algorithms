#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name;
    int lenght;
    int value;
} piece_t;

piece_t pieces[] = {
    {'1', 9, 150},
    {'2', 13, 35},
    {'3', 153, 200},
    {'4', 50, 160},
    {'5', 15, 60},

};

int *kernel (piece_t *pieces, int n, int w) {
    int i, j, a, b, *mm, **m, *s;
    mm = calloc((n + 1) * (w + 1), sizeof (int));
    m = malloc((n + 1) * sizeof (int *));
    m[0] = mm;
    for (i = 1; i <= n; i++) {
        m[i] = &mm[i * (w + 1)];
        for (j = 0; j <= w; j++) {
            if (pieces[i - 1].lenght > j) {
                m[i][j] = m[i - 1][j];
            }
            else {
                a = m[i - 1][j];
                b = m[i - 1][j - pieces[i - 1].lenght] + pieces[i - 1].value;
                m[i][j] = a > b ? a : b;
            }
        }
    }
    s = calloc(n, sizeof (int));
    for (i = n, j = w; i > 0; i--) {
        if (m[i][j] > m[i - 1][j]) {
            s[i - 1] = 1;
            j -= pieces[i - 1].lenght;
        }
    }
    free(mm);
    free(m);
    return s;
}

int main () {
    int i, n, tw = 0, tv = 0, *s;
    n = sizeof (pieces) / sizeof (piece_t);
    s = kernel(pieces, n, 50);
    for (i = 0; i < n; i++) {
        if (s[i]) {
            printf("%c %d %d\n", pieces[i].name, pieces[i].lenght, pieces[i].value);
            tw += pieces[i].lenght;
            tv += pieces[i].value;
        }
    }
    printf("total: %d %d\n",tw, tv);
    return 0;
}

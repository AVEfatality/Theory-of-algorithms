#include <stdio.h>
#include <stdlib.h>
int count = 0;
void solve(int n, int col, int *a)
{
    int i,j;
	if (col == n) {
		printf("\nNUMBER %d\n-----\n", ++count);
		for ( i = 0; i < n; i++)
            putchar('\n');
			for ( j = 0; j < n; j++)
				putchar(j == a[i] ? '1' :'0');

		return;
	}

	for ( i = 0, j = 0; i < n; i++) {
		for (j = 0; j < col && !(a[j] == i || abs(a[j] - i) == col - j); j++);
		if (j < col) continue;

		a[col] = i;
		solve(n, col + 1, a);
	}
}

int main()
{
	int const n = 8;
	int a[n];
	solve(n, 0, a);
	return 0;
}

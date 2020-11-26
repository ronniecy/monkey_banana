// 100 monkeys, 100 bananas. Every big monkey takes 3 bananas; every
// normal monkeys take 2 bananas, and every two small monkeys take 1
// banana. Question: how many big, normal and small monkeys?

#include <stdio.h>
#include <string.h>

#define MONKEY_TOTAL 100
#define BANANA_TOTAL 100

void prt_solution(int *s, int r, int c)
{
	int *n = s;
	int i, h = 1;
	for (i = 0; i < r * c; ++i) {
		if ((i%c) == 0 && *n)
			printf("\n%d: ", h++);
		if (*n == 0 && (i%c == 0))
			break;
		printf("%d ", *n++);
	}
}

void main()
{
	int x = 0, y = 0, z = 0, i = 0;
	int row = 10;
	int solution[row][3];
	int *s = &solution[0][0];
	memset(s, 0 , sizeof(int) * row * 3);

	i = 0;
	for (x = MONKEY_TOTAL; x >= 0; x--) {
		for (y = (MONKEY_TOTAL - x); y >= 0; y--) {
			z = MONKEY_TOTAL - x - y;
			if ((z%2 == 0) &&
			    ((3*x + 2*y + (z/2)) == BANANA_TOTAL) &&
			    ((x + y + z) == MONKEY_TOTAL)) {
				solution[i][0] = x;
				solution[i][1] = y;
				solution[i++][2] = z;
				if (i == (row-1))
					goto out;
			}
		}
	}

out:
	s = &(solution[0][0]);
	prt_solution(s, row, 3);
}
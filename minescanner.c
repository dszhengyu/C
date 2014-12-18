#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define N 5 //define N * N matrix

struct puzzle
{
	int mine;
	int around;
	int discovery;
} puzzle[N][N];

void generate(void);
void printCurrent(void);
void printAll(void);
int win(void);

int main(void)
{
	int i, j;
	generate();
	printCurrent();
	printAll();
	while (1)
	{
		printf("input the unit you want to scanner (format: N, N) (eg: 3, 3):\n");
		scanf("%d, %d", &i, &j);
		printf("your input is: %d, %d\n", i, j);
		if ((i > 0 && i <= N && j > 0 && j <= N) == 0) {
			printf("wrong, input again!\n");
			i = j = 0;
			continue;
		}

		i--;
		j--;
		puzzle[i][j].discovery = 1;
		if (puzzle[i][j].mine) {
			printf("BOMB!!!\n");
			printAll();
			break;
		}
		else {
			printCurrent();
		}
		if (win()) {
			printf("You Win!\n");
			printAll();
			break;
		}

	}

	return 0;
}

void generate(void)
{
	int k, i, j;
	//initialize
	for (i = 0; i < N / 2; i++)
		for (j = 0; j < N; j++) {
			puzzle[i][j].mine = 0;
			puzzle[i][j].around = 0;
			puzzle[i][j].discovery = 0;
		}
	//set mine
	for (k = 0; k < N;)
	{
		srand(time(NULL));
		i = rand() % N;
		j = rand() % N;
		if (puzzle[i][j].mine)
			continue;
		puzzle[i][j].mine = 1;
		k++;
	}
	//count the mine around
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			if (puzzle[i][j].mine) {
				if ((j - 1) >= 0)
					puzzle[i][j - 1].around++;
				puzzle[i][j].around++;
				if ((j + 1) < N)
					puzzle[i][j + 1].around++;
				if ((i - 1) >= 0) {
					if ((j - 1) >= 0)
					puzzle[i - 1][j - 1].around++;
					puzzle[i - 1][j].around++;
					if ((j + 1) < N)
					puzzle[i - 1][j + 1].around++;
				}
				if ((i + 1) < N) {
					if ((j - 1) >= 0)
					puzzle[i + 1][j - 1].around++;
					puzzle[i + 1][j].around++;
					if ((j + 1) < N)
					puzzle[i + 1][j + 1].around++;
				}
			}

		}
}

void printCurrent(void)
{
	int i, j;
	for (i = 0; i < N; i++) {
		for(j = 0; j < N; j ++) {
			if (puzzle[i][j].discovery == 1) {
				if (puzzle[i][j].mine == 1)
					printf("%3d  ", -1);
				else
					printf("%3d  ", puzzle[i][j].around);
			}
			else 
				printf("  *  ");
		}
		putchar('\n');
	}
}

void printAll(void)
{
	int i, j;
	for (i = 0; i < N; i++) {
		for(j = 0; j < N; j ++) {
			if (puzzle[i][j].mine)
				printf("%5d", -1);
			else
				printf("%5d", puzzle[i][j].around);			
		}
		putchar('\n');
	}
}

int win(void)
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			if (puzzle[i][j].mine == 0)
				if (puzzle[i][j].discovery == 1)
					;
				else
					return 0;
		}
	return 1;
}
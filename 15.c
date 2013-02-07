/*
 *
Starting in the top left corner of a 22 grid, there are 6 routes (without backtracking) to the bottom right corner.


How many routes are there through a 2020 grid?
*/ 

#include <stdio.h>

int main()
{
	unsigned long long grid[21][21];
	int i, j;

	memset(grid, 0, sizeof(unsigned long long) * 21 * 21);

	grid[0][0] = 0;

	for(i=1; i<21;i++)
		grid[i][0] = 1;

	for(j=1; j<21;j++)
		grid[0][j] = 1;
		

#if 0
	for(i=0; i<21;i++)
	{
		for(j=0; j<21;j++)
			printf("%2lld ", grid[i][j]);

		printf("\n");

	}
	printf("------------------------\n\n");
#endif

	for(i=1; i<21;i++)
	{
		for(j=1; j<21;j++)
			grid[i][j] = grid[i][j-1] + grid[i-1][j];
	}
		
	//printf("------------------------\n\n");
	for(i=0; i<21;i++)
	{
		for(j=0; j<21;j++)
			printf("%14lld, ", grid[i][j]);

		printf("\n");
	}

		
}

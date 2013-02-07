/*
 *
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

#define SIZE 1001

enum state
{
	CENTRE,
	DOWN,
	LEFT,
	UP,
	RIGHT
};

#include <stdio.h>

int main()
{
	//int grid[SIZE][SIZE];
	int row, col;
	int elements = 1;
	int state = CENTRE;
	int step_size = 1;
	int step_count = 0;
	int *grid;

	grid = malloc(sizeof(int)*SIZE*SIZE);

	row = SIZE/2;
	col = SIZE/2;

	memset(grid, 0, sizeof(int)*SIZE*SIZE);

	while(elements <= (SIZE*SIZE))
	{
		//printf("\n Adding into (%d, %d) = %d", row, col, elements);
		//grid[row][col] = elements++;
		*(grid + (row*SIZE+col)) = elements++;
		step_count++;

		if(step_count == step_size)
		{
			//printf("SC");
			step_count = 0;
			switch(state)
			{
				case CENTRE: 
					state = DOWN; 
					col = col + 1;
					step_size = 2;
					continue;
					break;
				case DOWN: 
					state = LEFT; 
					break;
				case LEFT: 
					state = UP; 
					break;
				case UP: 
					state = RIGHT; 
					break;
				case RIGHT: 
					state = DOWN; 
					col = col + 1;
					step_size += 2;
					continue;
					break;
			}
		}

		switch(state)
		{
			case DOWN: 
				row = row + 1;
				break;
			case LEFT: 
				col = col - 1;
				break;
			case UP: 
				row = row - 1;
				break;
			case RIGHT: 
				col = col + 1;
				break;
		}


	}


	for(row=0;row<SIZE;row++)
	{
		printf("\n");
		for(col=0;col<SIZE;col++)
		{
			//printf("%4d ,", grid[row][col]);
			printf("%4d ,", *(grid + (row*SIZE+col)));

		}
	}

	printf("\n");
	unsigned long long sum = 0;

	for(row=0;row<SIZE;row++)
	{
		for(col=0;col<SIZE;col++)
		{
			if(row == col || (row+col)==SIZE-1)
			{
				printf("\n Adding (%d,%d) = %d", row, col, *(grid + (row*SIZE+col)));
				sum += *(grid + (row*SIZE+col));
			}
		}
	}
	printf("\n Result = %lld", sum);

}


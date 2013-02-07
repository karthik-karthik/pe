/*
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p  1000, is the number of solutions maximised?
*/

#include <stdio.h>
#define TOTAL 1000

struct int_triangle 
{
	int num;
	int count;
};

int main()
{
	int i, j;
	int square_array[TOTAL];
	int count = 0;
	struct int_triangle int_right_triangle[TOTAL+1];
	memset(int_right_triangle, 0, sizeof(struct int_triangle)*(TOTAL+1));
	

	for(i=0;i<TOTAL;i++)
		square_array[i] = (i+1) * (i+1);

	int temp;
	int flag, k;
	for(i=0;i<TOTAL;i++)
	{
		for(j=0;j<TOTAL;j++)
		{
			if(i+j <= 1000)
			{
				temp = square_array[i] + square_array[j];
				flag = 0;

				for(k=0;k<TOTAL;k++)
				{
					if(temp == square_array[k])
					{
						flag = k;
						break;
					}
				}

				if(flag != 0)
				{
					//printf("\n Found one sequence: %d, %d, %d", i+1, j+1, k+1);
					if(i+j+k+3 <= 1000) 
					{
						//printf("\n FOUND THE SEQUENCE summing upto 1000");
						printf("\n Found one sequence: %d, %d, %d", i+1, j+1, k+1);
						//printf("\n Product = %d", (i+1)*(j+1)*(k+1));
						int_right_triangle[i+j+k+3].num=i+j+k+3;
						int_right_triangle[i+j+k+3].count++;
						count++;
					}
				}
			}

		}
	}
	printf("\n The total number of elements = %d", count);

	int max = 0;
	int pos = 0;
	for(i=0;i<TOTAL+1;i++)
	{
		if(int_right_triangle[i].num != 0)
		{
			printf("\n Sum = %d, Count = %d", int_right_triangle[i].num, int_right_triangle[i].count);
			if(int_right_triangle[i].count > max)
			{
				max = int_right_triangle[i].count;
				printf("\n New max");
				pos = i;
			}
		}
	}
	printf("\n %d Sum repeats %d times", int_right_triangle[pos].num, int_right_triangle[pos].count);

}

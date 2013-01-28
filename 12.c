/* 
 *
The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

 1: 1
 3: 1,3
 6: 1,2,3,6
10: 1,2,5,10
15: 1,3,5,15
21: 1,3,7,21
28: 1,2,4,7,14,28
We can see that 28 is the first triangle number to have over five divisors.

What is the value of the first triangle number to have over five hundred divisors?
*/

#include <stdio.h>

int main()
{
	int i, j;
	int triangle_number;
	int total_divisors;

	for(i=1;i<100000000;i++)
	{
		triangle_number = (i * (2+(i-1)))/2;
		//printf("\n Number = %d, Triangle number = %d : ", i, triangle_number);

		total_divisors = 0;
		for(j=1;j<=triangle_number;j++)
		{
			if((triangle_number % j) == 0)
			{
			//	printf(" %d,", j);
				total_divisors++;
			}
		}
		if(i%100 == 0)
			printf("\n Processing %d", i);
		//printf(".... Total divisors = %d", total_divisors);
		if(total_divisors >= 500)
		{
			printf("\n Number = %d, Triangle number = %d : ", i, triangle_number);
			printf(".... Total divisors = %d", total_divisors);
			return;
		}
	}
}

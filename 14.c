/*
 *
The following iterative sequence is defined for the set of positive integers:

n  n/2 (n is even)
n  3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13  40  20  10  5  16  8  4  2  1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <stdio.h>

int main()
{
	unsigned long long seed = 113383;
	unsigned long long number;
	int count;
	int max_count = 0;
	unsigned long long max_seed;

	for(seed=1; seed<1000000;seed++)
	{
		number = seed;
		count = 1;
		//printf("\n %lldd ", number);
		while(number != 1)
		{
			if(number % 2 == 0)
			{
				number = number/2;
			}
			else
			{
				number = 3*number + 1;
			}

			count++;
			//printf(" --> %lld ", number);
		}
		if(seed % 1000 == 0)
			printf("\n Number = %lld, Total elements in Collatz is %d", seed, count);
		if(max_count < count)
		{
			printf("\n Seed = %lld has %d elements", seed, count);
			max_count = count;
			max_seed = seed;
		}
	}
}

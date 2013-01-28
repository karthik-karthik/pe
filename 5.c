/* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <stdio.h>
#include <malloc.h>

void print_array(int *array, int size)
{
	int i = 0;
	while(i!= size)
	{
		printf("\n array[%d] = %d", i, array[i]);
		i++;
	}
}
int check_prime(int a)
{
   int c;
 
   for ( c = 2 ; c <= a - 1 ; c++ )
   { 
      if ( a%c == 0 )
	 return 0;
   }
   if ( c == a )
      return 1;
}
int main()
{
	int *array;
	int number;
	int i,j;
	int temp;
	int product = 1;
	int found = 0;

	printf("\n Enter the number for which you need to compute the LCM");
	scanf("%d", &number);

	array = (int *)malloc(sizeof(int) * number);

	/* Initialize */
	for(i=0; i<number; i++)
	{
		array[i] = i+1;
	}

	print_array(array, number);

	do
	{
		temp=0;


		for(j=2; j<=number; j++)
		{
			found = 0;
			if(check_prime(j) == 0)
			{
				//printf("\n %d is not prime", j);
				continue;
			}
			for(i=0; i<number; i++)
			{
				if((array[i] % j) == 0)
				{
					array[i] = array[i] / j;
					found = 1;
				}
			}

			if(found == 1)
			{
				product *= j;
				printf("\n j = %d", j);
			}
			//printf("\n****** Iteration = %d", j);
			//print_array(array, number);
		}


		for(i=0; i<number; i++)
		{
			if(array[i] != 1)
			{
				temp++;
			}
		}
	}while(temp != 0);

	print_array(array, number);
	printf("\n Product = %d", product);


}

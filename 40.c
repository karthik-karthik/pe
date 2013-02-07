/*
An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1  d10  d100  d1000  d10000  d100000  d1000000
*/

#include<stdio.h>

int main()
{
	int i;
	int count = 1;
	int number, rem;
	int stack[10];
	int stack_ptr = 0;

	memset(stack, 0, sizeof(int)*10);

	for(i=1;i<1000000;i++)
	{
		number = i;
		//printf("\n Processing number = %d", i);

		stack_ptr = 0;
		do
		{
			//printf("\n        +%d  number=%d ", stack_ptr, number);
			stack[stack_ptr++] = number%10;
			if(number%10 == 0)
			{
				number = number/10;
			}
			else
			{
				number = number - (number%10);
				number = number/10;
			}
		}while(number != 0);

		while(stack_ptr != 0)
		{
			//printf("\n         -%d", (stack_ptr-1));
			int new_no = stack[--stack_ptr];
			if(count == 1 || count == 10 || count == 100 || count == 1000 || count == 10000 || count == 100000 || count == 1000000)
				printf("\n Number[%d] = %d", count, new_no);
			count++;
		}

	}
}

/* A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>
#include <unistd.h>

int reverse_number(int num)
{
	int reverse = 0;
	int array[10];
	int i;

	memset(array, 0, sizeof(int)* 10);

	//printf("\n Num = %d, reverse = %d", num, reverse);
	while(num/10 != 0)
	{
		reverse += num%10;	
		//printf("\n 2. Num = %d, reverse = %d", num, reverse);
		num = num/10;
		reverse = reverse*10;
		//printf("\n 4. Num = %d, reverse = %d", num, reverse);
	}
	reverse += num;

	//printf("\n Reverse = %d", reverse);
	return reverse;
}

int main()
{
        int i = 10000;
        int sum = 0;
	int reverse;
	int max = 0;
	int count = 0;

        for(;i<=99999;i++)
        {
		reverse = reverse_number(i);
                if(i == reverse)
                {
                        printf("\n Palindrome found %d", i);
			count++;
                }
        }
	printf("\n Count = %d", count);
	return;

	int j=100, k=100;
	for(j=100;j<1000;j++)
	{
		for(k=100;k<1000;k++)
		{
			int mult = j*k;

			if(mult == reverse_number(mult))
			{
				printf("\n Hurray palindrome found = %d", mult);

				if(mult > max)
				{
					max = mult;
				}
			}
		}
	}
	printf("\n The highest number is %d", max);
}


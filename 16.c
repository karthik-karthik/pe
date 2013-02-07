#include <stdio.h>

#define LENGTH (1000+1)
#define NUMBER 2
#define POWER 1000

int main()
{
	int i=0;
	int num;
	int offset;
	int product, carry;
	char array[LENGTH];
	int sum = 0;

	memset(array, 0, sizeof(char) * LENGTH);

	array[0]=1;

	printf("\n ----------");
	for(i=0;i<POWER;i++)
	{
		printf("%d ", (array[i]));
	}
	printf("\n ----------");

	for(i=0;i<POWER;i++)
	{
		offset = 0; carry = 0;
		printf("\n Operating on %d at offset %d", (array[offset]), offset);
		while(array[offset] != 0 || carry != 0)
		{
			//printf("\n Operating on %d at offset %d", (array[offset] - 0x30), offset);
			num = array[offset];
			if(num == 0xa)
				num = 0;
			num = num * 2 + carry;
			if(num >= 10)
			{
				carry = 1;
				product = (num%10);
			}
			else
			{
				carry = 0;
				product = num;
			}

			if(product == 0)
				product = 0xa;
			array[offset++] = product;
			printf("\n Post-operation %d at offset = %d", (array[offset-1]), offset);
		}
	}

	i=0;
	while(i<offset)
	{
		if(array[i] == 0xa) array[i] = 0;
		i++;
	}
	printf("\n");
	while(offset>0)
	{
		printf("%d", (array[offset-1]));
		sum+=array[offset-1]; 
		offset--;
	}
	printf("\n --- \n");
	printf("\n Sum of digits = %d", sum);
#if 0
		num *= 2;

		temp = num;
		sum = 0;
		while(temp != 0)
		{
			sum += temp % 10;
			temp = temp/10;

		}
		printf("\n Num = %d, Sum = %d", num, sum);
#endif

}

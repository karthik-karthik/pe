/* A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,

a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <stdio.h>
#define TOTAL 1000

struct ptp
{
	int a;
	int b;
	int c;
};

int main()
{
	struct ptp pt[TOTAL];
	int read_index = 0;
	int write_index = 1;
	int i, j;
	int square_array[TOTAL];
	
#if 0
	int f[TOTAL];
	f[0] = 0;
	f[1] = 1;
	for(i=2; i<TOTAL; i++)
	{
		f[i] = f[i-2]+f[i-1];
	}
	for(i=0; i<TOTAL; i++)
	{
		printf("%d ", f[i]);
	}

	memset(&pt, 0, sizeof(struct ptp) * 20);

	pt[3].a = 4;
	pt[3].b = 3;
	pt[3].c = 5;


	for(i=4; i<10; i++)
	{
		pt[i].a = pt[i-1].a + pt[i-1].b + pt[i-1].c;
		pt[i].b = f[2*i-1-1] - pt[i-1].b;
		pt[i].c = f[2*i-1];
	}
#endif


#if 0
/* 
T1:	a - 2b + 2c	2a - b + 2c	2a - 2b + 3c
T2:	a + 2b + 2c	2a + b + 2c	2a + 2b + 3c
T3:	-a + 2b + 2c	-2a + b + 2c	-2a + 2b + 3c
*/
	memset(&pt, 0, sizeof(struct ptp)*TOTAL);
	pt[read_index].a = 3;
	pt[read_index].b = 4;
	pt[read_index].c = 5;


	while(write_index < (TOTAL-3))
	{
		pt[write_index].a = pt[read_index].a - 2*pt[read_index].b + 2*pt[read_index].c;
		pt[write_index].b = 2*pt[read_index].a - pt[read_index].b + 2*pt[read_index].c;
		pt[write_index++].c = 2*pt[read_index].a - 2*pt[read_index].b + 3*pt[read_index].c;

		pt[write_index].a = pt[read_index].a + 2*pt[read_index].b + 2*pt[read_index].c;
		pt[write_index].b = 2*pt[read_index].a + pt[read_index].b + 2*pt[read_index].c;
		pt[write_index++].c = 2*pt[read_index].a + 2*pt[read_index].b + 3*pt[read_index].c;

		pt[write_index].a = -pt[read_index].a + 2*pt[read_index].b + 2*pt[read_index].c;
		pt[write_index].b = -2*pt[read_index].a + pt[read_index].b + 2*pt[read_index].c;
		pt[write_index++].c = -2*pt[read_index].a + 2*pt[read_index].b + 3*pt[read_index].c;

		read_index++;
	}

	for(i=0; i<TOTAL; i++)
	{
		printf("\n %d :: %d, %d, %d", i,pt[i].a, pt[i].b, pt[i].c);

		/* Verify if they satisfy Pythogoras theorem */
		if( pt[i].a * pt[i].a + pt[i].b * pt[i].b == pt[i].c * pt[i].c)
		{
		//	printf("  GOOD");
		}
		else
		{
			printf("\n %d, %d, %d", pt[i].a, pt[i].b, pt[i].c);
			printf(" BAD sequence found");
		}

		if(pt[i].a + pt[i].b + pt[i].c == 1000)
		{
			printf("\n 1000 SEQUENCE: %d, %d, %d", pt[i].a, pt[i].b, pt[i].c);
		}
	}
#endif
	for(i=0;i<TOTAL;i++)
		square_array[i] = (i+1) * (i+1);

	int temp;
	int flag, k;
	for(i=0;i<TOTAL;i++)
	{
		for(j=0;j<TOTAL;j++)
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
				printf("\n Found one sequence: %d, %d, %d", i+1, j+1, k+1);
				if(i+j+k+3 == 1000) 
				{
					printf("\n FOUND THE SEQUENCE summing upto 1000");
					printf("\n Product = %d", (i+1)*(j+1)*(k+1));
					return;
				}
			}

		}
	}

}

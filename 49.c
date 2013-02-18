/*
The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?

*/  

#include<stdio.h>
 
int check_prime(int);

void sort(int *array, int total)
{
	int i,j;
	for(i=0;i<total;i++)
	{
		for(j=i+1;j<total;j++)
		{
			if(array[j] < array[i])
			{
				//printf("\n %d is less than %d", array[j], array[i]);
				int temp;
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				break;
			}
		}
	}
	//printf("\n Sorted");
}

struct diff
{
	int a;
	int b;
	int diff;
};

void difference(int *array, int total)
{
	int i,j;
	struct diff diff_array[1000];
	memset(diff_array, 0, sizeof(struct diff)*1000);
	int k = 0;
	int temp = 0;
	for(i=total-1;i>=0;i--)
	{
		for(j=i-1;j>=0;j--)
		{
			if(array[j] > array[i]) 
				printf("\n Invalid");
			else
			{
				diff_array[k].diff = array[i] - array[j];
				diff_array[k].a = array[i];
				diff_array[k].b = array[j];
				k++;
#if 0
				temp = 0;
				while(k!=0 && temp < k)
				{
					if((array[i] - array[j]) == diff_array[temp].diff)
						printf("\n %4d - %4d = %4d", array[i], array[j], array[i] - array[j]);

					temp++;
				}
#endif
				//printf("\n %4d - %4d = %4d", array[i], array[j], array[i] - array[j]);
			}
		}
	}
	//printf("\n Total elements = %d", k);
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k; j++)
		{
			if(diff_array[i].diff == diff_array[j].diff && (diff_array[i].a == diff_array[j].a || diff_array[i].a == diff_array[j].b || diff_array[i].b == diff_array[j].a || diff_array[i].b == diff_array[j].b))
			{
				printf("\n ---------------------------------------------------------");
				printf("\n %4d - %4d = %4d", diff_array[i].a, diff_array[i].b, diff_array[i].diff);
				printf("\n %4d - %4d = %4d", diff_array[j].a, diff_array[j].b, diff_array[j].diff);
				printf("\n ---------------------------------------------------------");
			}
		}
	}
	//printf("\n Sorted");
}
 
int main()
{
   int n, prime_number = 1;
   int result;
   unsigned long long number = 10000ULL;
   unsigned long long product = 1;

   int *primelist = NULL;
 
   for(n=1000; n<=number; n++)
   {
	   result = check_prime(n);

	   if ( result == 1 )
	   {
		   //printf("\n %d : %d : %llu", prime_number, n, product);
		   prime_number++;
	   }
   }
   printf("\n Total primes upto %llu = %d", number, prime_number-1);

   primelist = malloc(sizeof(int)*prime_number);

   prime_number = 0;
   for(n=1000; n<=number; n++)
   {
	   result = check_prime(n);

	   if ( result == 1 )
	   {
		   *(primelist+prime_number) = n;
		   prime_number++;
	   }
   }

   int i,j;
#if 0
   printf("\n List of primes"); 
   for(i=0;i<prime_number;i++)
   {
	   printf("\n %d : %d", (i+1), *(primelist+i));
   }
#endif

   int stack1[4];
   int stack2[4];
   int sp = 0;
   int temp;
   int permutations[100];
   int perm_sp = 0;
   for(i=0;i<prime_number;i++)
   {
	   temp= *(primelist+i);
	   memset(stack1, 0, sizeof(int)*4);
	   sp = 0;

	   memset(permutations, 0, sizeof(int)*100);
	   perm_sp = 0;

	   permutations[perm_sp++] = *(primelist+i);
	   
	   do
	   {
		   //printf("\n        +%d  number=%d ", stack_ptr, number);
		   stack1[sp++] = temp%10;
		   if(temp%10 == 0)
		   {
			   temp= temp/10;
		   }
		   else
		   {
			   temp= temp- (temp%10);
			   temp= temp/10;
		   }
	   }while(temp!= 0);

	   //printf("\n Number is %d and it has digits %d, %d, %d and %d", *(primelist+i), stack1[0], stack1[1], stack1[2], stack1[3]);

	   

   	   for(j=0;j<prime_number;j++)
	   {
		   temp= *(primelist+j);
		   memset(stack2, 0, sizeof(int)*4);
		   sp = 0;
		   int matches = 0;
		   int difference;

		   
		   do
		   {
			   //printf("\n        +%d  number=%d ", stack_ptr, number);
			   if(temp%10 == stack1[0] || temp%10 == stack1[1] || temp%10 == stack1[2] || temp%10 == stack1[3])
			   {
				   matches++;
			   }
			   else
			   {
				   //`printf("\n Ignoring %d", *(primelist+j));
				   break;
			   }
			   stack2[sp++] = temp%10;
			   if(temp%10 == 0)
			   {
				   temp= temp/10;
			   }
			   else
			   {
				   temp= temp- (temp%10);
				   temp= temp/10;
			   }
		   }while(temp!= 0);

		   if(matches == 4 && ((stack1[0] + stack1[1] + stack1[2] + stack1[3]) == (stack2[0] + stack2[1] + stack2[2] + stack2[3])))
		   {
			   if(*(primelist+j) != *(primelist+i))
			   {
			   	//printf("\n %d matches %d", *(primelist+j), *(primelist+i));

				permutations[perm_sp++] = *(primelist+j);
				//printf("\n %d", perm_sp);
			   }
		   }

		   
	   }
	   int x = 0;
	   int prev_diff = 0, diff = 0;
	   int flag = 0;
	   //printf("\n--------------------------------------------------------------------------------\n");
#if 0
	   while(x < perm_sp)
	   {
		   printf("%d, ", permutations[x++]);

	   }
#endif
	   sort(permutations, perm_sp);
	   x=0;
	   while(x < perm_sp)
	   {
		   //printf("%d, ", permutations[x++]);
#if 1
		   if(x == 1)
		   {
			   prev_diff = permutations[0] - permutations[1];
			   if(prev_diff < 0)
				   prev_diff *= -1;
		   }
		   else if(x >= 2)
		   {
			   diff = permutations[x] - permutations[x-1];
			   if(diff < 0)
				   diff *= -1;

			   if(prev_diff != diff)
			   {
				   x++;
				   prev_diff = diff;
				   continue;
			   }
			   else
			   {
				   flag = 1;
			   }
		   }
		   x++;
#endif
	   }

#if 1
	   if(flag == 1)
	   {
	   	   printf("\n");
#if 0
		   x=0;
		   //sort(permutations, perm_sp);
	   	   while(x < perm_sp)
		   {
			   printf("%d, ", permutations[x++]);
		   }
#endif
		   difference(permutations, perm_sp);
	   }
#endif
	   //printf("\n--------------------------------------------------------------------------------\n");
   }

   return 0;
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


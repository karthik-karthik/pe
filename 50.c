/*
The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?

*/  

#include<stdio.h>
 
int check_prime(int);
 
int main()
{
   int n, prime_number = 1;
   int result;
   unsigned long long number = 1000000ULL;
   unsigned long long product = 1;

   int *primelist = NULL;
 
   printf("\n 1 : 2");
 
   for(n=3; n<=number; n++)
   {
	   result = check_prime(n);

	   if ( result == 1 )
	   {
		   prime_number++;
		   //printf("\n %d : %d : %llu", prime_number, n, product);
	   }
   }
   printf("\n Total primes upto %llu = %d", number, prime_number);

   primelist = malloc(sizeof(int)*prime_number);

   prime_number = 0;
   *(primelist+prime_number) = 2;
   prime_number++;
   for(n=3; n<=number; n++)
   {
	   result = check_prime(n);

	   if ( result == 1 )
	   {
		   *(primelist+prime_number) = n;
		   prime_number++;
	   }
   }

   int i,j;
   printf("\n List of primes"); 
   for(i=0;i<prime_number;i++)
   {
	   printf("\n %d : %d", (i+1), *(primelist+i));
   }

   unsigned long long seed, sum;
   int stack[10000];
   int sp = 0;
   int k;
   int max = 0;
   for(i=0;i<prime_number;i++)
   {
	   memset(stack, 0, sizeof(int)*10000);
	   sp = 0;

	   seed = *(primelist+i);

	   sum = seed;
	   stack[sp++] = seed;

	   for(j=i+1; j<prime_number;j++)
	   {
		   sum +=  *(primelist+j);
	   	   stack[sp++] = *(primelist+j);

		   if(sum > 1000000) 
		   {
			   //printf("\n Sum exceeded 1000000");
			   break;
		   }

		   if(check_prime(sum) && sp>max)
		   {
			   printf("\n Sum of ");
			   k = 0;
			   while(k<sp) printf(" %d +", stack[k++]);
			   printf(" = %lld is prime, total element = %d", sum, sp);
			   max = sp;
		   }
	   }

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


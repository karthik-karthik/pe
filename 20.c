/*
n! means n  (n  1)  ...  3  2  1

For example, 10! = 10  9  ...  3  2  1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/  

#include<stdio.h>
 
int check_prime(int);
 
int main()
{
   int n, prime_number = 1;
   int result;
   unsigned long long number = 100ULL;
   unsigned long long product = 1;
 
   printf("\n 1 : 2");
 
   for(n=3; n<=number; n++)
   {
	   result = check_prime(n);

	   if ( result == 1 )
	   {
		   prime_number++;
		   product *= n;
		   printf("\n %d : %d : %llu", prime_number, n, product);


		   if(prime_number == 10001)
			   break;
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


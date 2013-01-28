/* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 * What is the 10 001st prime number?
 *
 */



#include<stdio.h>
 
int check_prime(int);
 
int main()
{
   int n, prime_number = 1;
   int result;
   unsigned long long number = 600851475143ULL;
 
   printf("\n 1 : 2");
 
   for(n=3; n<=number; n++)
   {
	   result = check_prime(n);

	   if ( result == 1 )
	   {
		   prime_number++;
		   printf("\n %d : %d", prime_number, n);

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


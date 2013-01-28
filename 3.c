/* The prime factors of 13195 are 5, 7, 13 and 29.  
 * What is the largest prime factor of the number 600851475143 ?
 *
 */

#include<stdio.h>
 
int check_prime(int);
 
int main()
{
   int n, result;
   unsigned long long number = 600851475143ULL;
 
 
   for(n=3; n<=number; n++)
   {
	   result = check_prime(n);

	   if ( result == 1 )
	   {
		   //printf("%d is prime.\n", n);
	   	   if(number % n == 0)
		   {
			   printf("\n We have prime divisor for %llu which is %d", number, n);
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


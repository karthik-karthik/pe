/* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.  
 * Find the sum of all the primes below two million.
 */

#include<stdio.h>
 
int check_prime(int);

int new_prime(int n)
{
	int f,r;
	if(n==1) 
		return 0;
	else if (n<4) 
		return 1;//2 and 3 are prime
	else if  ((n % 2)==0)
		return 0;
	else if (n<9)
		return 1;    //we have already excluded 4,6 and 8.
	else
	{
		if ((n%3)==0)
			return 0;
		else
			r=floor(sqrt(n));  // n rounded to the greatest integer r so that r*r<=n
			f=5;
			while(f<=r)
			{
				if(n % f==0)
					return 0; //(and step out of the function)
				if((n % (f+2))==0) 
					return 0; //(and step out of the function)
					f=f+6;
			}
	}
	return 1; //(in all other cases)
}
 
int main()
{
   int n, prime_number = 1;
   int result;
   unsigned long long number = 2000000ULL;
   unsigned long long sum_of_prime = 2;
 
   printf("\n 1 : 2");
 
   for(n=3; n<=number; n++)
   {
	   result = new_prime(n);

	   if ( result == 1 )
	   {
		   prime_number++;
		   sum_of_prime += (unsigned long long)n;
		   printf("\n %d : %d : %lld", prime_number, n, sum_of_prime);

		   //if(prime_number == 10001)
		   //	   break;
	   }
   }
   printf("\n Sum of primes = %lld", sum_of_prime);
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


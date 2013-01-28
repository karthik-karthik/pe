/* The sum of the squares of the first ten natural numbers is,

12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025  385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/


#include <stdio.h>

/* Arithmetic progression S= (n/2) * [2a+(n-1)d]
 * Sum of squares, S = n * (n+1) * (2n+1)/6 */

int main()
{
	int n;
	unsigned long long sum_of_sq, sq_of_sum;

	printf("\n Enter the number : ");
	scanf("%d", &n);

	sq_of_sum = ((n/2)*(2*1+(n-1)*1)) * ((n/2)*(2*1+(n-1)*1));
	sum_of_sq = n * (n+1) * (2*n+1)/6;

	printf("\n Sum of squares = %lld", sum_of_sq);
	printf("\n Square of sum = %lld", sq_of_sum);
	printf("\n Difference = %lld", (sq_of_sum - sum_of_sq));

}

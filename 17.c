/* 
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

#include<stdio.h>

struct table
{
	int num;
	char word[20];
};

struct table digits[1000] =
{
	{ 0, ""},
	{ 1, "one"},
	{ 2, "two"},
	{ 3, "three"},
	{ 4, "four"},
	{ 5, "five"},
	{ 6, "six"},
	{ 7, "seven"},
	{ 8, "eight"},
	{ 9, "nine"},
	{ 10, "ten"},
	{ 11, "eleven"},
	{ 12, "twelve"},
	{ 13, "thirteen"},
	{ 14, "fourteen"},
	{ 15, "fifteen"},
	{ 16, "sixteen"},
	{ 17, "seventeen"},
	{ 18, "eighteen"},
	{ 19, "nineteen"},
	{ 20, "twenty"},
	{ 30, "thirty"},
	{ 40, "forty"},
	{ 50, "fifty"},
	{ 60, "sixty"},
	{ 70, "seventy"},
	{ 80, "eighty"},
	{ 90, "ninety"},
};

int return_offset(int num)
{
	int offset = -1;
	int i;

	for(i=0;i<1000;i++)
	{
		if(num == digits[i].num)
		{
			offset = i;
			break;
		}
	}
	return offset;
}

int main()
{
	int i=1;
	int num;
	int temp = 0;
	int ret;
	char string[200];
	int total = 0;

	while(i<1000)
	{
		num = i;
		temp = 0;

		memset(string, 0, sizeof(string));

		if(num >= 100)
		{
			temp = num/100;
			ret = return_offset(temp);
			if(ret != -1)
				sprintf(string, digits[ret].word);
			strcat(string, "hundred");
		}
		if(num > 100 && num%100 != 0)
		{
			strcat(string, "and");
		}
		num = num - (temp * 100);
		if(num>=20 && num<=99)
		{
			temp = num/10;
			ret = return_offset(temp*10);
			if(ret != -1)
				strcat(string, digits[ret].word);

			temp = num%10;
			ret = return_offset(temp);
			if(ret != -1)
				strcat(string, digits[ret].word);
		}
		if(num>=1 && num<=19)
		{
			ret = return_offset(num);
			if(ret != -1)
				strcat(string, digits[ret].word);	
		}


		total += strlen(string);
		printf("\n %d - %s - %d - %d", i, string, strlen(string), total);
		i++;
	}
	total += 11;
	printf("\n 1000 - one thousand - 8 - %d", total);

	printf("\n Total string length = %d", total);
}

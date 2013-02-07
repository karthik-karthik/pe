/*
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

*/ 

#include <stdio.h>

enum days
{
	MON, 
	TUE,
	WED,
	THU,
	FRI,
	SAT,
	SUN
};


int startdays[12];

void init_startdays(int seed, int leap)
{
	startdays[0]=seed;
	startdays[1]=(startdays[0]+31)%7;
	startdays[2]=(startdays[1]+28+leap)%7;
	startdays[3]=(startdays[2]+31)%7;
	startdays[4]=(startdays[3]+30)%7;
	startdays[5]=(startdays[4]+31)%7;
	startdays[6]=(startdays[5]+30)%7;
	startdays[7]=(startdays[6]+31)%7;
	startdays[8]=(startdays[7]+31)%7;
	startdays[9]=(startdays[8]+30)%7;
	startdays[10]=(startdays[9]+31)%7;
	startdays[11]=(startdays[10]+30)%7;
}

int next_year()
{
	return (startdays[11]+31)%7;
}

void print_banner()
{
	int i;
	printf("\n           ");
	for(i=0;i<12;i++)
		printf("%5d ", i);
	
}
void print_startdays(int year, int leap)
{
	int i;

	printf("\n  %4d(%d)  ",year,leap);
	for(i=0;i<12;i++)
	{
		if(startdays[i] == MON) printf("   MON");
		if(startdays[i] == TUE) printf("   TUE");
		if(startdays[i] == WED) printf("   WED");
		if(startdays[i] == THU) printf("   THU");
		if(startdays[i] == FRI) printf("   FRI");
		if(startdays[i] == SAT) printf("   SAT");
		if(startdays[i] == SUN) printf("   SUN");
	}

}

int count_startdays(int day)
{
	int i;
	int total = 0;
	for(i=0;i<12;i++)
	{
		if(startdays[i] == day)
		{
			total++;
		}
	}
	return total;
}

int main()
{
	int total = 0;
	int seed = MON;
	int year = 1900;
	int leap = ((year%400 == 0)||((year%4 == 0) && (year % 100 != 0)))?1:0;

	print_banner();

	init_startdays(seed, leap);
	print_startdays(year++, leap);
	seed = next_year();

	while(year<2001)
	{
		leap = ((year%400 == 0)||((year%4 == 0) && (year % 100 != 0)))?1:0;
		init_startdays(seed, leap);
		print_startdays(year++, leap);
		seed = next_year();
		total += count_startdays(SUN);
		printf("   %d", count_startdays(SUN));
	}
	printf("\n Total Sundays that fell on the first day of the month = %d", total);

}

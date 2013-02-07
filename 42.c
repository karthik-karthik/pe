/*
 *
The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?
*/ 

#include<stdio.h>

enum wordboundary
{
	START,
	END
};

int tri_series[30];


int is_triangle_word(int num)
{
	int i, result = -1;
	for(i=0;i<30;i++)
	{
		if(tri_series[i] == num)
		{
			result = i;
			break;
		}
	}
	return result;
}

int main()
{
	FILE* fd = NULL;
	char buff;
	int word_count = 0;
	char word[100];
	enum wordboundary state=END;
	int word_length;
	int tri_word[2000];
	int i;
	int result = 0;

	memset(tri_word, 0, sizeof(int)*2000);

	for(i=0;i<30;i++)
		tri_series[i] = (i * (i+1))/2;

	fd = fopen("42.txt","r");
	if(NULL == fd)
	{
		printf("\n fopen() Error!!!\n");
		return 1;
	}
	
	while(fread(&buff, 1, 1, fd) == 1)
	{
		//printf("%c", buff);
		if(buff == '"')
		{
			state = (state+1)%2;
			if(state == START)
			{
				memset(word, 0, sizeof(char)* 100);
				word_length = 0;
				continue;
			}
			else
			{
				//printf("\n Word[%d] = %s, %d", word_count, word, tri_word[word_count]);
				if(is_triangle_word(tri_word[word_count]) != -1)
				{
						result++;
						printf("\n Triangle Word[%d] = %s, %d", word_count, word, tri_word[word_count]);
				}
			}

		}
		else if(buff == ',')
		{
			word_count++;
		}
		else
		{
			word[word_length++] = buff;
			tri_word[word_count] += (int)buff - 0x40;
		}
	}
	fclose(fd);
	printf("\n Total word count = %d", word_count+1);


	printf("\n");
	for(i=0;i<30;i++)
		printf(" %2d", tri_series[i]);

	printf("\n Result = %d", result);
}

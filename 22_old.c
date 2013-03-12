/*
 *
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938  53 = 49714.

What is the total of all the name scores in the file?
*/ 

#include<stdio.h>

#define COUNT 6000

enum wordboundary
{
	START,
	END
};


int main()
{
	FILE* fd = NULL;
	FILE* out_fd = NULL;
	char buff;
	int word_count = 0;
	char word[100];
	enum wordboundary state=END;
	int word_length;
	int tri_word[COUNT];
	int result = 0;

	memset(tri_word, 0, sizeof(int)*COUNT);

	fd = fopen("22.txt","r");
	if(NULL == fd)
	{
		printf("\n fopen() Error!!!\n");
		return 1;
	}

	out_fd = fopen("22_out.txt", "w");
	if(NULL == out_fd)
	{
		printf("\n22_out.txt fopen() Error!!!\n");
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
				printf("\n Word[%d] = %s, %d", word_count, word, tri_word[word_count]);
				fprintf(out_fd, "\n%s", word);
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
	fclose(out_fd);
	printf("\n Total word count = %d", word_count+1);

	system("cat 22_out.txt | sort > 22_sorted.txt");



	printf("\n Done");

}

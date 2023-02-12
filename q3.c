#include<stdio.h>
int main()
{
	char line[1000];
	int i,wordcount=0;
	printf("Please enter the sentence: ");
	scanf("%[^\n]",line);
	//capitalize the words
	for(i=0; line[i]!='\0'; i++)
	{
		if(line[i]!=' ')
		{
			line[i]=line[i]-32;
		}
		if(line[i]==' ')
		{
			++wordcount;
		}
	}
	printf("Number of words: %d\n",++wordcount);
	printf("Capitalized line is: %s\n",line);
	system("pause");
}

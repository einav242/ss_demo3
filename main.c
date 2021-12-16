#include <stdio.h>
#include <string.h>
#include "str.h"
#define TXT 1024
#define WORD 30 

int main()
{
    char word[30];
	memset(word,0,strlen(word));
	scanf("%c",&word[0]);
	int i=1;
	while(i<=30)
	{
		scanf("%c",&word[i]);
		if(word[i]==' ' || word[i]=='\n' || word[i]=='\t')
		{
			break;
		}
		i++;
	}
	char txt[1024];
	memset(txt,0,strlen(txt));
	scanf("%c",&txt[0]);
	int j=1;
	while (j<=1024)
	{
		scanf("%c",&txt[j]);
		if(txt[j]=='~')
		{
			break;
		}
		j++;
	}
	

	printf("Gematria Sequences: ");
	func1(word,i,txt,j);
	printf("\n");
	printf("Atbash Sequences: ");
	func2(word,i,txt,j);
	printf("\n");
	printf("Anagram Sequences: ");
	func3(word,i,txt,j);
	
	return 0;
}

	



#include <stdio.h>
#include <string.h>
#include "str.h"
#define TXT 1024
#define WORD 30 


int gimat(char c)
{
    int ans=0;
    if(c<=90 && c>=65)
    {
        ans=c-'A'+1;
    }
    else if(c<=122 && c>=97)
    {
        ans=c-'a'+1;
    }
    return ans;
}

int gimats(char *c)
{
	int ans = 0 ; 
	for(int i = 0 ; i < strlen(c);i++){
		ans = ans + gimat(c[i]);
	}
    return ans;
}

void print(char *str,int len,int key)
{
    if(key!=0)
    {
        printf("~");
    }
    for(int i = 0 ; i < len ; i++)
    {
        int ans = gimat(str[i]);
        if(i==0 && ans==0)
        {
            continue;
        }
        if(i==strlen(str)-1 && ans==0)
        {
            continue;
        }
        printf("%c",str[i]);
    }
	return;
    
}

void func1(char *word,int len_w,char *txt,int len_t)
{
    int sum=gimats(word);
    int i=0;        // bee =12 ;sum = 12 ;
    int j=0;
    int k=0;
    int count=0;
    int key=0;
    char s[1024];
    memset(s,0,strlen(s));
    while (txt[i]!='~')
    {
        int ans = gimat(txt[i]);
        int temp = count;
        if(temp+ans<sum) //0+ 12
        {
        	if(strlen(s)==0 && txt[i]!='~')
            {
        		int m=0;
                if(ans==0)
                {
                    m=i+2;
                }
                else
                {
                m=i+1;
                }
                while (txt[m]!='~')
                {
                	int ans2=gimat(txt[m]);
                    if(ans2!=0)
                    {
                        k=m;
                        break;
                    }
                    m++;
                }
            }
            count+=ans;
            s[j]=txt[i];
            j++;
            i++;
        }
        else if(ans==sum)
        {
            memset(s,0,strlen(s));
            s[0]=txt[i];
            print(s,strlen(s),key);
            key++;
            memset(s,0,strlen(s));
            count=0;
            j=0;
            i++;
        }
	    else if(temp+ans==sum)
        {
            s[j]=txt[i];
            print(s,strlen(s),key);
            key++;
            memset(s,0,strlen(s));
            count=0;
            j=0;
            i=k;
        }
        else if(ans>sum)
        {
            memset(s,0,strlen(s));
            count=0;
            j=0;
            i++;
        }
        else if(temp+ans>sum)
        {
            memset(s,0,strlen(s));
            count=0;
            j=0;
            if(txt[i+1]=='~')
            {
                i++;
            }
            else
            {
                i=k;
            }
        }
    }
    printf("\n");
	return;
    
}

int len(char *s,int len)
{
	int count=0;
	for(int i=0;i<len;i++)
	{
		if(gimat(s[i])==0)
		{
			continue;
		}
		count++;
	}
	return count;
}

void func2(char *w,int len_w,char *txt,int len_t)
{
	int i;
	char word[len_w];
	memset(word,0,len_w);
	for(i = 0 ; i < len_w ;i++)
	{
		if(w[i] >= 'a' && w[i] <= 'z')
		{
			char temp = w[i];
			word[i] = 'z'-temp+'a';
		}
		else if(w[i] >= 'A' && w[i] <= 'Z')
		{
			char temp = w[i];
			word[i] = 'Z'-temp+'A';	
		}
	}
	char str[30];
	memset(str,0,strlen(str));
	int key=0;
	i=0;
	int j=0;
	int k=0;
	while(txt[i]!='~')
	{
		if(len(str,strlen(str))==len_w)
	 	{
			print(str,strlen(str),k);
			memset(str,0,strlen(str));
			k++;
			j=0;
			i=i-strlen(str)+2;
		}
		else if(txt[i]==word[j])
		{
			if(strlen(str)==0)
			{
				str[j]=txt[i];
				i++;
				j++;
				key=0;
			}
			else if(key==0)
			{
				str[j]=txt[i];
				i++;
				j++;
			}
			else
			{
				i=i-strlen(str)+2;
				memset(str,0,strlen(str));
				j=0;
			}
		}
		else if(txt[i]==word[len_w-j-1])
		{
			if(strlen(str)==0)
			{
				str[j]=txt[i];
				i++;
				j++;
				key=1;
			}
			else if(key==1)
			{
				str[j]=txt[i];
				i++;
				j++;
				key=1;
			}
			else
			{
				i=i-strlen(str)+2;
				memset(str,0,strlen(str));
				j=0;
			}
		}
		else
		{
			i=i-strlen(str)+1;
			memset(str,0,strlen(str));
			j=0;
		}

	}

	printf("\n");
	
}

int contain(char *word,int len,char c)
{
	for(int i=0;i<len;i++)
	{
		if(word[i]==c)
		{
			return 1;
		}
	}
	return 0;
}

int how_many(char *word,int len,char c)
{
	int count=0;
	for(int i=0;i<len;i++)
	{
		if(word[i]==c)
		{
			count++;
		}
	}
	return count;
}

void func3(char *word,int len_w,char *txt,int len_t)
{
	char s[1024];
	memset(s,0,strlen(s));
	int i=0;
	int j=0;
	int key=0;
	while (txt[i]!='~')
	{
		if(contain(word,len_w,txt[i])==1 && len(s,strlen(s))<len_w)
		{
			int c1=how_many(word,len_w,txt[i]);
			int c2=how_many(s,strlen(s),txt[i]);
			if(c2<c1)
			{
				s[j]=txt[i];
				if(len(s,strlen(s))==len_w)
				{
					print(s,strlen(s),key);
					key++;
					i=i-strlen(s)+2;
					memset(s,0,strlen(s));
					j=0;
				}
				else
				{
					j++;
				}
			}
			else
			{
				i=i-strlen(s)+1;
				memset(s,0,strlen(s));
				j=0;
			}
			i++;
		}
		else if(txt[i]==' ')
		{
			s[j]=txt[i];
			j++;
			i++;
		}
		else if(len(s,strlen(s))==len_w)
		{
			print(s,strlen(s),key);
			key++;
			i=i-strlen(s)+2;
			memset(s,0,strlen(s));
			j=0;
		}
		else
		{
			i=i-strlen(s)+1;
			memset(s,0,strlen(s));
			j=0;
		}
	}
	printf("\n");
}

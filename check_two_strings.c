#include <stdio.h>
char compare(char a[], char b[]);
int main()
{
char a[100];
char b[100];
printf("enter a string");
fflush(stdin); fflush(stdout);
gets(a);
printf("enter your username");
fflush(stdin); fflush(stdout);
gets(b);
int k = compare(a,b);
printf("%d",k);
}
char compare(char a[],char b[])
{
	int i;
	for(i=0;i<=100;i++)
	{
		if(a[i]==b[i])
		{
			if(a[i]=='\0'||b[i]=='\0')
				break;
		}
		else
			break;
	}
	if(a[i]=='\0'&&b[i]=='\0')
		return 1;
	else
		return 0;
}

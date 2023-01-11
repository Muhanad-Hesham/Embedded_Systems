#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//a program in C to demonstrate how to handle the pointers in the program.



void main()
{
	char alph[27];
	char *ptr;
	int i;
	ptr= alph;
	for(i=0;i<26;i++)
	{
		*ptr=i+'A';
		ptr++;

	}
	ptr=alph;
	printf("the alphabets are:\n");
	for(i=0;i<26;i++,ptr++)
	{
		printf("%c ",*ptr);

	}

}

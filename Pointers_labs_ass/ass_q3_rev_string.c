#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//a program in C to print a string in reverse using a pointer



void main()
{
char str1[50];
char str2[50];
int i=0;
char* ptr1;
ptr1=str1;
char* ptr2;
ptr2=str2;
printf("input a string: ");
fflush(stdin); fflush(stdout);
scanf("%s",str1);
while(*ptr1)
{
	ptr1++;
	i++;
}
while(i-1>=0)
{
	ptr1--;
	*ptr2=*ptr1;
	ptr2++;
	--i;
}
*ptr2='\0'; //to make final element of the reverse array equal zero
printf("reverse string is: %s",str2);



}

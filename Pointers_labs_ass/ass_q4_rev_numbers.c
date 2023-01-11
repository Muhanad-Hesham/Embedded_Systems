#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//a program in C to print the elements of an array in reverse order


void main()
{
	int arr1[50];
	int arr2[50];
	int* ptr1=arr1;
	int*ptr2=arr2;
	int i;
	int n;
	printf("enter number of elements: ");
	fflush(stdout);
	scanf("%d",&n);
for(i=0;i<5;i++)
{
	scanf("%d",ptr1+i);
}
for(i=0;i<5;i++,ptr1++)
{
	printf("element %d : %d\n",i+1,*ptr1);
}
//ptr1=arr1;
printf("the elements of array in reverse order are: \n");
ptr1--;
for(i=0;i<5;i++,ptr2++)
{
	*ptr2=*ptr1;
	ptr1--;
	printf("element %d : %d\n",i+1,*ptr2);
}




}

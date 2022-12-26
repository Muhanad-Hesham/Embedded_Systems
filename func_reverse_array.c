#include <stdio.h>
//write  a function to reverse an array
void reverse(int array1[],int b[], int size);
void main()
{
	int array1[100];
	int b[100];
	int size;
	int i;
	printf("enter the size ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&size);
	printf("enter the first array ");

	for(i=0;i<size;i++)
		scanf("%d",&array1[i]);
	for(i=0;i<size;i++)
		printf("%d",array1[i]);
	printf("\n");
	 reverse ( array1, b, size);
}
void reverse(int array1[],int b[],int size)
{
	int i; int j;
	for(i=0,j=(size-1);i<size;i++,j--)
		b[i]=array1[j];
	for(i=0;i<size;i++)
		printf("%d",b[i]);
}

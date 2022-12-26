#include <stdio.h>

//write  a function to reverse an array
int last_occurance(int a[],int size,int num);
void main()
{
	int array[100];
	int size;
	int num;
	printf("enter the size of the array");
	fflush(stdin); fflush(stdout);
	scanf("%d",&size);
	printf("enter elements of the array");

	fflush(stdin); fflush(stdout);
	int i;
	for(i=0;i<size;i++)
		scanf("%d",&array[i]);
	for(i=0;i<size;i++)
		printf("%d",array[i]);
	printf("enter the number ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	int index = last_occurance(array,size,num);
	if(index==-1)
		printf("the number %d is not occured in the array",num);

	else
		printf("the last occurance of the variable is at index: %d",index);
}
int last_occurance(int a[],int size,int num)

{
	int i;
	int index=-1;
	for(i=0;i<size;i++)
	{
		if(a[i]==num)
			index=i;
	}
 return index;
}

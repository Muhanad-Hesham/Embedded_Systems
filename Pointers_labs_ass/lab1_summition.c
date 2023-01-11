#include <stdio.h>
#include <stdlib.h>
//It is required to calculate the summation weight of 5
//boxes. The user should enter the boxes
void main()
{
	int x[5];
	int sum=0;
	int* px=x;
	int i;
	for(i=0;i<5;i++)

		scanf("%d",px+i);
	for(i=0;i<5;i++)
		printf("%d",*px++);
	px=x;   //because px++ changes address of px
	for(i=0;i<5;i++,px++)
		sum+=*px;
	printf("\nsum= %d",sum);



}

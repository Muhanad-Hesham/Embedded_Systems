/*
 * main.c
 *
 *  Created on: Dec 16, 2022
 *      Author: Muhand
 */

/*
 * main.c
 *
 *  Created on: Dec 16, 2022
 *      Author: Muhand
 */

#include <stdio.h>
void main()
{
	int num;
	int element;
	int array[100];
	int i;
	printf("enter no. of elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	for(i=0;i<num;i++)
		scanf("%d",&array[i]);

	for(i=0;i<num;i++)
		printf("%d ",array[i]);
	printf("\nenter the element to be searched: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&element);

	for (i=0;i<num;i++)
	{
		if(element==array[i])

			printf("number found at the location:%d",i+1);
		break;
	}
	printf("can't found any number");


}


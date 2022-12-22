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
	int x;//num
	float z;//element
	int location;
	float array[100];
	int i;
	printf("enter number of elements: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);

	while(x>100||x<=0)
	{
		printf("enter another number");
		fflush(stdin); fflush(stdout);
		scanf("%d",&x);
	}
	printf("enter the elements of the array");
	fflush(stdin);fflush(stdout);

	for(int i=0;i<x;i++)

	{

		scanf("%f",&array[i]);

	}
	printf("enter the element to be inserted: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&z);
	printf("enter the specified location: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&location);
	for (i=x;i>=location;i--)
	{
		array[i]=array[i-1];
	}
	x++;
	array[location-1]=z;
	for(i=0;i<x;i++)
		printf("%f\t",array[i]);


}


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
	int x;//n numbers
	int y;// numbers
	float array[100];
	float avg;
	float sum=0;
	int i;
	printf("enter the number of data: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);
	while(x>100||x<=0)
	{
		printf("enter another number");
		fflush(stdin); fflush(stdout);
		scanf("%d",x);
	}
	for( i=0;i<x;i++){
		printf("%d. enter number: \n",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d",&y);
		array[i]=y;
		sum+=array[i];
		printf("sum equal %f\n", sum);
	}
	printf("i equal %d\n",i);
	avg = sum/i;
	printf("average is equal %f",avg);
}


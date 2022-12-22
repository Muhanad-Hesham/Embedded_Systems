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
void main(){
//using break statement
/*	int num;
	int x ;
	float sum = 0  ;
	float avg ;
	int i ;
	printf("maxiumum no. of inputs ");
	fflush(stdin); fflush(stdout);
	scanf("%d" , &x);
	for ( i=1;i<=x;i++)
	{
		printf("enter n%d",i);
		fflush(stdin); fflush(stdout);
		scanf("%d",&num);
		if(num<0)
			break;
		sum+=num;
	}
	avg = sum/(i-1);
	printf("average is equal %f",avg);*/
//using continue statement
	int x;
	int product=1;
	int i;
	for(i=1;i<=4;i++)
	{
		printf("number%d=",i);
		fflush(stdin); fflush(stdout);
		scanf("%d",&x);
		if(x==0)
			continue;
		product*=x;
	}
	printf("product is equal%d",product);
}


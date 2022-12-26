/*
 * main.c
 *
 *  Created on: Dec 22, 2022
 *      Author: Muhand
 */
#include<stdio.h>
void hamada(int first, int last);

void main()
{
	hamada(5,15);


}
void hamada(int first, int last)
{
	int i,j;
for(i=first;i<=last;i++)
	{

		for(j=i;j<=last;j++)
			printf("%d ",j);
		printf("\n");
	}
}

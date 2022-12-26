/*
 * main.c
 *
 *  Created on: Dec 22, 2022
 *      Author: Muhand
 */
#include<stdio.h>
int check_prime(int num);

void main()
{
	int n1 ; int n2;
	int flag; int i;
	printf("enter two numbers(intervals): ");
	fflush(stdin); fflush(stdout);
	scanf("%d%d",&n1,&n2);
	printf("prime numbers between %d and %d is ",n1,n2);
	for(i=n1+1;i<n2;i++)
	{
		flag=check_prime(i);
		if(flag==0)
			printf("%d ",i);
	}
}
int check_prime(int num)
{
	int j,flag=0;
	for(j=2;j<=num/2;j++)
	{
		if(num%j==0)
		{
			flag=1;
			break;
		}
	}
	return flag;

}








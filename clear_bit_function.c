#include <stdio.h>
//write  a function to reverse an array
int clear_bit (int num,int bit);
void main()
{
int num;
int bit;
printf("enter your number ");
fflush(stdin); fflush(stdout);
scanf("%d",&num);
printf("enter bit you want to clear ");
fflush(stdin); fflush(stdout);
scanf("%d",&bit);
printf("%d",clear_bit(num,bit));
}
int clear_bit (int num,int bit)
{
	num &=~(1<<bit);
	return num;
}

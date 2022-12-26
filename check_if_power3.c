#include <stdio.h>
#include <math.h>
//write  a function to reverse an array
int checkpower3 (int n);
void main()
{
int n;
printf("enter a number");
fflush(stdout);
scanf("%d",&n);
checkpower3(n)? printf("yes power of 3") : printf("not power of 3");
}
int checkpower3 (int n)
{
	double i;
	i=log(n)/log(3);


	return i==trunc(i) ;
}

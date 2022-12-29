#include <stdio.h>
#include <stdlib.h>
struct Sadd{

	float real;
	float imag;
}d1,d2,sum;
int main(void)
{
printf("'for 1st complex number'\n");
printf("Enter Real and Imaginary respectively: ");
fflush(stdout);
scanf("%f %f",&d1.real,&d1.imag);
printf("'for 2nd complex number'\n");
printf("Enter Real and Imaginary respectively: ");
fflush(stdout);
scanf("%f %f",&d2.real,&d2.imag);
sum.real=d1.real+d2.real;
sum.imag=d1.imag+d2.imag;
printf("sum of the numbers is:%.2f + %.2fi",sum.real,sum.imag);
}

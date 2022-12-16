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
	//swaping value of two variables with no temp variable "third variable"
	/*float a;
float b;
printf("enter a");
fflush(stdin); fflush(stdout);
scanf("%f",&a);
printf("enter b");
fflush(stdin); fflush(stdout);
scanf("%f",&b);
b=a+b;
a=b-a;
b=b-a;
printf("after swaping a= %f",a);
printf("after swaping b= %f",b);*/

	//swaping value of two variables using third variable "temp"
	float a;
	float b;
	float temp;
	printf("enter a");
    fflush(stdin); fflush(stdout);
	scanf("%f",&a);
	printf("enter b");
	fflush(stdin); fflush(stdout);
	scanf("%f",&b);
	temp=a;
	a=b;
	b=temp;
	printf("after swaping a= %f",a);
	printf("after swaping b= %f",b);
}


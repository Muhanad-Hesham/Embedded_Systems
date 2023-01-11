#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//a program in C to demonstrate how to handle the pointers in the program.



void main()
{
int m=29;
int*ab;
printf("address of m:%p\nvalue of m:%d",&m,m);
ab=&m;
printf("\naddress of pointer ab:%p\ncontent of pointer ab:%d",ab,*ab);
m=34;
printf("\naddress of pointer ab:%p\ncontent of pointer ab:%d",ab,*ab);
*ab=7;
printf("address of m:%p\nvalue of m:%d",&m,m);

}

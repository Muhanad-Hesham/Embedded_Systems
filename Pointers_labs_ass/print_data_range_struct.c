#include <stdio.h>
#include <stdlib.h>
// dumbing or printing memory range of structure using pointers
struct sdataset
{
	unsigned char data1;
	unsigned int data2;
	unsigned char data3;
	unsigned short data4;
};
struct sdataset data;
void print_data_range(char* base, int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%p \t %x \n",base,(unsigned char)*base); // %p to print address
		base++;
	}
}
void main()
{
data.data1=0x11;
data.data2=0xffffeeee;
data.data3=0x22;
data.data4=0xABCD;
print_data_range(&data,sizeof(data));
char* p= &data;
printf("p+8=%x \n",(unsigned char)*(p+8));
struct sdataset* pstruct=&data;
printf("p+8=%x \n",(unsigned char) pstruct->data3);
}

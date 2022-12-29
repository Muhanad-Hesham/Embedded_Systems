#include <stdio.h>
#include <stdlib.h>
struct Sstudent{

	char name[50];
	int roll;
	int mark;
};
int main(void)
{
	struct Sstudent s[10];
	int i;
	printf("Enter information of students");
	for(i=0;i<10;i++)
	{
		s[i].roll=i+1;
		printf("\nFor roll number %d",s[i].roll);
		printf("\n Enter name:");
		fflush(stdout);
		scanf("%s",s[i].name);
		printf("\n Enter mark:");
		fflush(stdout);
		scanf("%d",&s[i].mark);
		printf("\n");
	}
	printf("Displaying information of students");
	for(i=0;i<10;i++)
	{
		printf("\ninformation for roll number:%d",s[i].roll+1);
		printf("\nNamee: %s",s[i].name);
		printf("\nMark: %d",s[i].mark);
	}


}

#include <stdio.h>
#include <stdlib.h>
struct Sstudent{
	char m_name[50];
	int m_roll;
	int m_mark;
};
int main(void)
{
struct Sstudent s;
printf("Enter information of student:\n");
printf("Enter your name: ");
fflush(stdout);
scanf("%s",s.m_name);
printf("Enter your roll number: ");
fflush(stdout);
scanf("%d",&s.m_roll);
printf("Enter your mark: ");
fflush(stdout);
scanf("%d",&s.m_mark);
printf("Your name is: %s\nYour roll number is: %d\nYour mark is: %d\n",s.m_name,s.m_roll,s.m_mark);
}

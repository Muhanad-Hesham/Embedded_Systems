#include <stdio.h>
#include <stdlib.h>
struct Sadd{

	float feet;
	float inch;
}d1,d2,sum;
int main(void)
{
printf("Enter information of 1st distance:\n");
printf("Enter feet:");
fflush(stdout);
scanf("%f",&d1.feet);
printf("Enter inch:");
fflush(stdout);
scanf("%f",&d1.inch);
//  ****
printf("Enter information of 2nd distance:\n");
printf("Enter feet:");
fflush(stdout);
scanf("%f",&d2.feet);
printf("Enter inch:");
fflush(stdout);
scanf("%f",&d2.inch);
sum.feet=d1.feet+d2.feet;
sum.inch=d1.inch+d2.inch;
printf("%f\n",sum.feet);
printf("%f\n",sum.inch);

for(sum.inch;sum.inch>12;sum.inch)
{
	sum.inch-=12;
sum.feet++;
}
printf("Sum of distances=%f\'-%.2f\"",sum.feet,sum.inch);

/*if(sum.inch>12.0)
{
	sum.inch=sum.inch-12;
	sum.feet++;
	printf("Sum of distances=%f\'-%.2f\"",sum.feet,sum.inch);
}*/
}

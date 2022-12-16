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
	char x;
	printf("enter a character ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&x);
	if((x>='a'&& x<='z')||(x>='A'&& x<='Z'))
		printf("%c is character",x);
	else
		printf("%c is not alphabet",x);


}


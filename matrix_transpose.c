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
	float matrix[3][3];
	int row;
	int col;
	float transpose[3][3];
	for(row=0;row<3;row++)
	{
		for(col=0;col<3;col++)
		{
			scanf("%f",&matrix[row][col]);
		}
	}
	for(row=0;row<3;row++)
	{
		for(col=0;col<3;col++)
		{
			printf("%f\t",matrix[row][col]);
		}
		printf("\n\n");
	}

	for(row=0;row<3;row++)
	{
		for(col=0;col<3;col++)
		{
			transpose[row][col]=matrix[col][row];
		}
	}

	printf("\n");
	for(row=0;row<3;row++)
	{
		for(col=0;col<3;col++)
		{
			printf("%f\t",transpose[row][col]);
		}
		printf("\n\n");
	}




}


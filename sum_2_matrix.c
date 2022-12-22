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
	float matrix1[2][2];
	float matrix2[2][2];
	float matrix3[2][2];
	int i , j;
	printf("enter the elements of the first matrix\n");
	fflush(stdin); fflush(stdout);
	for( i=0;i<2;i++)
	{
		for( j =0;j<2;j++)
		{
			printf("enter m1%d%d: ", i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&matrix1[i][j]);
		}
	}
	printf("enter the elements of the second matrix\n");
	fflush(stdin); fflush(stdout);
	for( i=0;i<2;i++)
	{
		for( j =0;j<2;j++)
		{
			printf("enter m2%d%d: ", i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&matrix2[i][j]);
		}
	}
	for( i=0;i<2;i++)
	{
		for( j =0;j<2;j++)
		{
			matrix3[i][j]=matrix1[i][j]+matrix2[i][j];

		}
	}
	printf("\nsum of matrix\n");
	for( i=0;i<2;i++)
		{
			for( j =0;j<2;j++)
			{
				printf("%f\t",matrix3[i][j]);

			}
			printf("\n");
		}
}


/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void generateSpiral(int left, int right, int top, int bottom, int **input_array, int *output_array, int output_index)
{
	int index;

	if (left > right || top > bottom)
		return;

	for (index = left; index <= right; index++)
		output_array[output_index++] = input_array[top][index];
	for (index = top + 1; index <= bottom; index++)
		output_array[output_index++] = input_array[index][right];

	if (top != bottom)
		for (index = right - 1; index >= left; index--)
			output_array[output_index++] = input_array[bottom][index];
	if (left != right)
		for (index = bottom - 1; index > top; index--)
			output_array[output_index++] = input_array[index][left];


	generateSpiral(left + 1, right - 1, top + 1, bottom - 1, input_array, output_array, output_index);


}
int *spiral(int rows, int columns, int **input_array)
{
	if (rows <= 0 || columns <= 0 || input_array == NULL)
		return NULL;

	int *output_array = (int *)malloc(rows*columns*sizeof(int));
	generateSpiral(0, columns - 1, 0, rows - 1, input_array, output_array, 0);
	return output_array;
}
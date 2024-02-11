#include "my_mat.h"

int initMatrix(int mat[][LEN])
{
	// printf("hello there!");
	for (int i = 0; i < LEN; i++)
		for (int j = 0; j < LEN; j++)
		{
			// printf("enter the value for cell (%d,%d)", i, j);
			scanf("%d", &mat[i][j]);
		}

	for (int k = 0; k < LEN; k++)
		for (int i = 0; i < LEN; i++)
			for (int j = 0; j < LEN; j++)
				if (mat[i][k] && mat[k][j])
					if (mat[i][j] > mat[i][k] + mat[k][j])
						mat[i][j] = mat[i][k] + mat[k][j];
	return 0;
}

int findPath(int mat[][LEN], int flag)
{
	// if flag is 0 will print
	// the existance of a path else its weigth
	int i = 0, j = 0;
	scanf("%d", &i);
	scanf("%d", &j);
	if (flag)
		if (mat[i][j])
			printf("%d", mat[i][j]);
		else
			printf("-1");
	else
		if (mat[i][j])
			printf("True");
		else
			printf("False");
	return 0;
}
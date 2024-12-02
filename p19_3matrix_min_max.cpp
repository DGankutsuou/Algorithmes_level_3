#include "randomlib.h"
#include "arraylib.h"
#include "inputslib.h"
#include <iostream>
#include <iomanip>

using namespace std;

void	fill_3to3_matrix_with_random_numbers(int matrix[3][3], int from, int to)
{
	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix[i][j] = rnd::random_number(from, to);
}

void	print_3to3_matrix(int matrix[3][3])
{
	for(int i = 0; i < 3; i++)
	{
		cout << "row " << i + 1 << ": ";
		for (int j = 0; j < 3; j++)
			cout << setw(3) << matrix[i][j] << " ";
		cout << "\n";
	}
}

void	print_3to3_matrix_min_max(int matrix[3][3])
{
	short	min;
	short	max;

	min = matrix[0][0];
	max = min;
	for(int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (matrix[r][c] < min)
				min = matrix[r][c];
			else if (matrix[r][c] > max)
				max = matrix[r][c];
		}
	}
		cout << "The min number in this matrix: " << min << endl;
		cout << "The max number in this matrix: " << max << endl;
}

int	main(void)
{
	srand ((unsigned)time (NULL));

	int	mtx[3][3];
	// int	test[3][3] = {9, 0, 0,
	// 				0, 9, 0,
	// 				0, 0, 9};

	fill_3to3_matrix_with_random_numbers (mtx, 0, 9);
	print_3to3_matrix (mtx);
	cout << endl;
	print_3to3_matrix_min_max (mtx);
	return (0);
}

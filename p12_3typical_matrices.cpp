#include "randomlib.h"
#include "arraylib.h"
#include <iostream>
#include <iomanip>

using namespace std;

void	fill_3to3_matrix_with_random_numbers(int array[3][3], int from, int to)
{
	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			array[i][j] = rnd::random_number(from, to);
}

void	print_3to3_matrix(int array[3][3])
{
	for(int i = 0; i < 3; i++)
	{
		cout << "row " << i + 1 << ": ";
		for (int j = 0; j < 3; j++)
			cout << setw(3) << array[i][j] << " ";
		cout << "\n";
	}
}

int	sum_3to3_matrix(int array[3][3])
{
	int	sum;

	sum = 0;
	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			sum += array[i][j];
	return (sum);
}

bool	typical_3to3_matrices(int array1[3][3], int array2[3][3])
{
	for (short r = 0; r < 3; r++)
		for (short c = 0; c < 3; c++)
		{
			if (array1[r][c] != array2[r][c])
				return (0);
		}
	return (1);
}

int	main(void)
{
	srand ((unsigned)time (NULL));

	int	arr1[3][3];
	int	sum1;
	int	arr2[3][3];
	int	sum2;

	fill_3to3_matrix_with_random_numbers (arr1, 0, 9);
	print_3to3_matrix (arr1);
	sum1 = sum_3to3_matrix (arr1);
	cout << "\nThe sum of the matrix 1: " << sum1 << endl;
	cout << endl;
	fill_3to3_matrix_with_random_numbers (arr2, 0, 9);
	print_3to3_matrix (arr2);
	sum2 = sum_3to3_matrix (arr2);
	cout << "\nThe sum of the matrix 2: " << sum2 << endl;
	cout << endl;

	if (typical_3to3_matrices (arr1, arr2))
		cout << "Yes! The two matrices are typically equal." << endl;
	else
		cout << "No! The two matrices are not typically equal." << endl;
	return (0);
}

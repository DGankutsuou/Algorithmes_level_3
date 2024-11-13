#include "randomlib.h"
#include "arraylib.h"
#include <iostream>
#include <iomanip>
using namespace std;

void	fill_3to3_matrix_with_random_numbers(int array[3][3])
{
	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			array[i][j] = rnd::random_number(0, 9);
}

void	print_3to3_matrix(int array[3][3])
{
	for(int i = 0; i < 3; i++)
	{
		cout << "row " << i + 1 << ": ";
		for (int j = 0; j < 3; j++)
			printf ("%02d ", array[i][j]);
		cout << "\n";
	}
}

void	multiplay_two_3to3_matrices(int array1[3][3], int array2[3][3], int dest[3][3])
{
	for (short r = 0; r < 3; r++)
		for (short c = 0; c < 3; c++)
			dest[r][c] = array1[r][c] * array2[r][c];
}

int	main(void)
{
	srand ((unsigned)time (NULL));
	int	arr1[3][3];
	int	arr2[3][3];
	int	dest[3][3];

	fill_3to3_matrix_with_random_numbers(arr1);
	fill_3to3_matrix_with_random_numbers(arr2);
	cout << "Array 1:" << endl;
	print_3to3_matrix(arr1);
	cout << "Array 2:" << endl;
	print_3to3_matrix(arr2);
	multiplay_two_3to3_matrices(arr1, arr2, dest);
	cout << "The maltiplication of the two arrays:" << endl;
	print_3to3_matrix(dest);
	return (0);
}

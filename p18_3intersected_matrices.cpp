#include "randomlib.h"
#include "arraylib.h"
#include <iostream>
#include <iomanip>
#include <vector>

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

bool	check_number_in_3to3_matrix(int number, int matrix[3][3])
{
	short	counter;

	counter = 0;
	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (matrix[i][j] == number)
				return (true);
	return (false);
}

void	intersected_numbers_of_3tot3_matrices(vector <int> &v_inter, int array1[3][3], int array2[3][3])
{
	for (int r = 0; r < 3; r++)
		for (int c = 0; c < 3; c++)
			if (check_number_in_3to3_matrix (array1[r][c], array2))
				v_inter.push_back(array1[r][c]);
}

int	main(void)
{
	srand ((unsigned)time (NULL));

	int	arr1[3][3];
	int	sum1;
	int	arr2[3][3];
	int	sum2;
	vector <int> v_inter;

	fill_3to3_matrix_with_random_numbers (arr1, 0, 9);
	print_3to3_matrix (arr1);
	cout << endl;
	fill_3to3_matrix_with_random_numbers (arr2, 0, 9);
	print_3to3_matrix (arr2);
	cout << endl;
	intersected_numbers_of_3tot3_matrices (v_inter, arr1, arr2);
	cout << "Intersected numbers: ";
	for (int n : v_inter)
		cout << n << "  ";
	cout << endl;
	return (0);
}

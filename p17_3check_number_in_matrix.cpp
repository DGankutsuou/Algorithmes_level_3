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

int	main(void)
{
	srand ((unsigned)time (NULL));

	int	mtx[3][3];
	int	count;
	int	test[3][3] = {9, 0, 0,
					0, 9, 0,
					0, 0, 9};

	fill_3to3_matrix_with_random_numbers (mtx, 0, 9);
	print_3to3_matrix (mtx);
	cout << endl;
	if (check_number_in_3to3_matrix(0, mtx))
		cout << "The number is in the matrix" << endl;
	else
		cout << "The number is not in the matrix" << endl;

	return (0);
}

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

bool	is_palindrom_matrix(int matrix[3][3])
{
	for(int r = 0; r < 3; r++)
	{
		if (matrix[r][0] != matrix[r][2])
			return (false);
	}
	return (true);
}

int	main(void)
{
	srand ((unsigned)time (NULL));

	int	mtx[3][3];
	// int	test[3][3] = {0, 1, 0,
	// 				0, 9, 0,
	// 				0, 6, 0};

	fill_3to3_matrix_with_random_numbers (mtx, 0, 9);
	print_3to3_matrix (mtx);
	cout << endl;
	if (is_palindrom_matrix (mtx))
		cout << "This matrix is palindrom" << endl;
	else
		cout << "This matrix is not palindrom" << endl;
	return (0);
}

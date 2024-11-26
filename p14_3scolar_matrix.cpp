#include "randomlib.h"
#include "arraylib.h"
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

bool	is_scolar_matrix(int matrix[3][3])
{
	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (i == j && matrix[i][j] != matrix[0][0])
				return (0);
			else if (i != j && matrix[i][j] != 0)
				return (0);
		}
	return (1);
}

int	main(void)
{
	srand ((unsigned)time (NULL));

	int	mtx[3][3];
	int	test[3][3] = {9, 0, 0,
					0, 9, 0,
					0, 0, 9};
	fill_3to3_matrix_with_random_numbers (mtx, 0, 9);
	print_3to3_matrix (mtx);
	cout << endl;
	if (is_scolar_matrix (mtx))
		cout << "Yes! The matrix is scolar" << endl;
	else
		cout << "No! The matrix is not scolar" << endl;
	return (0);
}

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

bool	is_identity_matrix(int array[3][3])
{
	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (i == j && array[i][j] != 1)
				return (0);
			else if (i != j && array[i][j] != 0)
				return (0);
		}
	return (1);
}

int	main(void)
{
	srand ((unsigned)time (NULL));

	int	arr[3][3];
	int	test[3][3] = {1, 0, 0,
					0, 1, 0,
					0, 0, 1};
	fill_3to3_matrix_with_random_numbers (arr, 0, 1);
	print_3to3_matrix (arr);
	cout << endl;
	if (is_identity_matrix (arr))
		cout << "Yes! The matrix is identical" << endl;
	else
		cout << "No! The matrix is not identical" << endl;
	return (0);
}

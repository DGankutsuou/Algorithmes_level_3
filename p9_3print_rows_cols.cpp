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

void	print_3to3_matrix_middle_row(int array[3][3])
{
	for(int c = 0; c < 3; c++)
		printf ("%02d ", array[1][c]);
	cout << endl;
}

void	print_3to3_matrix_middle_col(int array[3][3])
{
	for(int r = 0; r < 3; r++)
		printf ("%02d ", array[r][1]);
	cout << endl;
}

int	main(void)
{
	srand ((unsigned)time (NULL));
	int	arr[3][3];

	fill_3to3_matrix_with_random_numbers(arr);
	cout << "Array:" << endl;
	print_3to3_matrix(arr);
	cout << endl;
	cout << "The middle row: ";
	print_3to3_matrix_middle_row(arr);
	cout << endl;
	cout << "The middle col: ";
	print_3to3_matrix_middle_col(arr);
	return (0);
}

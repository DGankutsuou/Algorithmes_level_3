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

int	main(void)
{
	srand ((unsigned)time (NULL));

	int	arr[3][3];
	int	sum;

	fill_3to3_matrix_with_random_numbers (arr, 0, 9);
	print_3to3_matrix (arr);
	sum = sum_3to3_matrix (arr);
	cout << "\nThe sum of the matrix: " << sum << endl;
	return (0);
}

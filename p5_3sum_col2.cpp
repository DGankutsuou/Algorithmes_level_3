#include "randomlib.h"
#include "arraylib.h"
#include <iostream>
#include <iomanip>
using namespace std;

void	fill_3to3_matrix_with_random_numbers(int array[3][3])
{
	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			array[i][j] = rnd::random_number(0, 99);
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

void	copy_3to3_colons_sum_matrix(int array[3][3], int dest[3])
{
	for (int j = 0; j < 3; j++)
	{
		dest[j] = 0;
		for(int i = 0; i < 3; i++)
			dest[j] += array[i][j];
	}
}

int	main(void)
{
	srand ((unsigned)time (NULL));
	int	arr[3][3];
	int dest[3];

	fill_3to3_matrix_with_random_numbers(arr);
	print_3to3_matrix(arr);
	copy_3to3_colons_sum_matrix(arr, dest);
	cout << "Colons sum:\n";
	arr::print_array(dest, 3);
	return (0);
}

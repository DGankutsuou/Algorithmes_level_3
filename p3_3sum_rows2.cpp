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

void	calculate_3to3_matrix_rows_sum(int array[3][3], int dest[3])
{
	for(int i = 0; i < 3; i++)
		dest[i] = arr::calculat_sum_of_array(array[i], 3);
}

int	main(void)
{
	srand ((unsigned)time (NULL));
	int	arr[3][3];
	int	dest[3];

	fill_3to3_matrix_with_random_numbers(arr);
	print_3to3_matrix(arr);
	calculate_3to3_matrix_rows_sum(arr, dest);
	cout << "The sum of all rows in an array:" << endl;
	arr::print_array(dest, 3);
	return (0);
}

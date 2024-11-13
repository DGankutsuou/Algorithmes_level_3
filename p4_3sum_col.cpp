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

void	copy_3to3_colons_sum_matrix(int array[3][3])
{
	int	sum;

	for (int j = 0; j < 3; j++)
	{
		sum = 0;
		cout << "colon " << j + 1 << ": ";
		for(int i = 0; i < 3; i++)
			sum += array[i][j];
		cout << sum << endl;
	}
}

int	main(void)
{
	srand ((unsigned)time (NULL));
	int	arr[3][3];

	fill_3to3_matrix_with_random_numbers(arr);
	print_3to3_matrix(arr);
	copy_3to3_colons_sum_matrix(arr);
	return (0);
}

#include <iostream>
#include <iomanip>
using namespace std;

void	fill_3to3_matrix_with_ordered_numbers(int array[3][3])
{
	short	counter;

	counter = 1;
	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			array[i][j] = counter++;
}

void	transpose_3to3_matrix(int array[3][3])
{
	int	tmp[3][3];

	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			tmp[j][i] = array[i][j];
	for(int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			array[i][j] = tmp[i][j];
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

int	main(void)
{
	int	arr[3][3];

	fill_3to3_matrix_with_ordered_numbers(arr);
	print_3to3_matrix(arr);
	cout << endl;
	transpose_3to3_matrix (arr);
	print_3to3_matrix(arr);
	return (0);
}

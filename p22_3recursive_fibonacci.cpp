#include <iostream>
using namespace std;

int	ft_fibonacci(int index)
{
	int	nbr;

	if (index == 2 || index == 1)
		return (1);
	else if (index == 0)
		return (0);
	else if (index < 0)
		return (-1);
	nbr = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (nbr);
}

void	print_fibonacci_numbers_recursivly(int numbers)
{
	static int	save = numbers;
	if (numbers < 1)
		return ;
	if (numbers > 1)
		print_fibonacci_numbers_recursivly(numbers - 1);
	cout << ft_fibonacci(numbers);
	if (numbers != save)
		cout << " - ";
	if (numbers == save)
		cout << endl;
}

int	print_fibonacci_numbers_recursivly2(int numbers)
{
	
}

int	main(void)
{
	print_fibonacci_numbers_recursivly (10);
	print_fibonacci_numbers_recursivly2 (10);
	return (0);
}

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

void	print_fibonacci_numbers(int numbers)
{
	int	index;

	index = 1;
	while (index <= numbers)
	{
		cout << ft_fibonacci (index);
		if (index != numbers)
			cout << " - ";
		index++;
	}
	cout << endl;
}

void	print_fibonacci_numbers_recursivly(int numbers)
{
	if (numbers < 1)
		return ;
	print_fibonacci_numbers_recursivly(numbers - 1);
	cout << ft_fibonacci(numbers) << " - ";
}

int	main(void)
{
	print_fibonacci_numbers (10);
	print_fibonacci_numbers_recursivly (10);
	cout << endl;
	return (0);
}
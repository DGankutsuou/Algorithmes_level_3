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

void	print_fibonacci_numbers_by_loop(int numbers)
{
	int	previous1;
	int	previous2;
	int	fibonacci;

	if (numbers < 1)
		return ;
	cout << 1;
	previous1 = 1;
	previous2 = 0;
	for (int f = 2; f <= numbers; f++)
	{
		fibonacci = previous1 + previous2;
		cout << " - " << fibonacci;
		previous2 = previous1;
		previous1 = fibonacci;
	}
	cout << endl;
}

int	main(void)
{
	print_fibonacci_numbers (10);
	print_fibonacci_numbers_by_loop (10);
	return (0);
}
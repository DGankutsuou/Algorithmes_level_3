#include "libft.hpp"

int	main(void)
{
	char	c;

	cout << "Enter a char: ";
	cin >> c;
	cout << "inverted: " << ft::invert_char(c) << endl;
	return (0);
}
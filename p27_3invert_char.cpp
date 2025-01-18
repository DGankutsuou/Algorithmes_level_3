#include "libft.hpp"

char	invertchar(char c)
{
	return (ft::ft_isupper(c) ? tolower(c) : toupper(c));
}

int	main(void)
{
	char	c;

	cout << "Enter a char: ";
	cin >> c;
	cout << "inverted: " << ft::ft_invert_char(c) << endl;
	cout << "inverted @abou-hadhoud: " << invertchar(c) << endl;
	return (0);
}
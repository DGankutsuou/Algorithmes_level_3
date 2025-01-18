#include "libft.hpp"

int	main(void)
{
	char	c;

	c = '\0';
	cout << "Enter a char: ";
	cin >> c;
	if (ft::ft_isvowel(c))
		cout << "This char is vowel" << endl;
	else
		cout << "This char is not vowel" << endl;
	return (0);
}
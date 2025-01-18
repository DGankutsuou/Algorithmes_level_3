#include "libft.hpp"
#include "inputslib.h"

void	str_vowels_count(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (ft::ft_isvowel(str[i]))
			cout << str[i] << " ";
	}
	cout << endl;
}

int	main(void)
{
	string	str;

	str = input::read_string();
	cout << "vowels: ";
	str_vowels_count (str);
	return (0);
}
#include "libft.hpp"

size_t	str_vowels_count(string str)
{
	size_t	counter;

	counter = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (ft::ft_isvowel(str[i]))
			counter++;
	}
	return (counter);
}

int	main(void)
{
	cout << "number of vowels: ";
	cout << str_vowels_count ("Hello, World!") << endl;
	return (0);
}
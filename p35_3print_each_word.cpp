#include "inputslib.h"
#include "libft.hpp"
#include <string>
#include <vector>

void	print_str_words(string str, string delim)
{
	string	word;
	short	pos;

	cout << "Words of this string:" << endl;
	while ((pos = str.find(delim)) != string::npos)
	{
		word = str.substr(0, pos);
		if (word != "")
			cout << "-> " << word << endl;
		str.erase(0, pos + delim.length());
	}
	if (str != "")
		cout << "-> " << str << endl;
}

int	main(void)
{
	char	*ptr;
	string	str;
	char	**words;

	str = input::read_string();
	ptr = &str[0];
	words = ft::ft_split(ptr, ' ');
	cout << "Words of this string:" << endl;
	while (*words != NULL)
	{
		printf ("-> %s\n", *words);
		words++;
	}
	cout << "Abou-hadhoud:" << endl;
	print_str_words(str, " ");
	return (0);
}

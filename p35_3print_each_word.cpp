#include "inputslib.h"
#include "libft.hpp"
#include <string>
#include <vector>

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
	return (0);
}

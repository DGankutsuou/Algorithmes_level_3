#include "libft.hpp"
#include "inputslib.h"

int	main(void)
{
	string	str;

	str = input::read_string();
	cout << ft::ft_strinvert(str) << endl;
	return (0);
}
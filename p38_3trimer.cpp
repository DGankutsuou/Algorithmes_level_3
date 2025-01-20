#include "inputslib.h"
#include "libft.hpp"
#include <string>
#include <vector>

void	trim_right(string &str)
{
	short	last;

	last = str.length() - 1;
	while (str[last] == ' ')
		last--;
	str.erase(last, str.length() - 1);
}

void	trim_left(string &str)
{
	short	last;

	last = 0;
	while (str[last] == ' ')
		last++;
	str.erase(0, last);
}

void	trim(string &str)
{
	trim_left(str);
	trim_right(str);
}

int	main(void)
{
	string	str;

	str = input::read_string();
	cout << "after triming:\n";
	trim(str);
	cout << "-> " << str << endl;
	return (0);
}

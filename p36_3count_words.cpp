#include "inputslib.h"
#include "libft.hpp"
#include <string>
#include <vector>

short	count_str_words(string str, string delim)
{
	string	word;
	short	pos;
	short	counter;

	counter = 0;
	while ((pos = str.find(delim)) != string::npos)
	{
		word = str.substr(0, pos);
		if (word != "")
			counter++;
		str.erase(0, pos + delim.length());
	}
	if (str != "")
		counter++;
	return (counter);
}

int	main(void)
{
	string	str;

	str = input::read_string();
	cout << "Number of words: ";
	cout << count_str_words(str, " ") << endl;
	return (0);
}

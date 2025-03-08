#include "inputslib.h"
#include "libft.hpp"
#include <string>
#include <vector>

vector <string>	spliter(string str, string delim)
{
	string	word;
	short	pos;
	vector <string> words;

	while ((pos = str.find(delim)) != string::npos)
	{
		word = str.substr(0, pos);
		if (word != "")
			words.push_back(word);
		str.erase(0, pos + delim.length());
	}
	if (str != "")
		words.push_back(str);
	return (words);
}

int	main(void)
{
	string	str;
	vector <string>	words;

	str = input::read_string("Enter a string: ");
	words = spliter(str, " ");
	cout << "Words are:\n";
	for (string &word : words)
	{
		cout << "-> " << word << endl;
	}
	return (0);
}

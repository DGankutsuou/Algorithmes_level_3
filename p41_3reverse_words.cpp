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

string	str_reverse(string str, string delim)
{
	string	joined;
	vector <string>	words;

	joined = "";
	words = spliter(str, " ");
	for (int i = words.size() - 1; i >= 0; i--)
	{
		joined += words[i] + delim;
	}
	return (joined.substr(0, joined.length() - delim.length()));
}

int	main(void)
{
	string	str;

	str = input::read_string();
	cout << "String reversed:\n";
	cout << "-> " << str_reverse(str, "; ") << endl;
	return (0);
}

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

string	str_replace_mc(string str, string delim, string to_replace, string replace_to, bool match_case = true)
{
	string	joined;
	vector <string>	words;

	joined = "";
	words = spliter(str, " ");
	for (int i = 0; i < words.size(); i++)
	{
		if (to_replace == words[i])
			joined += replace_to + delim;
		else if (!match_case && ft::lowerizer(to_replace) == ft::lowerizer(words[i]))
			joined += replace_to + delim;
		else
			joined += words[i] + delim;
	}
	return (joined.substr(0, joined.length() - delim.length()));
}

int	main(void)
{
	string	str;

	str = input::read_string();
	cout << "String replaced MC:\n";
	cout << "-> " << str_replace_mc(str, "; ", "USA", "MOROCCO") << endl;
	cout << "String replaced no MC:\n";
	cout << "-> " << str_replace_mc(str, "; ", "USA", "America", false) << endl;
	return (0);
}

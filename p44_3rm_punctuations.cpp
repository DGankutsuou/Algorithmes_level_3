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

string	str_replace(string str, string delim, string to_replace, string replace_to)
{
	string	joined;
	vector <string>	words;

	joined = "";
	words = spliter(str, " ");
	for (int i = 0; i < words.size(); i++)
	{
		if (to_replace == words[i])
			joined += replace_to + delim;
		else
			joined += words[i] + delim;
	}
	return (joined.substr(0, joined.length() - delim.length()));
}

string	str_replace2(string str, string to_replace, string replace_to)
{
	short	pos;

	pos = str.find(to_replace);
	while (pos != string::npos)
	{
		str.replace(pos, to_replace.length(), replace_to);
		pos = str.find(to_replace);
	}
	return (str);
}

string	rm_punctuations(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (ispunct(str[i]))
			str.erase(i, 1);
	}
	return (str);
}

int	main(void)
{
	string	str;

	str = input::read_string();
	cout << "Punctuations removed:\n";
	cout << "-> " << rm_punctuations (str) << endl;
	return (0);
}

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

string	str_replace(string str, string delim, string word1, string word2)
{
	string	joined;
	vector <string>	words;

	joined = "";
	words = spliter(str, " ");
	for (int i = 0; i < words.size(); i++)
	{
		if (word1 == words[i])
			joined += word2 + delim;
		else
			joined += words[i] + delim;
	}
	return (joined.substr(0, joined.length() - delim.length()));
}

int	main(void)
{
	string	str;

	str = input::read_string();
	cout << "String replaced:\n";
	cout << "-> " << str_replace(str, "; ", "USA", "MOROCCO") << endl;
	return (0);
}

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
		words.push_back(word);
	return (words);
}

string	joiner(vector <string> words, string delim)
{
	string	joined;

	joined = "";
	for (string &word : words)
		joined += word + delim;
	return (joined.substr(0, joined.length() - delim.length()));
}

int	main(void)
{
	string	str;
	vector <string>	words;

	str = input::read_string();
	words = spliter(str, " ");
	cout << "Original string:\n";
	cout << "-> " << joiner(words, "; ") << endl;
	return (0);
}

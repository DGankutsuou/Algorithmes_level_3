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

string	joiner(vector <string> words, string delim)
{
	string	joined;

	joined = "";
	for (string &word : words)
		joined += word + delim;
	return (joined.substr(0, joined.length() - delim.length()));
}

string	joiner(string words[100], short length, string delim)
{
	string	joined;

	joined = "";
	for (int i = 0; i < length; i++)
		joined += words[i] + delim;
	return (joined.substr(0, joined.length() - delim.length()));
}

int	main(void)
{
	string	str;
	string	words_arr[6] = {"hello,",
						"world!",
						"This",
						"is",
						"my",
						"solution."};
	vector <string>	words;

	str = input::read_string();
	words = spliter(str, " ");
	cout << "Original string:\n";
	cout << "-> " << joiner(words, "; ") << "\n";
	cout << "The array:\n";
	cout << "-> " << joiner(words_arr, 6, " ") << endl;
	return (0);
}

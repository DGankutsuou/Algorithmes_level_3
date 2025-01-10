#include <iostream>
#include <string>
using namespace std;

string	lowerizer(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = tolower(str[i]);
	}
	return (str);
}

string	capitalizer(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = toupper(str[i]);
	}
	return (str);
}

int	main(void)
{
	cout << capitalizer("abcd efgh ijkl") << endl;
	cout << lowerizer("ABCD EFGH IJKL") << endl;
	return (0);
}
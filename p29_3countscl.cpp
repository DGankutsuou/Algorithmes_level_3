#include "inputslib.h"
#include <string>
using namespace std;

size_t	small_letters_count(string str)
{
	size_t	counter = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (islower(str[i]))
			counter++;
	}
	return (counter);
}

size_t	upper_letters_count(string str)
{
	size_t	counter = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (isupper(str[i]))
			counter++;
	}
	return (counter);
}

int	main(void)
{
	string	str;

	str = input::read_string();
	cout << "string length       : " << str.length() << endl;
	cout << "string small letters: " << small_letters_count(str) << endl;
	cout << "string upper letters: " << upper_letters_count(str) << endl;
	return (0);
}
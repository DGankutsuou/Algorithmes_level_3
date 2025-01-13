#include <iostream>
using namespace std;

size_t	str_letter_count(string str, char c)
{
	size_t	counter;

	counter = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == c)
			counter++;
	}
	return (counter);
}

int	main(void)
{
	cout << str_letter_count ("Hahahaha, Hello World", 'l') << endl;
	return (0);
}
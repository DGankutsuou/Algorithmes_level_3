#include <iostream>
#include <string>
using namespace std;

size_t	str_letter_count_mc(string str, char c, bool mach_case = true)
{
	size_t	counter;

	counter = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (mach_case)
		{
			if (str[i] == c)
				counter++;
		}
		else
		{
			if (tolower(str[i]) == tolower(c))
				counter++;
		}
	}
	return (counter);
}

int	main(void)
{
	cout << str_letter_count_mc ("Hahahaha, Hello World, Limon", 'l') << endl;
	cout << str_letter_count_mc ("Hahahaha, Hello World, Limon", 'l', false) << endl;
	return (0);
}
#include <iostream>
using namespace std;

string	ft_strlowcase(string str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] >= 'A' && str[idx] <= 'Z')
			str[idx] += 32;
		idx++;
	}
	return (str);
}

int	main(void)
{
	cout << ft_strlowcase("HELLO, THIS IS LOWERCASE FUNCTION") << endl;
	return (0);
}
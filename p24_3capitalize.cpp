#include <iostream>
using namespace std;

string	ft_strcapitalize(string str)
{
	int	i;
	int	col;

	i = 0;
	col = 1;
	while (str[i])
	{
		if (col == 1 && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= '0' && str[i] <= '9')))
			col = 0;
		else if (col != 1 && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		col++;
		i++;
	}
	return (str);
}

int	main(void)
{
	cout << ft_strcapitalize("    Hello World, This is str capitalize     function  ") << endl;
	return (0);
}
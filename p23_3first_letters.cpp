#include <iostream>
using namespace std;

void	str_first_letters(string str)
{
	bool	not_space;

	not_space = false;
	if (str[0] != 0)
		cout << "First letters:" << endl;
	for (int i = 0; i < str.length(); i++)
	{
		not_space = ((str[i] != ' ' && (str[i] < 9 || str[i] > 13)) ? 1 : 0);
		if (i == 0 && not_space)
			cout << str[i] << endl;
		else if (str[i - 1] == ' ' || (str[i - 1] >= 9 && str[i - 1] <= 13))
		{
			if (not_space)
				cout << str[i] << endl;
		}
	}
}

int	main(void)
{
	str_first_letters("    Hello World, This is str first letters     function  ");
	return (0);
}
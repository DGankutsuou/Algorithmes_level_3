#pragma once
# include <iostream>
using namespace std;

namespace ft
{
	bool	ft_islower(char c)
	{
		if (c <= 'z' && c >= 'a')
			return (true);
		return (false);
	}

	bool	ft_isupper(char c)
	{
		if (c <= 'Z' && c >= 'A')
			return (true);
		return (false);
	}

	char	invert_char(char c)
	{
		if (ft_isupper(c))
			c += 32;
		else if (ft_islower(c))
			c -= 32;
		return (c);
	}

	string	ft_strinvert(string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			str[i] = invert_char(str[i]);
		}
		return (str);
	}
}
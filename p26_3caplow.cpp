#include <iostream>
#include <string>
using namespace std;

string	capitalizer(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			cout << toupper(str[i]) << endl;
		
	}
}

int	main(void)
{

	return (0);
}
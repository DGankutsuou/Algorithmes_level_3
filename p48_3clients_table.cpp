#include "libft.hpp"
#include "inputslib.h"
#include <fstream>

#define FILE_NAME "data_of_clients.txt"

void	print_clients_table(string file_name)
{
	fstream	file;

	file.open(FILE_NAME, ios::out);
	if (file.is_open())
	{
		
		file.close();
	}
}

int	main(void)
{
	print_clients_table(FILE_NAME);
	return (0);
}

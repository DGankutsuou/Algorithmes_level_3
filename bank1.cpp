#include <stdlib.h>
#include <cstdlib>
#include "inputslib.h"

void	show_main_menu_screen()
{
	system("clear");
	cout << "=====================================\n";
	cout << "              Main menu              \n";
	cout << "=====================================\n";
	cout << "\t[1]: Show clients list\n";
	cout << "\t[2]: Add new client\n";
	cout << "\t[3]: Delete client\n";
	cout << "\t[4]: Update client\n";
	cout << "\t[5]: Find client\n";
	cout << "\t[6]: Exit\n";
	cout << "=====================================\n" << endl;
}

void	bank_system()
{
	while (1)
	{
		show_main_menu_screen();
		break ;
	}
}

int	main(void)
{
	bank_system();
	return (0);
}

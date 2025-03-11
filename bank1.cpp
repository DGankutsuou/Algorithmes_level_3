#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include "inputslib.h"
#include "libft.hpp"

#define FILE_NAME "data_of_clients.txt"

struct s_data
{
	string	acount_number;
	string	pin_code;
	string	name;
	string	phone;
	string	acount_balance;
};

s_data	split_record(string str)
{
	s_data	data;
	vector <string> splited;

	splited = ft::spliter(str, "#//#");
	data.acount_number = splited[0];
	data.pin_code = splited[1];
	data.name = splited[2];
	data.phone = splited[3];
	data.acount_balance = splited[4];
	return (data);
}

void	load_file_to_vector(string file_name, vector <string> &v_file)
{
	fstream	file;
	string	line;

	file.open(file_name, ios::in); // read mode
	if (file.is_open())
	{
		while (getline(file, line))
			v_file.push_back(line);
		file.close();
	}
}

void	print_header(short number_of_clients)
{
	cout << "\n\t\t\t\t***Clients list (" << number_of_clients << ")***\n";
	for (int i = 0; i < 20; i++)
	{
		cout << "_____";
	}
	cout << '\n';
	cout << "| Acount number\t| Pin code\t| Client name\t\t\t";
	cout << "| Phone number\t| Acount balance\n";
	for (int i = 0; i < 20; i++)
	{
		cout << "_____";
	}
	cout << endl;
}

void	line_printer(string &line)
{
	s_data	data;

	data = split_record(line);
	cout << "| " << left << setw(14) << data.acount_number;
	cout << "| " << left << setw(14) << data.pin_code;
	cout << "| " << left << setw(30) << data.name;
	cout << "| " << left << setw(14) << data.phone;
	cout << "| " << left << setw(14) << data.acount_balance;
	cout << endl;
}

void	print_clients_table(vector <string> &v_file)
{
	print_header(v_file.size());
	for (string &line : v_file)
	{
		line_printer(line);
	}
	for (int i = 0; i < 20; i++)
	{
		cout << "_____";
	}
	cout << endl;
}

void	act(short choise)
{
	vector <string>	v_file;

	load_file_to_vector(FILE_NAME, v_file);
	switch (choise)
	{
		case 1:
			print_clients_table(v_file);
		// case 2:
		// case 3:
		// case 4:
		// case 5:
		// default:
	}
}

void	show_main_menu_screen(void)
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
	short	choise;
	char	pause;

	while (1)
	{
		show_main_menu_screen();
		choise = input::read_number_in_range(1, 6);
		act(choise);
		cout << "\nPress any key to return into main menu...";
		cin.clear();
		cin.get();
		break ;
	}
}

int	main(void)
{
	bank_system();
	return (0);
}

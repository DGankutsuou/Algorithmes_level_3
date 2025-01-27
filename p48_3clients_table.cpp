#include "libft.hpp"
#include "inputslib.h"
#include <fstream>
#include <iomanip>

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

int	main(void)
{
	vector <string>	v_file;

	load_file_to_vector(FILE_NAME, v_file);
	print_clients_table(v_file);
	return (0);
}

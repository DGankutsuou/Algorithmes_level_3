#include "inputslib.h"
#include "libft.hpp"
#include <stdlib.h>
#include <fstream>

#define FILE_NAME "data_of_clients.txt"

struct s_data
{
	string	acount_number;
	string	pin_code;
	string	name;
	string	phone;
	string	acount_balance;
};

s_data	read_new_client()
{
	s_data data;

	cout << "Enter accounnt number: ";
	getline(cin >> ws, data.acount_number);
	data.pin_code = input::read_string("Enter pin code: ");
	data.name = input::read_string("Enter client name: ");
	data.phone = input::read_string("Enter client phone number: ");
	data.acount_balance = input::read_string("Enter acount balance: ");
	return (data);
}

string	record_data(s_data &data)
{
	string	record;
	string	delim;

	record = "";
	delim = "#//#";
	record += data.acount_number + delim;
	record += data.pin_code + delim;
	record += data.name + delim;
	record += data.phone + delim;
	record += data.acount_balance;
	return (record);
}

void	save_record_to_file(string file_name, string record)
{
	fstream	file;

	file.open(FILE_NAME, ios::app);
	if (file.is_open())
	{
		file << record << endl;
		file.close();
	}
	else
	{
		cerr << "Failed to write in file :(" << endl;
		exit(1);
	}
}

void	add_new_client()
{
	s_data	data;

	data = read_new_client();
	save_record_to_file(FILE_NAME, record_data(data));
}

void	add_clients()
{
	char	add_more;

	add_more = 'y';
	do
	{
		system("cls");
		cout << "\n*Adding new client*\n\n";
		add_new_client();
		cout << "\nClient added successfuly. Dost Thou desire to add more: ";
		cin >> add_more;
	} while (tolower(add_more) == 'y');
}

int	main(void)
{
	add_clients();
	return (0);
}
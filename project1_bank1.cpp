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
	bool	to_be_deleted = false;
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

void	print_data(s_data &data)
{
	cout << "\nClient data:\n\n";
	cout << "Acount number : " << data.acount_number << "\n";
	cout << "Pin code      : " << data.pin_code << "\n";
	cout << "Client name   : " << data.name << "\n";
	cout << "Phone number  : " << data.phone << "\n";
	cout << "Acount balance: " << data.acount_balance << endl;
}

void	load_file_to_data_vector(string file_name, vector <s_data> &v_data)
{
	fstream	file;
	string	line;
	s_data	data;

	file.open(file_name, ios::in); // read mode
	if (file.is_open())
	{
		while (getline(file, line))
		{
			data = split_record(line);
			v_data.push_back(data);
		}
		file.close();
	}
	else
	{
		cerr << "Error: unable to open file" << endl;
		exit (0);
	}
}

bool	search_by_id(vector <s_data> &v_data, string id, s_data &client)
{
	for (s_data &data : v_data)
	{
		if (data.acount_number == id)
		{
			client = data;
			return (true);
		}
	}
	return (false);
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

bool	mark_client_to_be_deleted_by_id(string id, vector <s_data> &v_data)
{
	for (s_data &data : v_data)
	{
		if (data.acount_number == id)
		{
			data.to_be_deleted = true;
			return (true);
		}
	}
	cerr << "Error: Account number (" << id << ") not found" << endl;
	return (false);
}

void	save_clients_to_file(string file_name, vector <s_data> &v_data)
{
	fstream	file;
	string	record;

	file.open(FILE_NAME, ios::out);
	if (file.is_open())
	{
		for (s_data &data : v_data)
		{
			if (!data.to_be_deleted)
			{
				record = record_data(data);
				file << record << endl;
			}
		}
		file.close();
	}
	else
	{
		cerr << "Failed to open file :(" << endl;
		exit(1);
	}
}

bool	delete_client_by_id(string id, vector <s_data> &v_data)
{
	char	answer;
	s_data	client;

	answer = 'n';
	if (search_by_id(v_data, id, client))
	{
		print_data(client);
		cout << "Do you wish to delete this client? (Y/N)\n-> ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			mark_client_to_be_deleted_by_id(id, v_data);
			save_clients_to_file(FILE_NAME, v_data);
			load_file_to_data_vector(FILE_NAME, v_data);
			cout << "Client deleted successfuly" << endl;
			return (true);
		}

	}
	else
	{
		cerr << "Error: Account number (" << id << ") not found" << endl;
		return (false);
	}
	return (false);
}

bool	clients_deleter(vector <s_data> &v_data)
{
	string	id;

	system ("clear");
	cout << "Enter client's account number: ";
	getline(cin >> ws, id);
	return (delete_client_by_id(id, v_data));
}

s_data	read_new_client(vector <s_data> &v_data)
{
	s_data	data;

	cout << "Enter accounnt number: ";
	getline(cin >> ws, data.acount_number);
	while (search_by_id(v_data, data.acount_number, data))
	{
		cout << "This account number allready exist\n";
		cout << "Enter another number: ";
		getline(cin >> ws, data.acount_number);
	}
	data.pin_code = input::read_string("Enter pin code: ");
	data.name = input::read_string("Enter client name: ");
	data.phone = input::read_string("Enter client phone number: ");
	data.acount_balance = input::read_string("Enter acount balance: ");
	return (data);
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

void	add_new_client(vector <s_data> &v_data)
{
	s_data	data;

	data = read_new_client(v_data);
	save_record_to_file(FILE_NAME, record_data(data));
	v_data.push_back(data);
}

void	add_clients(vector <s_data> &v_data)
{
	char	add_more;

	add_more = 'y';
	do
	{
		system ("clear");
		cout << "\n*Adding new client*\n\n";
		add_new_client(v_data);
		cout << "\nClient added successfuly. Dost Thou desire to add more (Y/N)?\n-> ";
		cin >> add_more;
	} while (tolower(add_more) == 'y');
}

void	load_file_to_str_vector(string file_name, vector <string> &v_file)
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
	system ("clear");
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

s_data	change_client_infos(string id)
{
	s_data data;

	data.acount_number = id;
	cout << "Enter pin code: ";
	getline(cin >> ws, data.pin_code);
	data.name = input::read_string("Enter client name: ");
	data.phone = input::read_string("Enter client phone number: ");
	data.acount_balance = input::read_string("Enter acount balance: ");
	return (data);
}

bool	update_client_by_id(string id, vector <s_data> &v_clients)
{
	char	answer;
	s_data	client;

	answer = 'n';
	if (search_by_id(v_clients, id, client))
	{
		print_data(client);
		cout << "Do you wish to update this client infos? (Y/N)\n-> ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			for (s_data &data : v_clients)
			{
				if (data.acount_number == id)
				{
					data = change_client_infos(id);
					break ;
				}
			}
			save_clients_to_file(FILE_NAME, v_clients);
			cout << "Client updated successfuly" << endl;
			return (true);
		}
	}
	else
	{
		cerr << "Error: Account number (" << id << ") not found" << endl;
		return (false);
	}
	return (false);
}

bool	client_updater()
{
	return (update_client_by_id());
}

void	act(short choise)
{
	vector <string>	v_file;
	vector <s_data>	v_data;

	load_file_to_str_vector(FILE_NAME, v_file);
	load_file_to_data_vector(FILE_NAME, v_data);
	switch (choise)
	{
		case 1:
			print_clients_table(v_file);
			break ;
		case 2:
			add_clients(v_data);
			break ;
		case 3:
			clients_deleter(v_data);
			break ;
		case 4:

			break ;
		// case 5:
			break ;
		default:
			exit (0);
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
	cout << "\t[4]: Update client infos\n";
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
		cin >> pause;
	}
}

int	main(void)
{
	bank_system();
	return (0);
}

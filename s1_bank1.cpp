#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include "inputslib.h"
#include "libft.hpp"

#define FILE_NAME "data_of_clients.txt"

void	show_main_menu_screen(void);

enum e_main_menu_option
{
	e_show_clients_list = 1,
	e_add_new_client = 2,
	e_delete_client = 3,
	e_update_client_infos = 4,
	e_find_client = 5,
	e_exit = 6
};

struct s_data
{
	string	acount_number;
	string	pin_code;
	string	name;
	string	phone;
	string	acount_balance;
	bool	to_be_deleted = false;
};

string	read_account_number()
{
	string	account_number;

	cout << "Enter client's account number: ";
	getline(cin >> ws, account_number);
	return (account_number);
}

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

vector <s_data>	load_file_to_data_vector(string file_name)
{
	vector <s_data>	v_data;
	fstream			file;
	string			line;
	s_data			data;

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
	return (v_data);
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
	char			answer;
	s_data			client;

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
			v_data = load_file_to_data_vector(FILE_NAME);
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

bool	is_client_exist_by_id(string account_number, string file_name)
{
	fstream	file;

	file.open(file_name, ios::in);
	if (file.is_open() == true)
	{
		string	line;
		s_data	data;
		while (getline(file, line))
		{
			data = split_record(line);
			if (data.acount_number == account_number)
			{
				file.close();
				return (true);
			}
		}
		file.close();
		return (false);
	}
	else
	{
		cerr << "Error: Unable to open file: \"" << file_name << "\"" << endl;
		exit (1);
	}
}

s_data	read_new_client()
{
	s_data			data;
	vector <s_data>	v_data;

	v_data = load_file_to_data_vector(FILE_NAME);
	cout << "Enter accounnt number: ";
	getline(cin >> ws, data.acount_number);
	while (is_client_exist_by_id(data.acount_number, FILE_NAME))
	{
		cout << "This account number (" << data.acount_number
			<< ") allready exist\n";
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

	file.open(file_name, ios::app);
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
	s_data			data;
	data = read_new_client();
	save_record_to_file(FILE_NAME, record_data(data));
}

void	add_new_clients()
{
	char	add_more;

	add_more = 'y';
	do
	{
		cout << "\n*Adding new client*\n\n";
		add_new_client();
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
	cout << "\n\t\t***Clients list (" << number_of_clients << ")***\n";
	for (int i = 0; i < 5; i++)
	{
		cout << "____________________";
	}
	cout << '\n';
	cout << "| Acount number\t| Pin code\t| Client name\t\t";
	cout << "| Phone number\t| Acount balance\n";
	for (int i = 0; i < 5; i++)
	{
		cout << "____________________";
	}
	cout << endl;
}

void	line_printer(s_data &data)
{
	cout << "| " << left << setw(14) << data.acount_number;
	cout << "| " << left << setw(14) << data.pin_code;
	cout << "| " << left << setw(30) << data.name;
	cout << "| " << left << setw(14) << data.phone;
	cout << "| " << left << setw(14) << data.acount_balance;
	cout << endl;
}

void	print_clients_table()
{
	vector <s_data>	v_data;

	v_data = load_file_to_data_vector(FILE_NAME);
	if (v_data.size() == 0)
		cout << "No available clients in the system" << endl;
	else
	{
		print_header(v_data.size());
		for (s_data &data : v_data)
		{
			line_printer(data);
		}
		for (int i = 0; i < 5; i++)
		{
			cout << "____________________";
		}
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

bool	update_client_by_id(string id, vector <s_data> &v_data)
{
	char	answer;
	s_data	client;

	answer = 'n';
	if (search_by_id(v_data, id, client))
	{
		print_data(client);
		cout << "Do you wish to update this client infos? (Y/N)\n-> ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			for (s_data &data : v_data)
			{
				if (data.acount_number == id)
				{
					data = change_client_infos(id);
					break ;
				}
			}
			save_clients_to_file(FILE_NAME, v_data);
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

void	show_add_new_clients_screen(void)
{
	cout << "________________________________\n";
	cout << "\tAdd new clients\n";
	cout << "________________________________\n" << endl;
	add_new_clients();
}

void	show_delete_client_screen(void)
{
	string			account_number;
	vector <s_data>	v_data;

	cout << "________________________________\n";
	cout << "\tDelete client\n";
	cout << "________________________________\n" << endl;
	v_data = load_file_to_data_vector(FILE_NAME);
	account_number = read_account_number();
	delete_client_by_id(account_number, v_data);
}

void	show_update_client_screen(void)
{
	string			account_number;
	vector <s_data>	v_data;

	cout << "________________________________\n";
	cout << "\tUpdate client\n";
	cout << "________________________________\n" << endl;
	v_data = load_file_to_data_vector(FILE_NAME);
	account_number = read_account_number();
	update_client_by_id(account_number, v_data);
}

void	show_find_client_screen(void)
{
	vector <s_data>	v_data;
	s_data			client;
	string			account_number;

	cout << "________________________________\n";
	cout << "\tFind client\n";
	cout << "________________________________\n" << endl;
	v_data = load_file_to_data_vector(FILE_NAME);
	account_number = read_account_number();
	if (search_by_id(v_data, account_number, client))
		print_data(client);
	else
	{
		cout << "Client with account number (" <<
		account_number << ") is not found" << endl;
	}
}

void	show_exit_screen()
{
	cout << "________________________________\n";
	cout << "\tProgram exited\n";
	cout << "________________________________\n" << endl;
}

void	back_to_main_menu(void)
{
	char	back;

	cout << "press any key to go back to main menu...";
	cin >> back;
	show_main_menu_screen();
}

void	perform_option(e_main_menu_option option)
{
	switch (option)
	{
		case e_main_menu_option::e_show_clients_list:
			system ("clear");
			print_clients_table();
			back_to_main_menu();
			break ;
		case e_main_menu_option::e_add_new_client:
			system ("clear");
			show_add_new_clients_screen();
			back_to_main_menu();
			break ;
		case e_main_menu_option::e_delete_client:
			system ("clear");
			show_delete_client_screen();
			back_to_main_menu();
			break ;
		case e_main_menu_option::e_update_client_infos:
			system ("clear");
			show_update_client_screen();
			back_to_main_menu();
			break ;
		case e_main_menu_option::e_find_client:
			system ("clear");
			show_find_client_screen();
			back_to_main_menu();
			break ;
		case e_main_menu_option::e_exit:
			system ("clear");
			show_exit_screen();
			break ;
		default:
			exit (0);
	}
}

short	read_option()
{
	short	option;

	option = input::read_number_in_range(1, 6);
	return (option);
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
	perform_option(e_main_menu_option(read_option()));
}

int	main(void)
{
	show_main_menu_screen();
	return (0);
}

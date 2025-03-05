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

void	load_file_to_vector(string file_name, vector <s_data> &v_file)
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
			v_file.push_back(data);
		}
		file.close();
	}
	else
	{
		cerr << "Error: unable to open file" << endl;
		exit (0);
	}
}
/*
void	load_file_to_data_vector(string file_name, vector <s_data> &v_file)
{
	fstream	file;
	string	line;

	file.open(file_name, ios::in); // read mode
	if (file.is_open())
	{
		while (getline(file, line))
			v_file.push_back(split_record(line));
		file.close();
	}
}
*/

bool	search_by_id(vector <s_data> &v_file, string id, s_data &client)
{
	for (s_data &data : v_file)
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

bool	mark_client_to_be_deleted_by_id(string id, vector <s_data> &v_clients)
{
	for (s_data &data : v_clients)
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

void	save_clients_to_file(string file_name, vector <s_data> &v_clients)
{
	fstream	file;
	string	record;

	file.open(FILE_NAME, ios::out);
	if (file.is_open())
	{
		for (s_data &data : v_clients)
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

bool	delete_client_by_id(string id, vector <s_data> &v_clients)
{
	char	answer;
	s_data	client;

	answer = 'n';
	if (search_by_id(v_clients, id, client))
	{
		print_data(client);
		cout << "Do you wish to delete this client? (Y/N)\n-> ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			mark_client_to_be_deleted_by_id(id, v_clients);
			save_clients_to_file(FILE_NAME, v_clients);
			load_file_to_vector(FILE_NAME, v_clients);
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

int	main(void)
{
	string			id;
	string			answer;
	vector <s_data>	v_file;

	load_file_to_vector(FILE_NAME, v_file);
	id = input::read_string("Enter account number: ");
	delete_client_by_id(id, v_file);
	return (0);
}

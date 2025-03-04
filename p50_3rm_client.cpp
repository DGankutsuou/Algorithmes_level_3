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

void	print_data(s_data &data)
{
	cout << "\nClient data:\n\n";
	cout << "Acount number : " << data.acount_number << "\n";
	cout << "Pin code      : " << data.pin_code << "\n";
	cout << "Client name   : " << data.name << "\n";
	cout << "Phone number  : " << data.phone << "\n";
	cout << "Acount balance: " << data.acount_balance << endl;
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

void	search_by_id(vector <string> &v_file, string id)
{
	s_data	data;

	for (string &line : v_file)
	{
		if (line.find(id) != string::npos)
		{
			data = split_record(line);
			print_data(data);
			return ;
		}
	}
	cerr << "Error: Account number (" << id << ") not found" << endl;
	exit (0);
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

void	rm_client(string file_name, string id)
{
	vector <s_data>	v_file;
	fstream			file;

	load_file_to_data_vector(file_name, v_file);
	file.open(file_name, ios::trunc | ios::out);
	for (s_data &data : v_file)
	{
		if (data.acount_number != id)
			file << record_data(data) << endl;
	}
	file.close();
	cout << "Data purged successfuly" << endl;
}

int	main(void)
{
	string			id;
	string			answer;
	vector <string>	v_file;

	load_file_to_vector(FILE_NAME, v_file);
	cout << "Enter the account number: ";
	cin >> id;
	search_by_id(v_file, id);
	cout << "\nDo you wish to purge the file from this client (yes/no)?\n-> ";
	cin >> answer;
	if (answer == "yes")
		rm_client(FILE_NAME, id);
	else
		exit (0);
	return (0);
}

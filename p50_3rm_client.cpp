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

void	search_by_id(vector <string> &v_file)
{
	string	id = "";
	s_data	data;

	cout << "Enter the account number: ";
	cin >> id;
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
}

int	main(void)
{
	vector <string>	v_file;

	load_file_to_vector(FILE_NAME, v_file);
	search_by_id(v_file);
	return (0);
}

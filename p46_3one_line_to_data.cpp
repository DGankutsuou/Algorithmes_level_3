#include "inputslib.h"
#include "libft.hpp"

struct s_data
{
	string	acount_number;
	string	pin_code;
	string	name;
	string	phone;
	string	acount_balance;
};

s_data	read_data()
{
	s_data data;

	data.acount_number = input::read_string("Enter acount number: ");
	data.pin_code = input::read_string("Enter pin code: ");
	data.name = input::read_string("Enter client name: ");
	data.phone = input::read_string("Enter client phone number: ");
	data.acount_balance = input::read_string("Enter acount balance: ");
	return (data);
}

vector <string>	put_data_in_vector(s_data &data)
{
	vector <string>	v_data;

	v_data.push_back(data.acount_number);
	v_data.push_back(data.pin_code);
	v_data.push_back(data.name);
	v_data.push_back(data.phone);
	v_data.push_back(data.acount_balance);
	return (v_data);
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
	cout << "\nclient data:\n\n";
	cout << "Acount number : " << data.acount_number << "\n";
	cout << "Pin code      : " << data.pin_code << "\n";
	cout << "Client name   : " << data.name << "\n";
	cout << "Phone number  : " << data.phone << "\n";
	cout << "Acount balance: " << data.acount_balance << endl;
}

int	main(void)
{
	s_data			data;
	string			data_record;
	vector <string>	v_data;

	cout << "Enter client data:\n\n";
	data = read_data();
	cout << "\ndata record to be saved\n\n";
	v_data = put_data_in_vector(data);
	data_record = ft::joiner(v_data, "#//#");
	cout << data_record << endl;
	data = split_record(data_record);
	print_data(data);
	return (0);
}
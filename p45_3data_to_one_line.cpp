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

void	read_data(s_data &data)
{
	data.acount_number = input::read_string("Enter acount number: ");
	data.pin_code = input::read_string("Enter pin code: ");
	data.name = input::read_string("Enter client name: ");
	data.phone = input::read_string("Enter client phone number: ");
	data.acount_balance = input::read_string("Enter acount balance: ");
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

int	main(void)
{
	s_data	data;
	vector <string>	v_data;

	cout << "Enter client data:\n\n";
	read_data(data);
	cout << "\ndata record to be saved\n\n";
	v_data = put_data_in_vector(data);
	cout << ft::joiner(v_data, "#//#") << endl;
	return (0);
}
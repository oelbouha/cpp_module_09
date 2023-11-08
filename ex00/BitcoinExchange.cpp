/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:43:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/08 16:50:10 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	this->value = 0;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
	{
		database.clear();
		database = copy.database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){
	database.clear();
}

string BitcoinExchange::getDate(string line, string delimetre)
{
	int	pos;

	pos = line.find(delimetre);
	if (pos == -1)
	{
		date = line;
		throw "Error: bad input => ";
	}
	return (line.substr(0, pos));
}

void	BitcoinExchange::check_line(string line)
{
	string 	year;
	string 	month;
	string 	day;
	int		pos;

	pos = line.find("-");
	year = line.substr(0, pos);
	line = line.substr(pos + 1);
	pos = line.find("-");
	month = line.substr(0, pos);
	line = line.substr(pos + 1);
	pos = line.find(" ");
	day = line.substr(0, pos);
	is_valid_format(line.substr(pos), " | ");
	line = line.substr(pos + 3);
	valid_date(year, month, day);
	is_valid_number(line);
	this->value = std::strtod(line.c_str(), NULL);
	if (this->value >= 1000)
		throw "Error: too large a number.";
}

void	BitcoinExchange::parsing_line(string line)
{
	iterator 	it;

	date = getDate(line, " ");
	check_line(line);
	it = database.find(date);
	if (it == database.end())
	{
		it = database.upper_bound(date);
		--it;
		cout << date << " => " << value;
		cout << " = " << it->second * value <<  endl;
	}
	else
		cout << date<< " => "<< value<< " = "<< it->second * value << endl;
}

void	BitcoinExchange::read_file(char *filename)
{	
	std::ifstream	file(filename);
	string 			line;

	if (file.is_open() == false)
		throw "error: couldn't open input file";
	while (std::getline(file, line))
	{
		try
		{
			parsing_line(line);
		}
		catch(const char * error)
		{
			if (strcmp(error, "Error: bad input => ") == 0)
				cout << error << date << endl;
			else
				cout << error << endl;
		}
	}
}

void	BitcoinExchange::setupDatabase()
{	
	std::ifstream	database_file("data.csv");
	string			line;
	string			date;
	double			value;

	if (!database_file.is_open())
		throw "error: couldn't database file";
	while (std::getline(database_file, line))
	{
		date = getDate(line, ",");
		line = line.substr(line.find(",") + 1);
		value = std::strtod(line.c_str(), NULL);
		database[date] = value;
	}
}
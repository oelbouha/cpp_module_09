/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:28:19 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/08 16:46:45 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	is_valid_format(string str, string substr)
{
	for(size_t i = 0; i < substr.length(); i++)
	{
		if (substr[i] != str[i])
			throw "Error: bad input => ";
	}
}

void	is_valid_number(string line)
{
	int	check;

	check = 0;
	if (line[0] == '-' || line == ".")
		throw "Error: not a positive number.";
	if (line[0] == '+')
		line = line[1];
	for(size_t i = 0; i < line.length(); i++)
	{
		if (line[i] == '.')
		{
			if (check)
				throw "Error: not a valid number.";
			check += 1;
		}	
		else if (!isdigit(line[i]))
			throw "Error: not a valid number.";
	}
}

void	valid_date(string year, string month, string day)
{
	int		day_value;
	int		month_value;

	if (day.length() != 2 || month.length() != 2 || year.length() != 4)
		throw "Error: bad input => ";
	is_valid_number(year);
	is_valid_number(month);
	is_valid_number(day);
	month_value = std::strtod(month.c_str(), NULL);
	day_value = std::strtod(day.c_str(), NULL);
	if (month_value > 12 || day_value > 31)
		throw "Error: bad input => ";
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:13:46 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/08 16:49:16 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class BitcoinExchange
{
	public:
		typedef std::map<string, double>::iterator iterator;
		typedef std::map<string, double> map;

	private:
		string	date;
		double	value;
		map 	database;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& original);
		~BitcoinExchange();

		string	getDate(string line, string delimetre);
		void	read_file(char *filename);
		void	check_line(string str);
		void	parsing_line(string line);
		void	setupDatabase();
};

void	is_valid_number(string date);
void	valid_date(string month, string day, string year);
void	is_valid_format(string str, string substr);

#endif
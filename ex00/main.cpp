/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:01:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/08 16:40:01 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void init(char __unused *filename)
{
	BitcoinExchange btc;

	try
	{
		btc.setupDatabase();
		btc.read_file(filename);
	}
	catch(const char *error)
	{
		cout << error << endl;
	}
	catch(const std::exception& e)
	{
		cout << e.what() << endl;
	}
}

int main(int c, char **v)
{
	if (c == 2)
		init(v[1]);
	else
		cout << "error: No file found" << endl;
	return 0;
}

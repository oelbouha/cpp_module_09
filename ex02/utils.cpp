/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:07:02 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/08 14:34:42 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

void	is_positive_number(string input)
{
	for(int i = 0; input[i]; ++i)
	{
		if (!isdigit(input[i]))
			std::invalid_argument("Not a positive number");
	}
}

bool	PmergeMe::more_than_one_pair(vectorOfVectors& arr)
{
	size_t i;

	i = 0;
	if (arr[0].size() == elementSize && arr[1].size() == elementSize)
		i += 2;
	if (arr[i].size() == elementSize && arr[i + 1].size() == elementSize)
		return true;
	return false;
}

void	PmergeMe::is_double(int num)
{
	vector::iterator it;

	it = std::find(data.begin(), data.end(), num);
	if (it != data.end())
		throw std::invalid_argument("There is double");
}

void	PmergeMe::store_numbers(char **av)
{
	long	num;

	for(int i = 0; av[i]; i++)
	{
		is_positive_number(av[i]);
		num = std::strtod(av[i], NULL);
		is_double(num);
		data.push_back(num);
	}
	copy = data;
}

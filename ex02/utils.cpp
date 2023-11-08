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
	for(int i = 0; input[i]; i++)
	{
		if (!isdigit(input[i]))
			std::invalid_argument("Not a positive number");
	}
}

bool	PmergeMe::more_than_one_element(vectorOfVectors& arr)
{
	size_t i;

	i = 0;
	if (arr[0].size() == elementSize && arr[1].size() == elementSize)
		i += 2;
	while (i < arr.size() - 1)
	{
		if (arr[i].size() == elementSize && arr[i + 1].size() == elementSize)
		 	return true;
		i++;
	}
	return false;
}

void	PmergeMe::sort_pair_elements(PmergeMe::vector& vec)
{
	int		temp;
	size_t	i;

	i = -1;
	while (++i < vec.size() - 1)
	{
		if (vec[i] > vec[i + 1])
		{
			temp = vec[i + 1];
			vec[i + 1] = vec[i];
			vec[i] = temp;
			i = -1;
		}
	}
}

void	PmergeMe::is_double(int num)
{
	vector_iterator it;

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

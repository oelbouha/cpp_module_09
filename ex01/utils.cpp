/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:27:08 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/22 11:27:21 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	is_number(string str)
{
	size_t i;

	for(i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	skip_spaces(string str)
{
	size_t i;

	for(i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (i);	
	}
	return (0);
}
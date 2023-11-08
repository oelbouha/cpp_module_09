/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:43:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/22 11:36:40 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){
	result = 0;
}

RPN::RPN(const RPN& other){
	*this = other;
}

RPN& RPN::operator=(const RPN& copy)
{
	if (this != &copy)
	{
		stack.clear();
		stack = copy.stack;
	}
	return (*this);
}

RPN::~RPN(){
	stack.clear();
}

void	RPN::execute_operation(string line)
{
	iterator	it;
	int			n1;
	int			n2;

	if (stack.size() <= 1)
		throw "error: not a valid input";
	it = stack.end();
	n1 = *--it;
	n2 = *--it;
	if (line == "+")
		result = n1 + n2;
	else if (line == "-")
		result = n2 - n1;
	else if (line == "*")
		result = n2 * n1;
	else if (line == "/")
		result = n2 / n1;
	stack.erase(it);
	stack.erase(++it);
	stack.push_back(result);
}

void	RPN::valid_input(string input)
{
	size_t	i;

	for(i = 0; i < input.length() - 1; i++)
	{
		if (isdigit(input[i]) && isdigit(input[i + 1]))
			throw "Not a valid input";
		else if (strchr(" */-+", input[i]) == NULL && !isdigit(input[i]))
			throw "Not a valid input";
	}
}

void	RPN::reverseNotation(string input)
{
	string	str;
	int		last;
	int		value;

	input = input.substr(skip_spaces(input));
	last = input.length();
	if (input[last - 1] == ' ')
		last = input.find_last_not_of(" \t") + 1;
	input = input.substr(0, last);
	while (input.length())
	{
		str = input.substr(0, 1);
		input = input.substr(1);
		input = input.substr(skip_spaces(input));
		if (is_number(str))
		{
			value = std::strtod(str.c_str(), NULL);
			stack.push_back(value);
		}
		else
			execute_operation(str);
	}
}

int	RPN::getResult()
{
	return (result);
}

int	RPN::stack_size()
{
	return (stack.size());
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:13:46 by oelbouha          #+#    #+#             */
/*   Updated: 2023/10/08 22:06:27 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <deque>

using std::cout;
using std::endl;
using std::string;

class RPN
{
	private:
		std::deque<int> stack;
		typedef std::deque<int>::iterator iterator;
		int	result;

	public:
		RPN();
		RPN(const RPN& other);
		RPN&	operator=(const RPN& original);
		~RPN();

		void	reverseNotation(string input);
		void	execute_operation(string str);
		void	valid_input(string input);
		int		getResult();
		int		stack_size();
};

int		skip_spaces(string str);
int		is_number(string str);

#endif
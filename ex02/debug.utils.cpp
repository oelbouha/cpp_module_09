/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.utils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:57:45 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/08 14:33:17 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

void	PmergeMe::print_container_elements(vector vec)
{
	vector::iterator cur;

	cur = vec.begin();
	while (cur != vec.end())
	{
		cout << *cur << " ";
		cur++;	
	}
}

void	PmergeMe::print_array_vectors(vectorOfVectors vec, string str)
{
	vectorOfVectors::iterator	cur;
	vector::iterator 	it;
	vector	temp;

	cout << str << ": \n{";
	cur = vec.begin();
	while (cur != vec.end())
	{
		cout << "[";
		for(it = cur->begin(); it != cur->end(); it++)
			cout << *it << " ";
		cout << "]";
		cur++;	
	}
	cout << "}" << endl;
}

void	PmergeMe::print_pendCain()
{
	vectorOfVectors::iterator	scnd;
	pend::iterator 				it;
	vector::iterator 			cur;

	printf("	--++++++++++++++++++++++++++++--    \n");
	cout << "pendChain" << ": \n{ \n";
	it = pendChain.begin();
	while (it != pendChain.end())
	{
		cout << "vec: { ";
		cur = it->first.begin();
		for(; cur != it->first.end(); cur++)
				cout << *cur << " ";
		cout << "}" << endl;
		it++;
	}
	cout << "}" << endl;
	printf("	--++++++++++++++++++++++++++++-- \n");
}
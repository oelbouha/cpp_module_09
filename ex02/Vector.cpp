/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:43:56 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/08 15:45:05 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

PmergeMe::PmergeMe()
{
	odd_number = -1;
	elementSize = 1;
}

PmergeMe::~PmergeMe(){}

PmergeMe::vector	PmergeMe::getData(){
	return (data);
}

PmergeMe::vector	PmergeMe::getCopy(){
	return (copy);
}

size_t	PmergeMe::getDataSize(){
	return (data.size());
}

bool compare(PmergeMe::vector first, PmergeMe::vector second)
{
	return (first.back() < second.back());
}

void	PmergeMe::update_pend(iterator_to_vecOfVectors it)
{
	pend_iterator P_it;

	for (P_it = pendChain.begin(); P_it != pendChain.end(); ++P_it)
	{
		if (P_it->second >= it)
			++P_it->second;
	}
}

void	PmergeMe::insert_pend_to_main()
{
	iterator_to_vecOfVectors	pos;
	iterator_to_vecOfVectors	it;
	pend_iterator	P_it;
	pend_iterator	end;
	pend_iterator	start;
	int	idx;

	long int jcb_stl[] = {
        2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366,
        2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, 699050,
        1398102, 2796202, 5592406, 11184810, 22369622, 44739242, 89478486,
        178956970, 357913942, 715827882, 1431655766, 2863311530, 5726623062,
        11453246122, 22906492246, 45812984490
    };
	idx = 0;
	while (pendChain.size())
	{
		end = pendChain.begin();
		start = pendChain.begin();
		for (int i = 0; i < jcb_stl[idx] - 1 && start != pendChain.end(); ++i)
			++start;
		if (start == pendChain.end())
			--start;
		while (true)
		{
			pos = std::lower_bound(mainChain.begin(), start->second, start->first, compare);
			it = mainChain.insert(pos, start->first);
			pendChain.erase(start);
			update_pend(it);
			if (start == end)
				break ;
			--start;
		}
		++idx;
	}
	if (rest.size())
	{
		mainChain.insert(mainChain.end(), rest);
		rest.clear();
	}
}

void	PmergeMe::insertion()
{
	V_vec = make_paires();
	create_main_and_pend(V_vec);
	insert_pend_to_main();
	flaten_data(mainChain);
	elementSize /= 2;
}

void	PmergeMe::create_main_and_pend(vectorOfVectors& V_vec)
{
	iterator_to_vecOfVectors it;
	iterator_to_vecOfVectors cur;
	pend_pair	pair;
	size_t		i;

	if (V_vec.back().size() != V_vec.begin()->size())
	{
		rest = V_vec[V_vec.size() - 1];
		V_vec.pop_back();
	}
	pendChain.clear();
	mainChain.clear();
	pendChain.reserve(data.size());
	mainChain.reserve(data.size());
	mainChain.push_back(V_vec[0]);
	it = mainChain.insert(mainChain.end(), V_vec[1]);
	for (i = 2; i < V_vec.size(); i++)
	{
		pair.first = V_vec[i];
		++i;
		it = mainChain.end();
		if (i < V_vec.size())
			it = mainChain.insert(mainChain.end(), V_vec[i]);
		pair.second = it;
		pendChain.push_back(pair);	
	}
}

void	PmergeMe::sort_elements(vectorOfVectors& arr)
{
	vector	second;
	vector	first;

	for (size_t i = 0; i < arr.size(); i += 2)
	{
		first = arr[i];
		second = arr[i + 1];
		if (second.size() != elementSize)
			break ;
		else if (first.back() > second.back())
			std::swap(arr[i], arr[i + 1]);
	}
}

PmergeMe::vectorOfVectors	PmergeMe::Sort_paires()
{
	iterator_to_vecOfVectors	cur;
	vectorOfVectors				V_vec;
	vector_iterator				it;
	
	V_vec = make_paires();
	sort_elements(V_vec);
	return (V_vec);
}

PmergeMe::vectorOfVectors	PmergeMe::create_paires()
{
	vectorOfVectors		V_vec;
	vector_iterator		it;
	vector		vec;
	size_t		i;

	it = data.begin();
	while (it != data.end())
	{
		i = -1;
		while (++i < elementSize && it != data.end())
		{
			vec.push_back(*it);
			it++;
		}
		if (elementSize == 2)
			sort_pair_elements(vec);
		V_vec.push_back(vec);
		vec.clear();
	}
	return (V_vec);
}

PmergeMe::vectorOfVectors	PmergeMe::make_paires()
{
	vectorOfVectors		V_vec;
	vector_iterator		it;

	if (data.size() % 2)
	{
		odd_number = data.back();
		data.pop_back();
	}
	V_vec = create_paires();
	if (odd_number != -1)
	{
		vector temp;
		temp.push_back(odd_number);
		V_vec.push_back(temp);
		odd_number = -1;
	}
	return (V_vec);
}

void	PmergeMe::flaten_data(vectorOfVectors& V_vec)
{
	iterator_to_vecOfVectors	V_it;
	vector_iterator 	it;

	data.clear();
	V_it = V_vec.begin();
	for (; V_it != V_vec.end(); V_it++)
	{
		for (it = V_it->begin(); it != V_it->end(); it++)
			data.push_back(*it);
	}
}

void	PmergeMe::mergeSort()
{
	if (data.size() == 1)
		return ;
	elementSize *= 2;
	V_vec = Sort_paires();
	flaten_data(V_vec);
	if (more_than_one_pair(V_vec))
		mergeSort();
	insertion();
}
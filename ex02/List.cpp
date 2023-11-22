/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:57:17 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/08 21:16:39 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"

PmergeMeList::PmergeMeList()
{
	first_step = false;
	sort = false;
	odd_number = -1;
	elementSize = 1;
}

PmergeMeList::list	PmergeMeList::getData(){
	return (data);
}

PmergeMeList::list	PmergeMeList::getCopy(){
	return (copy);
}

size_t	PmergeMeList::getDataSize(){
	return (data.size());
}

PmergeMeList::~PmergeMeList(){}

void	PmergeMeList::is_double(int num)
{
	list_iterator	it;

	it = std::find(data.begin(), data.end(), num);
	if (it != data.end())
		throw std::invalid_argument("There is double");
}

bool	PmergeMeList::more_than_one_pair(listOflists& arr)
{
	ite_to_lstOflists cur;

	cur = arr.begin();
	if (cur->size() == elementSize)
		++cur;
	if (cur->size() == elementSize)
		++cur;
	while (cur != arr.end())
	{
		if (cur->size() == elementSize)
		{
			++cur;
			if (cur->size() == elementSize)
				return true;
		}
		++cur;
	}
	return false;
}

void	PmergeMeList::store_numbers(char **av)
{
	long	num;

	for(int i = 0; av[i]; i++)
	{
		is_positive_number(av[i]);
		num = std::strtod(av[i], NULL);
		is_double(num);
		data.push_back(num);
	}
	copy = data;;
}


bool compare(PmergeMeList::list first, PmergeMeList::list second)
{
	return (first.back() < second.back());
}

void	PmergeMeList::sort_pair_elements(list& vec)
{
	list_iterator	it;
	list_iterator	next;
	list_iterator	cur;

	it = vec.begin();
	next = it;
	++next;
	if (*next < *it)
		std::iter_swap(it, next);
}

PmergeMeList::listOflists	PmergeMeList::create_paires()
{
	list_iterator	it;
	listOflists		V_vec;
	list			vec;
	size_t			i;

	it = data.begin();
	while (it != data.end())
	{
		i = -1;
		while (++i < elementSize && it != data.end())
		{
			vec.push_back(*it);
			++it;
		}
		if (sort == false && elementSize == 2)
		{
			sort_pair_elements(vec);
			sort = true;
		}
		V_vec.push_back(vec);
		vec.clear();
	}
	return (V_vec);
}

PmergeMeList::listOflists	PmergeMeList::make_paires()
{
	ite_to_lstOflists		it;
	listOflists				V_vec;
	list					temp;

	if (data.size() % 2)
	{
		odd_number = data.back();
		data.pop_back();
	}
	V_vec = create_paires();
	if (odd_number != -1)
	{
		temp.push_back(odd_number);
		V_vec.push_back(temp);
		odd_number = -1;
	}
	return (V_vec);
}

void	PmergeMeList::sort_elements(listOflists& arr)
{
	ite_to_lstOflists cur;
	ite_to_lstOflists next;

	next = arr.begin();
	++next;
	cur = arr.begin();
	for (size_t i = 0; i < arr.size() - 1;)
	{
		if (next == arr.end() || next->size() != elementSize)
			break ;
		else if (cur->back() > next->back())
			std::iter_swap(cur, next);
		std::advance(next, 2);
		std::advance(cur, 2);
		i += 2;
	}
}

PmergeMeList::listOflists	PmergeMeList::Sort_paires()
{
	ite_to_lstOflists	cur;
	listOflists			V_vec;
	listOflists			it;
	
	first_step = true;
	V_vec = make_paires();
	sort_elements(V_vec);
	return (V_vec);
}

void	PmergeMeList::flaten_data(PmergeMeList::listOflists& V_vec)
{
	ite_to_lstOflists	V_it;
	list_iterator 		it;

	data.clear();
	for (V_it = V_vec.begin(); V_it != V_vec.end(); ++V_it)
	{
		for (it = V_it->begin(); it != V_it->end(); ++it)
			data.push_back(*it);
	}
}


void	PmergeMeList::create_main_and_pend(listOflists& V_vec)
{
	ite_to_lstOflists	it;
	ite_to_lstOflists	cur;
	list_iterator		tmp;
	pend_pair			pair;
	list				temp;

	if (V_vec.back().size() != V_vec.begin()->size())
	{
		rest = V_vec.back();
		V_vec.pop_back();
	}
	pendChain.clear();
	mainChain.clear();
	mainChain.push_back(V_vec.front());
	V_vec.pop_front();
	if (V_vec.size())
	{
		mainChain.push_back(V_vec.front());
		V_vec.pop_front();
	}
	while (V_vec.size())
	{
		pair.first = V_vec.front();
		V_vec.pop_front();
		it = mainChain.end();
		if (!V_vec.empty())
			it = mainChain.insert(mainChain.end(), V_vec.front());
		pair.second = it;
		pendChain.push_back(pair);
		if (V_vec.size())
			V_vec.pop_front();
	}
}

void	PmergeMeList::insert_pend_to_main()
{
	ite_to_lstOflists	pos;
	ite_to_lstOflists	it;
	pend_iterator		P_it;
	pend_iterator		end;
	pend_iterator		start;
	int		idx;

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
			mainChain.insert(pos, start->first);
			pendChain.erase(start);
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

void	PmergeMeList::insertion()
{
	V_vec = make_paires();
	create_main_and_pend(V_vec);
	insert_pend_to_main();
	flaten_data(mainChain);
	elementSize /= 2;
}

void	PmergeMeList::mergeSort()
{
	if (first_step)
		elementSize *= 2;
	V_vec = Sort_paires();
	flaten_data(V_vec);
	if (more_than_one_pair(V_vec))
		mergeSort();
	insertion();
}

void	PmergeMeList::print_container_elements(list vec)
{
	list_iterator cur;

	cur = vec.begin();
	while (cur != vec.end())
	{
		cout << *cur << " ";
		cur++;	
	}
}

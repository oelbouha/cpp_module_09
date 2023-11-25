/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:03:05 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/08 15:43:03 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include "utils.hpp"
#include <sys/_types/_size_t.h>

class PmergeMeList
{
	public:
		typedef	std::list<int>								list;
		typedef std::list<list>								listOflists;
		typedef std::pair<list, listOflists::iterator>		pend_pair;
		typedef std::list<pend_pair >						pend;

	private:
		listOflists			mainChain;
		listOflists			V_vec;
		pend 				pendChain;
		list 				data;
		list 				copy;
		list 				rest;
		size_t				elementSize;
		long				odd_number;

	public:
		PmergeMeList();
		~PmergeMeList();

		listOflists		Sort_paires();
		listOflists		make_paires();
		listOflists		create_paires();
	
		size_t			getDataSize();
		list			getData();
		list			getCopy();
		void			insert_pend_to_main();
		void			sort_elements(listOflists& arr);
		void			flaten_data(listOflists& V_vec);
		void			insertion();
		bool 			more_than_one_pair(listOflists& arr);
		void			create_main_and_pend(listOflists& arr);
		void			is_double(int num);
		void			store_numbers(char **av);
		void			mergeSort();
		void			print_container_elements(list vec);
};

#endif
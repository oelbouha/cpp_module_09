/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:20:58 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/08 15:47:57 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "utils.hpp"

class PmergeMe
{
	public:
		typedef	std::vector<int>									vector;
		typedef std::vector<vector>									vectorOfVectors;
		typedef std::pair<vector, vectorOfVectors::iterator>		pend_pair;
		typedef std::vector<pend_pair>								pend;

	private:
		vectorOfVectors		mainChain;
		pend 				pendChain;
		size_t				elementSize;
		vector 				data;
		vector 				copy;
		vector 				rest;

	public:
		PmergeMe();
		~PmergeMe();

		vectorOfVectors		Sort_paires();
		vectorOfVectors		create_paires();
		size_t				getDataSize();
		vector				getData();
		vector				getCopy();
		void				insert_pend_to_main();
		void				sort_elements(vectorOfVectors& arr);
		void				flaten_data(vectorOfVectors& V_vec);
		void				insertion();
		bool 				more_than_one_pair(vectorOfVectors& arr);
		void				create_main_and_pend(vectorOfVectors& arr);
		void				update_pend(vectorOfVectors::iterator it);
		void				is_double(int num);
		void				store_numbers(char **av);
		void				mergeSort();
		
		void				print_array_vectors(vectorOfVectors arr, string str);
		void				print_pendCain();
		void				print_container_elements(vector vec);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:22:46 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/08 15:45:41 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include "List.hpp"


void	sort_using_vector(char **av)
{
	PmergeMe 		vec;
	time_point		start;
	time_point		end;

	vec.store_numbers(av);
	start = std::chrono::high_resolution_clock::now();
	vec.mergeSort();
	end = std::chrono::high_resolution_clock::now();
	std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	cout << "before : ";
	vec.print_container_elements(vec.getCopy());
	cout << endl << "after  : ";
	vec.print_container_elements(vec.getData());
	cout << endl << "Time to process a range of " << vec.getDataSize();
	cout << " elements with std::list : " << duration.count() << " us" << endl;
	cout << endl;
}

void	sort_using_list(char **av)
{
	PmergeMeList 	list;
	time_point		start;
	time_point		end;

	list.store_numbers(av);
	start = std::chrono::high_resolution_clock::now();
	list.mergeSort();
	end = std::chrono::high_resolution_clock::now();
	std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	cout << "before : ";
	list.print_container_elements(list.getCopy());
	cout << endl << "after  : ";
	list.print_container_elements(list.getData());
	cout << endl << "Time to process a range of " << list.getDataSize();
	cout << " elements with std::list : " << duration.count() << " us" << endl;
}


void init(char **av)
{
	try
	{
		sort_using_vector(av);
		sort_using_list(av);
	}
	catch(const std::exception& e)
	{
		cout << e.what() << endl;
	}
}

int main(int c, char **av)
{
	if (c != 1)
		init(&av[1]);
	else
		cout << "error: No input found" << endl;
	return 0;
}



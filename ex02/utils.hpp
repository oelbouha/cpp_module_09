/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 01:49:41 by oelbouha          #+#    #+#             */
/*   Updated: 2023/11/08 14:36:15 by oelbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <list>
#include <sys/_types/_size_t.h>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::string;

typedef std::chrono::high_resolution_clock::time_point	time_point;

void	is_positive_number(string input);


#endif
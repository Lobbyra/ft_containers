/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:40:22 by jecaudal          #+#    #+#             */
/*   Updated: 2021/02/04 12:03:31 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"

int		main(int argc, char **argv)
{
	ft::vector<int>	v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);

	std::cout << v.max_size() << std::endl;

	std::vector<int>	v_std;

	v_std.push_back(1);
	v_std.push_back(2);
	v_std.push_back(3);
	v_std.push_back(4);
	v_std.push_back(5);
	v_std.push_back(6);
	v_std.push_back(7);
	v_std.push_back(8);
	v_std.push_back(9);

	std::cout << v_std.max_size() << std::endl;

	return (0);
}

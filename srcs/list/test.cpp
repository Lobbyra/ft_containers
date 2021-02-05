/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:47:01 by jecaudal          #+#    #+#             */
/*   Updated: 2021/02/02 18:27:42 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>

int		main(int argc, char **argv)
{
	ft::list<int> lst_num1(10, 10);
	ft::list<int> lst_num2(lst_num1);

	std::cout << lst_num2 << std::endl;
	return (0);
}

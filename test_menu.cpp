/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_menu.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 08:46:37 by jecaudal          #+#    #+#             */
/*   Updated: 2021/02/17 09:06:02 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/test_tools/utils_tester.hpp"

void	main_vector(void);
void	main_list(void);
void	main_stack(void);
void	main_queue(void);
void	main_map(void);

int		main(void)
{
	std::vector<void(*)(void)>	v_mains;
	std::vector<std::string>	v_descriptions;

	v_mains.push_back(main_vector);
	v_descriptions.push_back("0 : tests VECTOR container");

	v_mains.push_back(main_list);
	v_descriptions.push_back("1 : tests LIST container");

	v_mains.push_back(main_stack);
	v_descriptions.push_back("2 : tests STACK container");

	v_mains.push_back(main_queue);
	v_descriptions.push_back("3 : tests QUEUE container");

	v_mains.push_back(main_map);
	v_descriptions.push_back("4 : tests MAP container");

	menu(v_mains, v_descriptions, "TESTER");
	return (0);
}

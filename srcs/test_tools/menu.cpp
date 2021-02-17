/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:55:55 by jecaudal          #+#    #+#             */
/*   Updated: 2021/02/17 09:53:57 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include "../stack/stack.hpp"

static void clearscreen() { std::cout << std::string( 100, '\n' ); }

static int to_int(char const *s)
{
	if ( s == NULL || *s == '\0' )
		throw std::invalid_argument("null or empty string argument");

	bool negate = (s[0] == '-');
	if ( *s == '+' || *s == '-' )
		++s;

	if ( *s == '\0')
		throw std::invalid_argument("sign character only.");

	int result = 0;
	while(*s)
	{
		if ( *s < '0' || *s > '9' )
			throw std::invalid_argument("invalid input string");
		result = result * 10 - (*s - '0');  //assume negative number
		++s;
	}
	return negate ? result : -result; //-result is positive!
}

template <typename T>
static void	print_vector(std::vector<T> lst)
{
	for (typename std::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
}

void	menu(std::vector<void(*)()> lst_funs, std::vector<std::string> lst_messages, std::string title)
{
	std::string		input_line;

	// INPUT CHECK
	if (lst_funs.size() != lst_messages.size())
	{
		std::cerr << "ERROR : There isn't a message for each function test." << std::endl;
		return ;
	}

	// WELCOME MESSAGE
	std::cout << "Welcome in " << title << " test." << std::endl;

	// INTERACTIVE LOOP
	while (1)
	{
		std::cout << "Select a tester in this list to run and compare the code :" << std::endl;
		std::cout << "([exit|quit] to leave)" << std::endl << std::endl;
		print_vector(lst_messages);

		// GET
		std::cout << "> ";
		std::getline(std::cin, input_line);
		if (input_line == "exit" || input_line == "quit" || input_line == "e" || input_line == "q")
			return;
		clearscreen();

		try
		{
			// EVAL
			unsigned int input_num = to_int(input_line.c_str());
			if (input_num >= lst_funs.size())
				throw std::invalid_argument(" ");

			// EXEC
			(*(lst_funs[input_num]))();
		}
		catch (std::invalid_argument &e)
		{
			std::cerr << \
			"🔴 Input error, you can enter only a number existing" \
			<< std::endl << std::endl;
		}
		catch (std::exception &e) {	std::cerr << e.what() << std::endl; }

		// ENDING LOOP WAIT
		if (title != "TESTER")
		{
			std::cout << std::endl <<"Press enter to select another test" << std::endl;
			std::getline(std::cin, input_line);
		}
		else
			clearscreen();
	}
}

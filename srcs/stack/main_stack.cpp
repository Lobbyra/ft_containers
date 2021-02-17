/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:20:44 by jecaudal          #+#    #+#             */
/*   Updated: 2021/02/17 09:13:43 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>
#include <vector>
#include "../test_tools/utils_tester.hpp"
#include "stack.hpp"

static void	test_non_member_ope_std()
{
	print_header("STD TEST NON MEMBER OPE");

	std::stack<int>	st_nums_one;
	std::stack<int>	st_nums_two;

	st_nums_one.push(0);
	st_nums_one.push(1);
	st_nums_one.push(10);
	st_nums_one.push(11);
	st_nums_one.push(100);
	st_nums_one.push(101);
	st_nums_one.push(110);
	st_nums_one.push(111);

	std::cout << "st_nums_one.push(0);" << std::endl;
	std::cout << "st_nums_one.push(1);" << std::endl;
	std::cout << "st_nums_one.push(10);" << std::endl;
	std::cout << "st_nums_one.push(11);" << std::endl;
	std::cout << "st_nums_one.push(100);" << std::endl;
	std::cout << "st_nums_one.push(101);" << std::endl;
	std::cout << "st_nums_one.push(110);" << std::endl;
	std::cout << "st_nums_one.push(111);" << std::endl << std::endl;

	st_nums_two.push(0);
	st_nums_two.push(1);
	st_nums_two.push(10);
	st_nums_two.push(11);
	st_nums_two.push(100);
	st_nums_two.push(101);
	st_nums_two.push(110);
	st_nums_two.push(111);
	st_nums_two.push(1000);

	std::cout << "st_nums_two.push(0);" << std::endl;
	std::cout << "st_nums_two.push(1);" << std::endl;
	std::cout << "st_nums_two.push(10);" << std::endl;
	std::cout << "st_nums_two.push(11);" << std::endl;
	std::cout << "st_nums_two.push(100);" << std::endl;
	std::cout << "st_nums_two.push(101);" << std::endl;
	std::cout << "st_nums_two.push(110);" << std::endl;
	std::cout << "st_nums_two.push(111);" << std::endl;
	std::cout << "st_nums_two.push(1000);" << std::endl << std::endl;

	std::cout << "#- EQUAL & NON-EQUAL -#" << std::endl << std::endl;
	std::cout << "st_nums_one == st_nums_one : " << std::boolalpha << (st_nums_one == st_nums_one) << std::endl;
	std::cout << "st_nums_one == st_nums_two : " << std::boolalpha << (st_nums_one == st_nums_two) << std::endl << std::endl;

	std::cout << "st_nums_one != st_nums_one : " << std::boolalpha << (st_nums_one != st_nums_one) << std::endl;
	std::cout << "st_nums_one != st_nums_two : " << std::boolalpha << (st_nums_one != st_nums_two) << std::endl << std::endl;

	std::cout << "#- SUPERIOR & EQUAL-SUPERIOR -#" << std::endl << std::endl;

	std::cout << "st_nums_one < st_nums_one = " << (st_nums_one < st_nums_one) << std::endl;
	std::cout << "st_nums_one < st_nums_two = " << (st_nums_one < st_nums_two) << std::endl;
	std::cout << "st_nums_two < st_nums_one = " << (st_nums_two < st_nums_one) << std::endl;
	std::cout << "st_nums_one <= st_nums_one = " << (st_nums_one <= st_nums_one) << std::endl;
	std::cout << "st_nums_one <= st_nums_two = " << (st_nums_one <= st_nums_two) << std::endl;
	std::cout << "st_nums_two <= st_nums_one = " << (st_nums_two <= st_nums_one) << std::endl << std::endl;

	std::cout << "#- INFERIOR & EQUAL-INFERIOR -#" << std::endl << std::endl;

	std::cout << "st_nums_one > st_nums_one = " << (st_nums_one > st_nums_one) << std::endl;
	std::cout << "st_nums_one > st_nums_two = " << (st_nums_one > st_nums_two) << std::endl;
	std::cout << "st_nums_two > st_nums_one = " << (st_nums_two > st_nums_one) << std::endl;
	std::cout << "st_nums_one >= st_nums_one = " << (st_nums_one >= st_nums_one) << std::endl;
	std::cout << "st_nums_one >= st_nums_two = " << (st_nums_one >= st_nums_two) << std::endl;
	std::cout << "st_nums_two >= st_nums_one = " << (st_nums_two >= st_nums_one) << std::endl << std::endl;

}

static void	test_non_member_ope()
{
	print_header("FT TEST NON MEMBER OPE");

	ft::stack<int>	st_nums_one;
	ft::stack<int>	st_nums_two;

	st_nums_one.push(0);
	st_nums_one.push(1);
	st_nums_one.push(10);
	st_nums_one.push(11);
	st_nums_one.push(100);
	st_nums_one.push(101);
	st_nums_one.push(110);
	st_nums_one.push(111);

	std::cout << "st_nums_one.push(0);" << std::endl;
	std::cout << "st_nums_one.push(1);" << std::endl;
	std::cout << "st_nums_one.push(10);" << std::endl;
	std::cout << "st_nums_one.push(11);" << std::endl;
	std::cout << "st_nums_one.push(100);" << std::endl;
	std::cout << "st_nums_one.push(101);" << std::endl;
	std::cout << "st_nums_one.push(110);" << std::endl;
	std::cout << "st_nums_one.push(111);" << std::endl << std::endl;

	st_nums_two.push(0);
	st_nums_two.push(1);
	st_nums_two.push(10);
	st_nums_two.push(11);
	st_nums_two.push(100);
	st_nums_two.push(101);
	st_nums_two.push(110);
	st_nums_two.push(111);
	st_nums_two.push(1000);

	std::cout << "st_nums_two.push(0);" << std::endl;
	std::cout << "st_nums_two.push(1);" << std::endl;
	std::cout << "st_nums_two.push(10);" << std::endl;
	std::cout << "st_nums_two.push(11);" << std::endl;
	std::cout << "st_nums_two.push(100);" << std::endl;
	std::cout << "st_nums_two.push(101);" << std::endl;
	std::cout << "st_nums_two.push(110);" << std::endl;
	std::cout << "st_nums_two.push(111);" << std::endl;
	std::cout << "st_nums_two.push(1000);" << std::endl << std::endl;

	std::cout << "#- EQUAL & NON-EQUAL -#" << std::endl << std::endl;
	std::cout << "st_nums_one == st_nums_one : " << std::boolalpha << (st_nums_one == st_nums_one) << std::endl;
	std::cout << "st_nums_one == st_nums_two : " << std::boolalpha << (st_nums_one == st_nums_two) << std::endl << std::endl;

	std::cout << "st_nums_one != st_nums_one : " << std::boolalpha << (st_nums_one != st_nums_one) << std::endl;
	std::cout << "st_nums_one != st_nums_two : " << std::boolalpha << (st_nums_one != st_nums_two) << std::endl << std::endl;

	std::cout << "#- SUPERIOR & EQUAL-SUPERIOR -#" << std::endl << std::endl;

	std::cout << "st_nums_one < st_nums_one = " << (st_nums_one < st_nums_one) << std::endl;
	std::cout << "st_nums_one < st_nums_two = " << (st_nums_one < st_nums_two) << std::endl;
	std::cout << "st_nums_two < st_nums_one = " << (st_nums_two < st_nums_one) << std::endl;
	std::cout << "st_nums_one <= st_nums_one = " << (st_nums_one <= st_nums_one) << std::endl;
	std::cout << "st_nums_one <= st_nums_two = " << (st_nums_one <= st_nums_two) << std::endl;
	std::cout << "st_nums_two <= st_nums_one = " << (st_nums_two <= st_nums_one) << std::endl << std::endl;

	std::cout << "#- INFERIOR & EQUAL-INFERIOR -#" << std::endl << std::endl;

	std::cout << "st_nums_one > st_nums_one = " << (st_nums_one > st_nums_one) << std::endl;
	std::cout << "st_nums_one > st_nums_two = " << (st_nums_one > st_nums_two) << std::endl;
	std::cout << "st_nums_two > st_nums_one = " << (st_nums_two > st_nums_one) << std::endl;
	std::cout << "st_nums_one >= st_nums_one = " << (st_nums_one >= st_nums_one) << std::endl;
	std::cout << "st_nums_one >= st_nums_two = " << (st_nums_one >= st_nums_two) << std::endl;
	std::cout << "st_nums_two >= st_nums_one = " << (st_nums_two >= st_nums_one) << std::endl << std::endl;

	test_non_member_ope_std();
}

static void	test_push_std()
{
	print_header("STD TEST FUNCTIONS");

	std::stack<int>	st_nums;
	std::cout << "ft::stack<int> st_nums;" << std::endl << std::endl;

	// TEST EMPTY FUNCTION
	std::cout << "st_nums.empty() = " << std::boolalpha << st_nums.empty() << std::endl << std::endl;

	// TEST PUSH ONE ITEM
	st_nums.push(42);
	std::cout << "st_nums.push(42);" << std::endl << std::endl;

	std::cout << "st_nums.top() = " << st_nums.top() << std::endl << std::endl;

	std::cout << "st_nums.empty() = " << std::boolalpha << st_nums.empty() << std::endl << std::endl;

	std::cout << "st_nums.size() = " << std::boolalpha << st_nums.size() << std::endl << std::endl;

	// TEST PUSH MANY ITEMS
	st_nums.push(56);
	std::cout << "st_nums.push(56);" << std::endl << std::endl;

	std::cout << "st_nums.top() = " << st_nums.top() << std::endl << std::endl;

	std::cout << "st_nums.size() = " << std::boolalpha << st_nums.size() << std::endl << std::endl;

	// TEST POP FUNCTION
	st_nums.pop();
	std::cout << "st_nums.pop();" << std::endl << std::endl;

	std::cout << "st_nums.top() = " << st_nums.top() << std::endl << std::endl;

	std::cout << "st_nums.size() = " << std::boolalpha << st_nums.size() << std::endl << std::endl;

	st_nums.pop();
	std::cout << "st_nums.pop();" << std::endl << std::endl;

	std::cout << "st_nums.size() = " << std::boolalpha << st_nums.size() << std::endl << std::endl;

	std::cout << "st_nums.empty() = " << std::boolalpha << st_nums.empty() << std::endl << std::endl;

}

static void	test_push()
{
	print_header("FT TEST FUNCTIONS");

	ft::stack<int>	st_nums;
	std::cout << "ft::stack<int> st_nums;" << std::endl << std::endl;

	// TEST EMPTY FUNCTION
	std::cout << "st_nums.empty() = " << std::boolalpha << st_nums.empty() << std::endl << std::endl;

	// TEST PUSH ONE ITEM
	st_nums.push(42);
	std::cout << "st_nums.push(42);" << std::endl << std::endl;

	std::cout << "st_nums.top() = " << st_nums.top() << std::endl << std::endl;

	std::cout << "st_nums.empty() = " << std::boolalpha << st_nums.empty() << std::endl << std::endl;

	std::cout << "st_nums.size() = " << std::boolalpha << st_nums.size() << std::endl << std::endl;

	// TEST PUSH MANY ITEMS
	st_nums.push(56);
	std::cout << "st_nums.push(56);" << std::endl << std::endl;

	std::cout << "st_nums.top() = " << st_nums.top() << std::endl << std::endl;

	std::cout << "st_nums.size() = " << std::boolalpha << st_nums.size() << std::endl << std::endl;

	// TEST POP FUNCTION
	st_nums.pop();
	std::cout << "st_nums.pop();" << std::endl << std::endl;

	std::cout << "st_nums.top() = " << st_nums.top() << std::endl << std::endl;

	std::cout << "st_nums.size() = " << std::boolalpha << st_nums.size() << std::endl << std::endl;

	st_nums.pop();
	std::cout << "st_nums.pop();" << std::endl << std::endl;

	std::cout << "st_nums.size() = " << std::boolalpha << st_nums.size() << std::endl << std::endl;

	std::cout << "st_nums.empty() = " << std::boolalpha << st_nums.empty() << std::endl << std::endl;

	test_push_std();
}

void	main_stack(void)
{
	std::vector<void(*)(void)>	lst_funs_ptr;
	std::vector<std::string>	lst_funs_description;

	lst_funs_ptr.push_back(test_push);
	lst_funs_description.push_back("0 : test push");

	lst_funs_ptr.push_back(test_non_member_ope);
	lst_funs_description.push_back("1 : test non member operationnal");

	menu(lst_funs_ptr, lst_funs_description, "STACK");
}

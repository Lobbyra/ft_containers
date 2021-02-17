/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:47:43 by jecaudal          #+#    #+#             */
/*   Updated: 2021/02/17 12:31:07 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <iostream>
#include "vector.hpp"

static void clearscreen()
{
	std::cout << std::string( 100, '\n' );
}

static void	test_push_std(void)
{
	std::vector<int> test;

	std::cout << "## BASIC STD DEMONSTRATION ##" << std::endl;

	std::cout << "Creating ft::vector test." << std::endl;

	std::cout << "Empty() = " << std::boolalpha << test.empty() << std::endl << std::endl;

	std::cout << "--PUSH DATA--" << std::endl;
	test.push_back(56);
	std::cout << "Push : " << test[0] << std::endl;
	test.push_back(42);
	std::cout << "Push : " << test[1] << std::endl;

	std::cout << "Empty() = " << std::boolalpha << test.empty() << std::endl << std::endl;

	std::cout << "--INFOS--" << std::endl;
	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;

	std::cout << "--PUSH DATA--" << std::endl;
	test.push_back(9);
	std::cout << "Push : " << test[2] << std::endl;
	test.push_back(0);
	std::cout << "Push : " << test[3] << std::endl;
	test.push_back(13);
	std::cout << "Push : " << test[4] << std::endl;

	std::cout << "--INFOS--" << std::endl;
	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;
	std::cout << "##                        ##" << std::endl;

	// std::cout << "--MAX_SIZE--" << std::endl;
	// std::cout << test.max_size() << std::endl;
}

static void	test_push(void)
{
	ft::vector<int> test;

	std::cout << "## BASIC FT DEMONSTRATION ##" << std::endl;

	std::cout << "Creating ft::vector test." << std::endl;

	std::cout << "Empty() = " << std::boolalpha << test.empty() << std::endl << std::endl;

	std::cout << "--PUSH DATA--" << std::endl;
	test.push_back(56);
	std::cout << "Push : " << test[0] << std::endl;
	test.push_back(42);
	std::cout << "Push : " << test[1] << std::endl;

	std::cout << "Empty() = " << std::boolalpha << test.empty() << std::endl << std::endl;

	std::cout << "--INFOS--" << std::endl;
	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;

	std::cout << "--PUSH DATA--" << std::endl;
	test.push_back(9);
	std::cout << "Push : " << test[2] << std::endl;
	test.push_back(0);
	std::cout << "Push : " << test[3] << std::endl;
	test.push_back(13);
	std::cout << "Push : " << test[4] << std::endl;

	std::cout << "--INFOS--" << std::endl;
	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;
	std::cout << "##                       ##" << std::endl;

	// std::cout << "--MAX_SIZE--" << std::endl;
	// std::cout << test.max_size() << std::endl;
	test_push_std();
}

static void	test_element_access_std(void)
{
	std::vector<int> test;
	std::cout << "## ELEMENT ACCESS STD DEMONSTRATION ##" << std::endl;

	test.push_back(43);
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(56);

	std::cout << "For a vector<int> = {43, 1, 2, 3, 56}" << std::endl;
	std::cout << "----- TEST AT() -----" << std::endl;
	std::cout << "at(0) = " << test.at(0) << std::endl;
	std::cout << "at(1) = " << test.at(1) << std::endl;
	std::cout << "at(3) = " << test.at(3) << std::endl;
	std::cout << "at(4) = " << test.at(4) << std::endl;
	std::cout << "at(6) = ";
	try
	{
		std::cout << test.at(6) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-----           -----" << std::endl << std::endl;
	std::cout << "----- TEST FRONT() & BACK() -----" << std::endl;
	std::cout << "For a vector<std::string> = {\"999\", \"666\", \"123\", \"321\"}" << std::endl;

	ft::vector<std::string> test1;

	test1.push_back("999");
	test1.push_back("666");
	test1.push_back("123");
	test1.push_back("321");

	std::cout << "front() = " << test1.front() << std::endl;
	std::cout << "back() = " << test1.back() << std::endl;

	std::cout << "For a vector<std::string> = {\"2727\"}" << std::endl;

	ft::vector<std::string> test2;

	test2.push_back("2727");

	std::cout << "front() = " << test2.front() << std::endl;
	std::cout << "back() = " << test2.back() << std::endl;

	std::cout << "-----                       -----" << std::endl;

	std::cout << "######################################" << std::endl << std::endl;
}

static void	test_element_access(void)
{
	ft::vector<int> test;
	std::cout << "## ELEMENT ACCESS FT DEMONSTRATION ##" << std::endl;

	test.push_back(43);
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(56);

	std::cout << "For a vector<int> = {43, 1, 2, 3, 56}" << std::endl;
	std::cout << "----- TEST AT() -----" << std::endl;
	std::cout << "at(0) = " << test.at(0) << std::endl;
	std::cout << "at(1) = " << test.at(1) << std::endl;
	std::cout << "at(3) = " << test.at(3) << std::endl;
	std::cout << "at(4) = " << test.at(4) << std::endl;
	std::cout << "at(6) = ";
	try
	{
		std::cout << test.at(6) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-----           -----" << std::endl << std::endl;
	std::cout << "----- TEST FRONT() & BACK() -----" << std::endl;
	std::cout << "For a vector<std::string> = {\"999\", \"666\", \"123\", \"321\"}" << std::endl;

	ft::vector<std::string> test1;

	test1.push_back("999");
	test1.push_back("666");
	test1.push_back("123");
	test1.push_back("321");

	std::cout << "front() = " << test1.front() << std::endl;
	std::cout << "back() = " << test1.back() << std::endl;

	std::cout << "For a vector<std::string> = {\"2727\"}" << std::endl;

	ft::vector<std::string> test2;

	test2.push_back("2727");

	std::cout << "front() = " << test2.front() << std::endl;
	std::cout << "back() = " << test2.back() << std::endl;

	std::cout << "-----                       -----" << std::endl;

	std::cout << "#####################################" << std::endl << std::endl;
	test_element_access_std();
}

static void	test_re_serve_size_std(void)
{
	std::cout << "## RESERVE RESIZE STD DEMONSTRATION ##" << std::endl;

	std::cout << "=== RESERVE TEST ===" << std::endl;
	std::cout << "=== For a empty int vector = v ===" << std::endl;

	std::vector<int> v;

	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	v.reserve(100);
	std::cout << "v.reserve(100)" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	v.reserve(1);
	std::cout << "v.reserve(1)" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;

	std::cout << "=== RESIZE TEST ===" << std::endl;
	std::cout << "=== For a empty int vector = v2 ===" << std::endl;

	std::vector<int> v2;

	std::cout << "v2.capacity() = " << v2.capacity() << std::endl;
	std::cout << "v2.size() = " << v2.size() << std::endl;

	v2.resize(10);
	std::cout << "v2.resize(10);" << std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << std::endl;
	std::cout << std::endl;

	v2.resize(15, 15);
	std::cout << "v2.resize(15, 15);" << std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << std::endl;
	std::cout << std::endl;

	v2.resize(3);
	std::cout << "v2.resize(3);" << std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << std::endl;
	std::cout << std::endl;

	std::cout << "#####################################" << std::endl << std::endl;
}

static void	test_re_serve_size(void)
{
	std::cout << "## RESERVE RESIZE FT DEMONSTRATION ##" << std::endl;

	std::cout << "=== RESERVE TEST ===" << std::endl;
	std::cout << "=== For a empty int vector = v ===" << std::endl;

	ft::vector<int> v;

	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	v.reserve(100);
	std::cout << "v.reserve(100)" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	v.reserve(1);
	std::cout << "v.reserve(1)" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;

	std::cout << "=== RESIZE TEST ===" << std::endl;
	std::cout << "=== For a empty int vector = v2 ===" << std::endl;

	ft::vector<int> v2;

	std::cout << "v2.capacity() = " << v2.capacity() << std::endl;
	std::cout << "v2.size() = " << v2.size() << std::endl;

	v2.resize(10);
	std::cout << "v2.resize(10);" << std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << std::endl;
	std::cout << std::endl;

	v2.resize(15, 15);
	std::cout << "v2.resize(15, 15);" << std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << std::endl;
	std::cout << std::endl;

	v2.resize(3);
	std::cout << "v2.resize(3);" << std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << std::endl;
	std::cout << std::endl;

	std::cout << "#####################################" << std::endl << std::endl;
	test_re_serve_size_std();
}

static void	test_pop_back_std(void)
{
	std::cout << "## POP BACK STD DEMONSTRATION ##" << std::endl;

	std::cout << "=== For a vector<std::string> empty ===" << std::endl;

	std::vector<std::string> v;

	v.resize(10, "coucou !");
	std::cout << "v.resize(10, \"coucou !\");" << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << "#####################################" << std::endl << std::endl;
}

static void	test_pop_back(void)
{
	std::cout << "## POP BACK FT DEMONSTRATION ##" << std::endl;

	std::cout << "=== For a vector<std::string> empty ===" << std::endl;

	ft::vector<std::string> v;

	v.resize(10, "coucou !");
	std::cout << "v.resize(10, \"coucou !\");" << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	test_pop_back_std();

	std::cout << "#####################################" << std::endl << std::endl;
}

static void	test_iterator_incrementers_ft()
{
	ft::vector<int>				v;
	ft::vector<int>::iterator	it;

	std::cout << "#### FT PART ####" << std::endl;
	std::cout << "For a vector : ";
	v.push_back(5);
	v.push_back(42);
	v.push_back(56);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << "*(v.begin()) = " << *(v.begin()) << std::endl;

	std::cout << "##TEST FOR : i++ ++i --i i-- ##" << std::endl;
	it = v.begin();
	std::cout << "it = v.begin();" << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(it++) = " << *(it++) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(it--) = " << *(it--) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(++it) = " << *(++it) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(--it) = " << *(--it) << std::endl;
	std::cout << "*it = " << *it << std::endl << std::endl;
}

static void	test_iterator_incrementers_std()
{
	std::vector<int>				v;
	std::vector<int>::iterator	it;

	std::cout << "#### STD PART ####" << std::endl;
	std::cout << "For a vector : ";
	v.push_back(5);
	v.push_back(42);
	v.push_back(56);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << "*(v.begin()) = " << *(v.begin()) << std::endl;

	std::cout << "##TEST FOR : i++ ++i --i i-- ##" << std::endl;
	it = v.begin();
	std::cout << "it = v.begin();" << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(it++) = " << *(it++) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(it--) = " << *(it--) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(++it) = " << *(++it) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(--it) = " << *(--it) << std::endl;
	std::cout << "*it = " << *it << std::endl << std::endl;
}

void 	test_iterator_arithmetics_ft()
{
	ft::vector<int>				v;
	ft::vector<int>::iterator	it;

	std::cout << "#### FT PART ####" << std::endl;
	std::cout << "For a vector : ";
	v.push_back(5);
	v.push_back(42);
	v.push_back(56);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	it = v.begin();
	std::cout << "it = v.begin();" << std::endl;
	std::cout << "*(it + 0) = " << *(it + 0) << std::endl;
	std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
	std::cout << "*(it + 5) = " << *(it + 5) << std::endl << std::endl;

	it = v.end() - 1;
	std::cout << "it = v.end() - 1;" << std::endl;
	std::cout << "*(it - 0) = " << *(it - 0) << std::endl;
	std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
	std::cout << "*(it - 5) = " << *(it - 5) << std::endl << std::endl;
}

static void	test_iterator_arithmetics_std()
{
	std::vector<int>				v;
	std::vector<int>::iterator	it;

	std::cout << "#### STD PART ####" << std::endl;
	std::cout << "For a vector : ";
	v.push_back(5);
	v.push_back(42);
	v.push_back(56);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	it = v.begin();
	std::cout << "it = v.begin();" << std::endl;
	std::cout << "*(it + 0) = " << *(it + 0) << std::endl;
	std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
	std::cout << "*(it + 5) = " << *(it + 5) << std::endl << std::endl;

	it = v.end() - 1;
	std::cout << "it = v.end() - 1;" << std::endl;
	std::cout << "*(it - 0) = " << *(it - 0) << std::endl;
	std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
	std::cout << "*(it - 5) = " << *(it - 5) << std::endl << std::endl;
}

static void	test_iterator_booleans_ft()
{
	ft::vector<int>				v;
	ft::vector<int>::iterator	it;

	std::cout << "#### FT PART ####" << std::endl;
	std::cout << "For a vector v : ";
	v.push_back(5);
	v.push_back(42);
	v.push_back(56);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	ft::vector<int>::iterator	it_beg = v.begin();
	ft::vector<int>::iterator	it_end = v.end();
	std::cout << "For an iterator it_beg = v.begin()" << std::endl;
	std::cout << "For an iterator it_end = v.end()" << std::endl << std::endl;

	std::cout << "it_beg < it_end is " << std::boolalpha << (it_beg < it_end) << std::endl;
	std::cout << "it_end < it_beg is " << std::boolalpha << (it_end < it_beg) << std::endl;
	std::cout << "it_beg > it_end is " << std::boolalpha << (it_beg > it_end) << std::endl;
	std::cout << "it_end > it_beg is " << std::boolalpha << (it_end > it_beg) << std::endl << std::endl;

	std::cout << "it_beg == it_end is " << std::boolalpha << (it_beg == it_end) << std::endl;
	std::cout << "it_beg == it_beg is " << std::boolalpha << (it_beg == it_beg) << std::endl;
	std::cout << "it_beg != it_end is " << std::boolalpha << (it_beg != it_end) << std::endl;
	std::cout << "it_beg != it_beg is " << std::boolalpha << (it_beg != it_beg) << std::endl << std::endl;

	std::cout << "it_beg <= it_end is " << std::boolalpha << (it_beg <= it_end) << std::endl;
	std::cout << "it_end <= it_beg is " << std::boolalpha << (it_end <= it_beg) << std::endl;
	std::cout << "it_end <= it_end is " << std::boolalpha << (it_end <= it_end) << std::endl;
	std::cout << "it_beg >= it_end is " << std::boolalpha << (it_beg >= it_end) << std::endl;
	std::cout << "it_end >= it_beg is " << std::boolalpha << (it_end >= it_beg) << std::endl;
	std::cout << "it_end >= it_end is " << std::boolalpha << (it_end >= it_end) << std::endl << std::endl;
}

static void	test_iterator_booleans_std()
{
	std::vector<int>				v;
	std::vector<int>::iterator	it;

	std::cout << "#### STD PART ####" << std::endl;
	std::cout << "For a vector v : ";
	v.push_back(5);
	v.push_back(42);
	v.push_back(56);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::vector<int>::iterator	it_beg = v.begin();
	std::vector<int>::iterator	it_end = v.end();
	std::cout << "For an iterator it_beg = v.begin()" << std::endl;
	std::cout << "For an iterator it_end = v.end()" << std::endl << std::endl;

	std::cout << "it_beg < it_end is " << std::boolalpha << (it_beg < it_end) << std::endl;
	std::cout << "it_end < it_beg is " << std::boolalpha << (it_end < it_beg) << std::endl;
	std::cout << "it_beg > it_end is " << std::boolalpha << (it_beg > it_end) << std::endl;
	std::cout << "it_end > it_beg is " << std::boolalpha << (it_end > it_beg) << std::endl << std::endl;

	std::cout << "it_beg == it_end is " << std::boolalpha << (it_beg == it_end) << std::endl;
	std::cout << "it_beg == it_beg is " << std::boolalpha << (it_beg == it_beg) << std::endl;
	std::cout << "it_beg != it_end is " << std::boolalpha << (it_beg != it_end) << std::endl;
	std::cout << "it_beg != it_beg is " << std::boolalpha << (it_beg != it_beg) << std::endl << std::endl;

	std::cout << "it_beg <= it_end is " << std::boolalpha << (it_beg <= it_end) << std::endl;
	std::cout << "it_end <= it_beg is " << std::boolalpha << (it_end <= it_beg) << std::endl;
	std::cout << "it_end <= it_end is " << std::boolalpha << (it_end <= it_end) << std::endl;
	std::cout << "it_beg >= it_end is " << std::boolalpha << (it_beg >= it_end) << std::endl;
	std::cout << "it_end >= it_beg is " << std::boolalpha << (it_end >= it_beg) << std::endl;
	std::cout << "it_end >= it_end is " << std::boolalpha << (it_end >= it_end) << std::endl << std::endl;
	return ;
}

static void	test_iterator_deref_std()
{
	std::vector<int>				v;
	std::vector<int>::iterator	it;

	std::cout << "#### STD PART ####" << std::endl;
	std::cout << "For a vector v : ";
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	it = v.begin();
	std::cout << "it = v.begin()" << std::endl;

	std::cout << "cout *it = " << *it << std::endl;
	*it = 5;
	std::cout << "*it = 5" << std::endl;
	std::cout << "cout *it = " << *it << std::endl << std::endl;

	std::cout << "cout it[3] = " << it[3] << std::endl;
	it[3] = 42;
	std::cout << "it[3] = 42" << std::endl;
	std::cout << "cout it[3] = " << it[3] << std::endl;

	std::cout << "For a vector v : ";
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;
	it = v.begin() + 3;
	std::cout << "it = v.begin() + 3" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;

	*it++ = 345879;
	std::cout << "*it++ = 345879;" << std::endl;
	std::cout << "cout *(it - 1) = " << *(it - 1) << std::endl;
	*it-- = 999;
	std::cout << "*it-- = 999;" << std::endl;
	std::cout << "cout *(it + 1) = " << *(it + 1) << std::endl << std::endl;
	std::cout << "now v  : ";
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl << std::endl;
	std::cout << "it = v.begin() + 0" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	it += 4;
	std::cout << "it += 4" << *it << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	it -= 4;
	std::cout << "it -= 4" << *it << std::endl;
	std::cout << "cout *it = " << *it << std::endl << std::endl;
	std::vector<int>::iterator it_cpy(it);
	std::cout << "iterator it_cpy(it);" << std::endl;
	std::cout << "cout *it_cpy = " << *it_cpy << std::endl << std::endl;
}

static void	test_iterator_deref_ft()
{
	ft::vector<int>				v;
	ft::vector<int>::iterator	it;

	std::cout << "#### FT PART ####" << std::endl;
	std::cout << "For a vector v : ";
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	it = v.begin();
	std::cout << "it = v.begin()" << std::endl;

	std::cout << "### * ###" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	*it = 5;
	std::cout << "*it = 5" << std::endl;
	std::cout << "cout *it = " << *it << std::endl << std::endl;

	std::cout << "### [] ###" << std::endl;
	std::cout << "cout it[3] = " << it[3] << std::endl;
	it[3] = 42;
	std::cout << "it[3] = 42" << std::endl;
	std::cout << "cout it[3] = " << it[3] << std::endl;

	std::cout << "### *i++ *i-- ###" << std::endl;
	std::cout << "For a vector v : ";
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;
	it = v.begin() + 3;
	std::cout << "it = v.begin() + 3" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;

	*it++ = 345879;
	std::cout << "*it++ = 345879;" << std::endl;
	std::cout << "cout *(it - 1) = " << *(it - 1) << std::endl;
	*it-- = 999;
	std::cout << "*it-- = 999;" << std::endl;
	std::cout << "cout *(it + 1) = " << *(it + 1) << std::endl << std::endl;
	std::cout << "now v  : ";
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl << std::endl;
	std::cout << "it = v.begin() + 0" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	it += 4;
	std::cout << "it += 4" << *it << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	it -= 4;
	std::cout << "it -= 4" << *it << std::endl;
	std::cout << "cout *it = " << *it << std::endl << std::endl;
	ft::vector<int>::iterator it_cpy(it);
	std::cout << "iterator it_cpy(it);" << std::endl;
	std::cout << "cout *it_cpy = " << *it_cpy << std::endl << std::endl;
}

static void	test_iterator(void)
{
	std::string input_line;

	std::cout << "## TESTS FOR INCREMENTERS : i++ ++i --i i-- ##" << std::endl;
	test_iterator_incrementers_ft();
	test_iterator_incrementers_std();

	std::cout << std::endl <<"Press enter to the next iterator test" << std::endl;
	std::getline(std::cin, input_line);
	clearscreen();

	std::cout << "## TESTS FOR ARITHMETICS : it + a, it - a ##" << std::endl;
	test_iterator_arithmetics_ft();
	test_iterator_arithmetics_std();

	std::cout << std::endl <<"Press enter to the next iterator test" << std::endl;
	std::getline(std::cin, input_line);
	clearscreen();

	std::cout << "## TESTS FOR BOOLEANS : <, >, <=, >=, ==, != ##" << std::endl;
	test_iterator_booleans_ft();
	test_iterator_booleans_std();

	std::cout << std::endl <<"Press enter to the next iterator test" << std::endl;
	std::getline(std::cin, input_line);
	clearscreen();

	std::cout << "## TESTS FOR COMPOUND ASSIGNMENTS & DEREFERENCING : +=, -=, *, [], -> ##" << std::endl;
	test_iterator_deref_ft();
	test_iterator_deref_std();
}

static void	test_reverse_iterator_std(void)
{
	std::vector<int>	v;
	std::vector<int>::reverse_iterator	it;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	std::cout << "#### STD PART ####" << std::endl;
	std::cout << "For a vector v = ";
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << "for it = v.rbegin(); it != v.rend(); it++" << std::endl;
	std::cout << "	std::cout << *it << std::endl;" << std::endl;
	for (std::vector<int>::reverse_iterator it2 = v.rbegin(); it2 != v.rend(); it2++)
		std::cout << *it2 << std::endl;

	it = v.rbegin();
	std::cout << "*it = v.rbegin()" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	it += 4;
	std::cout << "it += 4" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	it -= 4;
	std::cout << "it -= 4" << std::endl;
	std::cout << "cout *it = " << *it << std::endl << std::endl;

	it = v.rbegin();
	std::cout << "cout *(it + 0) = " << *(it + 0) << std::endl;
	std::cout << "cout *(it + 1) = " << *(it + 1) << std::endl;
	std::cout << "cout *(it + 2) = " << *(it + 2) << std::endl;
	std::cout << "cout *(it + 3) = " << *(it + 3) << std::endl;
	std::cout << "cout *(it + 4) = " << *(it + 4) << std::endl << std::endl;
}

static void	test_reverse_iterator(void)
{
	ft::vector<int>	v;
	ft::vector<int>::reverse_iterator	it;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	std::cout << "#### FT PART ####" << std::endl;
	std::cout << "For a vector v = ";
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << "for it = v.rbegin(); it != v.rend(); it++" << std::endl;
	std::cout << "	std::cout << *it << std::endl;" << std::endl;
	for (ft::vector<int>::reverse_iterator it2 = v.rbegin(); it2 != v.rend(); it2++)
		std::cout << *it2 << std::endl;

	it = v.rbegin();
	std::cout << "*it = v.rbegin()" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	it += 4;
	std::cout << "it += 4" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	it -= 4;
	std::cout << "it -= 4" << std::endl;
	std::cout << "cout *it = " << *it << std::endl << std::endl;

	it = v.rbegin();
	std::cout << "cout *(it + 0) = " << *(it + 0) << std::endl;
	std::cout << "cout *(it + 1) = " << *(it + 1) << std::endl;
	std::cout << "cout *(it + 2) = " << *(it + 2) << std::endl;
	std::cout << "cout *(it + 3) = " << *(it + 3) << std::endl;
	std::cout << "cout *(it + 4) = " << *(it + 4) << std::endl << std::endl;
	test_reverse_iterator_std();
}

static void	test_constructors_std(void)
{
	std::cout << "#### STD PART CONSTRUCTORS ####" << std::endl;

	std::vector<int> v;

	std::cout << "--- DEFAULT CONSTRUCTOR ---" << std::endl;
	std::cout << "std::vector<int> v;" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;

	v.push_back(42);
	v.push_back(1);
	v.push_back(56);
	v.push_back(123);
	std::cout << "v.push_back(42);" << std::endl;
	std::cout << "v.push_back(1);" << std::endl;
	std::cout << "v.push_back(56);" << std::endl;
	std::cout << "v.push_back(123);" << std::endl;

	std::cout << "--- ITERATORS CONSTRUCTOR ---" << std::endl;
	std::cout << "std::vector<int> v_it(v.begin(), v.end());" << std::endl;
	std::vector<int> v_it(v.begin(), v.end());

	std::cout << "for (std::vector<int>::iterator it = v_it.begin(); it != v_it.end(); it++)" << std::endl;
	std::cout << "    std::cout << *it << std::endl;" << std::endl;
	for (std::vector<int>::iterator it = v_it.begin(); it != v_it.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "--- COPY CONSTRUCTOR ---" << std::endl;
	std::cout << "std::vector<int> v_cpy(v_it);" << std::endl;
	std::vector<int> v_cpy(v_it);

	std::cout << "for (std::vector<int>::iterator it = v_cpy.begin(); it != v_cpy.end(); it++)" << std::endl;
	std::cout << "std::cout << *it << std::endl;" << std::endl;
	for (std::vector<int>::iterator it = v_cpy.begin(); it != v_cpy.end(); it++)
		std::cout << *it << std::endl;
}

static void	test_constructors(void)
{
	std::cout << "#### FT PART CONSTRUCTORS ####" << std::endl;

	ft::vector<int> v;

	std::cout << "--- DEFAULT CONSTRUCTOR ---" << std::endl;
	std::cout << "ft::vector<int> v;" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;

	v.push_back(42);
	v.push_back(1);
	v.push_back(56);
	v.push_back(123);
	std::cout << "v.push_back(42);" << std::endl;
	std::cout << "v.push_back(1);" << std::endl;
	std::cout << "v.push_back(56);" << std::endl;
	std::cout << "v.push_back(123);" << std::endl;

	std::cout << "--- ITERATORS CONSTRUCTOR ---" << std::endl;
	std::cout << "ft::vector<int> v_it(v.begin(), v.end());" << std::endl;
	ft::vector<int> v_it(v.begin(), v.end());

	std::cout << "for (ft::vector<int>::iterator it = v_it.begin(); it != v_it.end(); it++)" << std::endl;
	std::cout << "    std::cout << *it << std::endl;" << std::endl;
	for (ft::vector<int>::iterator it = v_it.begin(); it != v_it.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "--- COPY CONSTRUCTOR ---" << std::endl;
	std::cout << "ft::vector<int> v_cpy(v_it);" << std::endl;
	ft::vector<int> v_cpy(v_it);

	std::cout << "for (ft::vector<int>::iterator it = v_cpy.begin(); it != v_cpy.end(); it++)" << std::endl;
	std::cout << "std::cout << *it << std::endl;" << std::endl;
	for (ft::vector<int>::iterator it = v_cpy.begin(); it != v_cpy.end(); it++)
		std::cout << *it << std::endl;

	// std::cout << "#--- FILL CONSTRUCTOR ---#" << std::endl;
	// std::cout << "ft::vector<int> v_fill(25, 42);" << std::endl;
	// ft::vector<int> v_fill(25, 42);

	// std::cout << "for (ft::vector<int>::iterator it = v_fill.begin(); it != v_fill.end(); it++)" << std::endl;
	// std::cout << "std::cout << *it << std::endl;" << std::endl;
	// for (ft::vector<int>::iterator it = v_fill.begin(); it != v_fill.end(); it++)
	// 	std::cout << *it << std::endl;
	test_constructors_std();
}

static void	test_assign_std(void)
{
	std::cout << "#### STD PART CONSTRUCTORS ####" << std::endl;

	ft::vector<int> v1;
	v1.push_back(42);
	v1.push_back(1);
	v1.push_back(56);
	v1.push_back(123);

	std::cout << "--- DEFAULT CONSTRUCTOR ---" << std::endl;
	std::cout << "ft::vector<int> v1;" << std::endl;
	std::cout << "For a vector v1 = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	ft::vector<int> v2;
	v2.push_back(420);
	v2.push_back(9999);
	v2.push_back(66666);
	v2.push_back(1234567);
	v2.push_back(507317);
	v2.push_back(2147483640);
	std::cout << "ft::vector<int> v2;" << std::endl;
	std::cout << "For a vector v2 = ";
	std::cout << "{";
	for (size_t i = 0; i < v2.size() - 1; i++)
		std::cout << v2[i] << ", ";
	std::cout << v2[v2.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v1.assign(v2.begin(), v2.end());
	std::cout << "v1.assign(v2.begin(), v2.end())" << std::endl;
		std::cout << "v1 = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v2.assign(10, 8);
	std::cout << "v2.assign(10, 8);" << std::endl;
		std::cout << "v2 = ";
	std::cout << "{";
	for (size_t i = 0; i < v2.size() - 1; i++)
		std::cout << v2[i] << ", ";
	std::cout << v2[v2.size() - 1];
	std::cout << "}" << std::endl;

	return ;
}

static void	test_assign(void)
{
	std::cout << "#### FT PART CONSTRUCTORS ####" << std::endl;

	ft::vector<int> v1;
	v1.push_back(42);
	v1.push_back(1);
	v1.push_back(56);
	v1.push_back(123);

	std::cout << "--- DEFAULT CONSTRUCTOR ---" << std::endl;
	std::cout << "ft::vector<int> v1;" << std::endl;
	std::cout << "For a vector v1 = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	ft::vector<int> v2;
	v2.push_back(420);
	v2.push_back(9999);
	v2.push_back(66666);
	v2.push_back(1234567);
	v2.push_back(507317);
	v2.push_back(2147483640);
	std::cout << "ft::vector<int> v2;" << std::endl;
	std::cout << "For a vector v2 = ";
	std::cout << "{";
	for (size_t i = 0; i < v2.size() - 1; i++)
		std::cout << v2[i] << ", ";
	std::cout << v2[v2.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v1.assign(v2.begin(), v2.end());
	std::cout << "v1.assign(v2.begin(), v2.end())" << std::endl;
		std::cout << "v1 = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v2.assign(10, 8);
	std::cout << "v2.assign(10, 8);" << std::endl;
		std::cout << "v2 = ";
	std::cout << "{";
	for (size_t i = 0; i < v2.size() - 1; i++)
		std::cout << v2[i] << ", ";
	std::cout << v2[v2.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	test_assign_std();
}

static void	test_insert_std(void)
{
	std::cout << "#### STD PART CONSTRUCTORS ####" << std::endl << std::endl;

	std::cout << "#--- Single Element ---#" << std::endl;
	std::vector<std::string>	v1;

	v1.push_back("coucou");
	v1.push_back("comment");
	v1.push_back("il");
	v1.push_back("va ?");

	std::cout << "#- Insert at the begining -#" << std::endl << std::endl;
	std::cout << "For a std::string vector v1 = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v1.insert(v1.begin(), "BANANAS SUKS ");
	std::cout << "insert(v1.begin(), \"BANANAS SUKS \")" << std::endl;

	std::cout << "v1 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "#- Insert in the middle -#" << std::endl << std::endl;
	v1.insert(v1.begin() + 3, "WIN SUKS ");
	std::cout << "insert(v1.begin() + 3, \"WIN SUKS \")" << std::endl;

	std::cout << "v1 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "#- Insert at the end -#" << std::endl << std::endl;
	v1.insert(v1.end(), "WIN SUKS ");
	std::cout << "insert(v1.end(), \"WIN SUKS \")" << std::endl;

	std::cout << "v1 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "#- Insert in empty vector -#" << std::endl << std::endl;
	std::vector<std::string> v2;
	std::cout << "For a std::string vector v2 = {}" << std::endl << std::endl;

	v2.insert(v2.begin(), "I'm alone here, it suks !");
	std::cout << "insert(v2.begin(), \"I'm alone here, it suks !\")" << std::endl;

	std::cout << "v2 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v2.size() - 1; i++)
		std::cout << v2[i] << ", ";
	std::cout << v2[v2.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "#--- Fill ---#" << std::endl << std::endl;

	std::vector<std::string>	v3;

	v3.push_back("i");
	v3.push_back("dont");
	v3.push_back("like");
	v3.push_back("all");
	v3.push_back("bananas");
	v3.push_back("bwark");

	std::cout << "#- Insert at the begining -#" << std::endl << std::endl;

	std::cout << "For a std::string vector v3 = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v3.insert(v3.begin(), 3 ,"BANANA");
	std::cout << "v3.insert(v3.begin(), 3 ,\"BANANA\");" << std::endl << std::endl;
	std::cout << "v3 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "#- Insert in the middle -#" << std::endl << std::endl;

	std::cout << "For a std::string vector v3 = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v3.insert(v3.begin() + 6, 1,"🍌");
	std::cout << "v3.insert(v3.begin() + 6, 3,\"🍌\");" << std::endl << std::endl;
	std::cout << "v3 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "#- Insert at the end -#" << std::endl << std::endl;

	std::cout << "For a std::string vector v3 = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v3.insert(v3.end(), 5,"ANANAB");
	std::cout << "v3.insert(v3.end(), 5,\"ANANAB\");" << std::endl << std::endl;
	std::cout << "v3 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "#- Insert in empty vector -#" << std::endl << std::endl;

	std::vector<std::string> v4;

	std::cout << "For a std::string vector v4 = {}" << std::endl << std::endl;

	v4.insert(v4.begin(), 5, "🍌");
	std::cout << "v4.insert(v4.begin(), 5,\"🍌\");" << std::endl;

	std::cout << "v4 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v4.size() - 1; i++)
		std::cout << v4[i] << ", ";
	std::cout << v4[v4.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "#--- Range ---#" << std::endl << std::endl;

	std::vector<std::string> apple(10, "🍎");
	std::vector<std::string> lemon(5, "🍋");

	std::cout << "For a std::string vector apple = ";
	std::cout << "{";
	for (size_t i = 0; i < apple.size() - 1; i++)
		std::cout << apple[i] << ", ";
	std::cout << apple[apple.size() - 1];
	std::cout << "}" << std::endl << std::endl;
	std::cout << "For a std::string vector lemon = ";
	std::cout << "{";
	for (size_t i = 0; i < lemon.size() - 1; i++)
		std::cout << lemon[i] << ", ";
	std::cout << lemon[lemon.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	apple.insert(apple.begin() + 5, lemon.begin(), lemon.end());
	std::cout << "apple.insert(apple.begin() + 5, lemon.begin(), lemon.end());" << std::endl << std::endl;

	std::cout << "Now apple = ";
	std::cout << "{";
	for (size_t i = 0; i < apple.size() - 1; i++)
		std::cout << apple[i] << ", ";
	std::cout << apple[apple.size() - 1];
	std::cout << "}" << std::endl;
}

static void	test_insert(void)
{
	std::cout << "#### FT PART CONSTRUCTORS ####" << std::endl << std::endl;

	std::cout << "#--- Single Element ---#" << std::endl;
	ft::vector<std::string>	v1;

	v1.push_back("coucou");
	v1.push_back("comment");
	v1.push_back("il");
	v1.push_back("va ?");

	std::cout << "#- Insert at the begining -#" << std::endl << std::endl;
	std::cout << "For a std::string vector v1 = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v1.insert(v1.begin(), "BANANAS SUKS ");
	std::cout << "insert(v1.begin(), \"BANANAS SUKS \")" << std::endl;

	std::cout << "v1 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "#- Insert in the middle -#" << std::endl << std::endl;
	v1.insert(v1.begin() + 3, "WIN SUKS ");
	std::cout << "insert(v1.begin() + 3, \"WIN SUKS \")" << std::endl;

	std::cout << "v1 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "#- Insert at the end -#" << std::endl << std::endl;
	v1.insert(v1.end(), "WIN SUKS ");
	std::cout << "insert(v1.end(), \"WIN SUKS \")" << std::endl;

	std::cout << "v1 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "#- Insert in empty vector -#" << std::endl << std::endl;
	ft::vector<std::string> v2;
	std::cout << "For a std::string vector v2 = {}" << std::endl << std::endl;

	v2.insert(v2.begin(), "I'm alone here, it suks !");
	std::cout << "insert(v2.begin(), \"I'm alone here, it suks !\")" << std::endl;

	std::cout << "v2 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v2.size() - 1; i++)
		std::cout << v2[i] << ", ";
	std::cout << v2[v2.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "#--- Fill ---#" << std::endl << std::endl;

	ft::vector<std::string>	v3;

	v3.push_back("i");
	v3.push_back("dont");
	v3.push_back("like");
	v3.push_back("all");
	v3.push_back("bananas");
	v3.push_back("bwark");

	std::cout << "#- Insert at the begining -#" << std::endl << std::endl;

	std::cout << "For a std::string vector v3 = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v3.insert(v3.begin(), 3 ,"BANANA");
	std::cout << "v3.insert(v3.begin(), 3 ,\"BANANA\");" << std::endl << std::endl;
	std::cout << "v3 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "#- Insert in the middle -#" << std::endl << std::endl;

	std::cout << "For a std::string vector v3 = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v3.insert(v3.begin() + 6, 1,"🍌");
	std::cout << "v3.insert(v3.begin() + 6, 3,\"🍌\");" << std::endl << std::endl;
	std::cout << "v3 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "#- Insert at the end -#" << std::endl << std::endl;

	std::cout << "For a std::string vector v3 = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v3.insert(v3.end(), 5,"ANANAB");
	std::cout << "v3.insert(v3.end(), 5,\"ANANAB\");" << std::endl << std::endl;
	std::cout << "v3 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "#- Insert in empty vector -#" << std::endl << std::endl;

	ft::vector<std::string> v4;

	std::cout << "For a std::string vector v4 = {}" << std::endl << std::endl;

	v4.insert(v4.begin(), 5, "🍌");
	std::cout << "v4.insert(v4.begin(), 5,\"🍌\");" << std::endl;

	std::cout << "v4 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v4.size() - 1; i++)
		std::cout << v4[i] << ", ";
	std::cout << v4[v4.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "#--- Range ---#" << std::endl << std::endl;

	ft::vector<std::string> apple(10, "🍎");
	ft::vector<std::string> lemon(5, "🍋");

	std::cout << "For a std::string vector apple = ";
	std::cout << "{";
	for (size_t i = 0; i < apple.size() - 1; i++)
		std::cout << apple[i] << ", ";
	std::cout << apple[apple.size() - 1];
	std::cout << "}" << std::endl << std::endl;
	std::cout << "For a std::string vector lemon = ";
	std::cout << "{";
	for (size_t i = 0; i < lemon.size() - 1; i++)
		std::cout << lemon[i] << ", ";
	std::cout << lemon[lemon.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	apple.insert(apple.begin() + 5, lemon.begin(), lemon.end());
	std::cout << "apple.insert(apple.begin() + 5, lemon.begin(), lemon.end());" << std::endl << std::endl;

	std::cout << "Now apple = ";
	std::cout << "{";
	for (size_t i = 0; i < apple.size() - 1; i++)
		std::cout << apple[i] << ", ";
	std::cout << apple[apple.size() - 1];
	std::cout << "}" << std::endl;

	test_insert_std();
}

static void	test_clear_erase_std(void)
{
	std::cout << "#### STD PART CONSTRUCTORS ####" << std::endl << std::endl;

	std::vector<std::string> mess(20, "MESS");

	std::cout << "#--- Clear() ---#" << std::endl;

	std::cout << "For a vector named mess = {";
	for (std::vector<std::string>::iterator it = mess.begin(); it + 1 != mess.end(); it++)
		std::cout << *it << ", ";
	if (mess.empty() == false)
		std::cout << mess[mess.size() - 1] << "}" << std::endl;
	else
		std::cout << "}" << std::endl;

	std::cout << "std::vector<std::string> mess(20, \"MESS\");" << std::endl;
	std::cout << "mess.size() = " << mess.size() << std::endl;
	std::cout << "mess.capacity() = " << mess.capacity() << std::endl << std::endl;

	mess.clear();
	std::cout << "mess.clear();" << std::endl;
	std::cout << "mess = {";
	if (mess.empty() == false)
	{
		for (std::vector<std::string>::iterator it = mess.begin(); it + 1 != mess.end(); it++)
			std::cout << *it << ", ";
		std::cout << mess[mess.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << "mess.size() = " << mess.size() << std::endl;
	std::cout << "mess.capacity() = " << mess.capacity() << std::endl << std::endl;

	std::cout << "#--- Erase() ---#" << std::endl;

	std::vector<std::string> alien_hidden(10, "🎅");

	alien_hidden.insert(alien_hidden.begin() + 2, "👽");
	alien_hidden.insert(alien_hidden.begin() + 5, "👽");
	alien_hidden.insert(alien_hidden.begin() + 5, "👽");
	alien_hidden.insert(alien_hidden.begin() + 9, "👽");
	std::cout << "For a string vector alien_hidden = {";
	if (alien_hidden.empty() == false)
	{
		for (std::vector<std::string>::iterator it = alien_hidden.begin(); it + 1 != alien_hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << alien_hidden[alien_hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	alien_hidden.erase(alien_hidden.begin() + 2);
	std::cout << "alien_hidden.erase(alien_hidden.begin() + 2);" << std::endl;
	std::cout << "now alien_hidden = {";
	if (alien_hidden.empty() == false)
	{
		for (std::vector<std::string>::iterator it = alien_hidden.begin(); it + 1 != alien_hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << alien_hidden[alien_hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	alien_hidden.erase(alien_hidden.begin() + 8);
	std::cout << "alien_hidden.erase(alien_hidden.begin() + 8);" << std::endl;
	std::cout << "now alien_hidden = {";
	if (alien_hidden.empty() == false)
	{
		for (std::vector<std::string>::iterator it = alien_hidden.begin(); it + 1 != alien_hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << alien_hidden[alien_hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	alien_hidden.erase(alien_hidden.begin() + 4, alien_hidden.begin() + 6);
	std::cout << "alien_hidden.erase(alien_hidden.begin() + 4, alien_hidden.begin() + 6);" << std::endl;
	std::cout << "now alien_hidden = {";
	if (alien_hidden.empty() == false)
	{
		for (std::vector<std::string>::iterator it = alien_hidden.begin(); it + 1 != alien_hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << alien_hidden[alien_hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	alien_hidden.erase(alien_hidden.begin(), alien_hidden.end());
	std::cout << "alien_hidden.erase(alien_hidden.begin(), alien_hidden.end());" << std::endl;
	std::cout << "now alien_hidden = {";
	if (alien_hidden.empty() == false)
	{
		for (std::vector<std::string>::iterator it = alien_hidden.begin(); it + 1 != alien_hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << alien_hidden[alien_hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	return ;
}

static void	test_clear_erase(void)
{
	std::cout << "#### FT PART CONSTRUCTORS ####" << std::endl << std::endl;

	ft::vector<std::string> mess(20, "MESS");

	std::cout << "#--- Clear() ---#" << std::endl;

	std::cout << "For a vector named mess = {";
	for (ft::vector<std::string>::iterator it = mess.begin(); it + 1 != mess.end(); it++)
		std::cout << *it << ", ";
	if (mess.empty() == false)
		std::cout << mess[mess.size() - 1] << "}" << std::endl;
	else
		std::cout << "}" << std::endl;

	std::cout << "ft::vector<std::string> mess(20, \"MESS\");" << std::endl;
	std::cout << "mess.size() = " << mess.size() << std::endl;
	std::cout << "mess.capacity() = " << mess.capacity() << std::endl << std::endl;

	mess.clear();
	std::cout << "mess.clear();" << std::endl;
	std::cout << "mess = {";
	if (mess.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = mess.begin(); it + 1 != mess.end(); it++)
			std::cout << *it << ", ";
		std::cout << mess[mess.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << "mess.size() = " << mess.size() << std::endl;
	std::cout << "mess.capacity() = " << mess.capacity() << std::endl << std::endl;

	std::cout << "#--- Erase() ---#" << std::endl;

	ft::vector<std::string> alien_hidden(10, "🎅");

	alien_hidden.insert(alien_hidden.begin() + 2, "👽");
	alien_hidden.insert(alien_hidden.begin() + 5, "👽");
	alien_hidden.insert(alien_hidden.begin() + 5, "👽");
	alien_hidden.insert(alien_hidden.begin() + 9, "👽");
	std::cout << "For a string vector alien_hidden = {";
	if (alien_hidden.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = alien_hidden.begin(); it + 1 != alien_hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << alien_hidden[alien_hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	alien_hidden.erase(alien_hidden.begin() + 2);
	std::cout << "alien_hidden.erase(alien_hidden.begin() + 2);" << std::endl;
	std::cout << "now alien_hidden = {";
	if (alien_hidden.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = alien_hidden.begin(); it + 1 != alien_hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << alien_hidden[alien_hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	alien_hidden.erase(alien_hidden.begin() + 8);
	std::cout << "alien_hidden.erase(alien_hidden.begin() + 8);" << std::endl;
	std::cout << "now alien_hidden = {";
	if (alien_hidden.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = alien_hidden.begin(); it + 1 != alien_hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << alien_hidden[alien_hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	alien_hidden.erase(alien_hidden.begin() + 4, alien_hidden.begin() + 6);
	std::cout << "alien_hidden.erase(alien_hidden.begin() + 4, alien_hidden.begin() + 6);" << std::endl;
	std::cout << "now alien_hidden = {";
	if (alien_hidden.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = alien_hidden.begin(); it + 1 != alien_hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << alien_hidden[alien_hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	alien_hidden.erase(alien_hidden.begin(), alien_hidden.end());
	std::cout << "alien_hidden.erase(alien_hidden.begin(), alien_hidden.end());" << std::endl;
	std::cout << "now alien_hidden = {";
	if (alien_hidden.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = alien_hidden.begin(); it + 1 != alien_hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << alien_hidden[alien_hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	test_clear_erase_std();
}

static void	test_swap_std(void)
{
	std::cout << "#### STD PART CONSTRUCTORS ####" << std::endl << std::endl;

	std::vector<std::string> victor(10, "🌹");
	std::cout << "For a string vector victor = {";
	if (victor.empty() == false)
	{
		for (std::vector<std::string>::iterator it = victor.begin(); it + 1 != victor.end(); it++)
			std::cout << *it << ", ";
		std::cout << victor[victor.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::vector<std::string> vincent(5, "🌷");
	std::cout << "For a string vector vincent = {";
	if (vincent.empty() == false)
	{
		for (std::vector<std::string>::iterator it = vincent.begin(); it + 1 != vincent.end(); it++)
			std::cout << *it << ", ";
		std::cout << vincent[vincent.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	vincent.swap(victor);
	std::cout << "vincent.swap(victor);" << std::endl;

	std::cout << "now victor = {";
	if (victor.empty() == false)
	{
		for (std::vector<std::string>::iterator it = victor.begin(); it + 1 != victor.end(); it++)
			std::cout << *it << ", ";
		std::cout << victor[victor.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "now vicent = {";
	if (vincent.empty() == false)
	{
		for (std::vector<std::string>::iterator it = vincent.begin(); it + 1 != vincent.end(); it++)
			std::cout << *it << ", ";
		std::cout << vincent[vincent.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	vincent.swap(victor);
	std::cout << "vincent.swap(victor);" << std::endl;

	std::cout << "now victor = {";
	if (victor.empty() == false)
	{
		for (std::vector<std::string>::iterator it = victor.begin(); it + 1 != victor.end(); it++)
			std::cout << *it << ", ";
		std::cout << victor[victor.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "now vicent = {";
	if (vincent.empty() == false)
	{
		for (std::vector<std::string>::iterator it = vincent.begin(); it + 1 != vincent.end(); it++)
			std::cout << *it << ", ";
		std::cout << vincent[vincent.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	victor.swap(vincent);
	std::cout << "victor.swap(vincent);" << std::endl;

	std::cout << "now victor = {";
	if (victor.empty() == false)
	{
		for (std::vector<std::string>::iterator it = victor.begin(); it + 1 != victor.end(); it++)
			std::cout << *it << ", ";
		std::cout << victor[victor.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "now vicent = {";
	if (vincent.empty() == false)
	{
		for (std::vector<std::string>::iterator it = vincent.begin(); it + 1 != vincent.end(); it++)
			std::cout << *it << ", ";
		std::cout << vincent[vincent.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::vector<std::string>	empty_one;
	std::vector<std::string>	empty_two;

	std::cout << "For a string vector empty_one = {";
	if (empty_one.empty() == false)
	{
		for (std::vector<std::string>::iterator it = empty_one.begin(); it + 1 != empty_one.end(); it++)
			std::cout << *it << ", ";
		std::cout << empty_one[empty_one.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "For a string vector empty_two = {";
	if (empty_two.empty() == false)
	{
		for (std::vector<std::string>::iterator it = empty_two.begin(); it + 1 != empty_two.end(); it++)
			std::cout << *it << ", ";
		std::cout << empty_two[empty_two.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	empty_one.swap(empty_two);
	std::cout << "empty_one.swap(empty_two);" << std::endl;

	std::cout << "now empty_one = {";
	if (empty_one.empty() == false)
	{
		for (std::vector<std::string>::iterator it = empty_one.begin(); it + 1 != empty_one.end(); it++)
			std::cout << *it << ", ";
		std::cout << empty_one[empty_one.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "now empty_two = {";
	if (empty_two.empty() == false)
	{
		for (std::vector<std::string>::iterator it = empty_two.begin(); it + 1 != empty_two.end(); it++)
			std::cout << *it << ", ";
		std::cout << empty_two[empty_two.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
}

static void	test_swap(void)
{
	std::cout << "#### FT PART CONSTRUCTORS ####" << std::endl << std::endl;

	ft::vector<std::string> victor(10, "🌹");
	std::cout << "For a string vector victor = {";
	if (victor.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = victor.begin(); it + 1 != victor.end(); it++)
			std::cout << *it << ", ";
		std::cout << victor[victor.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	ft::vector<std::string> vincent(5, "🌷");
	std::cout << "For a string vector vincent = {";
	if (vincent.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = vincent.begin(); it + 1 != vincent.end(); it++)
			std::cout << *it << ", ";
		std::cout << vincent[vincent.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	vincent.swap(victor);
	std::cout << "vincent.swap(victor);" << std::endl;

	std::cout << "now victor = {";
	if (victor.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = victor.begin(); it + 1 != victor.end(); it++)
			std::cout << *it << ", ";
		std::cout << victor[victor.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "now vicent = {";
	if (vincent.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = vincent.begin(); it + 1 != vincent.end(); it++)
			std::cout << *it << ", ";
		std::cout << vincent[vincent.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	vincent.swap(victor);
	std::cout << "vincent.swap(victor);" << std::endl;

	std::cout << "now victor = {";
	if (victor.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = victor.begin(); it + 1 != victor.end(); it++)
			std::cout << *it << ", ";
		std::cout << victor[victor.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "now vicent = {";
	if (vincent.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = vincent.begin(); it + 1 != vincent.end(); it++)
			std::cout << *it << ", ";
		std::cout << vincent[vincent.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	victor.swap(vincent);
	std::cout << "victor.swap(vincent);" << std::endl;

	std::cout << "now victor = {";
	if (victor.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = victor.begin(); it + 1 != victor.end(); it++)
			std::cout << *it << ", ";
		std::cout << victor[victor.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "now vicent = {";
	if (vincent.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = vincent.begin(); it + 1 != vincent.end(); it++)
			std::cout << *it << ", ";
		std::cout << vincent[vincent.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	ft::vector<std::string>	empty_one;
	ft::vector<std::string>	empty_two;

	std::cout << "For a string vector empty_one = {";
	if (empty_one.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = empty_one.begin(); it + 1 != empty_one.end(); it++)
			std::cout << *it << ", ";
		std::cout << empty_one[empty_one.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "For a string vector empty_two = {";
	if (empty_two.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = empty_two.begin(); it + 1 != empty_two.end(); it++)
			std::cout << *it << ", ";
		std::cout << empty_two[empty_two.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	empty_one.swap(empty_two);
	std::cout << "empty_one.swap(empty_two);" << std::endl;

	std::cout << "now empty_one = {";
	if (empty_one.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = empty_one.begin(); it + 1 != empty_one.end(); it++)
			std::cout << *it << ", ";
		std::cout << empty_one[empty_one.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "now empty_two = {";
	if (empty_two.empty() == false)
	{
		for (ft::vector<std::string>::iterator it = empty_two.begin(); it + 1 != empty_two.end(); it++)
			std::cout << *it << ", ";
		std::cout << empty_two[empty_two.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl << std::endl;

	test_swap_std();
}

static void	test_non_member_ope_std(void)
{
	std::cout << "#### STD NON-MEMBER OPERATORS TEST ####" << std::endl;
	std::cout << "#- EQUAL & NON-EQUAL -#" << std::endl;

	ft::vector<std::string>	v_str1;

	v_str1.push_back("Mulhouse");
	v_str1.push_back("Niort");
	v_str1.push_back("Locmaria grand-champ");
	v_str1.push_back("Vatan");
	v_str1.push_back("jouy-en-josasse");

	ft::vector<std::string>	v_str2(v_str1);

	ft::vector<std::string>	v_str3;

	v_str3.push_back("Paris");
	v_str3.push_back("Lyon");
	v_str3.push_back("Toulouse");
	v_str3.push_back("Grenoble");
	v_str3.push_back("Brest");

	std::cout << "For string vector v_str1 : " << v_str1 << std::endl;
	std::cout << "For string vector v_str2 : " << v_str2 << std::endl;
	std::cout << "For string vector v_str3 : " << v_str3 << std::endl << std::endl;

	std::cout << "v_str1 == v_str1 : " << std::boolalpha << (v_str1 == v_str1) << std::endl << std::endl;

	std::cout << "v_str1 == v_str2 : " << std::boolalpha << (v_str1 == v_str2) << std::endl;
	std::cout << "v_str1 != v_str2 : " << std::boolalpha << (v_str1 != v_str2) << std::endl << std::endl;

	std::cout << "v_str1 == v_str3 : " << std::boolalpha << (v_str1 == v_str3) << std::endl;
	std::cout << "v_str1 != v_str3 : " << std::boolalpha << (v_str1 != v_str3) << std::endl << std::endl;

	std::cout << "#- SUPERIOR & EQUAL-SUPERIOR -#" << std::endl;
	ft::vector<int>	v_nums1;

	v_nums1.push_back(0);
	v_nums1.push_back(1);
	v_nums1.push_back(10);
	v_nums1.push_back(11);
	v_nums1.push_back(100);
	v_nums1.push_back(101);
	v_nums1.push_back(110);
	v_nums1.push_back(111);

	ft::vector<int>	v_nums2(v_nums1);

	v_nums2.push_back(1000);

	std::cout << "For int string vector v_nums1 : " << v_nums1 << std::endl;
	std::cout << "For int string vector v_nums2 : " << v_nums2 << std::endl << std::endl;

	std::cout << "v_nums1 < v_nums1 = " << (v_nums1 < v_nums1) << std::endl;
	std::cout << "v_nums1 < v_nums2 = " << (v_nums1 < v_nums2) << std::endl;
	std::cout << "v_nums2 < v_nums1 = " << (v_nums2 < v_nums1) << std::endl;
	std::cout << "v_nums1 <= v_nums1 = " << (v_nums1 <= v_nums1) << std::endl;
	std::cout << "v_nums1 <= v_nums2 = " << (v_nums1 <= v_nums2) << std::endl;
	std::cout << "v_nums2 <= v_nums1 = " << (v_nums2 <= v_nums1) << std::endl << std::endl;

	std::cout << "#- INFERIOR & EQUAL-INFERIOR -#" << std::endl << std::endl;

	std::cout << "v_nums1 > v_nums1 = " << (v_nums1 > v_nums1) << std::endl;
	std::cout << "v_nums1 > v_nums2 = " << (v_nums1 > v_nums2) << std::endl;
	std::cout << "v_nums2 > v_nums1 = " << (v_nums2 > v_nums1) << std::endl;
	std::cout << "v_nums1 >= v_nums1 = " << (v_nums1 >= v_nums1) << std::endl;
	std::cout << "v_nums1 >= v_nums2 = " << (v_nums1 >= v_nums2) << std::endl;
	std::cout << "v_nums2 >= v_nums1 = " << (v_nums2 >= v_nums1) << std::endl << std::endl;

}

static void	test_non_member_ope(void)
{
	std::cout << "#### FT NON-MEMBER OPERATORS TEST ####" << std::endl;
	std::cout << "#- EQUAL & NON-EQUAL -#" << std::endl;

	ft::vector<std::string>	v_str1;

	v_str1.push_back("Mulhouse");
	v_str1.push_back("Niort");
	v_str1.push_back("Locmaria grand-champ");
	v_str1.push_back("Vatan");
	v_str1.push_back("jouy-en-josasse");

	ft::vector<std::string>	v_str2(v_str1);

	ft::vector<std::string>	v_str3;

	v_str3.push_back("Paris");
	v_str3.push_back("Lyon");
	v_str3.push_back("Toulouse");
	v_str3.push_back("Grenoble");
	v_str3.push_back("Brest");

	std::cout << "For string vector v_str1 : " << v_str1 << std::endl;
	std::cout << "For string vector v_str2 : " << v_str2 << std::endl;
	std::cout << "For string vector v_str3 : " << v_str3 << std::endl << std::endl;

	std::cout << "v_str1 == v_str1 : " << std::boolalpha << (v_str1 == v_str1) << std::endl << std::endl;

	std::cout << "v_str1 == v_str2 : " << std::boolalpha << (v_str1 == v_str2) << std::endl;
	std::cout << "v_str1 != v_str2 : " << std::boolalpha << (v_str1 != v_str2) << std::endl << std::endl;

	std::cout << "v_str1 == v_str3 : " << std::boolalpha << (v_str1 == v_str3) << std::endl;
	std::cout << "v_str1 != v_str3 : " << std::boolalpha << (v_str1 != v_str3) << std::endl << std::endl;

	std::cout << "#- SUPERIOR & EQUAL-SUPERIOR -#" << std::endl;
	ft::vector<int>	v_nums1;

	v_nums1.push_back(0);
	v_nums1.push_back(1);
	v_nums1.push_back(10);
	v_nums1.push_back(11);
	v_nums1.push_back(100);
	v_nums1.push_back(101);
	v_nums1.push_back(110);
	v_nums1.push_back(111);

	ft::vector<int>	v_nums2(v_nums1);

	v_nums2.push_back(1000);

	std::cout << "For int string vector v_nums1 : " << v_nums1 << std::endl;
	std::cout << "For int string vector v_nums2 : " << v_nums2 << std::endl << std::endl;

	std::cout << "v_nums1 < v_nums1 = " << (v_nums1 < v_nums1) << std::endl;
	std::cout << "v_nums1 < v_nums2 = " << (v_nums1 < v_nums2) << std::endl;
	std::cout << "v_nums2 < v_nums1 = " << (v_nums2 < v_nums1) << std::endl;
	std::cout << "v_nums1 <= v_nums1 = " << (v_nums1 <= v_nums1) << std::endl;
	std::cout << "v_nums1 <= v_nums2 = " << (v_nums1 <= v_nums2) << std::endl;
	std::cout << "v_nums2 <= v_nums1 = " << (v_nums2 <= v_nums1) << std::endl << std::endl;

	std::cout << "#- INFERIOR & EQUAL-INFERIOR -#" << std::endl << std::endl;

	std::cout << "v_nums1 > v_nums1 = " << (v_nums1 > v_nums1) << std::endl;
	std::cout << "v_nums1 > v_nums2 = " << (v_nums1 > v_nums2) << std::endl;
	std::cout << "v_nums2 > v_nums1 = " << (v_nums2 > v_nums1) << std::endl;
	std::cout << "v_nums1 >= v_nums1 = " << (v_nums1 >= v_nums1) << std::endl;
	std::cout << "v_nums1 >= v_nums2 = " << (v_nums1 >= v_nums2) << std::endl;
	std::cout << "v_nums2 >= v_nums1 = " << (v_nums2 >= v_nums1) << std::endl << std::endl;

	test_non_member_ope_std();
}

static void	test_non_member_swap_std(void)
{
	std::cout << "#### FT NON-MEMBER SWAP ####" << std::endl;

	ft::vector<int> v_nums_a(10, 10);
	ft::vector<int> v_nums_b(10, 50);

	std::cout << "For int vector v_nums_a : " << v_nums_a << std::endl;
	std::cout << "For int vector v_nums_b : " << v_nums_b << std::endl << std::endl;

	std::cout << "swap(v_nums_a, v_nums_b);" << std::endl << std::endl;
	swap(v_nums_a, v_nums_b);

	std::cout << "v_nums_a : " << v_nums_a << std::endl;
	std::cout << "v_nums_b : " << v_nums_b << std::endl << std::endl;
}

static void	test_non_member_swap(void)
{
	std::cout << "#### FT NON-MEMBER SWAP ####" << std::endl;

	ft::vector<int> v_nums_a(10, 10);
	ft::vector<int> v_nums_b(10, 50);

	std::cout << "For int vector v_nums_a : " << v_nums_a << std::endl;
	std::cout << "For int vector v_nums_b : " << v_nums_b << std::endl << std::endl;

	std::cout << "swap(v_nums_a, v_nums_b);" << std::endl << std::endl;
	swap(v_nums_a, v_nums_b);

	std::cout << "v_nums_a : " << v_nums_a << std::endl;
	std::cout << "v_nums_b : " << v_nums_b << std::endl << std::endl;

	test_non_member_swap_std();
}

#include "../test_tools/utils_tester.hpp"

void	main_vector(void)
{
	std::vector<void(*)(void)>	v_test_funs;
	std::vector<std::string>	v_descriptions;

	v_test_funs.push_back(test_push);
	v_descriptions.push_back("0 : empty() | op[] | push() | size() | capacity() | max_size()");

	v_test_funs.push_back(test_element_access);
	v_descriptions.push_back("1 : at() | front() | back()");

	v_test_funs.push_back(test_re_serve_size);
	v_descriptions.push_back("2 : reserve() | resize()");

	v_test_funs.push_back(test_pop_back);
	v_descriptions.push_back("3 : pop_back()");

	v_test_funs.push_back(test_iterator);
	v_descriptions.push_back("4 : iterators");

	v_test_funs.push_back(test_reverse_iterator);
	v_descriptions.push_back("5 : reverse_iterators");

	v_test_funs.push_back(test_constructors);
	v_descriptions.push_back("6 : constructors");

	v_test_funs.push_back(test_assign);
	v_descriptions.push_back("7 : assign");

	v_test_funs.push_back(test_insert);
	v_descriptions.push_back("8 : insert");

	v_test_funs.push_back(test_clear_erase);
	v_descriptions.push_back("9 : clear erase");

	v_test_funs.push_back(test_swap);
	v_descriptions.push_back("10 : swap");

	v_test_funs.push_back(test_non_member_ope);
	v_descriptions.push_back("11 : Non-member operators");

	v_test_funs.push_back(test_non_member_swap);
	v_descriptions.push_back("12 : Non-memver swap");

	menu(v_test_funs, v_descriptions, "VECTOR");
}

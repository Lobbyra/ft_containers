/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:55:10 by jecaudal          #+#    #+#             */
/*   Updated: 2021/02/17 14:14:25 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include "list.hpp"

int to_int(char const *s)
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

void clearscreen()
{
	std::cout << std::string( 100, '\n' );
}

template < class T >
inline std::ostream& operator << (std::ostream& os, const std::list<T>& v) 
{
	os << "{";
	for (typename std::list<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
		os << " " << *ii;
	os << " }";
	return os;
}

static void	test_essentials_std(void)
{
	std::cout << "#### STD TEST ESSENTIALS ####" << std::endl;
	std::cout << "#  push back #" << std::endl;
	std::cout << "    For list of ints : EMPTY" << std::endl;
	std::list<int>	lst1;

	std::cout << "lst1.push_back(10);" << std::endl;
	std::cout << "lst1.push_back(20);" << std::endl;
	std::cout << "lst1.push_back(30);" << std::endl << std::endl;
	lst1.push_back(10);
	lst1.push_back(20);
	lst1.push_back(30);

	std::cout << "#    back    #" << std::endl;
	std::cout << "    With the same list :" << std::endl;

	std::cout << "lst1.back() = " << lst1.back() << std::endl << std::endl;

	std::cout << "#  pop back  #" << std::endl;

	std::cout << "lst1.pop_back();" << std::endl;
	lst1.pop_back();
	std::cout << "lst1.back() = " << lst1.back() << std::endl;
	std::cout << "lst1.pop_back();" << std::endl;
	lst1.pop_back();
	std::cout << "lst1.back() = " << lst1.back() << std::endl;
	std::cout << "lst1.pop_back();" << std::endl << std::endl;
	lst1.pop_back();

	std::cout << "lst1.push_back(42);" << std::endl;
	lst1.push_back(42);
	std::cout << "lst1.back() = " << lst1.back() << std::endl;
	std::cout << "lst1.pop_back();" << std::endl << std::endl;
	lst1.pop_back();

	std::cout << "Size of lst1 = " << lst1.size() << std::endl << std::endl;

		std::cout << "#  push front #" << std::endl;
	std::cout << "    For list of ints : EMPTY" << std::endl;
	std::list<int>	lst2;

	std::cout << "lst2.push_front(10);" << std::endl;
	std::cout << "lst2.push_front(20);" << std::endl;
	std::cout << "lst2.push_front(30);" << std::endl << std::endl;
	lst2.push_front(10);
	lst2.push_front(20);
	lst2.push_front(30);

	std::cout << "#    front    #" << std::endl;
	std::cout << "    With the same list :" << std::endl;

	std::cout << "lst2.front() = " << lst2.front() << std::endl << std::endl;

	std::cout << "#  pop front  #" << std::endl;

	std::cout << "lst2.pop_front();" << std::endl;
	lst2.pop_front();
	std::cout << "lst2.front() = " << lst2.front() << std::endl;
	std::cout << "lst2.pop_front();" << std::endl;
	lst2.pop_front();
	std::cout << "lst2.front() = " << lst2.front() << std::endl;
	std::cout << "lst2.pop_front();" << std::endl << std::endl;
	lst2.pop_front();

	std::cout << "lst2.push_front(42);" << std::endl;
	lst2.push_front(42);
	std::cout << "lst2.front() = " << lst2.front() << std::endl;
	std::cout << "lst2.pop_front();" << std::endl << std::endl;
	lst2.pop_front();

	std::cout << "Size of lst2 = " << lst2.size() << std::endl;

}

static void	test_essentials(void)
{
	std::cout << "#### FT TEST ESSENTIALS ####" << std::endl;
	std::cout << "#  push back #" << std::endl;
	std::cout << "    For list of ints : EMPTY" << std::endl;
	ft::list<int>	lst1;

	std::cout << "lst1.push_back(10);" << std::endl;
	std::cout << "lst1.push_back(20);" << std::endl;
	std::cout << "lst1.push_back(30);" << std::endl << std::endl;
	lst1.push_back(10);
	lst1.push_back(20);
	lst1.push_back(30);

	std::cout << "#    back    #" << std::endl;
	std::cout << "    With the same list :" << std::endl;

	std::cout << "lst1.back() = " << lst1.back() << std::endl << std::endl;

	std::cout << "#  pop back  #" << std::endl;

	std::cout << "lst1.pop_back();" << std::endl;
	lst1.pop_back();
	std::cout << "lst1.back() = " << lst1.back() << std::endl;
	std::cout << "lst1.pop_back();" << std::endl;
	lst1.pop_back();
	std::cout << "lst1.back() = " << lst1.back() << std::endl;
	std::cout << "lst1.pop_back();" << std::endl << std::endl;
	lst1.pop_back();

	std::cout << "lst1.push_back(42);" << std::endl;
	lst1.push_back(42);
	std::cout << "lst1.back() = " << lst1.back() << std::endl;
	std::cout << "lst1.pop_back();" << std::endl << std::endl;
	lst1.pop_back();

	std::cout << "Size of lst1 = " << lst1.size() << std::endl << std::endl;

		std::cout << "#  push front #" << std::endl;
	std::cout << "    For list of ints : EMPTY" << std::endl;
	ft::list<int>	lst2;

	std::cout << "lst2.push_front(10);" << std::endl;
	std::cout << "lst2.push_front(20);" << std::endl;
	std::cout << "lst2.push_front(30);" << std::endl << std::endl;
	lst2.push_front(10);
	lst2.push_front(20);
	lst2.push_front(30);

	std::cout << "#    front    #" << std::endl;
	std::cout << "    With the same list :" << std::endl;

	std::cout << "lst2.front() = " << lst2.front() << std::endl << std::endl;

	std::cout << "#  pop front  #" << std::endl;

	std::cout << "lst2.pop_front();" << std::endl;
	lst2.pop_front();
	std::cout << "lst2.front() = " << lst2.front() << std::endl;
	std::cout << "lst2.pop_front();" << std::endl;
	lst2.pop_front();
	std::cout << "lst2.front() = " << lst2.front() << std::endl;
	std::cout << "lst2.pop_front();" << std::endl << std::endl;
	lst2.pop_front();

	std::cout << "lst2.push_front(42);" << std::endl;
	lst2.push_front(42);
	std::cout << "lst2.front() = " << lst2.front() << std::endl;
	std::cout << "lst2.pop_front();" << std::endl << std::endl;
	lst2.pop_front();

	std::cout << "Size of lst2 = " << lst2.size() << std::endl << std::endl << std::endl;

	test_essentials_std();
}

static void	test_capacity_std(void)
{
	std::cout << "#### STD CAPACITY TEST ####" << std::endl;
	std::cout << "For a string list : { need, to, finish, this, project }" << std::endl;

	std::list<std::string> lst;

	lst.push_back("need");
	lst.push_back("to");
	lst.push_back("finish");
	lst.push_back("this");
	lst.push_back("project");

	std::cout << "lst.size() = " << lst.size() << std::endl;
	std::cout << "lst.empty() = " << std::boolalpha << lst.empty() << std::endl << std::endl;

	std::cout << "For an empty string list :" << std::endl;

	std::list<std::string> lst2;

	std::cout << "lst2.size() = " << lst2.size() << std::endl;
	std::cout << "lst2.empty() = " << std::boolalpha << lst2.empty() << std::endl << std::endl;
}

static void	test_capacity(void)
{
	std::cout << "#### FT CAPACITY TEST ####" << std::endl;
	std::cout << "For a string list : { need, to, finish, this, project }" << std::endl;

	ft::list<std::string> lst;

	lst.push_back("need");
	lst.push_back("to");
	lst.push_back("finish");
	lst.push_back("this");
	lst.push_back("project");

	std::cout << "lst.size() = " << lst.size() << std::endl;
	std::cout << "lst.empty() = " << std::boolalpha << lst.empty() << std::endl << std::endl;

	std::cout << "For an empty string list :" << std::endl;

	ft::list<std::string> lst2;

	std::cout << "lst2.size() = " << lst2.size() << std::endl;
	std::cout << "lst2.empty() = " << std::boolalpha << lst2.empty() << std::endl << std::endl;

	test_capacity_std();
}

static void	test_iterator_std(void)
{
	std::list<std::string> lst;

	std::cout << "#### STD ITERATOR ESSENTIALS TEST ####" << std::endl;
	std::cout << "# BEGIN & END #" << std::endl;
	std::cout << "For a string list : { youtube, twitch, reddit, facebook }" << std::endl;

	lst.push_back("youtube");
	lst.push_back("twitch");
	lst.push_back("reddit");
	lst.push_back("facebook");

	std::cout << "For it.begin != it.end();" << std::endl;
	std::cout << "++it;" << std::endl;
	for (std::list<std::string>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << std::endl;

	std::cout << "*(lst.begin()) = " << *(lst.begin()) << std::endl << std::endl;

	std::cout << "# ITERATOR OVERLOADS #" << std::endl;

	std::list<std::string>::iterator it2 = lst.begin();

	std::cout << "it2 = lst.begin();" << std::endl;

	std::cout << "++it2 = " << *(++it2) << std::endl;
	std::cout << *it2 << std::endl;
	std::cout << "--it2 = " << *(--it2) << std::endl;
	std::cout << *it2 << std::endl << std::endl;

	std::cout << "it2++ = " << *(it2++) << std::endl;
	std::cout << *it2 << std::endl;
	std::cout << "it2-- = " << *(it2--) << std::endl;
	std::cout << *it2 << std::endl << std::endl;
}

static void	test_iterator(void)
{
	ft::list<std::string> lst;

	std::cout << "#### FT ITERATOR ESSENTIALS TEST ####" << std::endl;
	std::cout << "# BEGIN & END #" << std::endl;
	std::cout << "For a string list : { youtube, twitch, reddit, facebook }" << std::endl;

	lst.push_back("youtube");
	lst.push_back("twitch");
	lst.push_back("reddit");
	lst.push_back("facebook");

	std::cout << "For it.begin != it.end();" << std::endl;
	std::cout << "++it;" << std::endl;
	for (ft::list<std::string>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << std::endl;

	std::cout << "*(lst.begin()) = " << *(lst.begin()) << std::endl << std::endl;

	std::cout << "# ITERATOR OVERLOADS #" << std::endl;
	ft::list<std::string>::iterator it2 = lst.begin();

	std::cout << "it2 = lst.begin();" << std::endl;

	std::cout << "++it2 = " << *(++it2) << std::endl;
	std::cout << *it2 << std::endl;
	std::cout << "--it2 = " << *(--it2) << std::endl;
	std::cout << *it2 << std::endl << std::endl;

	std::cout << "it2++ = " << *(it2++) << std::endl;
	std::cout << *it2 << std::endl;
	std::cout << "it2-- = " << *(it2--) << std::endl;
	std::cout << *it2 << std::endl << std::endl;

	test_iterator_std();
}

static void	test_constructors_std(void)
{
	std::cout << "#### STD CONSTRUCTORS TEST ####" << std::endl;
	std::cout << "# FILL #" << std::endl << std::endl;

	std::cout << "std::list<int> lst(10, 10);" << std::endl;
	std::list<int>	lst(10, 10);

	std::cout << std::endl << "lst = { ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << "}" << std::endl << std::endl;

	std::cout << "std::list<std::string> lst2(10, \"coucou\");" << std::endl;
	std::list<std::string> lst2(10, "coucou");

	std::cout << std::endl << "lst2 = { ";
	for (std::list<std::string>::iterator it = lst2.begin(); it != lst2.end(); it++)
		std::cout << *it << " ";
	std::cout << "}" << std::endl << std::endl;

	std::cout << "# RANGE #" << std::endl;

	std::cout << "std::list<std::string> lst3(lst2.begin(), lst2.end());" << std::endl;
	std::list<std::string> lst3(lst2.begin(), lst2.end());

	std::cout << std::endl << "lst3 = { ";
	for (std::list<std::string>::iterator it = lst3.begin(); it != lst3.end(); it++)
		std::cout << *it << " ";
	std::cout << "}" << std::endl << std::endl;

	std::cout << "# COPY #" << std::endl;
	std::cout << "std::list<std::string> lst4;" << std::endl;
	std::list<std::string> lst4;

	lst4 = lst3;
	std::cout << "lst4 = lst3;" << std::endl;

	std::cout << "lst4 = { ";
	for (std::list<std::string>::iterator it = lst4.begin(); it != lst4.end(); it++)
		std::cout << *it << " ";
	std::cout << "}" << std::endl << std::endl;
}

static void	test_constructors(void)
{
	std::cout << "#### FT CONSTRUCTORS TEST ####" << std::endl;
	std::cout << "# FILL #" << std::endl << std::endl;

	std::cout << "ft::list<int> lst(10, 10);" << std::endl;
	ft::list<int>	lst(10, 10);

	std::cout << std::endl << "lst = " << lst << std::endl << std::endl;

	std::cout << "ft::list<std::string> lst2(10, \"coucou\");" << std::endl;
	ft::list<std::string> lst2(10, "coucou");

	std::cout << std::endl << "lst2 = " << lst2 << std::endl << std::endl;

	std::cout << "# RANGE #" << std::endl;

	std::cout << "ft::list<std::string> lst3(lst2.begin(), lst2.end());" << std::endl;
	ft::list<std::string> lst3(lst2.begin(), lst2.end());

	std::cout << std::endl << "lst3 = " << lst2 << std::endl << std::endl;

	std::cout << "# COPY #" << std::endl;
	std::cout << "ft::list<std::string> lst4;" << std::endl;
	ft::list<std::string> lst4;

	lst4 = lst3;
	std::cout << "lst4 = lst3;" << std::endl;

	std::cout << "lst4 = " << lst4 << std::endl << std::endl;

	test_constructors_std();
}

static void	test_operator_over_ite_std(void)
{
	std::cout << "#### STD OVERLOAD OPERATOR TEST ####" << std::endl;
	std::cout << "# operator==() #" << std::endl;

	std::list<bool> lst;

	lst.push_back(true);
	lst.push_back(false);
	lst.push_back(false);
	lst.push_back(true);
	lst.push_back(false);
	lst.push_back(true);

	std::cout << std::endl << "For a bool list lst = { ";
	for (std::list<bool>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << std::boolalpha << *it << " ";
	std::cout << "}" << std::endl << std::endl;

	std::list<bool>::iterator it_begin = lst.begin();
	std::list<bool>::iterator it_end = lst.end();

	std::cout << "For it_begin = lst.begin()" << std::endl;
	std::cout << "For it_end = lst.end()" << std::endl << std::endl;

	std::cout << "it_begin == it_end = " << std::boolalpha << (it_begin == it_end) << std::endl;
	std::cout << "it_begin == it_begin = " << std::boolalpha << (it_begin == it_begin) << std::endl << std::endl;

	std::cout << "# operator!=() #" << std::endl;

	std::cout << "it_begin != it_end = " << std::boolalpha << (it_begin != it_end) << std::endl;
	std::cout << "it_begin != it_begin = " << std::boolalpha << (it_begin != it_begin) << std::endl << std::endl;

	std::cout << "# operator*() #" << std::endl << std::endl;

	std::cout << "*(it_begin++) = " << std::boolalpha << *(it_begin++) << std::endl;
	std::cout << "*(it_begin++) = " << std::boolalpha << *(it_begin++) << std::endl;
	std::cout << "*(it_begin++) = " << std::boolalpha << *(it_begin++) << std::endl;
	std::cout << "*(it_begin++) = " << std::boolalpha << *(it_begin++) << std::endl;
	std::cout << "*(it_begin++) = " << std::boolalpha << *(it_begin++) << std::endl;
	std::cout << "*(it_begin++) = " << std::boolalpha << *(it_begin++) << std::endl << std::endl;
}

static void	test_operator_over_ite(void)
{
	std::cout << "#### FT OVERLOAD OPERATOR TEST ####" << std::endl;
	std::cout << "# operator==() #" << std::endl;

	ft::list<bool> lst;

	lst.push_back(true);
	lst.push_back(false);
	lst.push_back(false);
	lst.push_back(true);
	lst.push_back(false);
	lst.push_back(true);

	std::cout << "For a bool list = " << std::boolalpha << lst << std::endl << std::endl;

	ft::list<bool>::iterator it_begin = lst.begin();
	ft::list<bool>::iterator it_end = lst.end();

	std::cout << "For it_begin = lst.begin()" << std::endl;
	std::cout << "For it_end = lst.end()" << std::endl << std::endl;

	std::cout << "it_begin == it_end = " << std::boolalpha << (it_begin == it_end) << std::endl;
	std::cout << "it_begin == it_begin = " << std::boolalpha << (it_begin == it_begin) << std::endl << std::endl;

	std::cout << "# operator!=() #" << std::endl;

	std::cout << "it_begin != it_end = " << std::boolalpha << (it_begin != it_end) << std::endl;
	std::cout << "it_begin != it_begin = " << std::boolalpha << (it_begin != it_begin) << std::endl << std::endl;

	std::cout << "# operator*() #" << std::endl << std::endl;

	std::cout << "*(it_begin++) = " << std::boolalpha << *(it_begin++) << std::endl;
	std::cout << "*(it_begin++) = " << std::boolalpha << *(it_begin++) << std::endl;
	std::cout << "*(it_begin++) = " << std::boolalpha << *(it_begin++) << std::endl;
	std::cout << "*(it_begin++) = " << std::boolalpha << *(it_begin++) << std::endl;
	std::cout << "*(it_begin++) = " << std::boolalpha << *(it_begin++) << std::endl;
	std::cout << "*(it_begin++) = " << std::boolalpha << *(it_begin++) << std::endl << std::endl;

	test_operator_over_ite_std();
}

static void	test_modifiers_one_std(void)
{
	std::cout << "#### STD MODIFIERS PART ONE ####" << std::endl;
	std::cout << "#### CLEAR ####" << std::endl;

	std::list<std::string> lst;

	lst.push_back("mr");
	lst.push_back("robot");
	lst.push_back("is");
	lst.push_back("a");
	lst.push_back("very");
	lst.push_back("good");
	lst.push_back("series.");

	std::cout << "For a string list = " << lst << std::endl;
	std::cout << "lst.size() = " << lst.size() << std::endl << std::endl;

	lst.clear();
	std::cout << "lst.clear();"<< std::endl << std::endl;

	std::cout << "For a string list = " << lst << std::endl;
	std::cout << "lst.size() = " << lst.size() << std::endl << std::endl;

	lst.clear();
	std::cout << "lst.clear();"<< std::endl << std::endl;

	std::cout << "For a string list = " << lst << std::endl;
	std::cout << "lst.size() = " << lst.size() << std::endl << std::endl;

	std::cout << "#### ASSIGN ####" << std::endl;

	std::list<std::string> lst_empty;
	std::list<std::string> lst_watch_brands;

	lst_watch_brands.push_back("rolex");
	lst_watch_brands.push_back("lip");
	lst_watch_brands.push_back("montblanc");
	lst_watch_brands.push_back("cartier");
	lst_watch_brands.push_back("TAG_Heuer");

	std::cout << "For an empty string list : " << lst_empty << std::endl;
	std::cout << "With an string list lst_watch_brands : " << lst_watch_brands << std::endl << std::endl;

	lst_empty.assign(10, "empty");
	std::cout << "lst_empty.assign(10, \"empty\");" << std::endl;
	std::cout << "lst_empty = " << lst_empty << std::endl << std::endl;

	lst_empty.assign(lst_watch_brands.begin(), lst_watch_brands.end());
	std::cout << "lst_empty.assign(lst_watch_brands.begin(), lst_watch_brands.end());" << std::endl;

	std::cout << "lst_empty = " << lst_empty << std::endl << std::endl;

	std::cout << "#### INSERT ####" << std::endl;
	std::cout << "#- SINGLE ELEMENT -#" << std::endl;

	std::list<std::string> red_apples(10, "🍎");

	std::cout << "For red apples list : " << red_apples << std::endl << std::endl;

	std::cout << "// Inserting green apple at the begining of the list" << std::endl;
	std::cout << "red_apples.insert(red_apples.begin(), \"🍏\")" << std::endl;
	red_apples.insert(red_apples.begin(), "🍏");

	std::cout << "red apples list : " << red_apples << std::endl << std::endl;

	std::cout << "// Inserting green apple at the end of the list" << std::endl;
	std::cout << "red_apples.insert(red_apples.end(), \"🍏\")" << std::endl;
	red_apples.insert(red_apples.end(), "🍏");

	std::cout << "red apples list : " << red_apples << std::endl << std::endl;

	std::list<std::string>::iterator	it_middle = red_apples.begin();

	it_middle++;
	it_middle++;
	it_middle++;
	it_middle++;
	it_middle++;
	it_middle++;

	std::cout << "// Inserting green apple at the middle of the list" << std::endl;
	std::cout << "red_apples.insert(it_middle, \"🍏\")" << std::endl;
	red_apples.insert(it_middle, "🍏");

	std::cout << "red apples list : " << red_apples << std::endl << std::endl;

	std::cout << "#- RANGE -#" << std::endl;

	std::list<std::string> fruits;

	fruits.push_back("🍍");
	fruits.push_back("🍉");
	fruits.push_back("🍐");
	fruits.push_back("🍒");
	fruits.push_back("🍓");

	std::list<std::string> animals;

	animals.push_back("🐈");
	animals.push_back("🐊");
	animals.push_back("🐇");
	animals.push_back("🦖");
	animals.push_back("🐬");

	std::list<std::string>::iterator animalsIteMid = animals.begin();
	animalsIteMid++;
	animalsIteMid++;

	std::cout << "For fruit in string list : " << fruits << std::endl;
	std::cout << "For animal in string list : " << animals << std::endl;

	std::cout << "// Insert range of fruits in animals list" << std::endl;
	animals.insert(animalsIteMid, fruits.begin(), fruits.end());

	std::cout << "animal list after insert : " << animals << std::endl << std::endl;

	std::cout << "#- MULTIPLE SAME ELEMENT -#" << std::endl;

	std::cout << "// In the animal list, insert 5 bananas at the begining" << std::endl;
	animals.insert(animals.begin(), 5, "🍌");
	std::cout << "animals.insert(animals.begin(), 5, \"🍌\")" << std::endl;
	std::cout << "animal list after insert : " << animals << std::endl << std::endl;

	std::cout << "// In the animal list, insert 5 bananas at the end" << std::endl;
	animals.insert(animals.end(), 5, "🍌");
	std::cout << "animals.insert(animals.end(), 5, \"🍌\")" << std::endl;
	std::cout << "animal list after insert : " << animals << std::endl << std::endl;
}

static void	test_modifiers_one(void)
{
	std::cout << "#### FT MODIFIERS PART ONE ####" << std::endl;
	std::cout << "#### CLEAR ####" << std::endl;

	ft::list<std::string> lst;

	lst.push_back("mr");
	lst.push_back("robot");
	lst.push_back("is");
	lst.push_back("a");
	lst.push_back("very");
	lst.push_back("good");
	lst.push_back("series.");

	std::cout << "For a string list = " << lst << std::endl;
	std::cout << "lst.size() = " << lst.size() << std::endl << std::endl;

	lst.clear();
	std::cout << "lst.clear();"<< std::endl << std::endl;

	std::cout << "For a string list = " << lst << std::endl;
	std::cout << "lst.size() = " << lst.size() << std::endl << std::endl;

	lst.clear();
	std::cout << "lst.clear();"<< std::endl << std::endl;

	std::cout << "For a string list = " << lst << std::endl;
	std::cout << "lst.size() = " << lst.size() << std::endl << std::endl;

	std::cout << "#### ASSIGN ####" << std::endl;

	ft::list<std::string> lst_empty;
	ft::list<std::string> lst_watch_brands;

	lst_watch_brands.push_back("rolex");
	lst_watch_brands.push_back("lip");
	lst_watch_brands.push_back("montblanc");
	lst_watch_brands.push_back("cartier");
	lst_watch_brands.push_back("TAG_Heuer");

	std::cout << "For an empty string list : " << lst_empty << std::endl;
	std::cout << "With an string list lst_watch_brands : " << lst_watch_brands << std::endl << std::endl;

	lst_empty.assign(10, "empty");
	std::cout << "lst_empty.assign(10, \"empty\");" << std::endl;
	std::cout << "lst_empty = " << lst_empty << std::endl << std::endl;

	lst_empty.assign(lst_watch_brands.begin(), lst_watch_brands.end());
	std::cout << "lst_empty.assign(lst_watch_brands.begin(), lst_watch_brands.end());" << std::endl;

	std::cout << "lst_empty = " << lst_empty << std::endl << std::endl;

	std::cout << "#### INSERT ####" << std::endl;
	std::cout << "#- SINGLE ELEMENT -#" << std::endl;

	ft::list<std::string> red_apples(10, "🍎");

	std::cout << "For red apples list : " << red_apples << std::endl << std::endl;

	std::cout << "// Inserting green apple at the begining of the list" << std::endl;
	std::cout << "red_apples.insert(red_apples.begin(), \"🍏\")" << std::endl;
	red_apples.insert(red_apples.begin(), "🍏");

	std::cout << "red apples list : " << red_apples << std::endl << std::endl;

	std::cout << "// Inserting green apple at the end of the list" << std::endl;
	std::cout << "red_apples.insert(red_apples.end(), \"🍏\")" << std::endl;
	red_apples.insert(red_apples.end(), "🍏");

	std::cout << "red apples list : " << red_apples << std::endl << std::endl;

	ft::list<std::string>::iterator	it_middle = red_apples.begin();

	it_middle++;
	it_middle++;
	it_middle++;
	it_middle++;
	it_middle++;
	it_middle++;

	std::cout << "// Inserting green apple at the middle of the list" << std::endl;
	std::cout << "red_apples.insert(it_middle, \"🍏\")" << std::endl;
	red_apples.insert(it_middle, "🍏");

	std::cout << "red apples list : " << red_apples << std::endl << std::endl;

	std::cout << "#- RANGE -#" << std::endl;

	ft::list<std::string> fruits;

	fruits.push_back("🍍");
	fruits.push_back("🍉");
	fruits.push_back("🍐");
	fruits.push_back("🍒");
	fruits.push_back("🍓");

	ft::list<std::string> animals;

	animals.push_back("🐈");
	animals.push_back("🐊");
	animals.push_back("🐇");
	animals.push_back("🦖");
	animals.push_back("🐬");

	ft::list<std::string>::iterator animalsIteMid = animals.begin();
	animalsIteMid++;
	animalsIteMid++;

	std::cout << "For fruit in string list : " << fruits << std::endl;
	std::cout << "For animal in string list : " << animals << std::endl;

	std::cout << "// Insert range of fruits in animals list" << std::endl;
	animals.insert(animalsIteMid, fruits.begin(), fruits.end());

	std::cout << "animal list after insert : " << animals << std::endl << std::endl;

	std::cout << "#- MULTIPLE SAME ELEMENT -#" << std::endl;

	std::cout << "// In the animal list, insert 5 bananas at the begining" << std::endl;
	animals.insert(animals.begin(), 5, "🍌");
	std::cout << "animals.insert(animals.begin(), 5, \"🍌\")" << std::endl;
	std::cout << "animal list after insert : " << animals << std::endl << std::endl;

	std::cout << "// In the animal list, insert 5 bananas at the end" << std::endl;
	animals.insert(animals.end(), 5, "🍌");
	std::cout << "animals.insert(animals.end(), 5, \"🍌\")" << std::endl;
	std::cout << "animal list after insert : " << animals << std::endl << std::endl;

	test_modifiers_one_std();

}

static void	test_modifiers_two_std(void)
{
	std::cout << "#### STD MODIFIERS PART TWO ####" << std::endl;
	std::cout << "#### ERASE ####" << std::endl;
	std::cout << "#- ONE ELEMENT -#" << std::endl;

	std::list<std::string>	alien_hidden;

	alien_hidden.push_back("👽");
	alien_hidden.push_back("🎅");
	alien_hidden.push_back("🎅");
	alien_hidden.push_back("🎅");
	alien_hidden.push_back("👽");
	alien_hidden.push_back("👽");
	alien_hidden.push_back("👽");
	alien_hidden.push_back("👽");
	alien_hidden.push_back("🎅");
	alien_hidden.push_back("🎅");
	alien_hidden.push_back("🎅");
	alien_hidden.push_back("🎅");
	alien_hidden.push_back("🎅");
	alien_hidden.push_back("👽");

	std::cout << "For a string vector alien_hidden = " \
			  << alien_hidden << std::endl << std::endl;

	std::cout << "// Remove the begining alien" << std::endl;
	std::cout << "alien_hidden.erase(alien_hidden.begin());" << std::endl;
	alien_hidden.erase(alien_hidden.begin());
	std::cout << "Now alien_hidden = " \
			  << alien_hidden << std::endl << std::endl;

	std::cout << "// Remove the end alien" << std::endl;
	std::cout << "alien_hidden.erase(--alien_hidden.end());" << std::endl;
	alien_hidden.erase(--alien_hidden.end());
	std::cout << "Now alien_hidden = " \
			  << alien_hidden << std::endl << std::endl;

	std::cout << "#- RANGE -#" << std::endl;

	std::cout << "// Remove the group of alien" << std::endl;
	std::list<std::string>::iterator it_first_alien_grp = alien_hidden.begin();
	std::list<std::string>::iterator it_last_alien_grp;
	it_first_alien_grp++;
	it_first_alien_grp++;
	it_first_alien_grp++;
	it_last_alien_grp = it_first_alien_grp;
	it_last_alien_grp++;
	it_last_alien_grp++;
	it_last_alien_grp++;

	std::cout << "alien_hidden.erase(it_first_alien_grp, ++it_last_alien_grp);" << std::endl;
	alien_hidden.erase(it_first_alien_grp, ++it_last_alien_grp);
	std::cout << "Now alien_hidden = " \
			  << alien_hidden << std::endl << std::endl;

	std::cout << "#### RESIZE ####" << std::endl;

	std::cout << "// let's add some Santa girls with the resize function !" << std::endl;
	alien_hidden.resize(16, "🤶");
	std::cout << "alien_hidden.resize(16, \"🤶\")" << std::endl;
	std::cout << "Now alien_hidden = " \
			  << alien_hidden << std::endl << std::endl;

	std::cout << "As there is only one Santa claus and one Santa girl :" << std::endl;
	std::cout << "alien_hidden.resize(1, \"🎅\")" << std::endl;
	std::cout << "alien_hidden.resize(2, \"🤶\")" << std::endl;
	alien_hidden.resize(1, "🎅");
	alien_hidden.resize(2, "🤶");
	std::cout << "Now alien_hidden = " \
			  << alien_hidden << std::endl << std::endl;

	std::cout << "#### SWAP ####" << std::endl;

	std::list<std::string> ticks(5, "✅");
	std::list<std::string> cross(5, "❌");

	std::cout << "For a string list of ticks : " << ticks << std::endl;
	std::cout << "For a string list of cross : " << cross << std::endl << std::endl;

	std::cout << "// Now lets swap it" << std::endl;
	std::cout << "ticks.swap(cross);" << std::endl << std::endl;
	ticks.swap(cross);

	std::cout << "Now list of ticks : " << ticks << std::endl;
	std::cout << "Now list of cross : " << cross << std::endl << std::endl;
}
static void	test_modifiers_two(void)
{
	std::cout << "#### FT MODIFIERS PART TWO ####" << std::endl;
	std::cout << "#### ERASE ####" << std::endl;
	std::cout << "#- ONE ELEMENT -#" << std::endl;

	ft::list<std::string>	alien_hidden;

	alien_hidden.push_back("👽");
	alien_hidden.push_back("🎅");
	alien_hidden.push_back("🎅");
	alien_hidden.push_back("🎅");
	alien_hidden.push_back("👽");
	alien_hidden.push_back("👽");
	alien_hidden.push_back("👽");
	alien_hidden.push_back("👽");
	alien_hidden.push_back("🎅");
	alien_hidden.push_back("🎅");
	alien_hidden.push_back("🎅");
	alien_hidden.push_back("🎅");
	alien_hidden.push_back("🎅");
	alien_hidden.push_back("👽");

	std::cout << "For a string vector alien_hidden = " \
			  << alien_hidden << std::endl << std::endl;

	std::cout << "// Remove the begining alien" << std::endl;
	std::cout << "alien_hidden.erase(alien_hidden.begin());" << std::endl;
	alien_hidden.erase(alien_hidden.begin());
	std::cout << "Now alien_hidden = " \
			  << alien_hidden << std::endl << std::endl;

	std::cout << "// Remove the end alien" << std::endl;
	std::cout << "alien_hidden.erase(--alien_hidden.end());" << std::endl;
	alien_hidden.erase(--alien_hidden.end());
	std::cout << "Now alien_hidden = " \
			  << alien_hidden << std::endl << std::endl;

	std::cout << "#- RANGE -#" << std::endl;

	std::cout << "// Remove the group of alien" << std::endl;
	ft::list<std::string>::iterator it_first_alien_grp = alien_hidden.begin();
	ft::list<std::string>::iterator it_last_alien_grp;
	it_first_alien_grp++;
	it_first_alien_grp++;
	it_first_alien_grp++;
	it_last_alien_grp = it_first_alien_grp;
	it_last_alien_grp++;
	it_last_alien_grp++;
	it_last_alien_grp++;

	std::cout << "alien_hidden.erase(it_first_alien_grp, ++it_last_alien_grp);" << std::endl;
	alien_hidden.erase(it_first_alien_grp, ++it_last_alien_grp);
	std::cout << "Now alien_hidden = " \
			  << alien_hidden << std::endl << std::endl;

	std::cout << "#### RESIZE ####" << std::endl;

	std::cout << "// let's add some Santa girls with the resize function !" << std::endl;
	alien_hidden.resize(16, "🤶");
	std::cout << "alien_hidden.resize(16, \"🤶\")" << std::endl;
	std::cout << "Now alien_hidden = " \
			  << alien_hidden << std::endl << std::endl;

	std::cout << "As there is only one Santa claus and one Santa girl :" << std::endl;
	std::cout << "alien_hidden.resize(1, \"🎅\")" << std::endl;
	std::cout << "alien_hidden.resize(2, \"🤶\")" << std::endl;
	alien_hidden.resize(1, "🎅");
	alien_hidden.resize(2, "🤶");
	std::cout << "Now alien_hidden = " \
			  << alien_hidden << std::endl << std::endl;

	std::cout << "#### SWAP ####" << std::endl;

	ft::list<std::string> ticks(5, "✅");
	ft::list<std::string> cross(5, "❌");

	std::cout << "For a string list of ticks : " << ticks << std::endl;
	std::cout << "For a string list of cross : " << cross << std::endl << std::endl;

	std::cout << "// Now lets swap it" << std::endl;
	std::cout << "ticks.swap(cross);" << std::endl << std::endl;
	ticks.swap(cross);

	std::cout << "Now list of ticks : " << ticks << std::endl;
	std::cout << "Now list of cross : " << cross << std::endl << std::endl;

	test_modifiers_two_std();
}

class	potato
{
public:

	potato(int id) : _id(id)
	{
		std::cout << "BORN ! I'm the potato : " << id << std::endl;
	};

	potato(const potato &x)
	{
		*this = x;
	}

	potato& operator= (const potato& x)
	{
		_id = x._id;
		// std::cout << "BORN ! I'm the potato : " << _id << std::endl;
		return (*this);
	};

	const int &get_id(void) const { return (_id); };

	virtual ~potato() {};

private:

	int _id;

};

std::ostream	&operator<<(std::ostream &o, potato const &i)
{
	o << "🥔:" << i.get_id();
	return (o);
}

static void	test_operations_splice_std(void)
{
	std::cout << "#### STD OPERATIONS SPLICE ####" << std::endl;
	std::cout << "#- SINGLE ELEMENT -#" << std::endl;

	std::list<potato>	lst_potatoes;
	std::cout <<	\
	"// We'll take a list of potatoes (lst_potatoes) that say their ID when they are constructed : "	\
	<< std::endl << std::endl;

	lst_potatoes.push_back(potato(0));
	lst_potatoes.push_back(potato(1));
	lst_potatoes.push_back(potato(2));
	lst_potatoes.push_back(potato(3));
	lst_potatoes.push_back(potato(4));
	lst_potatoes.push_back(potato(5));
	lst_potatoes.push_back(potato(6));
	lst_potatoes.push_back(potato(7));
	lst_potatoes.push_back(potato(8));
	lst_potatoes.push_back(potato(9));

	std::cout << std::endl;
	std::cout << "So now the list of potatoes is : " << lst_potatoes << std::endl << std::endl;

	std::list<potato>	lst_empty_potatoes;

	std::cout << \
	"Let's take an other list of potatoes but an empty, lst_empty_potatoes : " \
	<< lst_empty_potatoes << std::endl << std::endl;

	std::cout << "// So now we'll put a potatoes from the first list to the" << std::endl << \
	" empty with splice function and no potatos are supposed to be constructed." << std::endl << std::endl;

	lst_empty_potatoes.splice(lst_empty_potatoes.begin(), lst_potatoes, ++lst_potatoes.begin());
	std::cout << "lst_empty_potatoes.splice(lst_empty_potatoes.begin(), lst_potatoes, ++lst_potatoes.begin());" << std::endl << std::endl;

	std::cout << "Now lst_empty_potatoes = " << lst_empty_potatoes << std::endl;;
	std::cout << "& lst_potatoes = " << lst_potatoes << std::endl << std::endl;

	std::list<potato>::iterator	ite_fourth = lst_potatoes.begin();

	ite_fourth++;
	ite_fourth++;
	ite_fourth++;

	std::cout << "#- RANGE -#" << std::endl;
	std::cout << "// Now Let's do the same but for the fourth potatoes in a row" << std::endl;
	lst_empty_potatoes.splice(lst_empty_potatoes.begin(), lst_potatoes, lst_potatoes.begin(), ++ite_fourth);
	std::cout << "lst_empty_potatoes.splice(lst_empty_potatoes.begin(), lst_potatoes, lst_potatoes.begin(), ++ite_fourth);" << std::endl << std::endl;

	std::cout << "Now lst_empty_potatoes = " << lst_empty_potatoes << std::endl;;
	std::cout << "& lst_potatoes = " << lst_potatoes << std::endl << std::endl;

	std::cout << "#- ENTIRE LIST -#" << std::endl;
	std::cout << "// Finally, let's splice the rest of potatoes in the originally empty list." << std::endl;
	lst_empty_potatoes.splice(lst_empty_potatoes.end(), lst_potatoes);
	std::cout << "lst_empty_potatoes.splice(lst_empty_potatoes.end(), lst_potatoes);" << std::endl << std::endl;

	std::cout << "Now lst_empty_potatoes = " << lst_empty_potatoes << std::endl;;
	std::cout << "& lst_potatoes = " << lst_potatoes << std::endl << std::endl;
}

static void	test_operations_splice(void)
{
	std::cout << "#### FT OPERATIONS SPLICE ####" << std::endl;
	std::cout << "#- SINGLE ELEMENT -#" << std::endl;

	ft::list<potato>	lst_potatoes;
	std::cout <<	\
	"// We'll take a list of potatoes (lst_potatoes) that say their ID when they are constructed : "	\
	<< std::endl << std::endl;

	lst_potatoes.push_back(potato(0));
	lst_potatoes.push_back(potato(1));
	lst_potatoes.push_back(potato(2));
	lst_potatoes.push_back(potato(3));
	lst_potatoes.push_back(potato(4));
	lst_potatoes.push_back(potato(5));
	lst_potatoes.push_back(potato(6));
	lst_potatoes.push_back(potato(7));
	lst_potatoes.push_back(potato(8));
	lst_potatoes.push_back(potato(9));

	std::cout << std::endl;
	std::cout << "So now the list of potatoes is : " << lst_potatoes << std::endl << std::endl;

	ft::list<potato>	lst_empty_potatoes;

	std::cout << \
	"Let's take an other list of potatoes but an empty, lst_empty_potatoes : " \
	<< lst_empty_potatoes << std::endl << std::endl;

	std::cout << "// So now we'll put a potatoes from the first list to the" << std::endl << \
	" empty with splice function and no potatos are supposed to be constructed." << std::endl << std::endl;

	lst_empty_potatoes.splice(lst_empty_potatoes.begin(), lst_potatoes, ++lst_potatoes.begin());
	std::cout << "lst_empty_potatoes.splice(lst_empty_potatoes.begin(), lst_potatoes, ++lst_potatoes.begin());" << std::endl << std::endl;

	std::cout << "Now lst_empty_potatoes = " << lst_empty_potatoes << std::endl;;
	std::cout << "& lst_potatoes = " << lst_potatoes << std::endl << std::endl;

	ft::list<potato>::iterator	ite_fourth = lst_potatoes.begin();

	ite_fourth++;
	ite_fourth++;
	ite_fourth++;

	std::cout << "#- RANGE -#" << std::endl;
	std::cout << "// Now Let's do the same but for the fourth potatoes in a row" << std::endl;
	lst_empty_potatoes.splice(lst_empty_potatoes.begin(), lst_potatoes, lst_potatoes.begin(), ++ite_fourth);
	std::cout << "lst_empty_potatoes.splice(lst_empty_potatoes.begin(), lst_potatoes, lst_potatoes.begin(), ++ite_fourth);" << std::endl << std::endl;

	std::cout << "Now lst_empty_potatoes = " << lst_empty_potatoes << std::endl;;
	std::cout << "& lst_potatoes = " << lst_potatoes << std::endl << std::endl;

	std::cout << "#- ENTIRE LIST -#" << std::endl;
	std::cout << "// Finally, let's splice the rest of potatoes in the originally empty list." << std::endl;
	lst_empty_potatoes.splice(lst_empty_potatoes.end(), lst_potatoes);
	std::cout << "lst_empty_potatoes.splice(lst_empty_potatoes.end(), lst_potatoes);" << std::endl << std::endl;

	std::cout << "Now lst_empty_potatoes = " << lst_empty_potatoes << std::endl;;
	std::cout << "& lst_potatoes = " << lst_potatoes << std::endl << std::endl;

	test_operations_splice_std();
}

bool	is_odd(int n) { return ((n % 2) != 0); };

bool	is_neg(int n) { return (n < 0); };

void test_operations_remove_std()
{
	std::cout << "#### STD OPERATIONS REMOVE | REMOVE_IF TEST ####" << std::endl;
	std::cout << "#### REMOVE ####" << std::endl;

	std::list<int>	lst_numbers;

	lst_numbers.push_back(69);
	lst_numbers.push_back(69);
	lst_numbers.push_back(42);
	lst_numbers.push_back(42);
	lst_numbers.push_back(69);
	lst_numbers.push_back(69);
	lst_numbers.push_back(69);
	lst_numbers.push_back(42);
	lst_numbers.push_back(42);
	lst_numbers.push_back(69);
	lst_numbers.push_back(42);
	lst_numbers.push_back(69);

	std::cout << "For a int list : " << lst_numbers << std::endl << std::endl;

	lst_numbers.remove(42);
	std::cout << "lst_numbers.remove(42);" << std::endl << std::endl;

	std::cout << "Now int list : " << lst_numbers << std::endl << std::endl;

	lst_numbers.remove(69);
	std::cout << "lst_numbers.remove(69);" << std::endl << std::endl;

	std::cout << "Now int list : " << lst_numbers << std::endl << std::endl;

	std::cout << "#### REMOVE_IF ####" << std::endl;

	std::list<int>	lst_nums;

	lst_nums.push_back(-4355);
	lst_nums.push_back(4573);
	lst_nums.push_back(-2267);
	lst_nums.push_back(3468);
	lst_nums.push_back(2351);
	lst_nums.push_back(-1112);
	lst_nums.push_back(-6356);
	lst_nums.push_back(6832);
	lst_nums.push_back(4548);
	lst_nums.push_back(-3252);
	lst_nums.push_back(-5420);
	lst_nums.push_back(2232);

	std::cout << "For a int list : " << lst_nums << std::endl << std::endl;

	lst_nums.remove_if(is_odd);
	std::cout << "lst_nums.remove_if(is_odd);" << std::endl << std::endl;

	std::cout << "Now int list : " << lst_nums << std::endl << std::endl;

	lst_nums.remove_if(is_neg);
	std::cout << "lst_nums.remove_if(is_neg);" << std::endl << std::endl;

	std::cout << "Now int list : " << lst_nums << std::endl << std::endl;
}

void test_operations_remove()
{
	std::cout << "#### FT OPERATIONS REMOVE | REMOVE_IF TEST ####" << std::endl;
	std::cout << "#### REMOVE ####" << std::endl;

	ft::list<int>	lst_numbers;

	lst_numbers.push_back(69);
	lst_numbers.push_back(69);
	lst_numbers.push_back(42);
	lst_numbers.push_back(42);
	lst_numbers.push_back(69);
	lst_numbers.push_back(69);
	lst_numbers.push_back(69);
	lst_numbers.push_back(42);
	lst_numbers.push_back(42);
	lst_numbers.push_back(69);
	lst_numbers.push_back(42);
	lst_numbers.push_back(69);

	std::cout << "For a int list : " << lst_numbers << std::endl << std::endl;

	lst_numbers.remove(42);
	std::cout << "lst_numbers.remove(42);" << std::endl << std::endl;

	std::cout << "Now int list : " << lst_numbers << std::endl << std::endl;

	lst_numbers.remove(69);
	std::cout << "lst_numbers.remove(69);" << std::endl << std::endl;

	std::cout << "Now int list : " << lst_numbers << std::endl << std::endl;

	std::cout << "#### REMOVE_IF ####" << std::endl;

	ft::list<int>	lst_nums;

	lst_nums.push_back(-4355);
	lst_nums.push_back(4573);
	lst_nums.push_back(-2267);
	lst_nums.push_back(3468);
	lst_nums.push_back(2351);
	lst_nums.push_back(-1112);
	lst_nums.push_back(-6356);
	lst_nums.push_back(6832);
	lst_nums.push_back(4548);
	lst_nums.push_back(-3252);
	lst_nums.push_back(-5420);
	lst_nums.push_back(2232);

	std::cout << "For a int list : " << lst_nums << std::endl << std::endl;

	lst_nums.remove_if(is_odd);
	std::cout << "lst_nums.remove_if(is_odd);" << std::endl << std::endl;

	std::cout << "Now int list : " << lst_nums << std::endl << std::endl;

	lst_nums.remove_if(is_neg);
	std::cout << "lst_nums.remove_if(is_neg);" << std::endl << std::endl;

	std::cout << "Now int list : " << lst_nums << std::endl << std::endl;

	test_operations_remove_std();
}

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

static void	test_operations_unique_std(void)
{
	std::cout << "#### STD UNIQUE MERGE TEST ####" << std::endl;
	std::cout << "#### UNIQUE ####" << std::endl;
	std::cout << "#- WITHOUT CONDITION -#" << std::endl;

	std::list<int> lst_nums;

	lst_nums.push_back(1);
	lst_nums.push_back(1);
	lst_nums.push_back(2);
	lst_nums.push_back(3);
	lst_nums.push_back(3);
	lst_nums.push_back(3);
	lst_nums.push_back(3);
	lst_nums.push_back(4);
	lst_nums.push_back(5);
	lst_nums.push_back(6);
	lst_nums.push_back(6);
	lst_nums.push_back(7);
	lst_nums.push_back(8);
	lst_nums.push_back(9);
	lst_nums.push_back(9);

	std::cout << "For a int list lst_nums : " << lst_nums << std::endl << std::endl;

	lst_nums.unique();
	std::cout << "lst_nums.unique();" << std::endl << std::endl;

	std::cout << "Now lst_nums = " << lst_nums << std::endl;

	std::list<int> lst_nums2;

	lst_nums2.push_back(1);
	lst_nums2.push_back(1);
	lst_nums2.push_back(1);
	lst_nums2.push_back(1);
	lst_nums2.push_back(1);
	lst_nums2.push_back(1);
	lst_nums2.push_back(1);

	std::cout << "For a int list lst_nums2 : " << lst_nums2 << std::endl << std::endl;

	lst_nums2.unique();
	std::cout << "lst_nums2.unique();" << std::endl << std::endl;

	std::cout << "Now lst_nums2 = " << lst_nums2 << std::endl << std::endl;

	std::cout << "#- WITH CONDITION -#" << std::endl << std::endl;

	std::list<float>	lst_floats;

	lst_floats.push_back(2.72);
	lst_floats.push_back(3.14);
	lst_floats.push_back(12.15);
	lst_floats.push_back(12.77);
	lst_floats.push_back(15.3);
	lst_floats.push_back(72.25);
	lst_floats.push_back(73.0);
	lst_floats.push_back(73.35);

	std::cout << "For a float list lst_floats : " << lst_floats << std::endl << std::endl;

	lst_floats.unique(same_integral_part);
	std::cout << "lst_floats.unique(same_integral_part);" << std::endl << std::endl;

	std::cout << "Now lst_floats : " << lst_floats << std::endl << std::endl;

	lst_floats.unique(is_near());
	std::cout << "lst_floats.unique(is_near());" << std::endl << std::endl;

	std::cout << "Now lst_floats : " << lst_floats << std::endl << std::endl;
}

static void	test_operations_unique(void)
{
	std::cout << "#### FT UNIQUE MERGE TEST ####" << std::endl;
	std::cout << "#### UNIQUE ####" << std::endl;
	std::cout << "#- WITHOUT CONDITION -#" << std::endl;

	ft::list<int> lst_nums;

	lst_nums.push_back(1);
	lst_nums.push_back(1);
	lst_nums.push_back(2);
	lst_nums.push_back(3);
	lst_nums.push_back(3);
	lst_nums.push_back(3);
	lst_nums.push_back(3);
	lst_nums.push_back(4);
	lst_nums.push_back(5);
	lst_nums.push_back(6);
	lst_nums.push_back(6);
	lst_nums.push_back(7);
	lst_nums.push_back(8);
	lst_nums.push_back(9);
	lst_nums.push_back(9);

	std::cout << "For a int list lst_nums : " << lst_nums << std::endl << std::endl;

	lst_nums.unique();
	std::cout << "lst_nums.unique();" << std::endl << std::endl;

	std::cout << "Now lst_nums = " << lst_nums << std::endl;

	ft::list<int> lst_nums2;

	lst_nums2.push_back(1);
	lst_nums2.push_back(1);
	lst_nums2.push_back(1);
	lst_nums2.push_back(1);
	lst_nums2.push_back(1);
	lst_nums2.push_back(1);
	lst_nums2.push_back(1);

	std::cout << "For a int list lst_nums2 : " << lst_nums2 << std::endl << std::endl;

	lst_nums2.unique();
	std::cout << "lst_nums2.unique();" << std::endl << std::endl;

	std::cout << "Now lst_nums2 = " << lst_nums2 << std::endl << std::endl;

	std::cout << "#- WITH CONDITION -#" << std::endl << std::endl;

	ft::list<float>	lst_floats;

	lst_floats.push_back(2.72);
	lst_floats.push_back(3.14);
	lst_floats.push_back(12.15);
	lst_floats.push_back(12.77);
	lst_floats.push_back(15.3);
	lst_floats.push_back(72.25);
	lst_floats.push_back(73.0);
	lst_floats.push_back(73.35);

	std::cout << "For a float list lst_floats : " << lst_floats << std::endl << std::endl;

	lst_floats.unique(same_integral_part);
	std::cout << "lst_floats.unique(same_integral_part);" << std::endl << std::endl;

	std::cout << "Now lst_floats : " << lst_floats << std::endl << std::endl;

	lst_floats.unique(is_near());
	std::cout << "lst_floats.unique(is_near());" << std::endl << std::endl;

	std::cout << "Now lst_floats : " << lst_floats << std::endl << std::endl;

	test_operations_unique_std();
}

template <typename T>
static bool	superior_comp(T &lvalue, T &rvalue) { return (lvalue > rvalue); };

static void	test_operations_sort_std(void)
{
std::cout << "#### STD OPERATIONS SORT TEST ####" << std::endl;
	std::cout << "#### WITHOUT CONDITION ####" << std::endl;

	std::list<int>			lst_int;

	lst_int.push_back(4);
	lst_int.push_back(-8392454);
	lst_int.push_back(3849);
	lst_int.push_back(-9000);
	lst_int.push_back(-2147483648);
	lst_int.push_back(2147483647);
	lst_int.push_back(0);

	std::cout << "For a int list lst_int : " << lst_int << std::endl;

	lst_int.sort();
	std::cout << "lst_int.sort();" << std::endl;

	std::cout << "Now lst_int : " << lst_int << std::endl << std::endl;

 	std::list<double>		lst_double;

	lst_double.push_back(2.2);
	lst_double.push_back(INFINITY);
	lst_double.push_back(42.42);
	lst_double.push_back(420.024);
	lst_double.push_back(3.14);
	lst_double.push_back(-233.141);
	lst_double.push_back(-INFINITY);
	lst_double.push_back(0);
	lst_double.push_back(347589.19454);

	std::cout << "For a double list lst_double : " << lst_double << std::endl;

	lst_double.sort();
	std::cout << "lst_double.sort();" << std::endl;

	std::cout << "Now lst_double : " << lst_double << std::endl << std::endl;

	std::list<std::string>	lst_string;

	lst_string.push_back("coucou8");
	lst_string.push_back("coucou1");
	lst_string.push_back("coucou4");
	lst_string.push_back("coucou4");
	lst_string.push_back("coucou2");
	lst_string.push_back("coucou1");
	lst_string.push_back("coucou9");
	lst_string.push_back("coucou0");
	lst_string.push_back("coucou6");

	std::cout << "For a std::string list lst_string : " << lst_string << std::endl;

	lst_string.sort();
	std::cout << "lst_string.sort();" << std::endl;

	std::cout << "Now lst_string : " << lst_string << std::endl << std::endl;

	std::cout << "#### WITH CONDITION ####" << std::endl;
	std::cout << "Conditition superior_comp = return (lvalue > rvalue);" << std::endl;

		std::list<int>			lst_int_condition;

	lst_int_condition.push_back(4);
	lst_int_condition.push_back(-8392454);
	lst_int_condition.push_back(3849);
	lst_int_condition.push_back(-9000);
	lst_int_condition.push_back(-2147483648);
	lst_int_condition.push_back(2147483647);
	lst_int_condition.push_back(0);

	std::cout << "For a int list lst_int_condition : " << lst_int_condition << std::endl;

	lst_int_condition.sort(superior_comp<int>);
	std::cout << "lst_int_condition.sort(superior_comp);" << std::endl;

	std::cout << "Now lst_int_condition : " << lst_int_condition << std::endl << std::endl;

 	std::list<double>		lst_double_condition;

	lst_double_condition.push_back(2.2);
	lst_double_condition.push_back(INFINITY);
	lst_double_condition.push_back(42.42);
	lst_double_condition.push_back(420.024);
	lst_double_condition.push_back(3.14);
	lst_double_condition.push_back(-233.141);
	lst_double_condition.push_back(-INFINITY);
	lst_double_condition.push_back(0);
	lst_double_condition.push_back(347589.19454);

	std::cout << "For a double list lst_double_condition : " << std::endl;

	lst_double_condition.sort(superior_comp<double>);
	std::cout << "lst_double_condition.sort(superior_comp);" << std::endl;

	std::cout << "Now lst_double_condition : " << lst_double_condition << std::endl << std::endl;

	std::list<std::string>	lst_string_condition;

	lst_string_condition.push_back("coucou8");
	lst_string_condition.push_back("coucou1");
	lst_string_condition.push_back("coucou4");
	lst_string_condition.push_back("coucou4");
	lst_string_condition.push_back("coucou2");
	lst_string_condition.push_back("coucou1");
	lst_string_condition.push_back("coucou9");
	lst_string_condition.push_back("coucou0");
	lst_string_condition.push_back("coucou6");

	std::cout << "For a std::string list lst_string_condition : " << std::endl;

	lst_string_condition.sort(superior_comp<std::string>);
	std::cout << "lst_string_condition.sort(superior_comp);" << std::endl;

	std::cout << "Now lst_string_condition : " << lst_string_condition << std::endl << std::endl;

}

static void	test_operations_sort(void)
{

	std::cout << "#### FT OPERATIONS SORT TEST ####" << std::endl;
	std::cout << "#### WITHOUT CONDITION ####" << std::endl;

	ft::list<int>			lst_int;

	lst_int.push_back(4);
	lst_int.push_back(-8392454);
	lst_int.push_back(3849);
	lst_int.push_back(-9000);
	lst_int.push_back(-2147483648);
	lst_int.push_back(2147483647);
	lst_int.push_back(0);

	std::cout << "For a int list lst_int : " << lst_int << std::endl;

	lst_int.sort();
	std::cout << "lst_int.sort();" << std::endl;

	std::cout << "Now lst_int : " << lst_int << std::endl << std::endl;

 	ft::list<double>		lst_double;

	lst_double.push_back(2.2);
	lst_double.push_back(INFINITY);
	lst_double.push_back(42.42);
	lst_double.push_back(420.024);
	lst_double.push_back(3.14);
	lst_double.push_back(-233.141);
	lst_double.push_back(-INFINITY);
	lst_double.push_back(0);
	lst_double.push_back(347589.19454);

	std::cout << "For a double list lst_double : " << lst_double << std::endl;

	lst_double.sort();
	std::cout << "lst_double.sort();" << std::endl;

	std::cout << "Now lst_double : " << lst_double << std::endl << std::endl;

	ft::list<std::string>	lst_string;

	lst_string.push_back("coucou8");
	lst_string.push_back("coucou1");
	lst_string.push_back("coucou4");
	lst_string.push_back("coucou4");
	lst_string.push_back("coucou2");
	lst_string.push_back("coucou1");
	lst_string.push_back("coucou9");
	lst_string.push_back("coucou0");
	lst_string.push_back("coucou6");

	std::cout << "For a std::string list lst_string : " << lst_string << std::endl;

	lst_string.sort();
	std::cout << "lst_string.sort();" << std::endl;

	std::cout << "Now lst_string : " << lst_string << std::endl << std::endl;

	std::cout << "#### WITH CONDITION ####" << std::endl;
	std::cout << "Conditition superior_comp = return (lvalue > rvalue);" << std::endl;

		ft::list<int>			lst_int_condition;

	lst_int_condition.push_back(4);
	lst_int_condition.push_back(-8392454);
	lst_int_condition.push_back(3849);
	lst_int_condition.push_back(-9000);
	lst_int_condition.push_back(-2147483648);
	lst_int_condition.push_back(2147483647);
	lst_int_condition.push_back(0);

	std::cout << "For a int list lst_int_condition : " << lst_int_condition << std::endl;

	lst_int_condition.sort(superior_comp<int>);
	std::cout << "lst_int_condition.sort(superior_comp);" << std::endl;

	std::cout << "Now lst_int_condition : " << lst_int_condition << std::endl << std::endl;

 	ft::list<double>		lst_double_condition;

	lst_double_condition.push_back(2.2);
	lst_double_condition.push_back(INFINITY);
	lst_double_condition.push_back(42.42);
	lst_double_condition.push_back(420.024);
	lst_double_condition.push_back(3.14);
	lst_double_condition.push_back(-233.141);
	lst_double_condition.push_back(-INFINITY);
	lst_double_condition.push_back(0);
	lst_double_condition.push_back(347589.19454);

	std::cout << "For a double list lst_double_condition : " << std::endl;

	lst_double_condition.sort(superior_comp<double>);
	std::cout << "lst_double_condition.sort(superior_comp);" << std::endl;

	std::cout << "Now lst_double_condition : " << lst_double_condition << std::endl << std::endl;

	ft::list<std::string>	lst_string_condition;

	lst_string_condition.push_back("coucou8");
	lst_string_condition.push_back("coucou1");
	lst_string_condition.push_back("coucou4");
	lst_string_condition.push_back("coucou4");
	lst_string_condition.push_back("coucou2");
	lst_string_condition.push_back("coucou1");
	lst_string_condition.push_back("coucou9");
	lst_string_condition.push_back("coucou0");
	lst_string_condition.push_back("coucou6");

	std::cout << "For a std::string list lst_string_condition : " << std::endl;

	lst_string_condition.sort(superior_comp<std::string>);
	std::cout << "lst_string_condition.sort(superior_comp);" << std::endl;

	std::cout << "Now lst_string_condition : " << lst_string_condition << std::endl << std::endl;

	test_operations_sort_std();
}

static void	test_operations_reverse_std(void)
{
	std::cout << "#### STD OPERATIONS REVERSE ####" << std::endl;

	std::list<int>	lst_numbers;

	lst_numbers.push_back(1);
	lst_numbers.push_back(2);
	lst_numbers.push_back(3);
	lst_numbers.push_back(4);
	lst_numbers.push_back(5);
	lst_numbers.push_back(6);
	lst_numbers.push_back(7);
	lst_numbers.push_back(8);
	lst_numbers.push_back(9);

	std::cout << "For a number list : " << lst_numbers << std::endl;
	lst_numbers.reverse();
	std::cout << "lst_numbers.reverse();" << std::endl;
	std::cout << "lst_numbers : " << lst_numbers << std::endl << std::endl;

	std::list<potato>	lst_potatos;

	lst_potatos.push_back(potato(1));
	lst_potatos.push_back(potato(2));
	lst_potatos.push_back(potato(3));
	lst_potatos.push_back(potato(4));
	lst_potatos.push_back(potato(5));
	lst_potatos.push_back(potato(6));
	lst_potatos.push_back(potato(7));
	lst_potatos.push_back(potato(8));
	lst_potatos.push_back(potato(9));

	std::cout << "For a potato list (constructor test) : " << lst_potatos << std::endl;
	lst_potatos.reverse();
	std::cout << "lst_potatos.reverse();" << std::endl;
	std::cout << "lst_potatos : " << lst_potatos << std::endl << std::endl;

	std::list<std::string>	lst_alone;

	lst_alone.push_back("Simone");

	std::cout << "For a string alone list (crash test) : " << lst_alone << std::endl;
	lst_alone.reverse();
	std::cout << "lst_alone.reverse();" << std::endl;
	std::cout << "lst_alone : " << lst_alone << std::endl << std::endl;

	std::list<std::string>	lst_empty;

	std::cout << "For a empty string list (crash test) : " << lst_empty << std::endl;
	lst_empty.reverse();
	std::cout << "lst_empty.reverse();" << std::endl;
	std::cout << "lst_empty : " << lst_empty << std::endl << std::endl;
}

static void	test_operations_reverse(void)
{
	std::cout << "#### FT OPERATIONS REVERSE ####" << std::endl;

	ft::list<int>	lst_numbers;

	lst_numbers.push_back(1);
	lst_numbers.push_back(2);
	lst_numbers.push_back(3);
	lst_numbers.push_back(4);
	lst_numbers.push_back(5);
	lst_numbers.push_back(6);
	lst_numbers.push_back(7);
	lst_numbers.push_back(8);
	lst_numbers.push_back(9);

	std::cout << "For a number list : " << lst_numbers << std::endl;
	lst_numbers.reverse();
	std::cout << "lst_numbers.reverse();" << std::endl;
	std::cout << "lst_numbers : " << lst_numbers << std::endl << std::endl;

	ft::list<potato>	lst_potatos;

	lst_potatos.push_back(potato(1));
	lst_potatos.push_back(potato(2));
	lst_potatos.push_back(potato(3));
	lst_potatos.push_back(potato(4));
	lst_potatos.push_back(potato(5));
	lst_potatos.push_back(potato(6));
	lst_potatos.push_back(potato(7));
	lst_potatos.push_back(potato(8));
	lst_potatos.push_back(potato(9));

	std::cout << "For a potato list (constructor test) : " << lst_potatos << std::endl;
	lst_potatos.reverse();
	std::cout << "lst_potatos.reverse();" << std::endl;
	std::cout << "lst_potatos : " << lst_potatos << std::endl << std::endl;

	ft::list<std::string>	lst_alone;

	lst_alone.push_back("Simone");

	std::cout << "For a string alone list (crash test) : " << lst_alone << std::endl;
	lst_alone.reverse();
	std::cout << "lst_alone.reverse();" << std::endl;
	std::cout << "lst_alone : " << lst_alone << std::endl << std::endl;

	ft::list<std::string>	lst_empty;

	std::cout << "For a empty string list (crash test) : " << lst_empty << std::endl;
	lst_empty.reverse();
	std::cout << "lst_empty.reverse();" << std::endl;
	std::cout << "lst_empty : " << lst_empty << std::endl << std::endl;

	test_operations_reverse_std();
}

static void	test_non_member_ope_std(void)
{
	std::cout << "#### STD NON-MEMBER OPERATORS TEST ####" << std::endl;
	std::cout << "#- EQUAL & NON-EQUAL -#" << std::endl;

	std::list<std::string>	lst_str1;

	lst_str1.push_back("Mulhouse");
	lst_str1.push_back("Niort");
	lst_str1.push_back("Locmaria grand-champ");
	lst_str1.push_back("Vatan");
	lst_str1.push_back("jouy-en-josasse");

	std::list<std::string>	lst_str2(lst_str1);

	std::list<std::string>	lst_str3;

	lst_str3.push_back("Paris");
	lst_str3.push_back("Lyon");
	lst_str3.push_back("Toulouse");
	lst_str3.push_back("Grenoble");
	lst_str3.push_back("Brest");

	std::cout << "For string list lst_str1 : " << lst_str1 << std::endl;
	std::cout << "For string list lst_str2 : " << lst_str2 << std::endl;
	std::cout << "For string list lst_str3 : " << lst_str3 << std::endl << std::endl;

	std::cout << "lst_str1 == lst_str1 : " << std::boolalpha << (lst_str1 == lst_str1) << std::endl << std::endl;

	std::cout << "lst_str1 == lst_str2 : " << std::boolalpha << (lst_str1 == lst_str2) << std::endl;
	std::cout << "lst_str1 != lst_str2 : " << std::boolalpha << (lst_str1 != lst_str2) << std::endl << std::endl;

	std::cout << "lst_str1 == lst_str3 : " << std::boolalpha << (lst_str1 == lst_str3) << std::endl;
	std::cout << "lst_str1 != lst_str3 : " << std::boolalpha << (lst_str1 != lst_str3) << std::endl << std::endl;

	std::cout << "#- SUPERIOR & EQUAL-SUPERIOR -#" << std::endl;
	std::list<int>	lst_nums1;

	lst_nums1.push_back(0);
	lst_nums1.push_back(1);
	lst_nums1.push_back(10);
	lst_nums1.push_back(11);
	lst_nums1.push_back(100);
	lst_nums1.push_back(101);
	lst_nums1.push_back(110);
	lst_nums1.push_back(111);

	std::list<int>	lst_nums2(lst_nums1);

	lst_nums2.push_back(1000);

	std::cout << "For int string list lst_nums1 : " << lst_nums1 << std::endl;
	std::cout << "For int string list lst_nums2 : " << lst_nums2 << std::endl << std::endl;

	std::cout << "lst_nums1 < lst_nums1 = " << (lst_nums1 < lst_nums1) << std::endl;
	std::cout << "lst_nums1 < lst_nums2 = " << (lst_nums1 < lst_nums2) << std::endl;
	std::cout << "lst_nums2 < lst_nums1 = " << (lst_nums2 < lst_nums1) << std::endl;
	std::cout << "lst_nums1 <= lst_nums1 = " << (lst_nums1 <= lst_nums1) << std::endl;
	std::cout << "lst_nums1 <= lst_nums2 = " << (lst_nums1 <= lst_nums2) << std::endl;
	std::cout << "lst_nums2 <= lst_nums1 = " << (lst_nums2 <= lst_nums1) << std::endl << std::endl;

	std::cout << "#- INFERIOR & EQUAL-INFERIOR -#" << std::endl << std::endl;

	std::cout << "lst_nums1 > lst_nums1 = " << (lst_nums1 > lst_nums1) << std::endl;
	std::cout << "lst_nums1 > lst_nums2 = " << (lst_nums1 > lst_nums2) << std::endl;
	std::cout << "lst_nums2 > lst_nums1 = " << (lst_nums2 > lst_nums1) << std::endl;
	std::cout << "lst_nums1 >= lst_nums1 = " << (lst_nums1 >= lst_nums1) << std::endl;
	std::cout << "lst_nums1 >= lst_nums2 = " << (lst_nums1 >= lst_nums2) << std::endl;
	std::cout << "lst_nums2 >= lst_nums1 = " << (lst_nums2 >= lst_nums1) << std::endl;
}

static void	test_non_member_ope(void)
{
	std::cout << "#### FT NON-MEMBER OPERATORS TEST ####" << std::endl;
	std::cout << "#- EQUAL & NON-EQUAL -#" << std::endl;

	ft::list<std::string>	lst_str1;

	lst_str1.push_back("Mulhouse");
	lst_str1.push_back("Niort");
	lst_str1.push_back("Locmaria grand-champ");
	lst_str1.push_back("Vatan");
	lst_str1.push_back("jouy-en-josasse");

	ft::list<std::string>	lst_str2(lst_str1);

	ft::list<std::string>	lst_str3;

	lst_str3.push_back("Paris");
	lst_str3.push_back("Lyon");
	lst_str3.push_back("Toulouse");
	lst_str3.push_back("Grenoble");
	lst_str3.push_back("Brest");

	std::cout << "For string list lst_str1 : " << lst_str1 << std::endl;
	std::cout << "For string list lst_str2 : " << lst_str2 << std::endl;
	std::cout << "For string list lst_str3 : " << lst_str3 << std::endl << std::endl;

	std::cout << "lst_str1 == lst_str1 : " << std::boolalpha << (lst_str1 == lst_str1) << std::endl << std::endl;

	std::cout << "lst_str1 == lst_str2 : " << std::boolalpha << (lst_str1 == lst_str2) << std::endl;
	std::cout << "lst_str1 != lst_str2 : " << std::boolalpha << (lst_str1 != lst_str2) << std::endl << std::endl;

	std::cout << "lst_str1 == lst_str3 : " << std::boolalpha << (lst_str1 == lst_str3) << std::endl;
	std::cout << "lst_str1 != lst_str3 : " << std::boolalpha << (lst_str1 != lst_str3) << std::endl << std::endl;

	std::cout << "#- SUPERIOR & EQUAL-SUPERIOR -#" << std::endl;
	ft::list<int>	lst_nums1;

	lst_nums1.push_back(0);
	lst_nums1.push_back(1);
	lst_nums1.push_back(10);
	lst_nums1.push_back(11);
	lst_nums1.push_back(100);
	lst_nums1.push_back(101);
	lst_nums1.push_back(110);
	lst_nums1.push_back(111);

	ft::list<int>	lst_nums2(lst_nums1);

	lst_nums2.push_back(1000);

	std::cout << "For int string list lst_nums1 : " << lst_nums1 << std::endl;
	std::cout << "For int string list lst_nums2 : " << lst_nums2 << std::endl << std::endl;

	std::cout << "lst_nums1 < lst_nums1 = " << (lst_nums1 < lst_nums1) << std::endl;
	std::cout << "lst_nums1 < lst_nums2 = " << (lst_nums1 < lst_nums2) << std::endl;
	std::cout << "lst_nums2 < lst_nums1 = " << (lst_nums2 < lst_nums1) << std::endl;
	std::cout << "lst_nums1 <= lst_nums1 = " << (lst_nums1 <= lst_nums1) << std::endl;
	std::cout << "lst_nums1 <= lst_nums2 = " << (lst_nums1 <= lst_nums2) << std::endl;
	std::cout << "lst_nums2 <= lst_nums1 = " << (lst_nums2 <= lst_nums1) << std::endl << std::endl;

	std::cout << "#- INFERIOR & EQUAL-INFERIOR -#" << std::endl << std::endl;

	std::cout << "lst_nums1 > lst_nums1 = " << (lst_nums1 > lst_nums1) << std::endl;
	std::cout << "lst_nums1 > lst_nums2 = " << (lst_nums1 > lst_nums2) << std::endl;
	std::cout << "lst_nums2 > lst_nums1 = " << (lst_nums2 > lst_nums1) << std::endl;
	std::cout << "lst_nums1 >= lst_nums1 = " << (lst_nums1 >= lst_nums1) << std::endl;
	std::cout << "lst_nums1 >= lst_nums2 = " << (lst_nums1 >= lst_nums2) << std::endl;
	std::cout << "lst_nums2 >= lst_nums1 = " << (lst_nums2 >= lst_nums1) << std::endl << std::endl;

	test_non_member_ope_std();
}

static void	test_non_member_swap_std(void)
{
	std::cout << "#### STD NON-MEMBER SWAP ####" << std::endl;

	std::list<int> lst_nums_a(10, 10);
	std::list<int> lst_nums_b(10, 50);

	std::cout << "For int list lst_nums_a : " << lst_nums_a << std::endl;
	std::cout << "For int list lst_nums_b : " << lst_nums_b << std::endl << std::endl;

	swap(lst_nums_a, lst_nums_b);

	std::cout << "lst_nums_a : " << lst_nums_a << std::endl;
	std::cout << "lst_nums_b : " << lst_nums_b << std::endl << std::endl;
}

static void	test_non_member_swap(void)
{
	std::cout << "#### FT NON-MEMBER SWAP ####" << std::endl;

	ft::list<int> lst_nums_a(10, 10);
	ft::list<int> lst_nums_b(10, 50);

	std::cout << "For int list lst_nums_a : " << lst_nums_a << std::endl;
	std::cout << "For int list lst_nums_b : " << lst_nums_b << std::endl << std::endl;

	swap(lst_nums_a, lst_nums_b);

	std::cout << "lst_nums_a : " << lst_nums_a << std::endl;
	std::cout << "lst_nums_b : " << lst_nums_b << std::endl << std::endl;

	test_non_member_swap_std();
}

bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

static void	test_operations_merge_std(void)
{
	std::cout << "#### STD OPERATIONS MERGE TEST ####" << std::endl;
	std::cout << "#- MERGE WITHOUT CONDITION -#" << std::endl << std::endl;

	std::list<double> lst_doubles_a;
	std::list<double> lst_doubles_b;

	lst_doubles_a.push_back(3.1);
	lst_doubles_a.push_back(2.2);
	lst_doubles_a.push_back(2.9);

	lst_doubles_b.push_back(3.7);
	lst_doubles_b.push_back(7.1);
	lst_doubles_b.push_back(1.4);

	lst_doubles_a.sort();
	lst_doubles_b.sort();

	std::cout << "lst_doubles_a :" << lst_doubles_a << std::endl;
	std::cout << "lst_doubles_b :" << lst_doubles_b << std::endl << std::endl;

	std::cout << "lst_doubles_a.merge(lst_doubles_b);" << std::endl << std::endl;
	lst_doubles_a.merge(lst_doubles_b);

	std::cout << "lst_doubles_a = " << lst_doubles_a << std::endl;
	std::cout << "lst_doubles_b = " << lst_doubles_b << std::endl << std::endl;

	std::cout << "lst_doubles_b.push_back(2.1);" << std::endl;
	lst_doubles_b.push_back(2.1);

	std::cout << "lst_doubles_a.merge(lst_doubles_b, mycomparison);" << std::endl << std::endl;
	lst_doubles_a.merge(lst_doubles_b, mycomparison);

	std::cout << "lst_doubles_a = " << lst_doubles_a << std::endl;
	std::cout << "lst_doubles_b = " << lst_doubles_b << std::endl << std::endl;

	std::list<int> lst_int_a;
	std::list<int> lst_int_b;

	lst_int_a.push_back(10);
	lst_int_a.push_back(20);
	lst_int_a.push_back(30);
	lst_int_a.push_back(40);
	lst_int_a.push_back(50);
	lst_int_a.push_back(60);

	lst_int_b.push_back(40);
	lst_int_b.push_back(41);
	lst_int_b.push_back(42);
	lst_int_b.push_back(43);
	lst_int_b.push_back(44);
	lst_int_b.push_back(45);

	std::cout << "lst_int_a : " << lst_int_a << std::endl;
	std::cout << "lst_int_b : " << lst_int_b << std::endl << std::endl;

	std::cout << "lst_int_a.merge(lst_int_b);" << std::endl << std::endl;
	lst_int_a.merge(lst_int_b);

	std::cout << "lst_int_a : " << lst_int_a << std::endl;
	std::cout << "lst_int_b : " << lst_int_b << std::endl << std::endl;

}

static void	test_operations_merge(void)
{
	std::cout << "#### FT OPERATIONS MERGE TEST ####" << std::endl;
	std::cout << "#- MERGE WITHOUT CONDITION -#" << std::endl;

	ft::list<double> lst_doubles_a;
	ft::list<double> lst_doubles_b;

	lst_doubles_a.push_back(3.1);
	lst_doubles_a.push_back(2.2);
	lst_doubles_a.push_back(2.9);

	lst_doubles_b.push_back(3.7);
	lst_doubles_b.push_back(7.1);
	lst_doubles_b.push_back(1.4);

	lst_doubles_a.sort();
	lst_doubles_b.sort();

	std::cout << "lst_doubles_a :" << lst_doubles_a << std::endl;
	std::cout << "lst_doubles_b :" << lst_doubles_b << std::endl << std::endl;

	std::cout << "lst_doubles_a.merge(lst_doubles_b);" << std::endl << std::endl;
	lst_doubles_a.merge(lst_doubles_b);

	std::cout << "lst_doubles_a = " << lst_doubles_a << std::endl;
	std::cout << "lst_doubles_b = " << lst_doubles_b << std::endl << std::endl;

	std::cout << "lst_doubles_b.push_back(2.1);" << std::endl;
	lst_doubles_b.push_back(2.1);

	std::cout << "lst_doubles_a.merge(lst_doubles_b, mycomparison);" << std::endl << std::endl;
	lst_doubles_a.merge(lst_doubles_b, mycomparison);

	std::cout << "lst_doubles_a = " << lst_doubles_a << std::endl;
	std::cout << "lst_doubles_b = " << lst_doubles_b << std::endl << std::endl;

	ft::list<int> lst_int_a;
	ft::list<int> lst_int_b;

	lst_int_a.push_back(10);
	lst_int_a.push_back(20);
	lst_int_a.push_back(30);
	lst_int_a.push_back(40);
	lst_int_a.push_back(50);
	lst_int_a.push_back(60);

	lst_int_b.push_back(40);
	lst_int_b.push_back(41);
	lst_int_b.push_back(42);
	lst_int_b.push_back(43);
	lst_int_b.push_back(44);
	lst_int_b.push_back(45);

	std::cout << "lst_int_a : " << lst_int_a << std::endl;
	std::cout << "lst_int_b : " << lst_int_b << std::endl << std::endl;

	std::cout << "lst_int_a.merge(lst_int_b);" << std::endl << std::endl;
	lst_int_a.merge(lst_int_b);

	std::cout << "lst_int_a : " << lst_int_a << std::endl;
	std::cout << "lst_int_b : " << lst_int_b << std::endl << std::endl;

	test_operations_merge_std();
}

#include "../test_tools/utils_tester.hpp"

void	main_list(void)
{
	std::vector<void(*)(void)>	v_test_functions;
	std::vector<std::string>	v_description;

	v_test_functions.push_back(test_essentials);
	v_description.push_back("0 : ESSENTIALS : push(front | back)() | pop(front | back)() | front() | back()");

	v_test_functions.push_back(test_capacity);
	v_description.push_back("1 : CAPACITY : empty() | size()");

	v_test_functions.push_back(test_iterator);
	v_description.push_back("2 : ITERATOR ESSENTIALS : begin() | end() | it++ | it--");

	v_test_functions.push_back(test_constructors);
	v_description.push_back("3 : LIST CONSTRUCTORS : fill | range | copy");

	v_test_functions.push_back(test_operator_over_ite);
	v_description.push_back("4 : ITERATOR OPE OVERLOAD");

	v_test_functions.push_back(test_modifiers_one);
	v_description.push_back("5 : MODIFIERS PART ONE : clear | assign | insert");

	v_test_functions.push_back(test_modifiers_two);
	v_description.push_back("6 : MODIFIERS PART TWO : erase | resize | swap");

	v_test_functions.push_back(test_operations_splice);
	v_description.push_back("7 : OPERATIONS : splice");

	v_test_functions.push_back(test_operations_remove);
	v_description.push_back("8 : OPERATIONS : remove | remove_if");

	v_test_functions.push_back(test_operations_unique);
	v_description.push_back("9 : OPERATIONS : unique");

	v_test_functions.push_back(test_operations_sort);
	v_description.push_back("10 : OPERATIONS : sort");

	v_test_functions.push_back(test_operations_reverse);
	v_description.push_back("11 : OPERATIONS : reverse");

	v_test_functions.push_back(test_non_member_ope);
	v_description.push_back("12 : NON-MEMBERS : operator overloads");

	v_test_functions.push_back(test_non_member_swap);
	v_description.push_back("13 : NON-MEMBERS : swap");

	v_test_functions.push_back(test_operations_merge);
	v_description.push_back("14 : OPERATIONS : merge");

	menu(v_test_functions, v_description, "LIST");
}

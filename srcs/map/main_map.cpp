/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:03:12 by jecaudal          #+#    #+#             */
/*   Updated: 2021/02/17 16:40:51 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"
#include <vector>
#include <iostream>
#include "../test_tools/utils_tester.hpp"



static void	test_operator_brackets_std(void)
{
	print_header("STD MAP OPERATOR BRACKETS TEST");

	std::map<std::string, int>	str_int_map;

	std::cout << "for a std::map<std::string, int> str_int_map;" << std::endl << std::endl;

	std::cout << "str_int_map.empty() : " << std::boolalpha << str_int_map.empty() << std::endl;
	std::cout << "str_int_map.size() : " << str_int_map.size() << std::endl;

	std::cout << "str_int_map[\"init\"] : " << str_int_map["init"] << std::endl;

	std::cout << "str_int_map.empty() : " << std::boolalpha << str_int_map.empty() << std::endl;
	std::cout << "str_int_map.size() : " << str_int_map.size() << std::endl << std::endl;

	str_int_map["init"] = 56;
	std::cout << "str_int_map[\"init\"] = 56;"<< std::endl;

	std::cout << "str_int_map[\"init\"] : " << str_int_map["init"] << std::endl;

	std::cout << "str_int_map.size() : " << str_int_map.size() << std::endl << std::endl;

	std::map<int, int>	int_int_map;

	std::cout << "for a std::map<int, int> int_int_map;" << std::endl << std::endl;

	std::cout << "str_int_map.empty() : " << std::boolalpha << str_int_map.empty() << std::endl;
	std::cout << "int_int_map.size() : " << int_int_map.size() << std::endl;

	std::cout << "int_int_map[0] : " << int_int_map[0] << std::endl;

	std::cout << "str_int_map.empty() : " << std::boolalpha << str_int_map.empty() << std::endl;
	std::cout << "int_int_map.size() : " << int_int_map.size() << std::endl << std::endl;

	int_int_map[0] = 56;
	std::cout << "int_int_map[0] = 56;"<< std::endl;

	std::cout << "int_int_map[0] : " << int_int_map[0] << std::endl;

	std::cout << "int_int_map.size() : " << int_int_map.size() << std::endl << std::endl;

	int_int_map[10] = 42;
	std::cout << "int_int_map[10] = 42;"<< std::endl;

	std::cout << "int_int_map[10] : " << int_int_map[10] << std::endl;

	std::cout << "int_int_map.slize() : " << int_int_map.size() << std::endl << std::endl;
}

static void	test_operator_brackets(void)
{
	print_header("FT MAP OPERATOR BRACKETS TEST");

	ft::map<std::string, int>	str_int_map;

	std::cout << "for a ft::map<std::string, int> str_int_map;" << std::endl << std::endl;

	std::cout << "str_int_map.empty() : " << std::boolalpha << str_int_map.empty() << std::endl;
	std::cout << "str_int_map.size() : " << str_int_map.size() << std::endl;

	std::cout << "str_int_map[\"init\"] : " << str_int_map["init"] << std::endl;

	std::cout << "str_int_map.empty() : " << std::boolalpha << str_int_map.empty() << std::endl;
	std::cout << "str_int_map.size() : " << str_int_map.size() << std::endl << std::endl;

	str_int_map["init"] = 56;
	std::cout << "str_int_map[\"init\"] = 56;"<< std::endl;

	std::cout << "str_int_map[\"init\"] : " << str_int_map["init"] << std::endl;

	std::cout << "str_int_map.size() : " << str_int_map.size() << std::endl << std::endl;

	ft::map<int, int>	int_int_map;

	std::cout << "for a ft::map<int, int> int_int_map;" << std::endl << std::endl;

	std::cout << "str_int_map.empty() : " << std::boolalpha << str_int_map.empty() << std::endl;
	std::cout << "int_int_map.size() : " << int_int_map.size() << std::endl;

	std::cout << "int_int_map[0] : " << int_int_map[0] << std::endl;

	std::cout << "str_int_map.empty() : " << std::boolalpha << str_int_map.empty() << std::endl;
	std::cout << "int_int_map.size() : " << int_int_map.size() << std::endl << std::endl;

	int_int_map[0] = 56;
	std::cout << "int_int_map[0] = 56;"<< std::endl;

	std::cout << "int_int_map[0] : " << int_int_map[0] << std::endl;

	std::cout << "int_int_map.size() : " << int_int_map.size() << std::endl << std::endl;

	int_int_map[10] = 42;
	std::cout << "int_int_map[10] = 42;"<< std::endl;

	std::cout << "int_int_map[10] : " << int_int_map[10] << std::endl;

	std::cout << "int_int_map.slize() : " << int_int_map.size() << std::endl << std::endl;

	test_operator_brackets_std();
}

static void	test_iterator_std(void)
{
	print_header("STD TEST ITERATOR");

	std::map<int, int>	int_int_map;
	std::cout << "For a std::map<int, int> int_int_map;" << std::endl << std::endl;

	int_int_map[56] = 56;
	int_int_map[30] = 30;
	int_int_map[70] = 70;
	int_int_map[22] = 22;
	int_int_map[40] = 40;
	int_int_map[60] = 60;
	int_int_map[95] = 95;
	int_int_map[11] = 11;
	int_int_map[65] = 65;
	int_int_map[3] = 3;
	int_int_map[16] = 16;
	int_int_map[63] = 63;
	int_int_map[67] = 67;

	std::cout << "int_int_map[56] = 56;" << std::endl;
	std::cout << "int_int_map[30] = 30;" << std::endl;
	std::cout << "int_int_map[70] = 70;" << std::endl;
	std::cout << "int_int_map[22] = 22;" << std::endl;
	std::cout << "int_int_map[40] = 40;" << std::endl;
	std::cout << "int_int_map[60] = 60;" << std::endl;
	std::cout << "int_int_map[95] = 95;" << std::endl;
	std::cout << "int_int_map[11] = 11;" << std::endl;
	std::cout << "int_int_map[65] = 65;" << std::endl;
	std::cout << "int_int_map[3] = 3;" << std::endl;
	std::cout << "int_int_map[16] = 16;" << std::endl;
	std::cout << "int_int_map[63] = 63;" << std::endl;
	std::cout << "int_int_map[67] = 67;" << std::endl << std::endl;

	std::cout << "for (std::map<int, int>::iterator it = int_int_map.begin(); it != int_int_map.end(); it++)" << std::endl;
	std::cout << "\tstd::cout << *it << std::endl;" << std::endl << std::endl;

	for (std::map<int, int>::iterator it = int_int_map.begin();
		 it != int_int_map.end();
		 it++)
		 std::cout << *it << std::endl;
	std::cout << std::endl;

	std::cout << "int_int_map.begin() == int_int_map.begin() : " << \
	std::boolalpha << (int_int_map.begin() == int_int_map.begin()) << std::endl;

	std::cout << "int_int_map.begin() != int_int_map.begin() : " << \
	std::boolalpha << (int_int_map.begin() != int_int_map.begin()) << std::endl;

	std::cout << "int_int_map.begin() == int_int_map.end() : " << \
	std::boolalpha << (int_int_map.begin() == int_int_map.end()) << std::endl;

	std::cout << "int_int_map.begin() != int_int_map.end() : " << \
	std::boolalpha << (int_int_map.begin() != int_int_map.end()) << std::endl << std::endl;
}

static void	test_iterator(void)
{
	print_header("FT TEST ITERATOR");

	ft::map<int, int>	int_int_map;
	std::cout << "For a ft::map<int, int> int_int_map;" << std::endl << std::endl;

	int_int_map[56] = 56;
	int_int_map[30] = 30;
	int_int_map[70] = 70;
	int_int_map[22] = 22;
	int_int_map[40] = 40;
	int_int_map[60] = 60;
	int_int_map[95] = 95;
	int_int_map[11] = 11;
	int_int_map[65] = 65;
	int_int_map[3] = 3;
	int_int_map[16] = 16;
	int_int_map[63] = 63;
	int_int_map[67] = 67;

	std::cout << "int_int_map[56] = 56;" << std::endl;
	std::cout << "int_int_map[30] = 30;" << std::endl;
	std::cout << "int_int_map[70] = 70;" << std::endl;
	std::cout << "int_int_map[22] = 22;" << std::endl;
	std::cout << "int_int_map[40] = 40;" << std::endl;
	std::cout << "int_int_map[60] = 60;" << std::endl;
	std::cout << "int_int_map[95] = 95;" << std::endl;
	std::cout << "int_int_map[11] = 11;" << std::endl;
	std::cout << "int_int_map[65] = 65;" << std::endl;
	std::cout << "int_int_map[3] = 3;" << std::endl;
	std::cout << "int_int_map[16] = 16;" << std::endl;
	std::cout << "int_int_map[63] = 63;" << std::endl;
	std::cout << "int_int_map[67] = 67;" << std::endl << std::endl;

	std::cout << "for (ft::map<int, int>::iterator it = int_int_map.begin(); it != int_int_map.end(); it++)" << std::endl;
	std::cout << "\tstd::cout << *it << std::endl;" << std::endl << std::endl;

	for (ft::map<int, int>::iterator it = int_int_map.begin();
		 it != int_int_map.end();
		 it++)
		 std::cout << *it << std::endl;
	std::cout << std::endl;

	std::cout << "int_int_map.begin() == int_int_map.begin() : " << \
	std::boolalpha << (int_int_map.begin() == int_int_map.begin()) << std::endl;

	std::cout << "int_int_map.begin() != int_int_map.begin() : " << \
	std::boolalpha << (int_int_map.begin() != int_int_map.begin()) << std::endl;

	std::cout << "int_int_map.begin() == int_int_map.end() : " << \
	std::boolalpha << (int_int_map.begin() == int_int_map.end()) << std::endl;

	std::cout << "int_int_map.begin() != int_int_map.end() : " << \
	std::boolalpha << (int_int_map.begin() != int_int_map.end()) << std::endl;

	test_iterator_std();
}

static void	test_reverse_iterator_std(void)
{
	print_header("STD TEST REVERSE ITERATOR");

	std::map<int, int>	int_int_map;
	std::cout << "For a std::map<int, int> int_int_map;" << std::endl << std::endl;

	int_int_map[74] = 74;
	int_int_map[64] = 64;
	int_int_map[77] = 77;
	int_int_map[56] = 56;
	int_int_map[76] = 76;
	int_int_map[87] = 87;
	int_int_map[58] = 58;
	int_int_map[83] = 83;
	int_int_map[92] = 92;

	std::cout << "int_int_map[74] = 74;" << std::endl;
	std::cout << "int_int_map[64] = 64;" << std::endl;
	std::cout << "int_int_map[77] = 77;" << std::endl;
	std::cout << "int_int_map[56] = 56;" << std::endl;
	std::cout << "int_int_map[76] = 76;" << std::endl;
	std::cout << "int_int_map[87] = 87;" << std::endl;
	std::cout << "int_int_map[58] = 58;" << std::endl;
	std::cout << "int_int_map[83] = 83;" << std::endl;
	std::cout << "int_int_map[92] = 92;" << std::endl << std::endl;

	std::cout << "for (std::map<int, int>::reverse_iterator it = int_int_map.begin(); it != int_int_map.end(); it++)" << std::endl;
	std::cout << "\tstd::cout << *it << std::endl;" << std::endl << std::endl;

	for (std::map<int, int>::reverse_iterator it = int_int_map.rbegin();
		 it != int_int_map.rend();
		 it++)
		 std::cout << *it << std::endl;
	std::cout << std::endl;

	std::cout << "int_int_map.rbegin() == int_int_map.rbegin() : " << \
	std::boolalpha << (int_int_map.rbegin() == int_int_map.rbegin()) << std::endl;

	std::cout << "int_int_map.rbegin() != int_int_map.rbegin() : " << \
	std::boolalpha << (int_int_map.rbegin() != int_int_map.rbegin()) << std::endl;

	std::cout << "int_int_map.rbegin() == int_int_map.rend() : " << \
	std::boolalpha << (int_int_map.rbegin() == int_int_map.rend()) << std::endl;

	std::cout << "int_int_map.rbegin() != int_int_map.rend() : " << \
	std::boolalpha << (int_int_map.rbegin() != int_int_map.rend()) << std::endl;
}

static void	test_reverse_iterator(void)
{
	print_header("FT TEST REVERSE ITERATOR");

	ft::map<int, int>	int_int_map;
	std::cout << "For a ft::map<int, int> int_int_map;" << std::endl << std::endl;

	int_int_map[74] = 74;
	int_int_map[64] = 64;
	int_int_map[77] = 77;
	int_int_map[56] = 56;
	int_int_map[76] = 76;
	int_int_map[87] = 87;
	int_int_map[58] = 58;
	int_int_map[83] = 83;
	int_int_map[92] = 92;

	std::cout << "int_int_map[74] = 74;" << std::endl;
	std::cout << "int_int_map[64] = 64;" << std::endl;
	std::cout << "int_int_map[77] = 77;" << std::endl;
	std::cout << "int_int_map[56] = 56;" << std::endl;
	std::cout << "int_int_map[76] = 76;" << std::endl;
	std::cout << "int_int_map[87] = 87;" << std::endl;
	std::cout << "int_int_map[58] = 58;" << std::endl;
	std::cout << "int_int_map[83] = 83;" << std::endl;
	std::cout << "int_int_map[92] = 92;" << std::endl << std::endl;

	std::cout << "for (ft::map<int, int>::reverse_iterator it = int_int_map.begin(); it != int_int_map.end(); it++)" << std::endl;
	std::cout << "\tstd::cout << *it << std::endl;" << std::endl << std::endl;

	for (ft::map<int, int>::reverse_iterator it = int_int_map.rbegin();
		 it != int_int_map.rend();
		 it++)
		 std::cout << *it << std::endl;
	std::cout << std::endl;

	std::cout << "int_int_map.rbegin() == int_int_map.rbegin() : " << \
	std::boolalpha << (int_int_map.rbegin() == int_int_map.rbegin()) << std::endl;

	std::cout << "int_int_map.rbegin() != int_int_map.rbegin() : " << \
	std::boolalpha << (int_int_map.rbegin() != int_int_map.rbegin()) << std::endl;

	std::cout << "int_int_map.rbegin() == int_int_map.rend() : " << \
	std::boolalpha << (int_int_map.rbegin() == int_int_map.rend()) << std::endl;

	std::cout << "int_int_map.rbegin() != int_int_map.rend() : " << \
	std::boolalpha << (int_int_map.rbegin() != int_int_map.rend()) << std::endl;

	test_reverse_iterator_std();
}

static void	test_erase_by_key_std(void)
{
	std::map<std::string, int>	map_family;

	print_header("STD ERASE BY KEY TEST");

	map_family["grand_mother"] = 99;
	map_family["Dad"] = 70;
	map_family["uncle"] = 60;
	map_family["A_me"] = 45;
	map_family["G_brother"] = 35;
	map_family["s_cousin"] = 40;
	map_family["v_cousin"] = 25;
	map_family["9_son"] = 20;
	map_family["C_daughter"] = 25;
	map_family["Z_nethew"] = 8;
	map_family["q_lilcousin"] = 15;
	map_family["uo_lilcousin"] = 1;
	map_family["B_lilson"] = 15;

	std::cout << "Our family is :" << std::endl;
	std::cout << map_family << std::endl;

	std::cout << "erase a leaf : map_family.erase(\"G_brother\")" << std::endl << std::endl;
	map_family.erase("G_brother");

	std::cout << map_family << std::endl;

	std::cout << "erase a one leaf branch : map_family.erase(\"C_daughter\")" << std::endl << std::endl;
	map_family.erase("C_daughter");

	std::cout << map_family << std::endl;

	std::cout << "erase a two leaf branch : map_family.erase(\"uncle\")" << std::endl << std::endl;
	map_family.erase("uncle");

	std::cout << map_family << std::endl;

	std::cout << "erase the root : map_family.erase(\"grand_mother\")" << std::endl << std::endl;
	map_family.erase("grand_mother");

	std::cout << map_family << std::endl;

}

static void	test_erase_by_key(void)
{
	ft::map<std::string, int>	map_family;

	std::cout << "Here is a representation of the binary tree :" << std::endl << std::endl;

	std::cout << \
	"                           grand-mother" << std::endl << \
	"                          /           \\" << std::endl << \
	"                         /             \\" << std::endl << \
	"                        /               \\" << std::endl << \
	"                       /                 \\" << std::endl << \
	"                      /                   \\" << std::endl << \
	"                     /                     \\" << std::endl << \
	"                    /                       \\" << std::endl << \
	"                   /                         \\" << std::endl << \
	"                  /                           \\" << std::endl << \
	"                 /                             \\" << std::endl << \
	"                /                               \\" << std::endl << \
	"               /                                 \\" << std::endl << \
	"              Dad                                uncle" << std::endl << \
	"             /   \\                              /     \\" << std::endl << \
	"            /     \\                            /       \\" << std::endl << \
	"           /       \\                          /         \\" << std::endl << \
	"          /         \\                        /           \\" << std::endl << \
	"         /           \\                      /             \\" << std::endl << \
	"       A_me       G_brother             s_cousin        v_cousin" << std::endl << \
	"      /   \\            \\                   /               /" << std::endl << \
	"     /     \\            \\                 /               /" << std::endl << \
	"    /       \\            \\               /               /" << std::endl << \
	"   /         \\            \\             /               /" << std::endl << \
	"9_son    C_daughter    Z_nethew    q_lilcousin    um_lilcousin" << std::endl << \
	std::endl;

	print_header("FT ERASE BY KEY TEST");

	map_family["grand_mother"] = 99;
	map_family["Dad"] = 70;
	map_family["uncle"] = 60;
	map_family["A_me"] = 45;
	map_family["G_brother"] = 35;
	map_family["s_cousin"] = 40;
	map_family["v_cousin"] = 25;
	map_family["9_son"] = 20;
	map_family["C_daughter"] = 25;
	map_family["Z_nethew"] = 8;
	map_family["q_lilcousin"] = 15;
	map_family["uo_lilcousin"] = 1;
	map_family["B_lilson"] = 15;

	std::cout << "Our family is :" << std::endl << std::endl;
	std::cout << map_family << std::endl;

	std::cout << "erase a leaf : map_family.erase(\"G_brother\")" << std::endl << std::endl;
	map_family.erase("G_brother");

	std::cout << map_family << std::endl;

	std::cout << "erase a one leaf branch : map_family.erase(\"C_daughter\")" << std::endl << std::endl;
	map_family.erase("C_daughter");

	std::cout << map_family << std::endl;

	std::cout << "erase a two leaf branch : map_family.erase(\"uncle\")" << std::endl << std::endl;
	map_family.erase("uncle");

	std::cout << map_family << std::endl;

	std::cout << "erase the root : map_family.erase(\"grand_mother\")" << std::endl << std::endl;
	map_family.erase("grand_mother");

	std::cout << map_family << std::endl;

	test_erase_by_key_std();
}

static void	test_erase_by_iterators_std(void)
{
	print_header("STD ERASE ITERATORS TEST");

	std::cout << "#-- Erase a range of elements --#" << std::endl;

	std::map<double, double> db_db_map;
	std::cout << "For a std::map<double, double> db_db_map;" << std::endl << std::endl;

	db_db_map[54.32] = 54.32;
	db_db_map[15.62] = 15.62;
	db_db_map[81.778] = 81.778;
	db_db_map[3.14] = 3.14;
	db_db_map[2.3948] = 2.3948;
	db_db_map[584.329] = 584.329;
	db_db_map[1] = 1;
	db_db_map[58932] = 58932;
	db_db_map[902.314] = 902.314;

	std::cout << "db_db_map :" << std::endl << db_db_map << std::endl << std::endl;

	db_db_map.erase(db_db_map.begin(), db_db_map.end());;
	std::cout << "db_db_map.erase(db_db_map.begin(), db_db_map.end());" << std::endl << std::endl;

	std::cout << "db_db_map :" << std::endl << db_db_map << std::endl << std::endl;

	std::cout << "#-- Erase a range of elements in a single element map --#" << std::endl << std::endl;

	std::cout << "For a std::map<std::string, std::string> str_str_map;" << std::endl << std::endl;

	std::map<std::string, std::string> str_str_map;

	std::cout << "str_str_map[\"I\'m alone\"] = \"i\'m not alone !\";" << std::endl << std::endl;
	str_str_map["I'm alone"] = "i'm not alone !";

	std::cout << "str_str_map :" << std::endl << str_str_map << std::endl << std::endl;

	str_str_map.erase(str_str_map.begin(), str_str_map.end());;
	std::cout << "str_str_map.erase(str_str_map.begin(), str_str_map.end());" << std::endl << std::endl;

	std::cout << "str_str_map :" << std::endl << str_str_map << std::endl << std::endl;

	std::cout << "#-- Erase by single iterator --#" << std::endl << std::endl;

	std::map<int, int>	int_int_map;

	int_int_map[66] = 66;
	int_int_map[47] = 47;
	int_int_map[74] = 74;
	int_int_map[54] = 54;
	int_int_map[71] = 71;
	int_int_map[53] = 53;
	int_int_map[59] = 59;
	int_int_map[69] = 69;
	int_int_map[72] = 72;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl;

	std::map<int, int>::iterator it = int_int_map.begin();

	std::cout << "std::map<int, int>::iterator it = int_int_map.begin();" << std::endl;

	it++;
	it++;
	it++;
	it++;

	std::cout << "it++" << std::endl;
	std::cout << "it++" << std::endl;
	std::cout << "it++" << std::endl;
	std::cout << "it++" << std::endl << std::endl;

	std::cout << "*it : " << *it << std::endl << std::endl;

	int_int_map.erase(it);
	std::cout << "int_int_map.erase(it);" << std::endl << std::endl;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl;

	std::cout << "#-- Erase by single iterator in a single list --#" << std::endl << std::endl;

	std::map<std::string, bool>	affirmation;
	std::cout << "std::map<std::string, bool>	affirmation;" << std::endl << std::endl;

	affirmation["Is the earth flat ?"] = false;

	std::cout << "affirmation : " << std::endl << affirmation << std::endl;

	std::map<std::string, bool>::iterator it_aff = affirmation.begin();

	affirmation.erase(it_aff);
	std::cout << "affirmation.erase(it_aff);" << std::endl << std::endl;

	std::cout << "affirmation : " << std::endl << affirmation << std::endl << std::endl;
}

static void	test_erase_by_iterators(void)
{
	print_header("FT ERASE ITERATORS TEST");

	std::cout << "#-- Erase a range of elements --#" << std::endl;

	ft::map<double, double> db_db_map;
	std::cout << "For a ft::map<double, double> db_db_map;" << std::endl << std::endl;

	db_db_map[54.32] = 54.32;
	db_db_map[15.62] = 15.62;
	db_db_map[81.778] = 81.778;
	db_db_map[3.14] = 3.14;
	db_db_map[2.3948] = 2.3948;
	db_db_map[584.329] = 584.329;
	db_db_map[1] = 1;
	db_db_map[58932] = 58932;
	db_db_map[902.314] = 902.314;

	std::cout << "db_db_map :" << std::endl << db_db_map << std::endl << std::endl;

	db_db_map.erase(db_db_map.begin(), db_db_map.end());;
	std::cout << "db_db_map.erase(db_db_map.begin(), db_db_map.end());" << std::endl << std::endl;

	std::cout << "db_db_map :" << std::endl << db_db_map << std::endl << std::endl;

	std::cout << "#-- Erase a range of elements in a single element map --#" << std::endl << std::endl;

	std::cout << "For a ft::map<std::string, std::string> str_str_map;" << std::endl << std::endl;

	ft::map<std::string, std::string> str_str_map;

	std::cout << "str_str_map[\"I\'m alone\"] = \"i\'m not alone !\";" << std::endl << std::endl;
	str_str_map["I'm alone"] = "i'm not alone !";

	std::cout << "str_str_map :" << std::endl << str_str_map << std::endl << std::endl;

	str_str_map.erase(str_str_map.begin(), str_str_map.end());;
	std::cout << "str_str_map.erase(str_str_map.begin(), str_str_map.end());" << std::endl << std::endl;

	std::cout << "str_str_map :" << std::endl << str_str_map << std::endl << std::endl;

	std::cout << "#-- Erase by single iterator --#" << std::endl << std::endl;

	ft::map<int, int>	int_int_map;

	int_int_map[66] = 66;
	int_int_map[47] = 47;
	int_int_map[74] = 74;
	int_int_map[54] = 54;
	int_int_map[71] = 71;
	int_int_map[53] = 53;
	int_int_map[59] = 59;
	int_int_map[69] = 69;
	int_int_map[72] = 72;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl;

	ft::map<int, int>::iterator it = int_int_map.begin();

	std::cout << "ft::map<int, int>::iterator it = int_int_map.begin();" << std::endl;

	it++;
	it++;
	it++;
	it++;

	std::cout << "it++" << std::endl;
	std::cout << "it++" << std::endl;
	std::cout << "it++" << std::endl;
	std::cout << "it++" << std::endl << std::endl;

	std::cout << "*it : " << *it << std::endl << std::endl;

	int_int_map.erase(it);
	std::cout << "int_int_map.erase(it);" << std::endl << std::endl;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl;

	std::cout << "#-- Erase by single iterator in a single list --#" << std::endl << std::endl;

	ft::map<std::string, bool>	affirmation;
	std::cout << "ft::map<std::string, bool>	affirmation;" << std::endl << std::endl;

	affirmation["Is the earth flat ?"] = false;

	std::cout << "affirmation : " << std::endl << affirmation << std::endl;

	ft::map<std::string, bool>::iterator it_aff = affirmation.begin();

	affirmation.erase(it_aff);
	std::cout << "affirmation.erase(it_aff);" << std::endl << std::endl;

	std::cout << "affirmation : " << std::endl << affirmation << std::endl;

	test_erase_by_iterators_std();
}

static void	test_clear_std(void)
{
	print_header("STD CLEAR TEST");

	std::map<std::string, double>	world_records_apnea;

	world_records_apnea["Mifsud"] = 11.35;
	world_records_apnea["Sietas"] = 10.12;
	world_records_apnea["Mathieu"] = 8.40;
	world_records_apnea["De Beaucaron"] = 8.16;
	world_records_apnea["Savornin"] = 8.12;
	world_records_apnea["Stepanek"] = 8.06;

	std::cout << "For a string double map world_records_apnea :" << std::endl << world_records_apnea << std::endl;
	std::cout << "world_records_apnea.size() : " << std::endl << world_records_apnea.size() << std::endl << std::endl;

	world_records_apnea.clear();
	std::cout << "world_records_apnea.clear();" << std::endl << std::endl;

	std::cout << "Now world_records_apnea : " << std::endl << world_records_apnea << std::endl;
	std::cout << "world_records_apnea.size() : " << std::endl << world_records_apnea.size() << std::endl << std::endl;

}

static void	test_clear(void)
{
	print_header("FT CLEAR TEST");

	ft::map<std::string, double>	world_records_apnea;

	world_records_apnea["Mifsud"] = 11.35;
	world_records_apnea["Sietas"] = 10.12;
	world_records_apnea["Mathieu"] = 8.40;
	world_records_apnea["De Beaucaron"] = 8.16;
	world_records_apnea["Savornin"] = 8.12;
	world_records_apnea["Stepanek"] = 8.06;

	std::cout << "For a string double map world_records_apnea :" << std::endl << world_records_apnea << std::endl;
	std::cout << "world_records_apnea.size() : " << std::endl << world_records_apnea.size() << std::endl << std::endl;

	world_records_apnea.clear();
	std::cout << "world_records_apnea.clear();" << std::endl << std::endl;

	std::cout << "Now world_records_apnea : " << std::endl << world_records_apnea << std::endl << std::endl;
	std::cout << "world_records_apnea.size() : " << std::endl << world_records_apnea.size() << std::endl << std::endl;

	test_clear_std();
}

static void	test_find_std(void)
{
	print_header("STD FIND TEST");

	std::map<int, int>	random_tree;

	random_tree[32] = 32;
	random_tree[19] = 19;
	random_tree[46] = 46;
	random_tree[18] = 18;
	random_tree[23] = 23;
	random_tree[44] = 44;
	random_tree[66] = 66;
	random_tree[24] = 24;
	random_tree[59] = 59;
	random_tree[75] = 75;

	std::cout << "random_tree : " << std::endl << random_tree << std::endl;

	std::map<int, int>::iterator it = random_tree.find(42442424);
	std::cout << "std::map<int, int>::iterator it = random_tree.find(42442424);" << std::endl << std::endl;

	std::cout << "it == random_tree.end() : " << std::boolalpha << (it == random_tree.end()) << std::endl << std::endl;

	std::map<int, int>::const_iterator it_found = random_tree.find(59);
	std::cout << "std::map<int, int>::const_iterator it_found = random_tree.find(59);" << std::endl << std::endl;

	std::cout << "*it_found : " << *it_found << std::endl << std::endl;
}

static void	test_find(void)
{
	print_header("FT FIND TEST");

	ft::map<int, int>	random_tree;

	random_tree[32] = 32;
	random_tree[19] = 19;
	random_tree[46] = 46;
	random_tree[18] = 18;
	random_tree[23] = 23;
	random_tree[44] = 44;
	random_tree[66] = 66;
	random_tree[24] = 24;
	random_tree[59] = 59;
	random_tree[75] = 75;

	std::cout << "random_tree : " << std::endl << random_tree << std::endl;

	ft::map<int, int>::iterator it = random_tree.find(42442424);
	std::cout << "ft::map<int, int>::iterator it = random_tree.find(42442424);" << std::endl << std::endl;

	std::cout << "it == random_tree.end() : " << std::boolalpha << (it == random_tree.end()) << std::endl << std::endl;

	ft::map<int, int>::const_iterator it_found = random_tree.find(59);
	std::cout << "ft::map<int, int>::const_iterator it_found = random_tree.find(59);" << std::endl << std::endl;

	std::cout << "*it_found : " << *it_found << std::endl << std::endl;

	test_find_std();
}

static void	test_insert_std(void)
{
	print_header("STD INSERT TEST");

	std::cout << "#-- INSERT WITH A PAIR ON AN EMPTY MAP --#" << std::endl << std::endl;

	std::map<int, int>	int_int_map;

	std::cout << "For an <int, int> empty map int_int_map;" << std::endl << std::endl;

	int_int_map.insert(std::pair<int, int>(42, 42));
	std::cout << "int_int_map.insert(std::pair<int, int>(42, 42));" << std::endl << std::endl;

	std::cout << "int_int_map[42] : " << int_int_map[42] << std::endl << std::endl;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl;

	int_int_map.insert(std::pair<int, int>(109, 109));
	std::cout << "int_int_map.insert(std::pair<int, int>(109, 109));" << std::endl << std::endl;

	int_int_map.insert(std::pair<int, int>(56, 56));
	std::cout << "int_int_map.insert(std::pair<int, int>(56, 56));" << std::endl << std::endl;

	int_int_map.insert(std::pair<int, int>(69, 69));
	std::cout << "int_int_map.insert(std::pair<int, int>(69, 69));" << std::endl << std::endl;

	int_int_map.insert(std::pair<int, int>(1, 1));
	std::cout << "int_int_map.insert(std::pair<int, int>(1, 1));" << std::endl << std::endl;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl;

	std::cout << "#-- INSERT WITH A POSITION --#" << std::endl << std::endl;

	std::map<int, int>::iterator	it = int_int_map.begin();

	it++;
	it++;

	int_int_map.insert(it, std::pair<int, int>(57, 57));

	std::cout << "int_int_map.insert(it, std::pair<int, int>(57, 57));" << std::endl << std::endl;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl << std::endl;

	int_int_map.insert(it, std::pair<int, int>(9100, 9100));

	std::cout << "int_int_map.insert(it, std::pair<int, int>(9100, 9100));" << std::endl << std::endl;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl << std::endl;

	int_int_map.insert(it, std::pair<int, int>(57, 57));

	std::cout << "int_int_map.insert(it, std::pair<int, int>(57, 57));" << std::endl << std::endl;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl << std::endl;

	int_int_map.insert(int_int_map.begin(), std::pair<int, int>(67, 67));

	std::cout << "int_int_map.insert(int_int_map.begin(), std::pair<int, int>(67, 67));" << std::endl << std::endl;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl << std::endl;

	std::cout << "#-- INSERT BY A RANGE --#" << std::endl << std::endl;

	std::cout << "std::map<int, int> int_int_map_two;" << std::endl;
	std::map<int, int>	int_int_map_two;

	int_int_map_two[23] = 23;
	int_int_map_two[29] = 29;
	int_int_map_two[95] = 95;
	int_int_map_two[192] = 192;
	int_int_map_two[6] = 6;
	int_int_map_two[654] = 654;

	std::cout << "int_int_map_two : " << std::endl << int_int_map_two << std::endl;

	int_int_map.insert(int_int_map_two.begin(), int_int_map_two.end());

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl;

}

static void	test_insert(void)
{
	print_header("FT INSERT TEST");

	std::cout << "#-- INSERT WITH A PAIR ON AN EMPTY MAP --#" << std::endl << std::endl;

	ft::map<int, int>	int_int_map;

	std::cout << "For an <int, int> empty map int_int_map;" << std::endl << std::endl;

	int_int_map.insert(ft::pair<int, int>(42, 42));
	std::cout << "int_int_map.insert(ft::pair<int, int>(42, 42));" << std::endl << std::endl;

	std::cout << "int_int_map[42] : " << int_int_map[42] << std::endl << std::endl;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl;

	int_int_map.insert(ft::pair<int, int>(109, 109));
	std::cout << "int_int_map.insert(ft::pair<int, int>(109, 109));" << std::endl << std::endl;

	int_int_map.insert(ft::pair<int, int>(56, 56));
	std::cout << "int_int_map.insert(ft::pair<int, int>(56, 56));" << std::endl << std::endl;

	int_int_map.insert(ft::pair<int, int>(69, 69));
	std::cout << "int_int_map.insert(ft::pair<int, int>(69, 69));" << std::endl << std::endl;

	int_int_map.insert(ft::pair<int, int>(1, 1));
	std::cout << "int_int_map.insert(ft::pair<int, int>(1, 1));" << std::endl << std::endl;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl;

	std::cout << "#-- INSERT WITH A POSITION --#" << std::endl << std::endl;

	ft::map<int, int>::iterator	it = int_int_map.begin();

	it++;
	it++;

	int_int_map.insert(it, ft::pair<int, int>(57, 57));

	std::cout << "int_int_map.insert(it, ft::pair<int, int>(57, 57));" << std::endl << std::endl;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl << std::endl;

	int_int_map.insert(it, ft::pair<int, int>(9100, 9100));

	std::cout << "int_int_map.insert(it, ft::pair<int, int>(9100, 9100));" << std::endl << std::endl;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl << std::endl;

	int_int_map.insert(it, ft::pair<int, int>(57, 57));

	std::cout << "int_int_map.insert(it, ft::pair<int, int>(57, 57));" << std::endl << std::endl;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl << std::endl;

	int_int_map.insert(int_int_map.begin(), ft::pair<int, int>(67, 67));

	std::cout << "int_int_map.insert(int_int_map.begin(), ft::pair<int, int>(67, 67));" << std::endl << std::endl;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl << std::endl;

	std::cout << "#-- INSERT BY A RANGE --#" << std::endl << std::endl;

	std::cout << "ft::map<int, int> int_int_map_two;" << std::endl;
	ft::map<int, int>	int_int_map_two;

	int_int_map_two[23] = 23;
	int_int_map_two[29] = 29;
	int_int_map_two[95] = 95;
	int_int_map_two[192] = 192;
	int_int_map_two[6] = 6;
	int_int_map_two[654] = 654;

	std::cout << "int_int_map_two : " << std::endl << int_int_map_two << std::endl;

	int_int_map.insert(int_int_map_two.begin(), int_int_map_two.end());

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl;

	test_insert_std();
}

static void	test_copy_std(void)
{
	print_header("STD COPY CONSTRUCTOR + ASSIGNATION OPERATOR");

	std::cout << "For a string, string map hand_france;" << std::endl << std::endl;

	std::map<std::string, std::string> hand_france;

	hand_france["Glauser"] = "Laura";
	hand_france["Nocandy"] = "Méline";
	hand_france["Coatenea"] = "Pauline";
	hand_france["Valentini"] = "Chloé";
	hand_france["Lassource"] = "Coralie";
	hand_france["Zaadi"] = "Grace";

	std::cout << "map hand_france : " << std::endl << hand_france << std::endl;

	std::map<std::string, std::string> cpy_hand_france(hand_france);
	std::cout << "std::map<std::string, std::string> cpy_hand_france(hand_france);" << std::endl << std::endl;

	std::cout << "map cpy_hand_france : " << std::endl << cpy_hand_france << std::endl;

	std::cout << "// Test to modify the new copied map" << std::endl;
	cpy_hand_france["Kouyaté"] = "Aissatou";

	std::cout << "cpy_hand_france[\"Kouyaté\"] = \"Aissatou\";" << std::endl << std::endl;

	std::cout << "map cpy_hand_france : " << std::endl << cpy_hand_france << std::endl;

	std::map<std::string, std::string> artists_world;

	std::cout << "For a string, string map top world artists :" << std::endl << std::endl;

	artists_world["Olivia Rodrigo"] = "drivers license";
	artists_world["The Weekend"] = "Save Your Tears";
	artists_world["Lil Tjay"] = "Calling My Phone";
	artists_world["The Weekend"] = "Blinding Lights";
	artists_world["Bad Bunny"] = "DAKITI";
	artists_world["Myke Towers"] = "Bandido";
	artists_world["24kGoldn"] = "Mood";

	std::cout << "map artists_world : " << std::endl << artists_world << std::endl;

	cpy_hand_france = artists_world;
	std::cout << "cpy_hand_france = artists_world;" << std::endl << std::endl;

	std::cout << "map cpy_hand_france : " << std::endl << cpy_hand_france << std::endl;

}

static void	test_copy(void)
{
	print_header("FT COPY CONSTRUCTOR + ASSIGNATION OPERATOR");

	std::cout << "For a string, string map hand_france;" << std::endl << std::endl;

	ft::map<std::string, std::string> hand_france;

	hand_france["Glauser"] = "Laura";
	hand_france["Nocandy"] = "Méline";
	hand_france["Coatenea"] = "Pauline";
	hand_france["Valentini"] = "Chloé";
	hand_france["Lassource"] = "Coralie";
	hand_france["Zaadi"] = "Grace";

	std::cout << "map hand_france : " << std::endl << hand_france << std::endl;

	ft::map<std::string, std::string> cpy_hand_france(hand_france);
	std::cout << "ft::map<std::string, std::string> cpy_hand_france(hand_france);" << std::endl << std::endl;

	std::cout << "map cpy_hand_france : " << std::endl << cpy_hand_france << std::endl;

	std::cout << "// Test to modify the new copied map" << std::endl;
	cpy_hand_france["Kouyaté"] = "Aissatou";

	std::cout << "cpy_hand_france[\"Kouyaté\"] = \"Aissatou\";" << std::endl << std::endl;

	std::cout << "map cpy_hand_france : " << std::endl << cpy_hand_france << std::endl;

	ft::map<std::string, std::string> artists_world;

	std::cout << "For a string, string map top world artists :" << std::endl << std::endl;

	artists_world["Olivia Rodrigo"] = "drivers license";
	artists_world["The Weekend"] = "Save Your Tears";
	artists_world["Lil Tjay"] = "Calling My Phone";
	artists_world["The Weekend"] = "Blinding Lights";
	artists_world["Bad Bunny"] = "DAKITI";
	artists_world["Myke Towers"] = "Bandido";
	artists_world["24kGoldn"] = "Mood";

	std::cout << "map artists_world : " << std::endl << artists_world << std::endl;

	cpy_hand_france = artists_world;
	std::cout << "cpy_hand_france = artists_world;" << std::endl << std::endl;

	std::cout << "map cpy_hand_france : " << std::endl << cpy_hand_france << std::endl;

	test_copy_std();
}

void 	test_swap_std(void)
{
	print_header("STD SWAP TEST");

	std::cout << "For a <int, string> map banana_box;" << std::endl;
	std::cout << "For a <int, string> map apple_box;" << std::endl;

	std::map<int, std::string>	banana_box;
	std::map<int, std::string>	apple_box;

	banana_box[34] = "🍌";
	banana_box[59] = "🍌";
	banana_box[32] = "🍌";
	banana_box[2] = "🍌";
	banana_box[492] = "🍌";
	banana_box[56] = "🍌";

	apple_box[92] = "🍎";
	apple_box[9] = "🍎";
	apple_box[103] = "🍎";
	apple_box[293] = "🍎";
	apple_box[93] = "🍎";
	apple_box[663] = "🍎";

	std::cout << "banana_box :" << std::endl << banana_box << std::endl;
	std::cout << "apple_box :" << std::endl << apple_box << std::endl << std::endl;

	banana_box.swap(apple_box);
	std::cout << "apple_box.swap(banana_box);" << std::endl << std::endl;

	std::cout << "banana_box :" << std::endl << banana_box << std::endl;
	std::cout << "apple_box :" << std::endl << apple_box << std::endl << std::endl;

	apple_box.swap(banana_box);
	std::cout << "apple_box.swap(banana_box);" << std::endl << std::endl;

	std::cout << "banana_box :" << std::endl << banana_box << std::endl;
	std::cout << "apple_box :" << std::endl << apple_box << std::endl << std::endl;
}

void 	test_swap(void)
{
	print_header("FT SWAP TEST");

	std::cout << "For a <int, string> map banana_box;" << std::endl;
	std::cout << "For a <int, string> map apple_box;" << std::endl;

	ft::map<int, std::string>	banana_box;
	ft::map<int, std::string>	apple_box;

	banana_box[34] = "🍌";
	banana_box[59] = "🍌";
	banana_box[32] = "🍌";
	banana_box[2] = "🍌";
	banana_box[492] = "🍌";
	banana_box[56] = "🍌";

	apple_box[92] = "🍎";
	apple_box[9] = "🍎";
	apple_box[103] = "🍎";
	apple_box[293] = "🍎";
	apple_box[93] = "🍎";
	apple_box[663] = "🍎";

	std::cout << "banana_box :" << std::endl << banana_box << std::endl;
	std::cout << "apple_box :" << std::endl << apple_box << std::endl << std::endl;

	banana_box.swap(apple_box);
	std::cout << "apple_box.swap(banana_box);" << std::endl << std::endl;

	std::cout << "banana_box :" << std::endl << banana_box << std::endl;
	std::cout << "apple_box :" << std::endl << apple_box << std::endl << std::endl;

	apple_box.swap(banana_box);
	std::cout << "apple_box.swap(banana_box);" << std::endl << std::endl;

	std::cout << "banana_box :" << std::endl << banana_box << std::endl;
	std::cout << "apple_box :" << std::endl << apple_box << std::endl << std::endl;

	test_swap_std();
}

static void	test_key_compare_std(void)
{
	print_header("STD KEY COMPARE TEST");

	std::map<char,int> mymap;

	std::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;
	mymap['d']=400;
	mymap['e']=500;
	mymap['f']=600;
	mymap['g']=700;
	mymap['h']=800;

	std::cout << "For a <char, int> \"mymap\" map : " << std::endl << mymap << std::endl;
	std::cout << "For a comparaison object \"mycomp\" = mymap.key_comp()" << std::endl << std::endl;

	std::cout << "For a char as highest key in map : char highest = mymap.rbegin()->first;" << std::endl << std::endl;

	char highest = mymap.rbegin()->first;		 // key value of last element

	std::map<char,int>::iterator it = mymap.begin();

	std::cout << "iterator it = mymap.begin();" << std::endl << std::endl;

	std::cout << "while (mycomp((*it).first, highest) == true)" << std::endl;
	std::cout << "    std::cout << it->first << \" => \" << it->second << std::endl;" << std::endl;
	std::cout << "    it++;" << std::endl << std::endl;

	std::cout << "=" << std::endl << std::endl;

	while (mycomp((*it).first, highest))
	{
		std::cout << it->first << " => " << it->second << std::endl;
		it++;
	}
}

static void	test_key_compare(void)
{
	print_header("FT KEY COMPARE TEST");

	ft::map<char,int> mymap;

	ft::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;
	mymap['d']=400;
	mymap['e']=500;
	mymap['f']=600;
	mymap['g']=700;
	mymap['h']=800;

	std::cout << "For a <char, int> \"mymap\" map : " << std::endl << mymap << std::endl;
	std::cout << "For a comparaison object \"mycomp\" = mymap.key_comp()" << std::endl << std::endl;

	std::cout << "For a char as highest key in map : char highest = mymap.rbegin()->first;" << std::endl << std::endl;

	char highest = mymap.rbegin()->first;		 // key value of last element

	ft::map<char,int>::iterator it = mymap.begin();

	std::cout << "iterator it = mymap.begin();" << std::endl << std::endl;

	std::cout << "while (mycomp((*it).first, highest) == true)" << std::endl;
	std::cout << "    std::cout << it->first << \" => \" << it->second << std::endl;" << std::endl;
	std::cout << "    it++;" << std::endl << std::endl;

	std::cout << "=" << std::endl << std::endl;

	while (mycomp((*it).first, highest))
	{
		std::cout << it->first << " => " << it->second << std::endl;
		it++;
	}

	std::cout << std::endl;

	test_key_compare_std();
}

static void	test_value_compare_std(void)
{
	print_header("STD VALUE COMPARE TEST");

	std::map<char,int> mymap;

	mymap['h']=100;
	mymap['g']=200;
	mymap['f']=300;
	mymap['e']=400;
	mymap['d']=500;
	mymap['c']=600;
	mymap['b']=700;
	mymap['a']=800;

	std::cout << "For a <char, int> \"mymap\" map : " << std::endl << mymap << std::endl;

	std::cout << "For a char as highest pair in map : char highest = *(mymap.rbegin());" << std::endl << std::endl;

	std::pair<char, int> highest = *(mymap.rbegin());

	std::cout << "iterator it = mymap.begin();" << std::endl << std::endl;
	std::map<char,int>::iterator it = mymap.begin();

	std::cout << "while (mymap.value_comp()(*it, highest))" << std::endl;
	std::cout << "    std::cout << it->first << \" => \" << it->second << std::endl;" << std::endl;
	std::cout << "    it++;" << std::endl << std::endl;

	std::cout << "=" << std::endl << std::endl;

	while (mymap.value_comp()(*it, highest))
	{
		std::cout << it->first << " => " << it->second << std::endl;
		it++;
	}

	std::cout << std::endl;
}

static void	test_value_compare(void)
{
	print_header("FT VALUE COMPARE TEST");

	ft::map<char,int> mymap;

	mymap['h']=100;
	mymap['g']=200;
	mymap['f']=300;
	mymap['e']=400;
	mymap['d']=500;
	mymap['c']=600;
	mymap['b']=700;
	mymap['a']=800;

	std::cout << "For a <char, int> \"mymap\" map : " << std::endl << mymap << std::endl;

	std::cout << "For a char as highest pair in map : char highest = *(mymap.rbegin());" << std::endl << std::endl;

	ft::pair<char, int> highest = *(mymap.rbegin());

	std::cout << "iterator it = mymap.begin();" << std::endl << std::endl;
	ft::map<char,int>::iterator it = mymap.begin();

	std::cout << "while (mymap.value_comp()(*it, highest))" << std::endl;
	std::cout << "    std::cout << it->first << \" => \" << it->second << std::endl;" << std::endl;
	std::cout << "    it++;" << std::endl << std::endl;

	std::cout << "=" << std::endl << std::endl;

	while (mymap.value_comp()(*it, highest))
	{
		std::cout << it->first << " => " << it->second << std::endl;
		it++;
	}

	std::cout << std::endl;

	test_value_compare_std();
}

static void	test_iterator_constructor(void)
{
	print_header("FT ITERATOR CONSTRUCTOR");

	std::cout << "For ft::map<std::string, std::string> map_countries" << std::endl;

	ft::map<std::string, std::string>	map_countries;

	map_countries["New-york"] = "USA";
	map_countries["Sydney"] = "Australia";
	map_countries["Paris"] = "France";
	map_countries["New-Delhi"] = "India";
	map_countries["Berlin"] = "Germany";
	map_countries["Brest"] = "France";
	map_countries["Prague"] = "Czech Republic";
	map_countries["Dublin"] = "Prague";

	std::cout << "map_countries :" << std::endl << map_countries << std::endl;

	ft::map<std::string, std::string> cpy_map_countries(map_countries.begin(), map_countries.end());
	std::cout << "ft::map<std::string, std::string> cpy_map_countries(map_countries.begin(), map_countries.end());" << std::endl;

	std::cout << "cpy_map_countries :" << std::endl << cpy_map_countries << std::endl;
}

static void	test_operations_std(void)
{
	print_header("STD OPERATIONS");

	std::cout << "#-- COUNT FUNCTION --#" << std::endl << std::endl;

	std::cout << "For a <int, int> map int_int_map;" << std::endl << std::endl;

	std::map<int, int>	int_int_map;

	int_int_map[19] = 19;
	int_int_map[12] = 12;
	int_int_map[53] = 53;
	int_int_map[24] = 24;
	int_int_map[82] = 82;
	int_int_map[23] = 23;
	int_int_map[49] = 49;
	int_int_map[59] = 59;
	int_int_map[98] = 98;
	int_int_map[87] = 87;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl;

	std::cout << "int_int_map.count(33453) : " << int_int_map.count(33453) << std::endl;
	std::cout << "int_int_map.count(98) : " << int_int_map.count(98) << std::endl;
	std::cout << "int_int_map.count(12) : " << int_int_map.count(12) << std::endl;
	std::cout << "int_int_map.count(49) : " << int_int_map.count(49) << std::endl;
	std::cout << "int_int_map.count(442) : " << int_int_map.count(442) << std::endl << std::endl;

	std::cout << "#-- LOWER BOUND FUNCTION --#" << std::endl << std::endl;

	std::cout << "(*int_int_map.lower_bound(23)).first : " << (*int_int_map.lower_bound(23)).first << std::endl;
	std::cout << "(*int_int_map.lower_bound(1)).first : " << (*int_int_map.lower_bound(1)).first << std::endl;
	std::cout << "(*int_int_map.lower_bound(59)).first : " << (*int_int_map.lower_bound(59)).first << std::endl;

	std::cout << "#-- UPPER BOUND FUNCTION --#" << std::endl << std::endl;
	std::cout << "(*int_int_map.upper_bound(23)).first : " << (*int_int_map.upper_bound(23)).first << std::endl;
	std::cout << "(*int_int_map.upper_bound(1)).first : " << (*int_int_map.upper_bound(1)).first << std::endl;
	std::cout << "(*int_int_map.upper_bound(59)).first : " << (*int_int_map.upper_bound(59)).first << std::endl;

	std::cout << "#-- EQUAL RANGE FUNCTION --#" << std::endl << std::endl;

	std::pair<std::map<int, int>::iterator,std::map<int, int>::iterator> ret;
	std::pair<std::map<int, int>::const_iterator,std::map<int, int>::const_iterator> ret_const;

	ret = int_int_map.equal_range(1);
	std::cout << "ret = int_int_map.equal_range(1);" << std::endl;
	std::cout << "*(ret.first) : " << *(ret.first) << std::endl;
	std::cout << "*(ret.second) : " << *(ret.second) << std::endl << std::endl;

	ret_const = int_int_map.equal_range(59);
	std::cout << "ret_const = int_int_map.equal_range(59);" << std::endl;
	std::cout << "*(ret_const.first) : " << *(ret_const.first) << std::endl;
	std::cout << "*(ret_const.second) : " << *(ret_const.second) << std::endl << std::endl;

	std::cout << std::endl;

}

static void	test_operations(void)
{
	print_header("FT OPERATIONS");

	std::cout << "#-- COUNT FUNCTION --#" << std::endl << std::endl;

	std::cout << "For a <int, int> map int_int_map;" << std::endl << std::endl;

	ft::map<int, int>	int_int_map;

	int_int_map[19] = 19;
	int_int_map[12] = 12;
	int_int_map[53] = 53;
	int_int_map[24] = 24;
	int_int_map[82] = 82;
	int_int_map[23] = 23;
	int_int_map[49] = 49;
	int_int_map[59] = 59;
	int_int_map[98] = 98;
	int_int_map[87] = 87;

	std::cout << "int_int_map : " << std::endl << int_int_map << std::endl;

	std::cout << "int_int_map.count(33453) : " << int_int_map.count(33453) << std::endl;
	std::cout << "int_int_map.count(98) : " << int_int_map.count(98) << std::endl;
	std::cout << "int_int_map.count(12) : " << int_int_map.count(12) << std::endl;
	std::cout << "int_int_map.count(49) : " << int_int_map.count(49) << std::endl;
	std::cout << "int_int_map.count(442) : " << int_int_map.count(442) << std::endl << std::endl;

	std::cout << "#-- LOWER BOUND FUNCTION --#" << std::endl << std::endl;

	ft::map<int, int>::iterator it;
	ft::map<int, int>::const_iterator it_const;

	std::cout << "(*int_int_map.lower_bound(23)).first : " <<	\
		(*(it = int_int_map.lower_bound(23))).first <<			\
		std::endl;
	std::cout << "(*int_int_map.lower_bound(1)).first : " <<	\
		(*(it_const = int_int_map.lower_bound(1))).first <<		\
		std::endl;
	std::cout << "(*int_int_map.lower_bound(59)).first : " <<	\
		(*(it = int_int_map.lower_bound(59))).first <<			\
		std::endl << std::endl;

	std::cout << "#-- UPPER BOUND FUNCTION --#" << std::endl << std::endl;

	std::cout << "(*int_int_map.upper_bound(23)).first : " <<	\
		(*(it = int_int_map.upper_bound(23))).first <<			\
		std::endl;
	std::cout << "(*int_int_map.upper_bound(1)).first : " <<	\
		(*(it_const = int_int_map.upper_bound(1))).first <<			\
		std::endl;
	std::cout << "(*int_int_map.upper_bound(59)).first : " <<	\
		(*(it = int_int_map.upper_bound(59))).first <<			\
		std::endl << std::endl;

	std::cout << "#-- EQUAL RANGE FUNCTION --#" << std::endl << std::endl;

	ft::pair<ft::map<int, int>::iterator,ft::map<int, int>::iterator> ret;
	ft::pair<ft::map<int, int>::const_iterator,ft::map<int, int>::const_iterator> ret_const;

	ret = int_int_map.equal_range(1);
	std::cout << "ret = int_int_map.equal_range(1);" << std::endl;
	std::cout << "*(ret.first) : " << *(ret.first) << std::endl;
	std::cout << "*(ret.second) : " << *(ret.second) << std::endl << std::endl;

	ret_const = int_int_map.equal_range(59);
	std::cout << "ret_const = int_int_map.equal_range(59);" << std::endl;
	std::cout << "*(ret_const.first) : " << *(ret_const.first) << std::endl;
	std::cout << "*(ret_const.second) : " << *(ret_const.second) << std::endl << std::endl;

	test_operations_std();
}

template <typename T>
struct	strLenLess
{
	bool operator()(const T &lhs, const T &rhs) const
	{
		return (lhs.size() < rhs.size());
	}
};

template <typename T>
struct	strLenGreater
{
	bool operator()(const T &lhs, const T &rhs) const
	{
		return (lhs.size() > rhs.size());
	}
};

static void	test_other_compare(void)
{
	print_header("FT OTHER COMPARE TEST");

	ft::map<int, int, std::greater<int> >	mymap;
	std::cout << "ft::map<int, int, std::greater<int> >	mymap;" << std::endl << std::endl;

	mymap[59] = 59;
	mymap[26] = 26;
	mymap[68] = 68;
	mymap[7] = 7;
	mymap[43] = 43;
	mymap[65] = 65;
	mymap[77] = 77;
	mymap[1] = 1;

	std::cout << "mymap : " << std::endl << mymap << std::endl;

	ft::map<std::string, std::string, strLenLess<std::string> >	str_str_map;
	std::cout << "ft::map<std::string, std::string, strLenGreater<int> >  std_str_map;" << std::endl << std::endl;

	str_str_map["Fils"] = "Fils";
	str_str_map["Corde"] = "Corde";
	str_str_map["Cactus"] = "Cactus";
	str_str_map["Section"] = "Section";
	str_str_map["Caravane"] = "Caravane";
	str_str_map["Feuillet"] = "Feuillet";
	str_str_map["Effacement"] = "Effacement";
	str_str_map["Radiographie"] = "Radiographie";

	std::cout << "str_str_map : " << std::endl << str_str_map << std::endl;

	ft::map<std::string, std::string, strLenGreater<std::string> >	another_map;
	std::cout << "ft::map<std::string, std::string, strLenGreater<int> >  another_map;" << std::endl << std::endl;

	another_map["Fils"] = "Fils";
	another_map["Corde"] = "Corde";
	another_map["Cactus"] = "Cactus";
	another_map["Section"] = "Section";
	another_map["Caravane"] = "Caravane";
	another_map["Feuillet"] = "Feuillet";
	another_map["Effacement"] = "Effacement";
	another_map["Radiographie"] = "Radiographie";

	std::cout << "another_map : " << std::endl << another_map << std::endl;
}

void	main_map(void)
{
	std::vector<void(*)(void)>	lst_funs_ptr;
	std::vector<std::string>	lst_funs_description;

	lst_funs_ptr.push_back(test_operator_brackets);
	lst_funs_description.push_back("0 : ESSENTIAL (operator[], size(), empty())");

	lst_funs_ptr.push_back(test_iterator);
	lst_funs_description.push_back("1 : ITERATOR");

	lst_funs_ptr.push_back(test_reverse_iterator);
	lst_funs_description.push_back("2 : REVERSE ITERATOR");

	lst_funs_ptr.push_back(test_erase_by_key);
	lst_funs_description.push_back("3 : ERASE BY KEY");

	lst_funs_ptr.push_back(test_erase_by_iterators);
	lst_funs_description.push_back("4 : ERASE BY ITERATORS");

	lst_funs_ptr.push_back(test_clear);
	lst_funs_description.push_back("5 : CLEAR");

	lst_funs_ptr.push_back(test_find);
	lst_funs_description.push_back("6 : FIND");

	lst_funs_ptr.push_back(test_insert);
	lst_funs_description.push_back("7 : INSERT");

	lst_funs_ptr.push_back(test_copy);
	lst_funs_description.push_back("8 : COPY CONSTRUCTOR + ASSIGNATION OPERATOR");

	lst_funs_ptr.push_back(test_swap);
	lst_funs_description.push_back("9 : SWAP FUNCTION");

	lst_funs_ptr.push_back(test_key_compare);
	lst_funs_description.push_back("10 : KEY COMPARE");

	lst_funs_ptr.push_back(test_value_compare);
	lst_funs_description.push_back("11 : VALUE COMPARE");

	lst_funs_ptr.push_back(test_iterator_constructor);
	lst_funs_description.push_back("12 : TEST ITERATOR CONSTRUCTOR");

	lst_funs_ptr.push_back(test_operations);
	lst_funs_description.push_back("13 : TEST OPERATIONS");

	lst_funs_ptr.push_back(test_other_compare);
	lst_funs_description.push_back("14 : TEST OTHER COMPARE");

	menu(lst_funs_ptr, lst_funs_description, "MAP");

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nest_template.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:37:53 by jecaudal          #+#    #+#             */
/*   Updated: 2020/12/14 12:29:10 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Experimentation about nested class in a template class.
**	Conclusion : A nested class in a template class is also a template class.
*/

#include <iostream>

template <typename T>
class	in
{
public:

	class	inin
	{
		public:
			T a;
			in inside;
	};
	T b;

	inin get_nested(void) { return (inin()); };

private:

	void coucou(void) { std::cout << "COUCOU" << std::endl; }
};

int		main(void)
{
	in<int> un;
	in<int>::inin deux;

	un.b = 5;
	deux.a = 5;

	std::cout << un.b << std::endl;
	std::cout << deux.a << std::endl;
	un.get_nested();
	deux.inside
	return (0);
}

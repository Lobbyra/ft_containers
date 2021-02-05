/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:24:24 by jecaudal          #+#    #+#             */
/*   Updated: 2021/02/05 12:24:37 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "../list/list.hpp"

namespace ft
{

template <class T, class Container = list<T> >
class	stack
{
public:

	typedef	typename list<T>::value_type	value_type;
	typedef	typename list<T>::size_type		size_type;
	typedef	Container						container_type;

	// DEFAULT CONSTRUCTOR
	explicit stack (const container_type& ctnr = container_type())
	: _cont(ctnr)
	{ };

	// COPY CONSTRUCTOR
	stack(stack const &src) : _cont(src._cont) {};

	template<typename _Tp1, typename _Seq1>
	friend bool operator== (const stack<_Tp1,_Seq1>& lhs, const stack<_Tp1,_Seq1>& rhs);

	template<typename _Tp1, typename _Seq1>
	friend bool operator<  (const stack<_Tp1,_Seq1>& lhs, const stack<_Tp1,_Seq1>& rhs);

	stack &operator=(stack const &src)
	{
		_cont = src._cont;
		return (*this);
	};

	virtual ~stack() {};

	bool empty() const { return (_cont.empty()); };

	size_type size() const { return (_cont.size()); };

		  value_type& top() { return (_cont.back()); };
	const value_type& top() const { return (_cont.back()); };

	void push (const value_type& val) { _cont.push_back(val); };

	void pop() {_cont.pop_back(); };

private:

	container_type	_cont;

};

template <class T, class Container>
bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (lhs._cont == rhs._cont);
};

template <class T, class Container>
bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (lhs._cont < rhs._cont);
};

template <class T, class Container>
bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (!(lhs == rhs));
};

template <class T, class Container>
bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	if (lhs == rhs)
		return (true);
	return (lhs < rhs);
};

template <class T, class Container>
bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	if (lhs == rhs)
		return (false);
	return (!(lhs < rhs));
};

template <class T, class Container>
bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	if (lhs == rhs)
		return (true);
	return (!(lhs < rhs));
};

}

#endif

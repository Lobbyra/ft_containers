/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:17:41 by jecaudal          #+#    #+#             */
/*   Updated: 2021/02/05 14:38:35 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

#include "../list/list.hpp"

namespace ft
{

template <class T, class Container = list<T> >
class	queue
{
public:

	typedef	typename list<T>::value_type	value_type;
	typedef	typename list<T>::size_type		size_type;
	typedef	Container						container_type;

	// DEFAULT CONSTRUCTOR
	explicit queue (const container_type& ctnr = container_type())
	: _cont(ctnr)
	{ };

	// COPY CONSTRUCTOR
	queue(queue const &src) : _cont(src._cont) {};

	template<typename _Tp1, typename _Seq1>
	friend bool operator== (const queue<_Tp1,_Seq1>& lhs, const queue<_Tp1,_Seq1>& rhs);

	template<typename _Tp1, typename _Seq1>
	friend bool operator<  (const queue<_Tp1,_Seq1>& lhs, const queue<_Tp1,_Seq1>& rhs);

	queue &operator=(queue const &src)
	{
		_cont = src._cont;
		return (*this);
	};

	virtual ~queue() {};

	bool empty() const { return (_cont.empty()); };

	size_type size() const { return (_cont.size()); };

		  value_type& back() { return (_cont.back()); };
	const value_type& back() const { return (_cont.back()); };

		  value_type& front() { return (_cont.front()); };
	const value_type& front() const { return (_cont.front()); };

	void push (const value_type& val) { _cont.push_back(val); };

	void pop() {_cont.pop_front(); };

private:

	container_type	_cont;

};

template <class T, class Container>
bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{
	return (lhs._cont == rhs._cont);
};

template <class T, class Container>
bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{
	return (lhs._cont < rhs._cont);
};

template <class T, class Container>
bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{
	return (!(lhs == rhs));
};

template <class T, class Container>
bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{
	if (lhs == rhs)
		return (true);
	return (lhs < rhs);
};

template <class T, class Container>
bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{
	if (lhs == rhs)
		return (false);
	return (!(lhs < rhs));
};

template <class T, class Container>
bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{
	if (lhs == rhs)
		return (true);
	return (!(lhs < rhs));
};

}

#endif

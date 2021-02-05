/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_const_iterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:46:21 by jecaudal          #+#    #+#             */
/*   Updated: 2021/02/04 10:49:04 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CONST_ITERATOR_HPP
# define VECTOR_CONST_ITERATOR_HPP

#include "vector_iterator.hpp"

namespace ft
{

template <typename T>
class	vectorConstIterator
{
public:

	typedef const T					value_type;
	typedef value_type&				reference;
	typedef const value_type&		const_reference;
	typedef value_type*				pointer;
	typedef typename std::ptrdiff_t difference_type;

	vectorConstIterator(void) {};
	vectorConstIterator(pointer ptr) { _ptr = ptr; };
	vectorConstIterator(vectorIterator<T> const &src) { _ptr = src.operator->(); } ;
	vectorConstIterator(vectorConstIterator const &src) { *this = src; } ;

	virtual ~vectorConstIterator() {};

	vectorConstIterator &operator=(vectorConstIterator const &src) { _ptr = src.operator->(); return (*this); };

	// BOOLEANS
	bool operator ==(vectorConstIterator const& b) const { return (_ptr == b._ptr); };
	bool operator !=(vectorConstIterator const& b) const { return (_ptr != b._ptr); };
	bool operator >(vectorConstIterator const& b) const { return (_ptr > b._ptr); };
	bool operator <(vectorConstIterator const& b) const { return (_ptr < b._ptr); };
	bool operator >=(vectorConstIterator const& b) const { return (_ptr >= b._ptr); };
	bool operator <=(vectorConstIterator const& b) const { return (_ptr <= b._ptr); };

	// ARITHMETICS
	vectorConstIterator operator +(difference_type b) { return (vectorConstIterator(_ptr + b)); }; // a + n
	vectorConstIterator operator -(difference_type b) { return (vectorConstIterator(_ptr - b)); }; // a - n

	difference_type operator +(vectorConstIterator b) { return (_ptr + b._ptr); }; // a + b
	difference_type operator -(vectorConstIterator b) { return (_ptr - b._ptr); }; // a - b

	// INCREMENTERS
	vectorConstIterator operator ++() { _ptr++; return (*this); };			// ++a
	vectorConstIterator operator ++(int) { _ptr++; return (vectorConstIterator(_ptr - 1)); };	// a++
	vectorConstIterator operator --() { _ptr--; return (*this); };			// --a
	vectorConstIterator operator --(int) { _ptr--; return (vectorConstIterator(_ptr + 1)); };	// a--

	//COMPOUND ASSIGNMENTS
	void operator +=(difference_type b) { _ptr += b; };	// a += b
	void operator -=(difference_type b) { _ptr -= b; };	// a -= b

	//DEREFERENCING & ADDRESS STUFF
	const_reference operator *() const { return (*_ptr); };								// *a
	const_reference operator [](difference_type b) const { return (*(_ptr + b)); };		// a[]
	pointer operator ->() { return (_ptr); };											// a->b
	pointer operator ->() const { return (_ptr); };											// a->b

	static const bool input_iter = true;

	private:
		pointer _ptr;

};

}

#endif

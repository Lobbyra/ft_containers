/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:48:50 by jecaudal          #+#    #+#             */
/*   Updated: 2021/02/04 11:01:56 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_REVERSE_ITERATOR_HPP
# define VECTOR_REVERSE_ITERATOR_HPP

namespace ft
{

template <typename iterator>
class	vectorReverseIterator
{
public:

	typedef typename iterator::value_type		value_type;
	typedef typename iterator::reference		reference;
	typedef typename iterator::const_reference	const_reference;
	typedef typename iterator::pointer			pointer;
	typedef typename iterator::const_pointer	const_pointer;
	typedef typename iterator::difference_type	difference_type;

	vectorReverseIterator(void) {};
	vectorReverseIterator(pointer ptr) { _ptr = ptr; };
	vectorReverseIterator(vectorIterator<value_type> const &src) { _ptr = src.operator->(); } ;
	vectorReverseIterator(vectorReverseIterator const &src) { *this = src; } ;

	virtual ~vectorReverseIterator() {};

	vectorReverseIterator &operator=(vectorReverseIterator const &src) { _ptr = src._ptr; return (*this); };

	// BOOLEANS
	bool operator ==(vectorReverseIterator const& b) const { return (_ptr == b._ptr); };
	bool operator !=(vectorReverseIterator const& b) const { return (_ptr != b._ptr); };
	bool operator >(vectorReverseIterator const& b) const { return (_ptr > b._ptr); };
	bool operator <(vectorReverseIterator const& b) const { return (_ptr < b._ptr); };
	bool operator >=(vectorReverseIterator const& b) const { return (_ptr >= b._ptr); };
	bool operator <=(vectorReverseIterator const& b) const { return (_ptr <= b._ptr); };

	// ARITHMETICS
	vectorReverseIterator operator +(difference_type b) { return (vectorReverseIterator(_ptr - b)); }; // a + b
	vectorReverseIterator operator -(difference_type b) { return (vectorReverseIterator(_ptr + b)); }; // a - b

	difference_type operator +(vectorReverseIterator b) { return (_ptr - b._ptr); }; // a + b
	difference_type operator -(vectorReverseIterator b) { return (_ptr + b._ptr); }; // a - b

	// INCREMENTERS
	vectorReverseIterator operator ++() { _ptr--; return (*this); };			// ++a
	vectorReverseIterator operator ++(int) { _ptr--; return (vectorReverseIterator(_ptr + 1)); };	// a++
	vectorReverseIterator operator --() { _ptr++; return (*this); };			// --a
	vectorReverseIterator operator --(int) { _ptr++; return (vectorReverseIterator(_ptr - 1)); };	// a--

	//COMPOUND ASSIGNMENTS
	void operator +=(difference_type b) { _ptr -= b; };	// a += b
	void operator -=(difference_type b) { _ptr += b; };	// a -= b

	//DEREFERENCING & ADDRESS STUFF
	reference operator *() { return (*_ptr); };											// *a
	const_reference operator *() const { return (*_ptr); };								// *a
	reference operator [](difference_type b) { return (*(_ptr + b)); };					// a[]
	const_reference operator [](difference_type b) const { return (*(_ptr + b)); };		// a[]
	pointer operator ->() { return (_ptr); };											// a->b
	pointer operator ->() const { return (_ptr); };											// a->b

	static const bool input_iter = true;

	private:
		pointer _ptr;
};

}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_const_reverse_iterator.hpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:49:19 by jecaudal          #+#    #+#             */
/*   Updated: 2021/02/04 11:12:13 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CONST_REVERSE_ITERATOR_HPP
# define VECTOR_CONST_REVERSE_ITERATOR_HPP

namespace ft
{

template <typename iterator>
class	vectorConstReverseIterator
{
public:

	typedef typename iterator::value_type		value_type;
	typedef typename iterator::reference		reference;
	typedef typename iterator::const_reference	const_reference;
	typedef typename iterator::pointer			pointer;
	typedef typename iterator::const_pointer	const_pointer;
	typedef typename iterator::difference_type	difference_type;

	vectorConstReverseIterator(void) {};
	vectorConstReverseIterator(vectorConstIterator<value_type> const &src) { _ptr = src.operator->(); } ;
	vectorConstReverseIterator(vectorReverseIterator<iterator> const &src) { _ptr = src.operator->(); } ;
	vectorConstReverseIterator(vectorConstReverseIterator const &src) { *this = src; } ;

	virtual ~vectorConstReverseIterator() {};

	vectorConstReverseIterator &operator=(vectorConstReverseIterator const &src) { _ptr = src._ptr; return (*this); };

	// BOOLEANS
	bool operator ==(vectorConstReverseIterator const& b) const { return (_ptr == b._ptr); };
	bool operator !=(vectorConstReverseIterator const& b) const { return (_ptr != b._ptr); };
	bool operator >(vectorConstReverseIterator const& b) const { return (_ptr > b._ptr); };
	bool operator <(vectorConstReverseIterator const& b) const { return (_ptr < b._ptr); };
	bool operator >=(vectorConstReverseIterator const& b) const { return (_ptr >= b._ptr); };
	bool operator <=(vectorConstReverseIterator const& b) const { return (_ptr <= b._ptr); };

	// ARITHMETICS
	vectorConstReverseIterator operator +(difference_type b) { return (vectorConstReverseIterator(_ptr - b)); }; // a + b
	vectorConstReverseIterator operator -(difference_type b) { return (vectorConstReverseIterator(_ptr + b)); }; // a - b

	difference_type operator +(vectorConstReverseIterator b) { return (_ptr - b._ptr); }; // a + b
	difference_type operator -(vectorConstReverseIterator b) { return (_ptr + b._ptr); }; // a - b

	// INCREMENTERS
	vectorConstReverseIterator operator ++() { _ptr--; return (*this); };			// ++a
	vectorConstReverseIterator operator ++(int) { _ptr--; return (vectorConstReverseIterator(_ptr + 1)); };	// a++
	vectorConstReverseIterator operator --() { _ptr++; return (*this); };			// --a
	vectorConstReverseIterator operator --(int) { _ptr++; return (vectorConstReverseIterator(_ptr - 1)); };	// a--

	//COMPOUND ASSIGNMENTS
	void operator +=(difference_type b) { _ptr -= b; };	// a += b
	void operator -=(difference_type b) { _ptr += b; };	// a -= b

	//DEREFERENCING & ADDRESS STUFF
	const_reference operator *() const { return (*_ptr); };								// *a
	reference operator [](difference_type b) { return (*(_ptr + b)); };					// a[]
	const_reference operator [](difference_type b) const { return (*(_ptr + b)); };		// a[]
	pointer operator ->() { return (_ptr); };											// a->b
	pointer operator ->() const { return (_ptr); };											// a->b

	static const bool input_iter = true;

	private:

		vectorConstReverseIterator(pointer ptr) { _ptr = ptr; };
		pointer _ptr;
};

}

#endif

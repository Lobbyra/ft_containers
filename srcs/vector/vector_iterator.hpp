/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:44:49 by jecaudal          #+#    #+#             */
/*   Updated: 2021/02/04 10:57:36 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

namespace ft
{

template <typename T>
class	vectorIterator
{
public:

	typedef T						value_type;
	typedef value_type&				reference;
	typedef const value_type&		const_reference;
	typedef value_type*				pointer;
	typedef const value_type*		const_pointer;
	typedef typename std::ptrdiff_t difference_type;

	vectorIterator(void) {};
	vectorIterator(pointer ptr) { _ptr = ptr; };
	vectorIterator(vectorIterator const &src) { *this = src; } ;

	virtual ~vectorIterator() {};

	vectorIterator &operator=(vectorIterator const &src) { _ptr = src.operator->(); return (*this); };

	// BOOLEANS
	bool operator ==(vectorIterator const& b) const { return (_ptr == b._ptr); };
	bool operator !=(vectorIterator const& b) const { return (_ptr != b._ptr); };
	bool operator >(vectorIterator const& b) const { return (_ptr > b._ptr); };
	bool operator <(vectorIterator const& b) const { return (_ptr < b._ptr); };
	bool operator >=(vectorIterator const& b) const { return (_ptr >= b._ptr); };
	bool operator <=(vectorIterator const& b) const { return (_ptr <= b._ptr); };

	// ARITHMETICS
	vectorIterator operator +(difference_type b) { return (vectorIterator(_ptr + b)); }; // a + n
	vectorIterator operator -(difference_type b) { return (vectorIterator(_ptr - b)); }; // a - n

	difference_type operator +(vectorIterator b) { return (_ptr + b._ptr); }; // a + b
	difference_type operator -(vectorIterator b) { return (_ptr - b._ptr); }; // a - b

	// INCREMENTERS
	vectorIterator operator ++() { _ptr++; return (*this); };			// ++a
	vectorIterator operator ++(int) { _ptr++; return (vectorIterator(_ptr - 1)); };	// a++
	vectorIterator operator --() { _ptr--; return (*this); };			// --a
	vectorIterator operator --(int) { _ptr--; return (vectorIterator(_ptr + 1)); };	// a--

	//COMPOUND ASSIGNMENTS
	void operator +=(difference_type b) { _ptr += b; };	// a += b
	void operator -=(difference_type b) { _ptr -= b; };	// a -= b

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:09:50 by jecaudal          #+#    #+#             */
/*   Updated: 2021/01/13 10:44:14 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <limits>
# include <memory>
# include <vector>
# include <cstddef>
# include <sstream>
# include "utils.hpp"

namespace ft
{

template <typename T>
class	vectorIterator
{
public:

	typedef T&			reference;
	typedef const T&	const_reference;
	typedef T*			pointer;
	typedef T			value_type;
	typedef typename std::ptrdiff_t difference_type;

	vectorIterator(void) {};
	vectorIterator(pointer ptr) { _ptr = ptr; };
	vectorIterator(vectorIterator const &src) { *this = src; } ;

	virtual ~vectorIterator() {};

	vectorIterator &operator=(vectorIterator const &src) { _ptr = src._ptr; return (*this); };

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

	static const bool input_iter = true;

	private:
		pointer _ptr;

};

template <typename T>
class	vectorReverseIterator
{
public:

	typedef T&			reference;
	typedef const T&	const_reference;
	typedef T*			pointer;
	typedef T			value_type;
	typedef typename std::ptrdiff_t difference_type;

	vectorReverseIterator(void) {};
	vectorReverseIterator(pointer ptr) { _ptr = ptr; };
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

	const bool input_iter = true;

	private:
		pointer _ptr;
};

template< typename T, class Allocator = std::allocator<T> >
class	vector
{
public:

	typedef T value_type;
	typedef Allocator allocator_type;
	typedef typename std::size_t size_type;
	typedef typename std::ptrdiff_t difference_type;
	typedef typename Allocator::reference reference;
	typedef typename Allocator::const_reference const_reference;
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;

	/*
	**	CONSTRUCTORS
	*/
	explicit vector(const Allocator& alloc = Allocator())
	: _alloc(alloc), _ptr(0), _size_alloc(0), _size_filled(0)
	{};

	template<class InputIt>
	vector(InputIt first, InputIt last, const Allocator& alloc = Allocator(),
	typename ft::enable_if<InputIt::input_iter, InputIt>::type = nullptr)
	: _alloc(alloc), _ptr(0), _size_alloc(0), _size_filled(0)
	{
		while (first != last)
		{
			this->push_back(*first);
			first++;
		}
	};

	vector(vector &src)
	: _alloc(allocator_type()), _size_alloc(0), _size_filled(0)
	{ *this = src; };

	explicit vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type())
	: _alloc(alloc), _ptr(0), _size_alloc(0), _size_filled(0)
	{
		for (size_type i = 0; i < n; i++)
			this->push_back(val);
	};

	virtual ~vector() { this->clear(); };

	typedef typename ft::vectorIterator<T> iterator;
	// typedef typename ft::vectorIterator<T> const const_iterator;
	typedef typename ft::vectorReverseIterator<T> reverse_iterator;
	// typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

	vector &operator=(vector &src)
	{
		this->clear();
		for (iterator it = src.begin(); it != src.end(); it++)
			this->push_back(*it);
		return (*this);
	};

	template<class InputIt>
	void assign(InputIt first, InputIt last,
	typename ft::enable_if<InputIt::input_iter, InputIt>::type = nullptr)
	{
		this->clear();
		for (iterator it = first; it != last; it++)
				this->push_back(*it);
	};

	void assign(size_type count, const T& value)
	{
		this->clear();
		for (size_type n = 0; n < count; n++)
			this->push_back(value);
	};

	reference		at(size_type pos)
	{
		if (pos >= _size_filled)
			throw _out_of_range(pos);
		return (_ptr[pos]);
	};
	const_reference	at(size_type pos) const
	{
		if (pos >= _size_filled)
			throw _out_of_range(pos);
		return (_ptr[pos]);
	};

	reference		operator[](size_type pos) { return (_ptr[pos]); };
	const_reference	operator[](size_type pos) const { return (_ptr[pos]); };

	reference		front() { return (*_ptr); };
	const_reference	front() const { return (*_ptr); };

	reference		back() { return (*(_ptr + (_size_filled - 1))); };
	const_reference	back() const { return (*(_ptr + (_size_filled - 1))); };

	iterator		begin() { return (iterator(_ptr)); };
	// const_iterator	begin() const;

	iterator		end() { return (iterator(_ptr + _size_filled)); };
	// const_iterator	end() const;

	reverse_iterator	rbegin() { return (reverse_iterator(_ptr + (_size_filled - 1))); };
	// const_reverse_iterator	rbegin() const { return (reverse_iterator(_ptr + _size_filled)); };

	reverse_iterator	rend() { return (reverse_iterator(_ptr - 1)); };
	// const_reverse_iterator rend() const { return (reverse_iterator(_ptr)); };

	size_type	size() const { return (_size_filled); };
	bool		empty() const { return ((_size_filled == 0)); };
	// size_type	max_size() const { return (std::numeric_limits<size_type>::max()); };
	size_type	capacity() const { return (_size_alloc); };
	void		reserve(size_type new_cap)
	{
		value_type	*new_arr;

		if (new_cap <= _size_alloc)
			return ;
		new_arr = _alloc.allocate(new_cap);
		for (size_t i = 0; i < _size_filled; i++)
			_alloc.construct(new_arr + i, *(_ptr + i));
		_size_alloc = new_cap;
		_ptr = new_arr;
	};

	void clear()
	{
		if (_size_alloc > 0)
		{
			for (iterator it = this->begin(); it != this->end(); it++)
				_alloc.destroy(&(*it));
			_alloc.deallocate(_ptr, _size_alloc);
		}
		_size_alloc = 0;
		_size_filled = 0;
	};

	iterator	insert(iterator pos, const T& value)
	{
		iterator			absolute_iterator;
		difference_type		int_pos = pos - this->begin();

		if (this->capacity() == this->size())
			_extend();
		absolute_iterator = this->begin() + int_pos;

		vector		temp(absolute_iterator, this->end());

		for (size_t i = 0; i < temp.size(); i++)
			this->pop_back();

		this->push_back(value);
		iterator it = temp.begin();
		for (size_t i = 0; i < temp.size(); i++, it++)
			this->push_back(*it);

		return (this->begin() + int_pos);
	};

	void		insert(iterator pos, size_type count, const T& value)
	{
		difference_type		int_pos = pos - this->begin();

		while (_size_alloc - _size_filled < count)
			_extend();

		vector		temp(this->begin() + int_pos, this->end());

		for (size_t i = 0; i < temp.size(); i++)
			this->pop_back();
		while (count > 0)
		{
			this->push_back(value);
			count--;
		} 
		for (iterator it = temp.begin(); it != temp.end(); it++)
			this->push_back(*it);
	};

	template<class InputIt>
	void		insert(iterator pos, InputIt first, InputIt last,
	typename ft::enable_if<InputIt::input_iter, InputIt>::type = nullptr)
	{
		size_t				count = 0;
		difference_type		int_pos = pos - this->begin();

		while (first != last)
		{
			first++;
			count++;
		}
		first -= count;

		while (_size_alloc - _size_filled < count)
			_extend();

		vector		temp(this->begin() + int_pos, this->end());

		for (size_t i = 0; i < temp.size(); i++)
			this->pop_back();
		while (first != last)
		{
			this->push_back(*first);
			first++;
		}
		for (iterator it = temp.begin(); it != temp.end(); it++)
			this->push_back(*it);
	};

	iterator erase(iterator pos)
	{
		vector	temp(pos + 1, this->end());

		for (size_t i = 0; i < temp.size(); i++)
			this->pop_back();
		this->pop_back();
		for (iterator it = temp.begin(); it != temp.end(); it++)
			this->push_back(*it);
		return (pos);
	};

	iterator erase(iterator first, iterator last)
	{
		iterator temp(first);

		while (temp != last)
		{
			erase(first);
			temp++;
		}
		return (first);
	};

	void push_back(const T& value)
	{
		if (_size_alloc == 0)
		{
			_ptr = _alloc.allocate(1);
			_size_alloc++;
		}
		if (_size_filled == _size_alloc)
			_extend();
		_alloc.construct(_ptr + _size_filled, value);
		_size_filled++;
	};

	void pop_back()
	{
		if (_size_filled > 0)
		{
			_alloc.destroy(_ptr + (_size_filled - 1));
			_size_filled--;
		}
	};

	void resize (size_type n, value_type val = value_type())
	{
		value_type *new_arr;

		new_arr = _alloc.allocate(n);
		if (n > _size_filled)
		{
			for (size_t i = 0; i < _size_filled; i++)
				_alloc.construct(new_arr + i, *(_ptr + i));
			for (size_t i = 0; i < n - _size_filled; i++)
				_alloc.construct(new_arr + _size_filled + i, val);
		}
		else
		{
			for (size_t i = 0; i < n; i++)
				_alloc.construct(new_arr + i, *(_ptr + i));
		}
		if (_size_filled)
		{
			_alloc.destroy(_ptr);
			_alloc.deallocate(_ptr, _size_alloc);
		}
		_size_alloc = n;
		_size_filled = n;
		_ptr = new_arr;
	};

	void swap(vector& other);

private:
/*
**	_ptr -> array of data saved
**	_size_alloc -> number of blocks alloced to _ptr
**	_size_filled -> number of objects saved in the containers
**
**	_extend() -> function to double space alloced. It copy previous data
*/

	Allocator _alloc;
	T		*_ptr;
	size_t	_size_alloc;
	size_t	_size_filled;
	void	_extend(void)
	{
		if (_size_alloc == 0)
		{
			_ptr = _alloc.allocate(1);
			_size_alloc++;
		}
		else
		{
			T *new_arr = _alloc.allocate(_size_alloc * 2);
			for (size_t i = 0; i < _size_filled; i++)
			{
				_alloc.construct(new_arr + i, *(_ptr + i));
				_alloc.destroy(_ptr + i);
			}
			_alloc.deallocate(_ptr, _size_alloc);
			_ptr = new_arr;
			_size_alloc *= 2;
		}
	};

	std::out_of_range	_out_of_range(size_type pos)
	{
		std::stringstream ss;

		ss << "vector::_M_range_check: __n (which is " << pos << ")" <<	\
		" >= this->size() (which is " << _size_filled << ")";
		return (std::out_of_range(ss.str()));
	};
};

// template< class T, class Alloc >
// bool operator==(const vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

// template< class T, class Alloc >
// bool operator!=(const vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

// template< class T, class Alloc >
// bool operator<(const vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

// template< class T, class Alloc >
// bool operator<=(const vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

// template< class T, class Alloc >
// bool operator>(const vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

// template< class T, class Alloc >
// bool operator>=(const vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

}

#endif

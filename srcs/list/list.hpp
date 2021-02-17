/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:33:37 by jecaudal          #+#    #+#             */
/*   Updated: 2021/02/17 09:04:36 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <limits>
# include <memory>
# include <vector>
# include <cstddef>
# include <iostream>
# include <sstream>
# include <unistd.h>
# include "../utils.hpp"

namespace ft
{

# define SENTINEL_NODE NULL

template < class T, class Alloc = std::allocator<T> >
class	Node
{
public:

	typedef Alloc	allocator_type;

	Node(const allocator_type& alloc = allocator_type())
		: _ptr(0), _next(0), _prev(0), _alloc(alloc) {};

	Node(const T &elem, const allocator_type& alloc = allocator_type())
		: _ptr(0), _next(0), _prev(0), _alloc(alloc)
	{
		_ptr = _alloc.allocate(1);
		_alloc.construct(_ptr, elem);
	};

	Node(Node const &src)
	{
		*this = src;
	};

	Node &operator=(Node const &src)
	{
		_ptr = src._ptr;
		_next = src._next;
		_prev = src._prev;

		return (*this);
	};

	virtual ~Node()
	{
		if (_ptr)
		{
			_alloc.destroy(_ptr);
			_alloc.deallocate(_ptr, 1);
		}
	};

	void	set(Node *next, Node *prev, T *ptr)
	{
		set_next(next);
		set_prev(prev);
		set_ptr(ptr);
	}

	void	set_nodes(Node *next, Node *prev)
	{
		set_next(next);
		set_prev(prev);
	}

	void	set_next(Node *next) { _next = next; };

	void	set_prev(Node *prev) { _prev = prev; };

	void	set_ptr(T *ptr) { _ptr = ptr; };

	void	set_elem(T &elem)
	{
		if (_ptr)
		{
			_alloc.destroy(_ptr);
			_alloc.deallocate(_ptr, 1);
		}
		_ptr = _alloc.allocate(1);
		_alloc.construct(_ptr, elem);
	};

	bool	is_sentinel(void) { return (_ptr == SENTINEL_NODE); };

	const Node	*get_curr(void) const { return (this); };
	T			*get_elem(void) const { return (_ptr); };
	Node		*get_prev(void) const { return (_prev); };
	Node		*get_next(void) const { return (_next); };

private:

	T				*_ptr;
	Node			*_next;
	Node			*_prev;
	allocator_type	_alloc;

};

template <typename T>
std::ostream	&operator<<(std::ostream &o, Node<T> const &i)
{
	std::cout <<						\
	"_curr = " << i.get_curr() <<		\
	", _next = " << i.get_next() <<		\
	", _prev = " << i.get_prev() <<		\
	", _ptr = " << i.get_elem() <<		\
	std::endl;
	return (o);
};

template <typename T>
class	listIterator
{
public:

	typedef T						value_type;
	typedef value_type&				reference;
	typedef const value_type&		const_reference;
	typedef Node<T>*				pointer;
	typedef Node<T> const *				const_pointer;
	typedef typename std::ptrdiff_t	difference_type;

	listIterator(void) : _ptr(NULL) {};
	listIterator(pointer ptr) : _ptr(ptr) { };
	listIterator(const listIterator &src) : _ptr(src._ptr) { };

	virtual ~listIterator() {};

	listIterator &operator=(listIterator const &src)
	{
		_ptr = src._ptr;
		return (*this);
	};

	listIterator operator ++() { _ptr = _ptr->get_next(); return (*this); };	// ++a
	listIterator operator --() { _ptr = _ptr->get_prev(); return (*this); };	// --a

	bool operator ==(listIterator const& b) const { return (_ptr == b._ptr); };
	bool operator !=(listIterator const& b) const { return (_ptr != b._ptr); };

	listIterator operator ++(int)	// a++
	{
		listIterator temp = *this;
		++(*this);
		return (temp);
	};

	listIterator operator --(int)	// a--
	{
		listIterator temp = *this;
		--(*this);
		return (temp);
	};

	reference operator *() { return (*(_ptr->get_elem())); };											// *a
	const_reference operator *() const { return (*(_ptr->get_elem())); };								// *a
	pointer operator ->() { return (_ptr); };											// a->b
	pointer operator ->() const { return (_ptr); };											// a->b

	static const bool input_iter = true;

private:

	pointer	_ptr;

};

template <typename T>
class	listConstIterator
{
public:

	typedef const T					value_type;
	typedef value_type&				reference;
	typedef const value_type&		const_reference;
	typedef Node<T>*				pointer;
	typedef Node<T>const *			const_pointer;
	typedef typename std::ptrdiff_t	difference_type;

	listConstIterator(void) {};
	listConstIterator(pointer ptr) { _ptr = ptr; };
	listConstIterator(const listIterator<T> &src) { _ptr = src.operator->(); };
	listConstIterator(const listConstIterator &src) { _ptr = src._ptr; };

	virtual ~listConstIterator() {};

	listConstIterator &operator=(listConstIterator const &src)
	{
		_ptr = src._ptr;
		return (*this);
	};

	listConstIterator operator ++() { _ptr = _ptr->get_next(); return (*this); };	// ++a
	listConstIterator operator --() { _ptr = _ptr->get_prev(); return (*this); };	// --a

	bool operator ==(listConstIterator const& b) const { return (_ptr == b.operator->()); };
	bool operator !=(listConstIterator const& b) const { return (_ptr != b.operator->()); };

	listConstIterator operator ++(int)	// a++
	{
		listConstIterator temp = *this;
		++(*this);
		return (temp);
	};

	listConstIterator operator --(int)	// a--
	{
		listConstIterator temp = *this;
		--(*this);
		return (temp);
	};

	const_reference operator *() const { return (*(_ptr->get_elem())); };								// *a
	pointer operator ->() { return (_ptr); };											// a->b
	pointer operator ->() const { return (_ptr); };											// a->b

	static const bool input_iter = true;

private:

	pointer	_ptr;

};

template <typename iterator>
class	listReverseIterator
{
public:

	typedef typename iterator::value_type		value_type;
	typedef typename iterator::reference		reference;
	typedef typename iterator::const_reference	const_reference;
	typedef typename iterator::pointer			pointer;
	typedef typename iterator::const_pointer	const_pointer;
	typedef typename iterator::difference_type	difference_type;

	listReverseIterator(void) {};
	listReverseIterator(pointer ptr) { _ptr = ptr; };
	listReverseIterator(const listIterator<value_type> &src) { _ptr = src.operator->(); };
	listReverseIterator(const listReverseIterator &src) { _ptr = src._ptr; };

	virtual ~listReverseIterator() {};

	listReverseIterator &operator=(listReverseIterator const &src)
	{
		_ptr = src._ptr;
		return (*this);
	};

	listReverseIterator operator ++() { _ptr = _ptr->get_prev(); return (*this); };	// ++a
	listReverseIterator operator --() { _ptr = _ptr->get_next(); return (*this); };	// --a

	bool operator ==(listReverseIterator const& b) const { return (_ptr == b.operator->()); };
	bool operator !=(listReverseIterator const& b) const { return (_ptr != b.operator->()); };

	listReverseIterator operator ++(int)	// a++
	{
		listReverseIterator temp = *this;
		++(*this);
		return (temp);
	};

	listReverseIterator operator --(int)	// a--
	{
		listReverseIterator temp = *this;
		--(*this);
		return (temp);
	};

	reference operator *() { return (*(_ptr->get_elem())); };											// *a
	const_reference operator *() const { return (*(_ptr->get_elem())); };								// *a
	pointer operator ->() { return (_ptr); };											// a->b
	pointer operator ->() const { return (_ptr); };											// a->b

	static const bool input_iter = true;

private:

	pointer	_ptr;

};

template <typename iterator>
class	listConstReverseIterator
{
public:

	typedef typename iterator::value_type		value_type;
	typedef typename iterator::reference		reference;
	typedef typename iterator::const_reference	const_reference;
	typedef typename iterator::pointer			pointer;
	typedef typename iterator::const_pointer	const_pointer;
	typedef typename iterator::difference_type	difference_type;

	listConstReverseIterator(void) {};
	listConstReverseIterator(pointer ptr) { _ptr = ptr; };
	listConstReverseIterator(const listConstIterator<value_type> &src) { _ptr = src.operator->(); };
	listConstReverseIterator(const listReverseIterator<iterator> &src) { _ptr = src.operator->(); };
	listConstReverseIterator(const listConstReverseIterator &src) { _ptr = src.operator->(); };

	virtual ~listConstReverseIterator() {};

	listConstReverseIterator &operator=(listConstReverseIterator const &src)
	{
		_ptr = src._ptr;
		return (*this);
	};

	listConstReverseIterator operator ++() { _ptr = _ptr->get_prev(); return (*this); };	// ++a
	listConstReverseIterator operator --() { _ptr = _ptr->get_next(); return (*this); };	// --a

	bool operator ==(listConstReverseIterator const& b) const { return (_ptr == b.operator->()); };
	bool operator !=(listConstReverseIterator const& b) const { return (_ptr != b.operator->()); };

	listConstReverseIterator operator ++(int)	// a++
	{
		listConstReverseIterator temp = *this;
		++(*this);
		return (temp);
	};

	listConstReverseIterator operator --(int)	// a--
	{
		listConstReverseIterator temp = *this;
		--(*this);
		return (temp);
	};

	const_reference operator *() const { return (*(_ptr->get_elem())); };								// *a
	pointer operator ->() { return (_ptr); };											// a->b
	pointer operator ->() const { return (_ptr); };											// a->b

	static const bool input_iter = true;

private:

	pointer	_ptr;

};

template < class T, class Alloc = std::allocator<T> >
class	list
{
public:

	// TYPEDEFS
	typedef T											value_type;
	typedef Alloc										allocator_type;
	typedef typename std::size_t						size_type;
	typedef typename std::ptrdiff_t						difference_type;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;

	typedef typename ft::listIterator<T>							iterator;
	typedef typename ft::listConstIterator<T>						const_iterator;
	typedef typename ft::listReverseIterator<iterator>				reverse_iterator;
	typedef typename ft::listConstReverseIterator<iterator>			const_reverse_iterator;

	// CONSTRUCTORS AND DESTRUCTORS
	explicit list (const allocator_type& alloc = allocator_type())
	: _ptr(_new_sentinel()), _alloc(alloc), _size(0)
	{
		(void)alloc;
	};

	explicit list (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
	: _ptr(_new_sentinel()), _alloc(alloc), _size(0)
	{
		while (n)
		{
			this->push_back(val);
			n--;
		}
	};

	template <class InputIterator>
	list (InputIterator first, InputIterator last,
		const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<InputIterator::input_iter, InputIterator>::type = NULL)
		: _ptr(_new_sentinel()), _alloc(alloc), _size(0)
	{
		for (const_iterator it = first; it != last; it++)
			this->push_back(*it);
	};

	list (const list& x)
	: _ptr(_new_sentinel()), _size(0)
	{
		list<T> temp(x.begin(), x.end());

		*this = temp;
	};

	~list()
	{
		this->clear();
		delete _ptr;
	};

	// OPERATOR OVERLOADS
	list& operator= (list& x)
	{
		this->clear();
		for(iterator it = x.begin(); it != x.end(); it++)
			this->push_back(*it);
		return (*this);
	};

	// ITERATORS
	iterator begin() { return (iterator(_ptr->get_next())); }

	const_iterator begin() const { return (const_iterator(_ptr->get_next())); }

	iterator end() { return (iterator(_ptr)); }

	const_iterator end() const { return (const_iterator(_ptr)); }

	reverse_iterator rbegin() { return (reverse_iterator(--this->end())); };
	const_reverse_iterator rbegin() const { return (const_reverse_iterator(--this->end())); };

	reverse_iterator rend() { return (reverse_iterator(--this->begin())); };
	const_reverse_iterator rend() const { return (const_reverse_iterator(--this->begin())); };

	// CAPACITY
	bool empty() const { return (_size == 0); };

	size_type size() const { return (_size); };

	size_type max_size() const
	{
		return (std::numeric_limits<size_type>::max() / (sizeof(value_type)));
	};

	// ELEMENT ACCESS
	reference front()
	{
		return (*(_ptr->get_next()->get_elem()));
	};
	const_reference front() const
	{
		reference ref = front();
		return (ref);
	};

	reference back()
	{
		return (*(_ptr->get_prev()->get_elem()));
	};
	const_reference back() const
	{
		reference ref = back();
		return (ref);
	};

	void assign (size_type n, const value_type& val)
	{
		this->clear();
		list	replacement(n, val);

		*this = replacement;
	};

	template <class InputIterator>
	void assign (InputIterator first, InputIterator last,
	typename ft::enable_if<InputIterator::input_iter, InputIterator>::type = NULL)
	{
		this->clear();
		list	replacement(first, last);

		*this = replacement;
	};

	void push_back(const value_type& val)
	{
		Node<T>	*new_begin = _new_node(val);

		// new node preparation
		new_begin->set_next(_ptr);
		new_begin->set_prev(_ptr->get_prev());

		// left node modification (prev to sentinel)
		_ptr->get_prev()->set_next(new_begin);

		// right node modification (sentinel)
		_ptr->set_prev(new_begin);

		_size++;
	};

	void pop_back()
	{
		_del_node(_ptr->get_prev());
		_size--;
	};

	void push_front(const value_type& val)
	{
		Node<T>	*new_begin = _new_node(val);

		// new node preparation
		new_begin->set_next(_ptr->get_next()); //left - prev
		new_begin->set_prev(_ptr); //left - prev_

		// right node modification (next to sentinel)
		_ptr->get_next()->set_prev(new_begin);

		// left node modification (sentinel)
		_ptr->set_next(new_begin);
		_size++;
	};

	void pop_front()
	{
		_del_node(_ptr->get_next());
		_size--;
	};

	iterator insert (iterator position, const value_type& val)
	{
		Node<T>	*curr = position.operator->();
		Node<T>	*to_insert = _new_node(val);

		to_insert->set_next(curr);
		to_insert->set_prev(curr->get_prev());

		curr->get_prev()->set_next(to_insert);
		curr->set_prev(to_insert);

		_size++;
		return (--position);
	};

	void insert (iterator position, size_type n, const value_type& val)
	{
		while (n > 0)
		{
			insert(position, val);
			n--;
		}
	};

	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last,
	typename ft::enable_if<InputIterator::input_iter, InputIterator>::type = NULL)
	{
		while (first != last)
		{
			insert(position, *first);
			first++;
		}
	};

	iterator erase (iterator position)
	{
		_del_node(position.operator->());
		_size--;
		return (position);
	};

	iterator erase (iterator first, iterator last)
	{
		while (first != last)
			erase(first++);
		return (first);
	};

	void swap (list& x)
	{
		Node<T> *temp = _ptr;

		_ptr = x._ptr;
		x._ptr = temp;
	};

	void resize (size_type n, value_type val = value_type())
	{
		if (n < _size)
			while (_size != n)
				this->pop_back();
		else if (n > _size)
			while (_size != n)
				this->push_back(val);
	};

	void clear()
	{
		while (_size)
		{
			this->pop_back();
		}
	};

	// OPERATIONS
	void splice (iterator position, list& x, iterator i)
	{
		Node<T> *to_transfert = i.operator->();
		Node<T> *destination = position.operator->();

		if (to_transfert->is_sentinel())
			return ;

		// Remove Node from X
		to_transfert->get_prev()->set_next(to_transfert->get_next());
		to_transfert->get_next()->set_prev(to_transfert->get_prev());

		// Init node to new destination
		to_transfert->set_next(destination);
		to_transfert->set_prev(destination->get_prev());

		// Insert Node in current list
		destination->get_prev()->set_next(to_transfert);
		destination->set_prev(to_transfert);

		// Avoid Unused variable compilation error
		(void)x;

		_size++;
	};

	void splice (iterator position, list& x, iterator first, iterator last)
	{
		iterator temp = first;

		while (temp++ != last)
		{
			this->splice(position, x, first);
			first = temp;
		}
	};

	void splice (iterator position, list& x)
	{
		this->splice(position, x, x.begin(), x.end());
	};

	void remove (const value_type& val)
	{
		iterator next;

		for (iterator it = this->begin(); it != this->end(); it++)
		{
			if (*it == val)
			{
				next = ++it;
				erase(--it);
				it = --next;
			}
		}
	};

	template <class Predicate>
	void remove_if (Predicate pred)
	{
		iterator next;

		for (iterator it = this->begin(); it != this->end(); it++)
		{
			if (pred(*it))
			{
				next = ++it;
				erase(--it);
				it = --next;
			}
		}
	};

	void unique()
	{
		iterator curr = this->begin();
		iterator next = this->begin();

		next++;

		while (next != this->end())
		{
			if (*curr == *next)
				_del_node(curr.operator->());
			curr = next;
			next++;
		}
	};

	template <class BinaryPredicate>
	void unique (BinaryPredicate binary_pred)
	{
		iterator curr = this->begin();
		iterator next = this->begin();

		next++;
		while (next != this->end())
		{
			if (binary_pred(*next, *curr) == true)
			{
				this->erase(next);
				curr = this->begin();
				next = curr;
				next++;
			}
			else
			{
				curr = next;
				next++;
			}
		}
	};

	void sort() { this->sort(_default_comp); };

	template <class Compare>
	void sort (Compare comp)
	{
		iterator	it_curr = this->begin();
		iterator	it_next = this->begin();

		it_next++;
		while (it_next != this->end())
		{
			if (*it_curr != *it_next && comp(*it_curr, *it_next) == false)
			{
				this->splice(it_curr, *this, it_next);
				it_curr = this->begin();
				it_next = this->begin();
			}
			else
				it_curr = it_next;
			it_next++;
		}
	};

	void reverse()
	{
		Node<T>		*temp;
		Node<T>		*it_node;
		iterator	it = this->begin();

		while (it != this->end())
		{
			it_node = it.operator->();
			temp = it_node->get_prev();
			it_node->set_prev(it_node->get_next());
			it_node->set_next(temp);
			it--;
		}
		it_node = _ptr;
		temp = it_node->get_prev();
		it_node->set_prev(it_node->get_next());
		it_node->set_next(temp);
	};

	void merge (list& x) { merge(x, _default_comp); };

	template <class Compare>
	void merge (list& x, Compare comp)
	{
		iterator it_x = x.begin();
		iterator it_this = this->begin();

		while (it_x != x.end() && it_this != this->end())
		{
			if (comp(*it_x, *it_this))
				this->splice(it_this, x, it_x++);
			else
				it_this++;
		}
		while (it_x != x.end())
			this->splice(this->end(), x, it_x++);
	};

private:

	Node<T>	*_new_node(void)
	{
		Node<T> *new_node = new Node<T>;

		return (new_node);
	}

	Node<T>	*_new_node(const value_type& val)
	{
		Node<T> *new_node = new Node<T>(val);

		return (new_node);
	}

	Node<T>	*_new_sentinel(void)
	{
		Node<T> *sentinel = _new_node();

		sentinel->set_next(sentinel);
		sentinel->set_prev(sentinel);
		sentinel->set_ptr(SENTINEL_NODE);
		return (sentinel);
	}

	void	_del_node(Node<T> *node)
	{
		if (node->is_sentinel() == false)
		{
			node->get_prev()->set_next(node->get_next());
			node->get_next()->set_prev(node->get_prev());

			delete node;
		}
	}

	void	_recount(void)
	{
		size_t size = 0;

		for	(iterator it = this->begin(); it != this->end(); it++)
			size++;
		_size = size;
	}

	static bool	_default_comp(T &lvalue, T &rvalue) { return (lvalue < rvalue); };

	Node<T>					*_ptr;
	allocator_type			_alloc;
	size_t					_size;

};

template < class T >
std::ostream& operator <<(std::ostream& s, ft::list<T>& lst) 
{
	s << "{ ";
	for (typename list<T>::const_iterator it = lst.begin(); it != lst.end(); it++)
		s << *it << " ";
	s << "}";
	return s;
}

template <class T, class Alloc>
bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	typename ft::list<T>::const_iterator	it_lhs = lhs.begin();
	typename ft::list<T>::const_iterator	it_rhs = rhs.begin();

	if (lhs.size() != rhs.size())
		return (false);
	while (it_lhs != lhs.end() && it_rhs != rhs.end() &&
			*it_lhs == *it_rhs)
	{
		it_lhs++;
		it_rhs++;
	}
	return (it_lhs == lhs.end() && it_rhs == rhs.end());
};

template <class T, class Alloc>
bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	return (!(lhs == rhs));
};

template <class T, class Alloc>
bool operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	typename ft::list<T>::const_iterator	it_lhs = lhs.begin();
	typename ft::list<T>::const_iterator	it_rhs = rhs.begin();

	if (lhs == rhs)
		return (false);
	while (it_lhs != lhs.end() && it_rhs != rhs.end() &&
			*it_lhs == *it_rhs)
	{
		it_lhs++;
		it_rhs++;
	}
	if (it_rhs != rhs.end())
		return (true);
	return (false);
};

template <class T, class Alloc>
bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return (true);
	return (lhs < rhs);
};

template <class T, class Alloc>
bool operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return (false);
	return (!(lhs < rhs));
};

template <class T, class Alloc>
bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
{
	if (lhs == rhs)
		return (true);
	return (!(lhs < rhs));
};

template <class T, class Alloc>
void swap (list<T,Alloc>& x, list<T,Alloc>& y) { x.swap(y); };

}

#endif

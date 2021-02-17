/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 09:48:49 by jecaudal          #+#    #+#             */
/*   Updated: 2021/02/17 12:19:01 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <map>
# include <limits>
# include <memory>
# include <utility>
# include <cstddef>
# include <iostream>
# include "../utils.hpp"

// Debug
# include <stdio.h>

namespace ft
{

template <typename Tkey, typename Tvalue>
class pair
{
public:

	pair(void) {};

	template<class U, class V>
	pair (const pair<U,V>& pr)
	{
		this->first = pr.first;
		this->second = pr.second;
	};

	pair (const Tkey& a, const Tvalue& b)
	: first(a), second(b)
	{};

	~pair() {};

	pair &operator=(pair const &src)
	{
		this->first = src.first;
		this->second = src.second;

		return (*this);
	};

	Tkey first;
	Tvalue second;
};

template <class Tkey, class Tvalue>
bool operator== (const pair<Tkey,Tvalue>& lhs, const pair<Tkey,Tvalue>& rhs)
{
	return (lhs.first == rhs.first && lhs.second == lhs.second);
};

template <class Tkey, class Tvalue>
bool operator!= (const pair<Tkey,Tvalue>& lhs, const pair<Tkey,Tvalue>& rhs)
{
	return (!(lhs == rhs));
};

template <typename Tkey, typename Tvalue>
std::ostream	&operator<<(std::ostream &o, pair<Tkey, Tvalue> const &i)
{
	std::cout << \
	"key = " << i.first << ", value = " << i.second << " ";
	return (o);
};

template <typename Tkey, typename Tvalue>
class	MapNode
{
public:

	typedef MapNode<Tkey, Tvalue>	node;
	typedef node *					node_ptr;
	typedef const node *			const_node_ptr;

	typedef ft::pair<Tkey, Tvalue>	value_type;
	typedef value_type				pair;

	MapNode(void)
	: _empty(false), _top(NULL), _left(NULL), _right(NULL)
	{};

	MapNode(value_type const &pair)
	: _empty(false), _keyval(pair), _top(NULL), _left(NULL), _right(NULL)
	{};

	MapNode(MapNode const &src) { *this = src; };

	MapNode &operator=(MapNode const &src)
	{
		_keyval = src._keyval;
		_top = src._top;
		_left = src._left;
		_right = src._right;

		return (*this);
	};

	virtual ~MapNode() { };

	void	set_top(const node_ptr node)	{ _top = node; };
	void	set_left(const node_ptr node)	{ _left = node; };
	void	set_right(const node_ptr node)	{ _right = node; };

	const_node_ptr	get_curr(void) const  { return (this); };
	node_ptr	get_top(void) const   { return (_top); };
	node_ptr	get_left(void) const  { return (_left); };
	node_ptr	get_right(void) const { return (_right); };

	void	set_key(const Tkey &key)		{ _keyval.first = key; };
	void	set_val(const Tvalue &val)		{ _keyval.second = val; };
	void	set_pair(const value_type &val)	{ *_keyval = val; };

	Tkey	&get_key(void) { return (_keyval.first); };
	Tkey const	&get_key(void) const { return (_keyval.first); };
	Tvalue	&get_val(void) { return (_keyval.second); };
	pair	&get_pair(void) { return (_keyval); };
	pair const	&get_pair(void) const { return (_keyval); };

private:

	bool		_empty;
	pair		_keyval;
	node_ptr	_top;
	node_ptr	_left;
	node_ptr	_right;
};

template <typename Tkey, typename Tvalue>
std::ostream	&operator<<(std::ostream &o, MapNode<Tkey, Tvalue> const &i)
{
	std::cout << \
	"curr = " << i.get_curr() << std::endl << \
	"_top = " << i.get_top() << std::endl << \
	"_left = " << i.get_left() << std::endl << \
	"_right = " << i.get_right() << std::endl << \
	"_keyval : " << std::endl << i.get_pair();
	return (o);
};

template <typename Tkey, typename Tvalue, class Compare = std::less<Tkey> >
class	mapIterator
{
public:

	/*
	**	CUSTOM TRAITS
	*/
	typedef MapNode<Tkey, Tvalue>	node;
	typedef node *					node_ptr;
	typedef ft::pair<const Tkey, Tvalue>	pair;

	/*
	**	GENERAL TRAITS
	*/
	typedef Tkey	key_type;
	typedef Tvalue	mapped_type;

	typedef ft::pair<key_type, mapped_type>	value_type;

	typedef Compare	key_compare;

	typedef value_type &	reference;
	typedef const reference	const_reference;
	typedef value_type *	pointer;
	typedef const pointer	const_pointer;

	mapIterator(void)
	: _is_ghost(false)
	{};

	mapIterator(node_ptr ptr)
	: _is_ghost(false)
	{ _ptr = ptr; };

	mapIterator(const mapIterator &src)
	: _is_ghost(src.get_is_ghost())
	{
		if (this->get_is_ghost() == true)
			_ptr = new node(*(src.get_ptr()));
		else
			_ptr = src._ptr;
	};

	virtual ~mapIterator()
	{
		if (_is_ghost == true)
			delete _ptr;
	};

	mapIterator &operator=(mapIterator const &src)
	{
		if (_is_ghost == true) // past-the-end managment
			delete _ptr;
		_ptr = src._ptr;
		return (*this);
	};

	mapIterator operator ++()
	{
		if (is_the_last_leaf() == true) // past-the-end managment
		{
			node_ptr ghost_node = new node();

			ghost_node->set_top(_ptr);
			set_is_ghost(true);
			_ptr = ghost_node;
			return (*this);
		}
		if (_ptr->get_right())
		{
			_ptr = _ptr->get_right();
			go_leftmost();
		}
		else
		{
			while (_ptr->get_top() && _ptr->get_top()->get_left() != _ptr)
				_ptr = _ptr->get_top();
			if (_ptr->get_top()->get_left() == _ptr)
				_ptr = _ptr->get_top();
		}
		return (*this);
	};	// ++a

	mapIterator operator --()
	{
		if (_is_ghost == true) // past-the-end managment
		{
			node_ptr	cache_top = _ptr->get_top();

			delete _ptr;
			set_is_ghost(false);
			_ptr = cache_top;
			return (*this);
		}
		if (_ptr->get_left())
		{
			_ptr = _ptr->get_left();
			go_rightmost();
		}
		else
		{
			while (_ptr->get_top() && _ptr->get_top()->get_right() != _ptr)
				_ptr = _ptr->get_top();
			if (_ptr->get_top()->get_right() == _ptr)
				_ptr = _ptr->get_top();
		}
		return (*this);
	};	// --a

	bool operator ==(mapIterator const& b) const
	{
		key_type	&lhs = _ptr->get_key();
		key_type	&rhs = (*b).first;

		if (this->_is_ghost == true && b._is_ghost == true)
		{
			return (true);
		}
		else if (this->_is_ghost == true || b._is_ghost == true)
		{
			return (false);
		}
		return (lhs == rhs);
	};

	bool operator !=(mapIterator const& b) const { return (!(*this == b)); };

	mapIterator operator ++(int)	// a++
	{
		mapIterator temp = *this;
		++(*this);
		return (temp);
	};

	mapIterator operator --(int)	// a--
	{
		mapIterator temp = *this;
		--(*this);
		return (temp);
	};

	reference operator *() { return (_ptr->get_pair()); };											// *a
	const_reference operator *() const { return (_ptr->get_pair()); };								// *a
	pointer operator ->() { return (&(_ptr->get_pair())); };											// a->b
	pointer operator ->() const { return (&(_ptr->get_pair())); };											// a->b

	static const bool input_iter = true;

	void	go_rightmost(void)
	{
		while (_ptr->get_right())
			_ptr = _ptr->get_right();
	}

	void	go_leftmost(void)
	{
		while (_ptr->get_left())
			_ptr = _ptr->get_left();
	}

	bool	is_the_last_leaf(void)
	{
		node_ptr road_to_root = _ptr;

		if (road_to_root->get_right())
			return (false);
		while (road_to_root->get_top() &&
			   road_to_root->get_top()->get_right() == road_to_root)
			road_to_root = road_to_root->get_top();

		return (road_to_root->get_top() == NULL);
	}

	void	set_is_ghost(bool b) { _is_ghost = b; }

	node_ptr	get_ptr(void) const { return (_ptr); };

	bool		get_is_ghost(void) const { return (_is_ghost); };

private:

	/*
	**	ghost iterator is the past-the-end iterator.
	**	This boolean is for memory managment, if the iterator go out of this
	**	node, it have to free the node stored.
	*/
	bool		_is_ghost;
	node_ptr	_ptr;

};

template <typename Tkey, typename Tvalue, class Compare = std::less<Tkey> >
class	mapConstIterator
{
public:

	/*
	**	CUSTOM TRAITS
	*/
	typedef MapNode<Tkey, Tvalue>			node;
	typedef node *					node_ptr;
	typedef ft::pair<const Tkey, Tvalue>	pair;

	/*
	**	GENERAL TRAITS
	*/
	typedef Tkey	key_type;
	typedef Tvalue	mapped_type;

	typedef ft::pair<key_type, mapped_type>	value_type;

	typedef Compare	key_compare;

	typedef value_type &		reference;
	typedef value_type const &	const_reference;
	typedef value_type *		pointer;
	typedef const pointer		const_pointer;

	mapConstIterator(void)
	: _is_ghost(false)
	{};

	mapConstIterator(node_ptr ptr)
	: _is_ghost(false)
	{ _ptr = ptr; };

	mapConstIterator(const mapIterator<Tkey, Tvalue, Compare> &src)
	: _is_ghost(src.get_is_ghost())
	{ 
		if (this->get_is_ghost() == true)
			_ptr = new node(*(src.get_ptr()));
		else
			_ptr = src.get_ptr();
	};

	mapConstIterator(const mapConstIterator &src)
	: _is_ghost(src.get_is_ghost())
	{
		if (this->get_is_ghost() == true)
			_ptr = new node(*(src.get_ptr()));
		else
			_ptr = src._ptr;
	};

	virtual ~mapConstIterator()
	{
		if (_is_ghost == true)
			delete _ptr;
	};

	mapConstIterator &operator=(mapConstIterator const &src)
	{
		if (_is_ghost == true) // past-the-end managment
			delete _ptr;
		_ptr = src._ptr;
		return (*this);
	};

	mapConstIterator operator ++()
	{
		if (is_the_last_leaf() == true) // past-the-end managment
		{
			node_ptr ghost_node = new node();

			ghost_node->set_top(_ptr);
			set_is_ghost(true);
			_ptr = ghost_node;
			return (*this);
		}
		if (_ptr->get_right())
		{
			_ptr = _ptr->get_right();
			go_leftmost();
		}
		else
		{
			while (_ptr->get_top() && _ptr->get_top()->get_left() != _ptr)
				_ptr = _ptr->get_top();
			if (_ptr->get_top()->get_left() == _ptr)
				_ptr = _ptr->get_top();
		}
		return (*this);
	};	// ++a

	mapConstIterator operator --()
	{
		if (_is_ghost == true) // past-the-end managment
		{
			node_ptr	cache_top = _ptr->get_top();

			delete _ptr;
			set_is_ghost(false);
			_ptr = cache_top;
			return (*this);
		}
		if (_ptr->get_left())
		{
			_ptr = _ptr->get_left();
			go_rightmost();
		}
		else
		{
			while (_ptr->get_top() && _ptr->get_top()->get_right() != _ptr)
				_ptr = _ptr->get_top();
			if (_ptr->get_top()->get_right() == _ptr)
				_ptr = _ptr->get_top();
		}
		return (*this);
	};	// --a

	bool operator ==(mapConstIterator const& b) const
	{
		const key_type	&lhs = _ptr->get_key();
		const key_type	&rhs = (*b).first;

		if (this->_is_ghost == true && b._is_ghost == true)
		{
			return (true);
		}
		else if (this->_is_ghost == true || b._is_ghost == true)
		{
			return (false);
		}
		return (lhs == rhs);
	};

	bool operator !=(mapConstIterator const& b) const { return (!(*this == b)); };

	mapConstIterator operator ++(int)	// a++
	{
		mapConstIterator temp = *this;
		++(*this);
		return (temp);
	};

	mapConstIterator operator --(int)	// a--
	{
		mapConstIterator temp = *this;
		--(*this);
		return (temp);
	};

	const_reference operator *() const { return (_ptr->get_pair()); };								// *a
	pointer operator ->() const { return (&(_ptr->get_pair())); };											// a->b

	static const bool input_iter = true;

	void	go_rightmost(void)
	{
		while (_ptr->get_right())
			_ptr = _ptr->get_right();
	}

	void	go_leftmost(void)
	{
		while (_ptr->get_left())
			_ptr = _ptr->get_left();
	}

	bool	is_the_last_leaf(void)
	{
		node_ptr road_to_root = _ptr;

		if (road_to_root->get_right())
			return (false);
		while (road_to_root->get_top() &&
			   road_to_root->get_top()->get_right() == road_to_root)
			road_to_root = road_to_root->get_top();

		return (road_to_root->get_top() == NULL);
	}

	void	set_is_ghost(bool b) { _is_ghost = b; }

	node_ptr	get_ptr(void) const { return (_ptr); };

	bool		get_is_ghost(void) const { return (_is_ghost); };

private:

	/*
	**	ghost iterator is the past-the-end iterator.
	**	This boolean is for memory managment, if the iterator go out of this
	**	node, it have to free the node stored.
	*/
	bool		_is_ghost;
	node_ptr	_ptr;

};

template <typename Tkey, typename Tvalue, class Compare = std::less<Tkey> >
class	mapReverseIterator
{
public:

	/*
	**	CUSTOM TRAITS
	*/
	typedef MapNode<Tkey, Tvalue>	node;
	typedef node *					node_ptr;
	typedef ft::pair<const Tkey, Tvalue>	pair;

	/*
	**	GENERAL TRAITS
	*/
	typedef Tkey	key_type;
	typedef Tvalue	mapped_type;

	typedef ft::pair<key_type, mapped_type>	value_type;

	typedef Compare	key_compare;

	typedef value_type &	reference;
	typedef const reference	const_reference;
	typedef value_type *	pointer;
	typedef const pointer	const_pointer;

	mapReverseIterator(void)
	: _is_ghost(false)
	{};

	mapReverseIterator(node_ptr ptr)
	: _is_ghost(false)
	{ _ptr = ptr; };

	mapReverseIterator(const mapIterator<Tkey, Tvalue, Compare> &src)
	: _is_ghost(src.get_is_ghost())
	{
		if (this->get_is_ghost() == true)
			_ptr = new node(*(src.get_ptr()));
		else
			_ptr = src.get_ptr();
	};

	mapReverseIterator(const mapReverseIterator &src)
	: _is_ghost(src.get_is_ghost())
	{
		if (this->get_is_ghost() == true)
			_ptr = new node(*(src.get_ptr()));
		else
			_ptr = src._ptr;
	};

	virtual ~mapReverseIterator()
	{
		if (_is_ghost == true)
			delete _ptr;
	};

	mapReverseIterator &operator=(mapReverseIterator const &src)
	{
		if (_is_ghost == true) // past-the-end managment
			delete _ptr;
		_ptr = src._ptr;
		return (*this);
	};

	mapReverseIterator operator ++()
	{
		if (is_the_last_leaf() == true) // past-the-end managment
		{
			node_ptr ghost_node = new node();

			ghost_node->set_top(_ptr);
			set_is_ghost(true);
			_ptr = ghost_node;
			return (*this);
		}
		if (_ptr->get_left())
		{
			_ptr = _ptr->get_left();
			go_rightmost();
		}
		else
		{
			while (_ptr->get_top() && _ptr->get_top()->get_right() != _ptr)
				_ptr = _ptr->get_top();
			if (_ptr->get_top()->get_right() == _ptr)
				_ptr = _ptr->get_top();
		}
		return (*this);
	};	// ++a

	mapReverseIterator operator --()
	{
		if (_is_ghost == true) // past-the-end managment
		{
			node_ptr	cache_top = _ptr->get_top();

			delete _ptr;
			set_is_ghost(false);
			_ptr = cache_top;
			return (*this);
		}
		if (_ptr->get_right())
		{
			_ptr = _ptr->get_right();
			go_leftmost();
		}
		else
		{
			while (_ptr->get_top() && _ptr->get_top()->get_left() != _ptr)
				_ptr = _ptr->get_top();
			if (_ptr->get_top()->get_left() == _ptr)
				_ptr = _ptr->get_top();
		}
		return (*this);
	};	// --a

	bool operator ==(mapReverseIterator const& b) const
	{
		key_type	&lhs = _ptr->get_key();
		key_type	&rhs = (*b).first;

		if (this->_is_ghost == true && b._is_ghost == true)
		{
			return (true);
		}
		else if (this->_is_ghost == true || b._is_ghost == true)
		{
			return (false);
		}
		return (lhs == rhs);
	};

	bool operator !=(mapReverseIterator const& b) const { return (!(*this == b)); };

	mapReverseIterator operator ++(int)	// a++
	{
		mapReverseIterator temp = *this;
		++(*this);
		return (temp);
	};

	mapReverseIterator operator --(int)	// a--
	{
		mapReverseIterator temp = *this;
		--(*this);
		return (temp);
	};

	reference operator *() { return (_ptr->get_pair()); };											// *a
	const_reference operator *() const { return (_ptr->get_pair()); };								// *a
	pointer operator ->() { return (&(_ptr->get_pair())); };											// a->b
	pointer operator ->() const { return (&(_ptr->get_pair())); };											// a->b

	static const bool input_iter = true;

	void	go_rightmost(void)
	{
		while (_ptr->get_right())
			_ptr = _ptr->get_right();
	}

	void	go_leftmost(void)
	{
		while (_ptr->get_left())
			_ptr = _ptr->get_left();
	}

	bool	is_the_last_leaf(void)
	{
		node_ptr road_to_root = _ptr;

		if (road_to_root->get_left())
			return (false);
		while (road_to_root->get_top() &&
			   road_to_root->get_top()->get_left() == road_to_root)
			road_to_root = road_to_root->get_top();

		return (road_to_root->get_top() == NULL);
	}

	void	set_is_ghost(bool b) { _is_ghost = b; }

	node_ptr	get_ptr(void) const { return (_ptr); };

	bool		get_is_ghost(void) const { return (_is_ghost); };

private:

	/*
	**	ghost iterator is the past-the-end iterator.
	**	This boolean is for memory managment, if the iterator go out of this
	**	node, it have to free the node stored.
	*/
	bool		_is_ghost;
	node_ptr	_ptr;

};

template <typename Tkey, typename Tvalue, class Compare = std::less<Tkey> >
class	mapConstReverseIterator
{
public:

	/*
	**	CUSTOM TRAITS
	*/
	typedef MapNode<Tkey, Tvalue>	node;
	typedef node *					node_ptr;
	typedef ft::pair<const Tkey, Tvalue>	pair;

	/*
	**	GENERAL TRAITS
	*/
	typedef Tkey	key_type;
	typedef Tvalue	mapped_type;

	typedef ft::pair<key_type, mapped_type>	value_type;

	typedef Compare	key_compare;

	typedef value_type &	reference;
	typedef const value_type &	const_reference;
	typedef value_type *	pointer;
	typedef const pointer	const_pointer;

	mapConstReverseIterator(void)
	: _is_ghost(false)
	{};

	mapConstReverseIterator(node_ptr ptr)
	: _is_ghost(false)
	{ _ptr = ptr; };

	mapConstReverseIterator(const mapIterator<Tkey, Tvalue, Compare> &src)
	: _is_ghost(src.get_is_ghost())
	{
		if (this->get_is_ghost() == true)
			_ptr = new node(*(src.get_ptr()));
		else
			_ptr = src.get_ptr();
	};

	mapConstReverseIterator(const mapReverseIterator<Tkey, Tvalue, Compare> &src)
	: _is_ghost(src.get_is_ghost())
	{
		if (this->get_is_ghost() == true)
			_ptr = new node(*(src.get_ptr()));
		else
			_ptr = src.get_ptr();
	};

	mapConstReverseIterator(const mapConstReverseIterator &src)
	: _is_ghost(src.get_is_ghost())
	{
		if (this->get_is_ghost() == true)
			_ptr = new node(*(src.get_ptr()));
		else
			_ptr = src._ptr;
	};

	virtual ~mapConstReverseIterator()
	{
		if (_is_ghost == true)
			delete _ptr;
	};

	mapConstReverseIterator &operator=(mapConstReverseIterator const &src)
	{
		if (_is_ghost == true) // past-the-end managment
			delete _ptr;
		_ptr = src._ptr;
		return (*this);
	};

	mapConstReverseIterator operator ++()
	{
		if (is_the_last_leaf() == true) // past-the-end managment
		{
			node_ptr ghost_node = new node();

			ghost_node->set_top(_ptr);
			set_is_ghost(true);
			_ptr = ghost_node;
			return (*this);
		}
		if (_ptr->get_left())
		{
			_ptr = _ptr->get_left();
			go_rightmost();
		}
		else
		{
			while (_ptr->get_top() && _ptr->get_top()->get_right() != _ptr)
				_ptr = _ptr->get_top();
			if (_ptr->get_top()->get_right() == _ptr)
				_ptr = _ptr->get_top();
		}
		return (*this);
	};	// ++a

	mapConstReverseIterator operator --()
	{
		if (_is_ghost == true) // past-the-end managment
		{
			node_ptr	cache_top = _ptr->get_top();

			delete _ptr;
			set_is_ghost(false);
			_ptr = cache_top;
			return (*this);
		}
		if (_ptr->get_right())
		{
			_ptr = _ptr->get_right();
			go_leftmost();
		}
		else
		{
			while (_ptr->get_top() && _ptr->get_top()->get_left() != _ptr)
				_ptr = _ptr->get_top();
			if (_ptr->get_top()->get_left() == _ptr)
				_ptr = _ptr->get_top();
		}
		return (*this);
	};	// --a

	bool operator ==(mapConstReverseIterator const& b) const
	{
		key_type	&lhs = _ptr->get_key();
		key_type	&rhs = (*b).first;

		if (this->_is_ghost == true && b._is_ghost == true)
		{
			return (true);
		}
		else if (this->_is_ghost == true || b._is_ghost == true)
		{
			return (false);
		}
		return (lhs == rhs);
	};

	bool operator !=(mapConstReverseIterator const& b) const { return (!(*this == b)); };

	mapConstReverseIterator operator ++(int)	// a++
	{
		mapConstReverseIterator temp = *this;
		++(*this);
		return (temp);
	};

	mapConstReverseIterator operator --(int)	// a--
	{
		mapConstReverseIterator temp = *this;
		--(*this);
		return (temp);
	};

	const_reference operator *() const { return (_ptr->get_pair()); };								// *a
	pointer operator ->() const { return (&(_ptr->get_pair())); };											// a->b

	static const bool input_iter = true;

	void	go_rightmost(void)
	{
		while (_ptr->get_right())
			_ptr = _ptr->get_right();
	}

	void	go_leftmost(void)
	{
		while (_ptr->get_left())
			_ptr = _ptr->get_left();
	}

	bool	is_the_last_leaf(void)
	{
		node_ptr road_to_root = _ptr;

		if (road_to_root->get_left())
			return (false);
		while (road_to_root->get_top() &&
			   road_to_root->get_top()->get_left() == road_to_root)
			road_to_root = road_to_root->get_top();

		return (road_to_root->get_top() == NULL);
	}

	void	set_is_ghost(bool b) { _is_ghost = b; }

	node_ptr	get_ptr(void) const { return (_ptr); };

	bool		get_is_ghost(void) const { return (_is_ghost); };

private:

	/*
	**	ghost iterator is the past-the-end iterator.
	**	This boolean is for memory managment, if the iterator go out of this
	**	node, it have to free the node stored.
	*/
	bool		_is_ghost;
	node_ptr	_ptr;

};

template < class Tkey,                                     // map::key_type
           class Tvalue,                                       // map::mapped_type
           class Compare = std::less<Tkey>,                     // map::key_compare
           class Alloc = std::allocator<pair<const Tkey,Tvalue> >    // map::allocator_type
           >
class	map
{
public:

	/*
	**	CUSTOM TRAITS
	*/
	typedef MapNode<Tkey, Tvalue>	node;
	typedef node *					node_ptr;

	/*
	**	GENERAL TRAITS
	*/
	typedef Tkey	key_type;
	typedef Tvalue	mapped_type;

	typedef ft::pair<key_type, mapped_type>	value_type;

	typedef Compare	key_compare;

	typedef std::allocator<value_type>	allocator_type;

	typedef value_type &	reference;
	typedef const reference	const_reference;
	typedef value_type *	pointer;
	typedef const pointer	const_pointer;

	typedef mapIterator<Tkey, Tvalue, Compare>			iterator;
	typedef mapConstIterator<Tkey, Tvalue, Compare>		const_iterator;
	typedef mapReverseIterator<Tkey, Tvalue, Compare>	reverse_iterator;
	typedef mapConstReverseIterator<Tkey, Tvalue, Compare>	const_reverse_iterator;

	typedef size_t		size_type;
	typedef ptrdiff_t	difference_type;

	explicit map (const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type())
	: _size(0), _root(NULL), _comp(comp), _alloc(alloc)
	{};

	template <class InputIterator>
	map (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<InputIterator::input_iter, InputIterator>::type = NULL)
		: _size(0), _root(NULL), _comp(comp), _alloc(alloc)
		{
			this->insert(first, last);
		};

	map (const map& x)
	: _size(0), _root(NULL), _comp(Compare()), _alloc(allocator_type())
	{
		*this = x;
	}

	map &operator=(map const &src)
	{
		this->clear();
		if (src.size() > 0)
			this->insert(src.begin(), src.end());
		return (*this);
	};

	virtual ~map() { this->clear(); };

	mapped_type& operator[] (const key_type& k)
	{
		node_ptr	target_position = _find_node(k);

		if (_root == NULL)
		{
			value_type	new_root(value_type(k, mapped_type()));
			_size++;
			_root = _new_node(new_root);
			return (_root->get_val());
		}
		else if (target_position->get_key() != k)
		{
			value_type	new_pair(value_type(k, mapped_type()));
			_size++;
			return (_assign_pair_node(target_position, new_pair));
		}
		return (target_position->get_val());
	};

	pair<iterator,bool>	insert (const value_type& val)
	{
		if (this->size() > 0 &&
			_find_node(val.first)->get_pair() == val)
			return (pair<iterator, bool>(this->end(), false));

		(*this)[val.first] = val.second;

		iterator new_node(_root);
		while (*new_node != val && new_node != this->end())
			new_node++;

		return (pair<iterator, bool>(new_node, true));
	};

	iterator insert (iterator position, const value_type& val)
	{
		if (this->size() > 0 &&
			_find_node(val.first)->get_pair() == val) // Element already exist case
		{
			iterator	it = this->begin();

			while (*it != val && it != this->end())
				it++;
			return (it);
		}

		node_ptr	pos_node;

		while (position != this->end() &&
			   _comp((*position).first, val.first) == true) // find the strict previous elem
			position++;

		if (position != this->end() &&
			_comp((*position).first, val.first) == true) // insert if previous elem found
		{
			node_ptr new_node = new node(val);

			pos_node = position.get_ptr();

			if (pos_node->get_right())
			{
				pos_node = pos_node->get_right();
				while (pos_node->get_left())
					pos_node = pos_node->get_left();
				pos_node->set_left(new_node);
			}
			else
				pos_node->set_right(new_node);
			new_node->set_top(pos_node);
			_size++;
		}
		else
			return ((this->insert(val)).first);

		return (iterator(pos_node));
	};

	template <class InputIterator>
	void insert (InputIterator first, InputIterator last,
	typename ft::enable_if<InputIterator::input_iter, InputIterator>::type = NULL)
	{
		while (first != last)
		{
			this->insert(*first);
			first++;
		}
	};

	bool empty() const { return (_size == 0); };

	size_type size() const { return (_size); };

	size_type max_size() const
	{
		return (std::numeric_limits<size_type>::max() / (sizeof(value_type)));
	};

	iterator begin()
	{
		iterator temp(_root);

		temp.go_leftmost();
		return (temp);
	};

	const_iterator begin() const
	{
		const_iterator temp(_root);

		temp.go_leftmost();
		return (temp);
	};

	/*
	**	End will stored a ghost node that have for top pointer the rightmost
	**	element.
	*/
	iterator end() { return (_get_fake_ite()); };
	const_iterator end() const
	{
		iterator i(_get_fake_ite());
		const_iterator ci(i);

		return (ci);
	};

	reverse_iterator rbegin() { return (reverse_iterator(--this->end())); };
	const_reverse_iterator rbegin() const { return (this->rbegin()); };

	reverse_iterator rend() { return (reverse_iterator(_get_fake_rev_ite())); };
	const_reverse_iterator rend() const { return (rend()); };

	size_type erase (const key_type& k)
	{
		node_ptr	node_k = _find_node(k);

		node_ptr	new_root;

		if (node_k != NULL && node_k->get_key() != k)
			return (0);

		_size--;
		if (node_k->get_left() == NULL && node_k->get_right() == NULL)
			new_root = _delete_leaf(node_k);
		else if (node_k->get_left() == NULL || node_k->get_right() == NULL)
			new_root = _delete_branch_one_child(node_k);
		else
			new_root = _delete_branch_two_child(node_k);

		if (new_root != NULL && new_root->get_top() == NULL)
			_root = new_root;
		return (1);
	};

	template <class InputIterator>
	void erase (InputIterator position,
	typename ft::enable_if<InputIterator::input_iter, InputIterator>::type = NULL)
	{
		InputIterator	next = position;

		next++;
		erase(position, next);
	};

	template <class InputIterator>
	void erase (InputIterator first, InputIterator last,
	typename ft::enable_if<InputIterator::input_iter, InputIterator>::type = NULL)
	{
		InputIterator prev = first;

		while (first != last)
		{
			first++;
			this->erase((*prev).first);
			prev = first;
		}
	};

	void swap (map& x)
	{
		size_t		x_size = x._size;
		node_ptr	x_root = x._root;

		x._root = _root;
		x._size = _size;

		_root = x_root;
		_size = x_size;
	};

	void clear()
	{
		if (this->size() > 0)
			this->erase(this->begin(), this->end());
		_root = NULL;
	};

	key_compare key_comp() const { return (key_compare()); };

	class	value_compare
	{
	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;

		Compare comp;

		value_compare(Compare c) : comp(c) {};
		virtual ~value_compare() {};

		bool operator() (const value_type& x, const value_type& y) const
		{
			return (comp(x.first, y.first));
		}

	};

	value_compare value_comp() const { return (value_compare(Compare())); };

	iterator find (const key_type& k)
	{
		if (_find_node(k) != NULL && _find_node(k)->get_key() != k)
			return (this->end());
		else
			return (iterator(_find_node(k)));
	};

	const_iterator find (const key_type& k) const
	{
		if (_find_node(k) != NULL && _find_node(k)->get_key() != k)
			return (this->end());
		else
			return (const_iterator(_find_node(k)));
	};

	size_type count (const key_type& k) const
	{
		return ( find(k) != this->end() );
	};

	iterator lower_bound (const key_type& k)
	{
		iterator it = this->begin();

		while ( _comp((*it).first, k) == true &&
				it != this->end() )
		{
			it++;
		}
		return (it);
	};

	const_iterator lower_bound (const key_type& k) const
	{
		return (lower_bound(k));
	};

	iterator upper_bound (const key_type& k)
	{
		iterator it = this->begin();

		while ( _comp((*it).first, k) == true &&
				it != this->end() )
		{
			it++;
		}

		if (it == this->end())
			return (this->end());

		if (it != this->begin())
			it++;

		return (it);
	};

	const_iterator upper_bound (const key_type& k) const
	{
		return (upper_bound(k));
	};

	pair<iterator,iterator>				equal_range (const key_type& k)
	{
		return (ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
	};

	pair<const_iterator,const_iterator> equal_range (const key_type& k) const
	{
		return (ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
	};

private:

	void	print(void) const
	{
		std::cout << *_root << std::endl;
		if (_root->get_left())
			print(_root->get_left());
		if (_root->get_right())
			print(_root->get_right());
	}

	void	print(node_ptr ptr) const
	{
		std::cout << "------------------" << std::endl;
		std::cout << *ptr << std::endl;
		if (ptr->get_left())
			print(ptr->get_left());
		if (ptr->get_right())
			print(ptr->get_right());
		std::cout << "------------------" << std::endl;
	}

	/*
	**	Create and alloc nodes easily
	*/
	node_ptr	_new_node(void) const
	{
		node_ptr	new_node = new node();

		return (new_node);
	}

	node_ptr	_new_node(value_type &val) const
	{
		node_ptr	new_node = new node(val);

		return (new_node);
	}

	/*
	**	Return the node that have val for key. If no node found, return NULL.
	*/
	node_ptr	_find_node(const key_type &val) const
	{
		node_ptr temp = _root;

		while (temp != NULL && temp->get_key() != val)
		{
			if (_comp(val, temp->get_key()) == true)
			{
				if (temp->get_left() != NULL)
					temp = temp->get_left();
				else
					break;
			}
			else
			{
				if (temp->get_right() != NULL)
					temp = temp->get_right();
				else
					break;
			}
		}
		return (temp);
	}

	/*
	**	Function that assign val to a leaf and attach it to the gived node.
	*/
	mapped_type	&_assign_pair_node(node_ptr node, value_type &val)
	{
		node_ptr	temp = _new_node(val);

		temp->set_top(node);
		if (_comp(val.first, node->get_key()) == true)
		{
			node->set_left(temp);
			return (node->get_left()->get_val());
		}
		else
			node->set_right(temp);
		return (node->get_right()->get_val());
	}

	/*
	**	Return true or false if the pair gived is stored in the BST
	*/
	bool	_is_stored(value_type &val)
	{
		return (this->get_parent(val)->get_key() == val.first);
	}

	node_ptr	_delete_leaf(node_ptr &leaf)
	{
		if (leaf->get_top())
		{
			if (leaf->get_top()->get_left() == leaf)
				leaf->get_top()->set_left(NULL);
			else if (leaf->get_top()->get_right() == leaf)
				leaf->get_top()->set_right(NULL);
		}
		delete leaf;

		return (NULL);
	}

	node_ptr	_delete_branch_one_child(node_ptr &leaf)
	{
		node_ptr child;

		if (leaf->get_left())
			child = leaf->get_left();
		else
			child = leaf->get_right();

		if (leaf->get_top() != NULL)
		{
			if (leaf->get_top()->get_left() == leaf)
				leaf->get_top()->set_left(child);
			else if (leaf->get_top()->get_right() == leaf)
				leaf->get_top()->set_right(child);
		}
		child->set_top(leaf->get_top());
		delete leaf;

		return (child);
	}

	node_ptr	_delete_branch_two_child(node_ptr &leaf)
	{
		node_ptr	to_exchange = leaf->get_right();

		while (to_exchange->get_left())
			to_exchange = to_exchange->get_left();

		if (to_exchange == leaf->get_right())
		{
			to_exchange->set_top(leaf->get_top());
			if (leaf->get_top())
			{
				if (leaf->get_top()->get_left() == leaf)
					leaf->get_top()->set_left(to_exchange);
				else if (leaf->get_top()->get_right() == leaf)
					leaf->get_top()->set_right(to_exchange);
			}
			to_exchange->set_top(leaf->get_top());
			to_exchange->set_left(leaf->get_left());
			leaf->get_left()->set_top(to_exchange);
			delete leaf;
		}
		else
		{
			to_exchange->get_top()->set_left(to_exchange->get_right());
			to_exchange->set_right(leaf->get_right());
			to_exchange->get_right()->set_top(to_exchange);
			to_exchange->set_top(leaf->get_top());
			to_exchange->set_left(leaf->get_left());
			to_exchange->get_left()->set_top(to_exchange);
			if (to_exchange->get_top())
			{
				if (to_exchange->get_top()->get_left() == leaf)
					to_exchange->get_top()->set_left(to_exchange);
				else if (to_exchange->get_top()->get_right() == leaf)
					to_exchange->get_top()->set_right(to_exchange);
			}
			delete leaf;
		}
		return (to_exchange);
	}

	/*
	**	The fake iterator is an iterator that point on a past-the-end element.
	**	In this implementation of map, a past-the-end node is an empty node
	**	that have only top pointer to the last valid node.
	**
	**					  rightmost_leaf
	**							^
	**							|
	**						   top
	**							|
	**	fake_iterator -> past_the_end_node
	*/
	iterator	_get_fake_ite(void) const
	{
		node_ptr	ghost_node = _new_node();
		iterator	rightmostnode(_root);

		rightmostnode.go_rightmost();
		ghost_node->set_top(rightmostnode.get_ptr());

		iterator	fake_ite(ghost_node);

		fake_ite.set_is_ghost(true);
		return (fake_ite);
	}

	iterator	_get_fake_rev_ite(void)
	{
		node_ptr	ghost_node = _new_node();
		iterator	leftmostnode(_root);

		leftmostnode.go_leftmost();
		ghost_node->set_top(leftmostnode.get_ptr());

		iterator	fake_ite(ghost_node);

		fake_ite.set_is_ghost(true);
		return (fake_ite);
	}

	size_t			_size;
	node_ptr		_root;
	key_compare		_comp;
	allocator_type	_alloc;
};

template <typename Tkey, typename Tvalue, typename Compare = std::less<Tkey>>
std::ostream	&operator<<(std::ostream &o, map<Tkey, Tvalue, Compare> &i)
{
	if (i.size() == 0)
	{
		o << "{}";
		return (o);
	}
	for (typename ft::map<Tkey, Tvalue, Compare>::const_iterator it = i.begin();
		 it != i.end();
		 it++)
		o << *it << std::endl;
	return (o);
};

}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:59:34 by artmende          #+#    #+#             */
/*   Updated: 2022/07/12 17:40:52 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>
# include <utility>

# include "pair.hpp"
# include "red_black_tree.hpp"


// iterator through the tree : https://stackoverflow.com/questions/2942517/how-do-i-iterate-over-binary-tree

namespace ft
{



	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class map
	// Key :  map::key_type
	// T : map::mapped_type
	// Compare : map::key_compare
	// Alloc : map::allocator_type
	{
	public:
		typedef				Key									key_type;
		typedef				T									mapped_type;
		typedef				pair<const key_type,mapped_type>	value_type;
		typedef				Compare								key_compare;
	//	typedef				/* something */						value_compare;
		typedef				Alloc								allocator_type;
		typedef	typename	allocator_type::reference			reference;
		typedef typename	allocator_type::const_reference		const_reference;
		typedef typename	allocator_type::pointer				pointer;
		typedef typename	allocator_type::const_pointer		const_pointer;
	//	typedef				/* something */						iterator; // a bidirectional iterator to value_type	convertible to const_iterator
	//	typedef				/* something */						const_iterator; // a bidirectional iterator to const value_type
	//	typedef				reverse_iterator<iterator>			reverse_iterator;
	//	typedef				reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef typename	allocator_type::difference_type		difference_type;
		typedef typename	allocator_type::size_type			size_type;

	private:

		red_black_tree<Key, T, Compare, Alloc>	_tree;

	public:
		////////////////////// CONSTRUCTORS - DESTRUCTOR ///////////////////////
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) // empty (1)
		{}

		//template <class InputIterator> // range (2)
		//map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		//{}
		
		map(const map& x) // copy (3)
		{}

		~map()
		{}

		map& operator=(const map& x)
		{
			return (*this);
		}

		////////////////////////////// ITERATORS ///////////////////////////////

		//iterator	begin()
		//{}

		//const_iterator	begin() const
		//{}

		//iterator	end()
		//{}

		//const_iterator	end() const
		//{}

		//reverse_iterator	rbegin()
		//{}

		//const_reverse_iterator	rbegin() const
		//{}

		//reverse_iterator	rend()
		//{}

		//const_reverse_iterator	rend() const
		//{}

		/////////////////////////////// CAPACITY ///////////////////////////////

		//bool	empty() const
		//{}

		//size_type	size() const
		//{}

		//size_type	max_size() const
		//{}

		///////////////////////////	ELEMENT ACCESS	////////////////////////////

		//mapped_type&	operator[](const key_type& k)
		//{}

		///////////////////////////	MODIFIERS	////////////////////////////////

		//pair<iterator,bool>	insert(const value_type& val) // value_type is a pair (reference to a pair)
		//{}

		//iterator	insert(iterator position, const value_type& val)
		//{}

		//template <class InputIterator>
		//void	insert(InputIterator first, InputIterator last)
		//{}

		//void	erase(iterator position)
		//{}

		//size_type	erase(const key_type& k)
		//{}

		//void	erase(iterator first, iterator last)
		//{}

		//void	swap(map& x)
		//{}

		//void	clear()
		//{}

		///////////////////////////	OBSERVERS	////////////////////////////////

		//key_compare	key_comp() const
		//{}

		//value_compare	value_comp() const
		//{}

		///////////////////////////	OPERATIONS	////////////////////////////////

		//iterator	find(const key_type& k)
		//{}

		//const_iterator	find(const key_type& k) const
		//{}

		//size_type	count(const key_type& k) const
		//{}

		//iterator	lower_bound(const key_type& k)
		//{}

		//const_iterator	lower_bound(const key_type& k) const
		//{}

		//iterator	upper_bound(const key_type& k)
		//{}

		//const_iterator	upper_bound(const key_type& k) const
		//{}

		//pair<const_iterator,const_iterator>	equal_range(const key_type& k) const
		//{}

		//pair<iterator,iterator>	equal_range(const key_type& k)
		//{}

		///////////////////////////	ALLOCATOR	////////////////////////////////

		//allocator_type	get_allocator() const
		//{}

	};

}

// creating a default object, then using assignment to give it the right value

#endif

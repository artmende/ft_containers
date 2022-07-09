/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:59:34 by artmende          #+#    #+#             */
/*   Updated: 2022/07/09 15:51:14 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>
# include <utility>

# include "pair.hpp"
# include "red_black_tree.hpp"




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

		// some tree

	public:
		// public member functions
	};

}

#endif

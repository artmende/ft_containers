/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:16:18 by artmende          #+#    #+#             */
/*   Updated: 2022/07/12 15:00:07 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <iostream>
# include "pair.hpp"

namespace ft
{
	template <typename Key, typename T>
	class red_black_node
	{
		// default contructor forbidden
		// constructor with k defined, and v as optional param
		// operator = just set the v

	private:
		red_black_node();

	public:
		red_black_node(Key const & k, T & value = T())
		: k(k), v(value), left(NULL), right(NULL), parent(NULL), color(false)
		{}

		red_black_node(red_black_node const & x) // template? different template type ?
		: k(x.k), v(x.v), left(NULL), right(NULL), parent(NULL), color(x.color) // shallow copy
		{}

		~red_black_node() {}

		red_black_node &	operator=(red_black_node const & x) // template? different template type ?
		{
			if (&x != this)
			{
				this->v = x.v;
			}
			return (*this);
		}

		Key const				*k; // object is allocated, and its address is stored here
		T						*v;
		red_black_node<Key, T>	*left;
		red_black_node<Key, T>	*right;
		red_black_node<Key, T>	*parent;
		bool					color; // true is black, false is red
	};

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > > // probably no need to put = because the type is given by map
	class red_black_tree
	{
	private:
		red_black_node<Key, T>	*root;
	public:
		red_black_tree() : root(NULL) {}

		

	};



}


#endif

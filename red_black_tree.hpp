/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:16:18 by artmende          #+#    #+#             */
/*   Updated: 2022/07/09 17:21:57 by artmende         ###   ########.fr       */
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
		red_black_node(Key const & k, T & value = T()) : k(k), v(value)
		{}
		red_black_node(red_black_node const & x) : k(x.k), v(x.v) // template? different template type ?
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

		Key const				k;
		T						v;
		red_black_node<Key, T>	*left;
		red_black_node<Key, T>	*right;
		red_black_node<Key, T>	*parent;
	};

	template <typename Key, typename T>
	class red_black_tree
	{
	private:
		red_black_node<Key, T>	*root;
	public:
		red_black_tree() {}

	};



}


#endif

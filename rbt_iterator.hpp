/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:19:08 by artmende          #+#    #+#             */
/*   Updated: 2022/07/26 16:06:50 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

# include <iostream>
# include <iterator>

// iterator takes a node of my tree as a parameter.
// begin is the smallest node
// end is the biggest node with a special bit set to indicate its past
// same for rend
// in private we have 2 things : a pointer to the current node and the bit indicating if we are outside or not


namespace ft
{
	template<typename NODE>
	class tree_iterator
	{
	public:
		// all typedef

	public:

		tree_iterator() : _inner_node (NULL), _is_out(true) {}
		tree_iterator(tree_iterator const & x) : _inner_node(x._inner_node), _is_out(x._is_out) {}
		~tree_iterator() {}

		tree_iterator &	operator=(tree_iterator const & x) { if (this != &x) {this->_inner_node = x._inner_node; this->_is_out = x._is_out;} return (*this); }

	private:
		NODE	*_inner_node;
		bool	_is_out;
	};
}


#endif

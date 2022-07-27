/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:19:08 by artmende          #+#    #+#             */
/*   Updated: 2022/07/27 16:42:02 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_ITERATOR_HPP
# define BST_ITERATOR_HPP

# include <iostream>
# include <iterator>
# include "red_black_tree.hpp"

// iterator takes a node of my tree as a parameter.
// begin is the smallest node
// end is the biggest node with a special bit set to indicate its past
// same for rend
// in private we have 2 things : a pointer to the current node and the bit indicating if we are outside or not


namespace ft
{
	template<typename T> // T is the value type stored inside of the tree
	class bst_iterator
	{
	public:
		typedef				T*														iterator_type;
		typedef				std::bidirectional_iterator_tag							iterator_category;
		typedef typename	std::iterator_traits<iterator_type>::value_type			value_type;
		typedef typename	std::iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename	std::iterator_traits<iterator_type>::pointer			pointer; // a pointer to the type that is stored in the tree
		typedef typename	std::iterator_traits<iterator_type>::reference			reference;
		typedef				red_black_node<T>										node;

		bst_iterator() : _inner_node(NULL), _is_out(true) {}
		bst_iterator(bst_iterator const & x) : _inner_node(x._inner_node), _is_out(x._is_out) {}
		~bst_iterator() {}

		bst_iterator &	operator=(bst_iterator const & x) { if (this != &x) {this->_inner_node = x._inner_node; this->_is_out = x._is_out;} return (*this); }

	private:
		node	*_inner_node;
		bool	_is_out;
	};
}


#endif

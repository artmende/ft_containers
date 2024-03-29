/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:19:08 by artmende          #+#    #+#             */
/*   Updated: 2022/08/14 19:27:08 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_ITERATOR_HPP
# define BST_ITERATOR_HPP

# include <iostream>
# include <iterator>
# include "red_black_tree.hpp"

namespace ft
{
	template <typename T>
	class red_black_node;

	template<typename T, typename node> // T is the value type stored inside of the tree
	class bst_iterator
	{
	public:
		typedef				T*														iterator_type;
		typedef				std::bidirectional_iterator_tag							iterator_category;
		typedef typename	std::iterator_traits<iterator_type>::value_type			value_type;
		typedef typename	std::iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename	std::iterator_traits<iterator_type>::pointer			pointer; // a pointer to the type that is stored in the tree
		typedef typename	std::iterator_traits<iterator_type>::reference			reference;

		bst_iterator() : _inner_node(NULL) {}
		bst_iterator(bst_iterator<T, node> const & x) : _inner_node(x._inner_node) {}
		bst_iterator(const node *ptr) : _inner_node(ptr) {}
		~bst_iterator() {}

		bst_iterator &	operator=(bst_iterator const & x) { if (this != &x) {this->_inner_node = x._inner_node;} return (*this); }

		operator bst_iterator<const T, node>() const { return this->_inner_node; } // This is what allow const_iterator to be constructed from iterator and allow them to be compared together

		reference	operator*() const
		{
			return (this->_inner_node->v);
		}

		pointer	operator->() const
		{
			return (&(this->_inner_node->v));
		}

		////////////////////////	INCREMENT OPERATORS	////////////////////////

		bst_iterator &	operator++() // ++it
		{
			if (this->_inner_node)
				this->_inner_node = this->_inner_node->find_successor();
			return (*this);
		}

		bst_iterator	operator++(int) // it++
		{
			bst_iterator<T, node>	temp(*this);
			++(*this);
			return (temp);
		}

		bst_iterator &	operator--() // --it
		{
			if (this->_inner_node)
				this->_inner_node = this->_inner_node->find_predecessor();
			return (*this);
		}

		bst_iterator	operator--(int) // it--
		{
			bst_iterator<T, node>	temp(*this);
			--(*this);
			return (temp);
		}

	//private: // gonna stay public // use in erase method in map
		const node	*_inner_node;
	};

	template <typename T1, typename NODE1, typename T2, typename NODE2>
	bool	operator==(bst_iterator<T1, NODE1> const & a, bst_iterator<T2, NODE2> const & b)
	{
		return (a._inner_node == b._inner_node);
	}

	template <typename T1, typename NODE1, typename T2, typename NODE2>
	bool	operator!=(bst_iterator<T1, NODE1> const & a, bst_iterator<T2, NODE2> const & b)
	{
		return (!(a == b));
	}
}

#endif

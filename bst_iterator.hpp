/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:19:08 by artmende          #+#    #+#             */
/*   Updated: 2022/08/02 14:47:29 by artmende         ###   ########.fr       */
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

/*

Is default-constructible, copy-constructible, copy-assignable and destructible	X a;
X b(a);
b = a;
Can be compared for equivalence using the equality/inequality operators
(meaningful when both iterator values iterate over the same underlying sequence).	a == b
a != b
Can be dereferenced as an rvalue (if in a dereferenceable state).	*a
a->m
For mutable iterators (non-constant iterators):
Can be dereferenced as an lvalue (if in a dereferenceable state).	*a = t
Can be incremented (if in a dereferenceable state).
The result is either also dereferenceable or a past-the-end iterator.
Two iterators that compare equal, keep comparing equal after being both increased.
++a
a++
*a++
Can be decremented (if a dereferenceable iterator value precedes it).
--a
a--
*a--

*/

namespace ft
{

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

		bool	operator==(bst_iterator const & rhs) const
		{
			return (this->_inner_node == rhs._inner_node);
		}

		bool	operator!=(bst_iterator const & rhs) const
		{
			return (this->_inner_node != rhs._inner_node);
		}
	
	private:
		const node	*_inner_node;

	};

	// maybe need to put comparison operators outside to make it work with reverse iterator
}


#endif

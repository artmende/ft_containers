/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:19:08 by artmende          #+#    #+#             */
/*   Updated: 2022/08/01 10:58:39 by artmende         ###   ########.fr       */
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

		bst_iterator() : _inner_node(NULL), _is_out(true) {}
		bst_iterator(bst_iterator<T, node> const & x) : _inner_node(x._inner_node), _is_out(x._is_out) {}
		bst_iterator(const node *ptr) : _inner_node(ptr), _is_out(false) {}
		~bst_iterator() {}

		bst_iterator &	operator=(bst_iterator const & x) { if (this != &x) {this->_inner_node = x._inner_node; this->_is_out = x._is_out;} return (*this); }

		operator bst_iterator<const T, node>() const { return this->_inner_node; }



		reference	operator*() const
		{
			//if (this->_is_out == true)
			//	throw std::out_of_range("Out of range"); // remove comment later
			return (this->_inner_node->v);
		}

		pointer	operator->() const
		{
			if (this->_is_out == true)
				throw std::out_of_range("Out of range");
			return (&(this->_inner_node->v));
		}

		////////////////////////	INCREMENT OPERATORS	////////////////////////

		bst_iterator &	operator++() // ++it
		{
			node const	*n = this->_inner_node->find_successor();
			if (n == NULL) // we are already at the last node
				this->_is_out = true;
			else if (this->_is_out == true) // we are before the first node
				this->_is_out = false;
			else
				this->_inner_node = n;
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
			node const	*n = this->_inner_node->find_predecessor();
			if (n == NULL)
				this->_is_out = true;
			else if (this->_is_out == true)
				this->_is_out = false;
			else
				this->_inner_node = n;
			return (*this);
		}

		bst_iterator	operator--(int) // it--
		{
			bst_iterator<T, node>	temp(*this);
			--(*this);
			return (temp);
		}



	private:
		const node	*_inner_node;
		bool		_is_out;
	};
}


#endif

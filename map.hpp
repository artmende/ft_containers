/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:59:34 by artmende          #+#    #+#             */
/*   Updated: 2022/08/02 15:05:19 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>
# include <utility>

# include "pair.hpp"
# include "red_black_tree.hpp"
# include "bst_iterator.hpp"


// iterator through the tree : https://stackoverflow.com/questions/2942517/how-do-i-iterate-over-binary-tree

namespace ft
{



	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class map
	{



	public:
		typedef				Key											key_type;
		typedef				T											mapped_type;
		typedef				pair<const key_type, mapped_type>			value_type;
		typedef				Compare										key_compare;
		typedef				Alloc										allocator_type;
		typedef	typename	allocator_type::reference					reference;
		typedef typename	allocator_type::const_reference				const_reference;
		typedef typename	allocator_type::pointer						pointer;
		typedef typename	allocator_type::const_pointer				const_pointer;
		typedef typename	allocator_type::difference_type				difference_type;
		typedef typename	allocator_type::size_type					size_type;
		typedef typename	red_black_tree<value_type>::iterator		iterator;
		typedef typename	red_black_tree<value_type>::const_iterator	const_iterator;
//		typedef				ft::bst_iterator<value_type, ft::red_black_node<value_type> >	iterator;
//		typedef				ft::bst_iterator<const value_type, ft::red_black_node<value_type> >	const_iterator;
	//	typedef				/* something */						iterator; // a bidirectional iterator to value_type	convertible to const_iterator
	//	typedef				/* something */						const_iterator; // a bidirectional iterator to const value_type
	//	typedef				reverse_iterator<iterator>			reverse_iterator;
	//	typedef				reverse_iterator<const_iterator>	const_reverse_iterator;



	private:
		class value_compare : public std::binary_function<value_type, value_type, bool> // it compares the pairs by looking only at the key
		{
			friend class map;
		protected:
			key_compare	comp;

			
		public:
			value_compare(key_compare c) : comp(c) {}
			bool	operator()(const value_type& x, const value_type& y) const // value_type is the pair
			{
				return (comp(x.first, y.first));
			}
		};



	public :
		////////////////////// CONSTRUCTORS - DESTRUCTOR ///////////////////////
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) // empty (1)
		: _comp(comp), _alloc(alloc), _val_comp(value_compare(comp)), _tree(red_black_tree<value_type, value_compare, Alloc>(comp)), _size(0)
		{}

		//template <class InputIterator> // range (2)
		//map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		//{}
		
		map(const map& x) : _comp(x._comp), _alloc(x._alloc), _val_comp(x._val_comp), _tree(x._tree), _size(x._size) // copy (3)
		{
//			this->_tree = x._tree;
		}

		~map()
		{}

		map& operator=(const map& x)
		{
			(void)x;
			return (*this);
		}


		red_black_tree<value_type, value_compare, Alloc>	*base()
		{
			return (&(this->_tree));
		}


		////////////////////////////// ITERATORS ///////////////////////////////

		iterator	begin()
		{
			iterator	ret(this->_tree.begin());
			return (ret);
		}

		//const_iterator	begin() const
		//{}

		iterator	end()
		{
			iterator	ret(this->_tree.end());
			return (ret);
		}

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

		bool	empty() const
		{
			return (this->_size == 0);
		}

		size_type	size() const
		{
			return (this->_size);
		}

		size_type	max_size() const
		{
			return (this->_alloc.max_size());
		}

		///////////////////////////	ELEMENT ACCESS	////////////////////////////

		mapped_type&	operator[](const key_type& k)
		{
			red_black_node<value_type>	*ret = this->_tree.insert(ft::make_pair<key_type, mapped_type>(k, mapped_type()));
			return(ret->v.second);
		}

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


	//private:
		key_compare											_comp;
		allocator_type										_alloc;
		value_compare										_val_comp;
		red_black_tree<value_type, value_compare, Alloc>	_tree;
		size_type											_size;
	};




}

// creating a default object, then using assignment to give it the right value

#endif

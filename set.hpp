/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:23:34 by artmende          #+#    #+#             */
/*   Updated: 2022/08/15 16:20:05 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <iostream>
# include <memory>
# include <utility>

# include "pair.hpp"
# include "red_black_tree.hpp"
# include "bst_iterator.hpp"
# include "reverse_iterator.hpp"
//# include "lexicographical_compare_equal.hpp"

namespace ft
{
	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set
	{
	public:
		typedef				T											key_type;
		typedef				T											value_type;
		typedef				Compare										key_compare;
		typedef				Compare										value_compare;
		typedef				Alloc										allocator_type;
		typedef	typename	allocator_type::reference					reference;
		typedef typename	allocator_type::const_reference				const_reference;
		typedef typename	allocator_type::pointer						pointer;
		typedef typename	allocator_type::const_pointer				const_pointer;
		typedef typename	allocator_type::difference_type				difference_type;
		typedef typename	allocator_type::size_type					size_type;
		typedef typename	red_black_tree<value_type>::iterator		iterator;
		typedef typename	red_black_tree<value_type>::const_iterator	const_iterator;
		typedef				ft::reverse_iterator<iterator>				reverse_iterator;
		typedef				ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	private:
		key_compare											_comp;
		allocator_type										_alloc;
		red_black_tree<value_type, value_compare, Alloc>	_tree;

	public:
		////////////////////// CONSTRUCTORS - DESTRUCTOR ///////////////////////
		explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _comp(comp), _alloc(alloc), _tree(red_black_tree<value_type, value_compare, Alloc>())
		{}

		template <class InputIterator>
		set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _comp(comp), _alloc(alloc), _tree(red_black_tree<value_type, value_compare, Alloc>())
		{
			while (first != last)
			{
				this->_tree.insert(*first);
				++first;
			}
		}

		set(const set& x) : _comp(x._comp), _alloc(x._alloc), _tree(x._tree)
		{}

		~set() {}

		set&	operator=(const set& x)
		{
			if (this != &x)
			{
				this->_tree = x._tree;
			}
			return (*this);
		}

		////////////////////////////// ITERATORS ///////////////////////////////

		iterator	begin()
		{
			iterator	ret(this->_tree.begin());
			return (ret);
		}

		const_iterator	begin() const
		{
			const_iterator	ret(this->_tree.begin());
			return (ret);
		}

		iterator	end()
		{
			iterator	ret(this->_tree.end());
			return (ret);
		}

		const_iterator	end() const
		{
			const_iterator	ret(this->_tree.end());
			return (ret);
		}

		reverse_iterator	rbegin()
		{
			reverse_iterator	ret(this->end());
			return (ret);
		}

		const_reverse_iterator	rbegin() const
		{
			const_reverse_iterator	ret(this->end());
			return (ret);
		}

		reverse_iterator	rend()
		{
			reverse_iterator	ret(this->begin());
			return (ret);
		}

		const_reverse_iterator	rend() const
		{
			const_reverse_iterator	ret(this->begin());
			return (ret);
		}

		/////////////////////////////// CAPACITY ///////////////////////////////

		bool	empty() const
		{
			return (this->size() == 0);
		}

		size_type	size() const
		{
			return (_tree.size());
		}

		size_type	max_size() const
		{
			return (this->_tree.max_size());
		}

		///////////////////////////	MODIFIERS	////////////////////////////////

		pair<iterator,bool>	insert(const value_type& val)
		{
			size_t	size_before = this->_tree.size();
			red_black_node<value_type>	*ret = this->_tree.insert(val);
			if (size_before == this->_tree.size())
				return (ft::make_pair<iterator, bool>(ret, false));
			else
				return (ft::make_pair<iterator, bool>(ret, true));
		}

		iterator	insert(iterator position, const value_type& val)
		{
			(void)position;
			return ((this->insert(val)).first);
		}

		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				this->insert(*first);
				++first;
			}
		}

		void	erase(iterator position)
		{
			uintptr_t	test = reinterpret_cast<uintptr_t>(position._inner_node);
			this->_tree.remove(reinterpret_cast<red_black_node<value_type> *>(test));
		}

		size_type	erase(const value_type& val)
		{
			red_black_node<value_type>	*to_erase = this->_tree.find(val);
			this->_tree.remove(to_erase);
			if (to_erase)
				return (1);
			else
				return (0);
		}

		void	erase(iterator first, iterator last)
		{
			while (first != last)
			{
				iterator	to_erase = first;
				++first;
				this->erase(to_erase);
			}
		}

		void	swap(set& x)
		{
			this->_tree.swap(x._tree);
		}

		void	clear()
		{
			ft::set<value_type>	temp;
			this->swap(temp);
		}

		///////////////////////////	OBSERVERS	////////////////////////////////

		key_compare	key_comp() const
		{
			return (this->_comp);
		}

		value_compare	value_comp() const
		{
			return (this->_val_comp);
		}

		///////////////////////////	OPERATIONS	////////////////////////////////

		iterator	find(const value_type& val) const
		{
			const red_black_node<value_type>	*ret = this->_tree.find(val);
			if (ret)
				return (iterator(ret));
			else
				return (this->end());
		}

		size_type	count(const value_type& val) const
		{
			const red_black_node<value_type>	*n = this->_tree.find(val);
			if (n)
				return (1);
			else
				return (0);
		}

		iterator	lower_bound(const value_type& val) const
		{
			return (this->_tree.lower_bound(val));
		}

		iterator	upper_bound(const value_type& val) const
		{
			return (this->_tree.upper_bound(val));
		}

		pair<iterator,iterator>	equal_range(const value_type& val) const
		{
			iterator	low = this->lower_bound(val);
			iterator	up = this->upper_bound(val);
			pair<iterator,iterator>	ret(low, up);

			return (ret);
		}

		///////////////////////////	ALLOCATOR	////////////////////////////////

		allocator_type	get_allocator() const
		{
			return (this->_alloc);
		}

	};
}



#endif

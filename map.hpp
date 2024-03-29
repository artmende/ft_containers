/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:59:34 by artmende          #+#    #+#             */
/*   Updated: 2022/08/14 15:55:49 by artmende         ###   ########.fr       */
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
# include "reverse_iterator.hpp"
# include "lexicographical_compare_equal.hpp"


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
		typedef				ft::reverse_iterator<iterator>				reverse_iterator;
		typedef				ft::reverse_iterator<const_iterator>		const_reverse_iterator;

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
		: _comp(comp), _alloc(alloc), _val_comp(value_compare(comp)), _tree(red_black_tree<value_type, value_compare, Alloc>(_val_comp))
		{}

		template <class InputIterator> // range (2)
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _comp(comp), _alloc(alloc), _val_comp(value_compare(comp)), _tree(red_black_tree<value_type, value_compare, Alloc>(_val_comp))
		{
			while (first != last)
			{
				this->_tree.insert(*first);
				++first;
			}
		}
		
		map(const map& x) : _comp(x._comp), _alloc(x._alloc), _val_comp(x._val_comp), _tree(x._tree) // copy (3)
		{}

		~map()
		{}

		map& operator=(const map& x)
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

		///////////////////////////	ELEMENT ACCESS	////////////////////////////

		mapped_type&	operator[](const key_type& k)
		{
			red_black_node<value_type>	*ret = this->_tree.insert(ft::make_pair<key_type, mapped_type>(k, mapped_type()));
			return(ret->v.second);
		}

		///////////////////////////	MODIFIERS	////////////////////////////////

		pair<iterator,bool>	insert(const value_type& val) // value_type is a pair (reference to a pair)
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

		size_type	erase(const key_type& k)
		{
			red_black_node<value_type>	*to_erase = this->_tree.find(ft::make_pair<key_type, mapped_type>(k, mapped_type()));
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

		void	swap(map& x)
		{
			this->_tree.swap(x._tree);
		}

		void	clear()
		{
			ft::map<key_type, mapped_type>	temp;
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

		iterator	find(const key_type& k)
		{
			red_black_node<value_type>	*ret = this->_tree.find(ft::make_pair<key_type, mapped_type>(k, mapped_type()));
			if (ret)
				return (iterator(ret));
			else
				return (this->end());
		}

		const_iterator	find(const key_type& k) const
		{
			const red_black_node<value_type>	*ret = this->_tree.find(ft::make_pair<key_type, mapped_type>(k, mapped_type()));
			if (ret)
				return (const_iterator(ret));
			else
				return (this->end());
		}

		size_type	count(const key_type& k) const
		{
			const red_black_node<value_type>	*n = this->_tree.find(ft::make_pair<key_type, mapped_type>(k, mapped_type()));
			if (n)
				return (1);
			else
				return (0);
		}

		iterator	lower_bound(const key_type& k)
		{
			return (this->_tree.lower_bound(ft::make_pair<key_type, mapped_type>(k, mapped_type())));
		}

		const_iterator	lower_bound(const key_type& k) const
		{
			return (this->_tree.lower_bound(ft::make_pair<key_type, mapped_type>(k, mapped_type())));
		}

		iterator	upper_bound(const key_type& k)
		{
			return (this->_tree.upper_bound(ft::make_pair<key_type, mapped_type>(k, mapped_type())));
		}

		const_iterator	upper_bound(const key_type& k) const
		{
			return (this->_tree.upper_bound(ft::make_pair<key_type, mapped_type>(k, mapped_type())));
		}

		pair<const_iterator,const_iterator>	equal_range(const key_type& k) const
		{
			const_iterator	low = this->lower_bound(k);
			const_iterator	up = this->upper_bound(k);
			pair<const_iterator,const_iterator>	ret(low, up);

			return (ret);
		}

		pair<iterator,iterator>	equal_range(const key_type& k)
		{
			iterator	low = this->lower_bound(k);
			iterator	up = this->upper_bound(k);
			pair<iterator,iterator>	ret(low, up);

			return (ret);
		}

		///////////////////////////	ALLOCATOR	////////////////////////////////

		allocator_type	get_allocator() const
		{
			return (this->_alloc);
		}

	private:
		key_compare											_comp;
		allocator_type										_alloc;
		value_compare										_val_comp;
		red_black_tree<value_type, value_compare, Alloc>	_tree;
	};

	template <class Key, class T, class Compare, class Alloc>
	bool	operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		else
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (lhs == rhs || lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs < rhs) && lhs != rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (lhs == rhs || lhs > rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	void	swap(ft::map<Key, T, Compare, Alloc> &lhs, ft::map<Key, T, Compare, Alloc> &rhs)
	{
		lhs.swap(rhs);
	}
}

#endif

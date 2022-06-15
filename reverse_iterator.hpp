/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:37:25 by artmende          #+#    #+#             */
/*   Updated: 2022/06/15 16:55:16 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>
# include <iterator>

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	public:

		typedef				Iterator							iterator_type;
		typedef	typename	iterator_type::iterator_category	iterator_category;
		typedef	typename	iterator_type::value_type			value_type;
		typedef	typename	iterator_type::difference_type		difference_type;
		typedef	typename	iterator_type::pointer				pointer;
		typedef	typename	iterator_type::reference			reference;

	private:
		iterator_type	_it;
	public:
		// member functions overload
		reverse_iterator() : _it(iterator_type(NULL)) {}

		explicit reverse_iterator (iterator_type it) : _it(it) {}

		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it) : _it(rev_it.base()) {}

		~reverse_iterator() {}

		reverse_iterator<iterator_type> &	operator=(const reverse_iterator<iterator_type> & x)
		{ if (this != &x) { this->_it = x._it; } return (*this); }

		iterator_type	base() const
		{
			return (this->_it);
		}

		//////////////////////	DEREFERENCE OPERATORS	////////////////////////

		reference	operator*() const
		{
			return (*(this->_it));
		}

		reference	operator[](int i) const
		{
			return (this->_it[i]);
		}

		pointer	operator->() const
		{
			return (this->_it.base());
		}

		////////////////////////	INCREMENT OPERATORS	////////////////////////

		reverse_iterator<iterator_type> &	operator++() // ++it
		{
			--(this->_it);
			return (*this);
		}

		reverse_iterator<iterator_type>	operator++(int) // it++
		{
			reverse_iterator<iterator_type>	temp(*this);
			--(this->_it);
			return (temp);
		}

		reverse_iterator<iterator_type> &	operator--() // --it
		{
			++(this->_it);
			return (*this);
		}

		reverse_iterator<iterator_type>	operator--(int) // it--
		{
			reverse_iterator<iterator_type>	temp(*this);
			++(this->_it);
			return (temp);
		}

		//////////////////////	ARITHMETIC OPERATORS	////////////////////////

		reverse_iterator<iterator_type>	operator+(difference_type n) const
		{
			return (this->_it - n);
		}

		reverse_iterator<iterator_type>	operator-(difference_type n) const
		{
			return (this->_it + n);
		}

		difference_type operator-(reverse_iterator<iterator_type> & x) const
		{
			return (this->_it - x._it);
		}
	};

	////////////////////////	COMPARISON OPERATORS	////////////////////////

	template <typename T, typename U> // 2 different types because it could be const and non const
	bool	operator==(reverse_iterator<T> const & a, reverse_iterator<U> const & b)
	{
		return (a.base() == b.base());
	}

	template <typename T, typename U> // 2 different types because it could be const and non const
	bool	operator!=(reverse_iterator<T> const & a, reverse_iterator<U> const & b)
	{
		return (a.base() != b.base());
	}

	template <typename T, typename U> // 2 different types because it could be const and non const
	bool	operator<(reverse_iterator<T> const & a, reverse_iterator<U> const & b)
	{
		return (a.base() > b.base());
	}

	template <typename T, typename U> // 2 different types because it could be const and non const
	bool	operator>(reverse_iterator<T> const & a, reverse_iterator<U> const & b)
	{
		return (a.base() < b.base());
	}

	template <typename T, typename U> // 2 different types because it could be const and non const
	bool	operator<=(reverse_iterator<T> const & a, reverse_iterator<U> const & b)
	{
		return (a.base() >= b.base());
	}

	template <typename T, typename U> // 2 different types because it could be const and non const
	bool	operator>=(reverse_iterator<T> const & a, reverse_iterator<U> const & b)
	{
		return (a.base() <= b.base());
	}

	////////////////////////	ARITHMETIC NON MEMBER	////////////////////////

	template <typename T>
	reverse_iterator<T>	operator+(typename ft::reverse_iterator<T>::difference_type n, reverse_iterator<T> const & rit)
	{
		return (rit.base() + n);
	}
}

# endif

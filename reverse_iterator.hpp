/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:37:25 by artmende          #+#    #+#             */
/*   Updated: 2022/07/01 18:32:45 by artmende         ###   ########.fr       */
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
//			return (*(this->_it));///////////
			return (*(this->_it - 1));
		}

		reference	operator[](int i) const
		{
		//	return (this->_it[i]);
			return (*(this->_it - (i + 1)));
		}

		pointer	operator->() const
		{
			return (this->_it.base() - 1);
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
			return (reverse_iterator<iterator_type>(this->_it - n));
		}

		reverse_iterator<iterator_type>	operator-(difference_type n) const
		{
			return (reverse_iterator<iterator_type>(this->_it + n));
		}

		difference_type operator-(reverse_iterator<iterator_type> const & x) const
		{
			return (x._it - this->_it);
		}

		reverse_iterator<iterator_type> &	operator+=(difference_type n)
		{
			this->_it -= n;
			return (*this);
		}

		reverse_iterator<iterator_type> &	operator-=(difference_type n)
		{
			this->_it += n;
			return (*this);
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
		return (reverse_iterator<T>(rit.base() - n));
	}

	template <typename T, typename U>
	typename reverse_iterator<T>::difference_type	operator-(reverse_iterator<T> const & a, reverse_iterator<U> const & b)
	{
		return (b.base() - a.base());
	}
	// need to test those arithmetic non member

}

# endif

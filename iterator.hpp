/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:53:49 by artmende          #+#    #+#             */
/*   Updated: 2022/06/11 17:48:51 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <iterator>
# include "vector.hpp"
/*# include <type_traits>*/

namespace ft
{
	template< class T2 > struct remove_const{typedef T2 type; };	
	template< class T2 > struct remove_const<const T2>{ typedef T2 type; };

	template <typename T> // can T be my container ? no. T is the type contained. From there all other type will be derived : pointer, reference, difference_type etc
	class vector_random_access_iterator
	{
	public:

		typedef				T*														iterator_type;
		typedef typename	std::iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename	std::iterator_traits<iterator_type>::value_type			value_type;
		typedef typename	std::iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename	std::iterator_traits<iterator_type>::pointer			pointer;
		typedef typename	std::iterator_traits<iterator_type>::reference			reference;

	private:
		pointer	_ptr;
	public:
		///////////////	CONSTRUCTORS - DESTRUCTOR - ASSIGNATION	////////////////

		vector_random_access_iterator() : _ptr(NULL) {} // default
		vector_random_access_iterator(const vector_random_access_iterator<typename remove_const<T>::type > & x) : _ptr(x.base()) {} // copy
		vector_random_access_iterator(pointer p) : _ptr(p) {}
		~vector_random_access_iterator() {}

		vector_random_access_iterator<typename remove_const<T>::type > &	operator=(const vector_random_access_iterator<typename remove_const<T>::type > & x)
		{ if (this != &x) { this->_ptr = x._ptr; } return (*this); }

		pointer	base() const
		{
			return (this->_ptr);
		}

		//////////////////////	DEREFERENCE OPERATORS	////////////////////////

		reference	operator*() const
		{
			return (*this->_ptr);
		}

		reference	operator[](int i) const
		{
			return (*(this->_ptr + i));
		}

		pointer	operator->() const
		{
			return (this->_ptr);
		}

		////////////////////////	INCREMENT OPERATORS	////////////////////////

		vector_random_access_iterator<T> &	operator++() // ++it
		{
			this->_ptr++;
			return (*this);
		}

		vector_random_access_iterator<T> &	operator++(int) // it++
		{
			vector_random_access_iterator<T>	temp(*this);
			this->_ptr++;
			return (temp);
		}

		vector_random_access_iterator<T> &	operator--() // ++it
		{
			this->_ptr--;
			return (*this);
		}

		vector_random_access_iterator<T> &	operator--(int) // it++
		{
			vector_random_access_iterator<T>	temp(*this);
			this->_ptr--;
			return (temp);
		}

		//////////////////////	ARITHMETIC OPERATORS	////////////////////////

		vector_random_access_iterator<T>	operator+(difference_type n) const
		{
			return (this->_ptr + n);
		}

		vector_random_access_iterator<T>	operator-(difference_type n) const
		{
			return (this->_ptr - n);
		}

		difference_type	operator-(vector_random_access_iterator<T> & x) const
		{
			return (this->_ptr - x._ptr);
		}
	};


	////////////////////////	COMPARISON OPERATORS	////////////////////////

	template <typename T, typename U> // 2 different types because it could be const and non const
	bool	operator==(vector_random_access_iterator<T> const & a, vector_random_access_iterator<U> const & b)
	{
		return (a.base() == b.base());
	}

	template <typename T, typename U>
	bool	operator!=(vector_random_access_iterator<T> const & a, vector_random_access_iterator<U> const & b)
	{
		return (a.base() != b.base());
	}

	template <typename T, typename U>
	bool	operator<(vector_random_access_iterator<T> const & a, vector_random_access_iterator<U> const & b)
	{
		return (a.base() < b.base());
	}

	template <typename T, typename U>
	bool	operator>(vector_random_access_iterator<T> const & a, vector_random_access_iterator<U> const & b)
	{
		return (a.base() > b.base());
	}

	template <typename T, typename U>
	bool	operator<=(vector_random_access_iterator<T> const & a, vector_random_access_iterator<U> const & b)
	{
		return (a.base() <= b.base());
	}

	template <typename T, typename U>
	bool	operator>=(vector_random_access_iterator<T> const & a, vector_random_access_iterator<U> const & b)
	{
		return (a.base() >= b.base());
	}

	////////////////////////	ARITHMETIC NON MEMBER	////////////////////////

	template <typename T>
	vector_random_access_iterator<T>	operator+(typename ft::vector_random_access_iterator<T>::difference_type n, vector_random_access_iterator<T> const & it)
	{
		return (it.base() + n);
	}
}

# endif

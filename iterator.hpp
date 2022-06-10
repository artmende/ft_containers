/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:53:49 by artmende          #+#    #+#             */
/*   Updated: 2022/06/10 18:58:38 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <iterator>
# include "vector.hpp"
/*# include <type_traits>*/

/*
		typedef				T													iterator_type;
		typedef typename	iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename	iterator_traits<iterator_type>::value_type			value_type;
		typedef typename	iterator_traits<iterator_type>::difference_type		difference_type;
		typedef typename	iterator_traits<iterator_type>::pointer				pointer;
		typedef typename	iterator_traits<iterator_type>::reference			reference;
*/

/*
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
	struct iterator
	{
		typedef	T			value_type;
		typedef	Distance	difference_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;
		typedef	Category	iterator_category;
	};
*/


namespace ft
{

	template< class T2 > struct remove_const{typedef T2 type; };	
	template< class T2 > struct remove_const<const T2>{ typedef T2 type; };

	template <typename T> // can T be my container ? no
	class vector_random_access_iterator
	{
	public: // should i use iterator traits instead ?

		//typedef				T									iterator_type;
		//typedef typename	std::random_access_iterator_tag		iterator_category;
		//typedef				T						value_type;
		//typedef typename	std::ptrdiff_t					difference_type;
		//typedef				T*							pointer;
		//typedef				T&						reference;

		typedef				T*													iterator_type;
		typedef typename	std::iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename	std::iterator_traits<iterator_type>::value_type			value_type;
		typedef typename	std::iterator_traits<iterator_type>::difference_type		difference_type;
		typedef typename	std::iterator_traits<iterator_type>::pointer				pointer;
		typedef typename	std::iterator_traits<iterator_type>::reference			reference;

	private:
		pointer	_ptr;
	public:
		/////////////// CONSTRUCTORS - DESTRUCTOR - ASSIGNATION ////////////////
		vector_random_access_iterator() : _ptr(NULL) {} // default
		vector_random_access_iterator(const vector_random_access_iterator<typename remove_const<T>::type > & x) : _ptr(x.base()) {} // copy
		vector_random_access_iterator(pointer p) : _ptr(p) {}
		~vector_random_access_iterator() {}

//	operator vector_random_access_iterator<const T>() const { return this->_ptr; }

		vector_random_access_iterator<typename remove_const<T>::type > &	operator=(const vector_random_access_iterator<typename remove_const<T>::type > & x)
		{ if (this != &x) { this->_ptr = x._ptr; } return (*this); }

		pointer	base() const
		{
			return (this->_ptr);
		}

		reference	operator*() const
		{
			return (*this->_ptr);
		}

		vector_random_access_iterator<T> &	operator++()
		{
			this->_ptr++;
			return (*this);
		}

	};

	template <typename T>
	bool	operator==(vector_random_access_iterator<T> const & a, vector_random_access_iterator<T> const & b)
	{
		return (a.base() == b.base());
	}

	template <typename T>
	bool	operator!=(vector_random_access_iterator<T> const & a, vector_random_access_iterator<T> const & b)
	{
		return (a.base() != b.base());
	}


/*	template <typename T, typename U>
	bool	operator==(vector_random_access_iterator<T> const & a, vector_random_access_iterator<U> const & b)
	{
		return (a.base() == b.base());
	}

	template <typename T, typename U>
	bool	operator!=(vector_random_access_iterator<T> const & a, vector_random_access_iterator<U> const & b)
	{
		return (a.base() != b.base());
	}*/




}


# endif

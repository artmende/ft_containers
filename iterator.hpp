/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:53:49 by artmende          #+#    #+#             */
/*   Updated: 2022/06/09 18:45:54 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
	struct iterator
	{
		typedef	T			value_type;
		typedef	Distance	difference_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;
		typedef	Category	iterator_category;
	};

	template <typename T>
	class random_access_iterator
	{
	public:
		typedef				T													iterator_type;
		typedef typename	iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename	iterator_traits<iterator_type>::value_type			value_type;
		typedef typename	iterator_traits<iterator_type>::difference_type		difference_type;
		typedef typename	iterator_traits<iterator_type>::pointer				pointer;
		typedef typename	iterator_traits<iterator_type>::reference			reference;
	private:
		T*	_ptr;
	public:
		random_access_iterator() : _ptr(NULL) {}
		~random_access_iterator() {}
	};
}


# endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:51:52 by artmende          #+#    #+#             */
/*   Updated: 2022/06/01 11:46:09 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>

namespace	ft
{
	template<typename T>
	class vector
	{
	public:
		typedef T value_type;

/*		explicit vector(const allocator_type& alloc = allocator_type()) // default constructor
		{}
		explicit vector(size_type n, const value_type& val = value_type(), // fill constructor
			const allocator_type& alloc = allocator_type())
		{}
		template <class InputIterator>
			vector(InputIterator first, InputIterator last, // range constructor
				const allocator_type& alloc = allocator_type())
		{}
		vector(const vector& x) // copy constructor
		{}*/

		vector() : _values(NULL) {} // default constructor
		vector(size_t n, const value_type& val = value_type())
		{
			std::allocator<value_type>	al;
			this->_values = al.allocate(n);
			for (size_t i = 0; i < n; i++)
			{
				al.construct(this->_values + i, val);
			}
			this->_size = n;
		}



		~vector()
		{
			std::allocator<value_type>	al;
			al.deallocate(this->_values, this->_size);
		}

		void	push_back(const value_type& val)
		{
			
		}
		void	*get()
		{
			return ((void *)this->_values);
		}
	private:
		value_type*	_values;
		size_t		_size;
	};
}

#endif

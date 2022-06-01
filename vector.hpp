/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:51:52 by artmende          #+#    #+#             */
/*   Updated: 2022/06/01 17:29:16 by artmende         ###   ########.fr       */
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

		vector() : _values(NULL), _size(0), _capacity(0) // default constructor
		{}

		vector(size_t n, const value_type& val = value_type()) : // fill constructor
		_size(n), _capacity(n)
		{
			this->_values = this->_al.allocate(n);
			for (size_t i = 0; i < n; i++)
			{
				this->_al.construct(this->_values + i, val);
			}
		}

		vector(const vector& x) // copy constructor
		{

		}


		~vector()
		{
			std::allocator<value_type>	al;
			for (size_t i = 0; i < this->_size; i++)
			{
				al.destroy(this->_values + i);
			}
			al.deallocate(this->_values, this->_size);
		}

		void	push_back(const value_type& val)
		{
			if (this->_size < this->_capacity)
			{
				this->_al.construct(this->_values + this->_size, val);
				++this->_size;
			}
			else
			{
				if (this->_capacity == 0)
				{
					this->_values = this->_al.allocate(1);
					this->_al.construct(this->_values, val);
					this->_size = 1;
					this->_capacity = 1;
					return ;
				}
				value_type*	newarray = this->_al.allocate(this->_capacity * 2);
				for (size_t i = 0; i < this->_capacity; i++)
				{
					this->_al.construct(newarray + i, *(this->_values + i));
//					this->_al.destroy(this->_values + i);
				}
				this->_al.construct(newarray + this->_size, val);
				for (size_t i = 0; i < this->_capacity; i++)
				{
//					this->_al.construct(newarray + i, *(this->_values + i));
					this->_al.destroy(this->_values + i);
				}
				this->_al.deallocate(this->_values, this->_capacity);
				this->_capacity *= 2;

				++this->_size;
				this->_values = newarray;
			}
		}

		size_t	size() const
		{
			return (this->_size);
		}

		size_t	capacity() const
		{
			return (this->_capacity);
		}

		value_type &		operator[](int const index)
		{
			return (*(this->_values + index));
		}
	private:
		std::allocator<value_type>	_al;
		value_type*	_values;
		size_t		_size;
		size_t		_capacity;
	};
}

#endif

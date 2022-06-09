/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:51:52 by artmende          #+#    #+#             */
/*   Updated: 2022/06/09 15:44:49 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
/*# include <cstddef>*/

namespace	ft
{
	template<typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef				T									value_type;
		typedef				Alloc								allocator_type;
		typedef typename	allocator_type::reference			reference;
		typedef typename	allocator_type::const_reference		const_reference;
		typedef typename	allocator_type::pointer				pointer;
		typedef typename	allocator_type::const_pointer		const_pointer;
		typedef				std::ptrdiff_t						difference_type;
		typedef				std::size_t							size_type;

/* 
		////////////////////// CONSTRUCTORS - DESTRUCTOR ///////////////////////
 */
		explicit vector(const allocator_type& alloc = allocator_type()) // default constructor
		: GROWING_FACTOR(2), _inner_array(NULL), _size(0), _capacity(0)
		{
			(void)alloc;
		}

		explicit vector(size_type n, const value_type& val = value_type(), // fill constructor
			const allocator_type& alloc = allocator_type())
		: GROWING_FACTOR(2), _size(n), _capacity(n)
		{
			(void)alloc;
			this->_inner_array = this->_al.allocate(n);
			for (size_t i = 0; i < n; i++)
			{
				this->_al.construct(this->_inner_array + i, val);
			}
		}

/*		template <class InputIterator>
			vector(InputIterator first, InputIterator last, // range constructor
				const allocator_type& alloc = allocator_type())
		{}*/

		vector(const vector& x) // copy constructor
		: GROWING_FACTOR(2), _size(x._size), _capacity(x._capacity)
		{
			this->_inner_array = this->_al.allocate(this->_capacity);
			for (size_t i = 0; i < this->_size; i++)
			{
				this->_al.construct(this->_inner_array + i, *(x._inner_array + i));
			}
		}

		~vector()
		{
			delete_all_data_and_deallocate();
		}

		vector&	operator=(const vector& x)
		{
			if (this != &x)
			{
				delete_all_data_and_deallocate();
				this->_capacity = x._capacity;
				this->_size = x._size;
				this->_inner_array = this->_al.allocate(this->_capacity);
				for (size_t i = 0; i < this->_size; i++)
				{
					this->_al.construct(this->_inner_array + i, *(x._inner_array + i));
				}
			}
		}


/* 		////////////////////////////// ITERATORS ///////////////////////////////


		/////////////////////////////// CAPACITY ///////////////////////////////
 */
		size_type	size() const
		{
			return (this->_size);
		}

		size_type	max_size() const
		{
			return (this->_al.max_size());
		}

		void	resize(size_type n, value_type val = value_type())
		{
			if (n <= this->_size) // delete elements at the end
			{
				for (size_t i = n; i < this->_size; i++)
				{
					this->_al.destroy(this->_inner_array + i);
				}
				this->_size = n;
			}
			else if (n <= this->_capacity) // add elements but no need to allocate
			{
				for (size_t i = this->_size; i < n; i++)
				{
					this->_al.construct(this->_inner_array + i, val);
				}
				this->_size = n;
			}
			else // allocate at least twice the capacity and add elements 
			{
				this->_inner_array = reallocate_array_with_capacity(n > this->_capacity * this->GROWING_FACTOR ? n : this->_capacity * this->GROWING_FACTOR);
				for (size_t i = this->_size; i < n; i++)
				{
					this->_al.construct(this->_inner_array + i, val);
				}
				this->_size = n;
			}
		}

		size_type	capacity() const
		{
			return (this->_capacity);
		}

		bool	empty() const
		{
			return (this->_size ? false : true);
		}

		void	reserve(size_type n)
		{
			this->_inner_array = reallocate_array_with_capacity(n);
		}


/* 		//////////////////////////// ELEMENT ACCESS ////////////////////////////
 */
		reference	operator[](size_type n)
		{
			return (*(this->_inner_array + n));
		}

		const_reference	operator[](size_type n) const
		{
			return (*(this->_inner_array + n));
		}

		reference	at(size_type n)
		{
			if (n >= this->_size)
				throw std::out_of_range("Out of range");
			return ((*this)[n]);
		}

		const_reference	at(size_type n) const
		{
			if (n >= this->_size)
				throw std::out_of_range("Out of range");
			return ((*this)[n]);
		}

		reference	front()
		{
			return ((*this)[0]);
		}

		const_reference	front() const
		{
			return ((*this)[0]);
		}

		reference back()
		{
			return ((*this)[this->_size - 1]);
		}

		const_reference back() const
		{
			return ((*this)[this->_size - 1]);
		}

/* 
		////////////////////////////////////////// Modifiers //////////////////
 */

		void	push_back(const value_type& val)
		{
			if (this->_size == this->_capacity) // need to allocate more
				this->_inner_array = reallocate_array_with_capacity(this->_capacity == 0 ? 1 : this->_capacity * this->GROWING_FACTOR);
			this->_al.construct(this->_inner_array + this->_size, val);
			++this->_size;
		}

		void	pop_back()
		{
			if (this->_size == 0)
				return ;
			this->_al.destroy(this->_inner_array + this->_size - 1);
			--this->_size;
		}



	private:
		double const	GROWING_FACTOR;
//		allocator_type	_al;
		std::allocator<T>	_al;
		value_type*		_inner_array;
		size_type		_size;
		size_type		_capacity;
		

		void	delete_all_data_and_deallocate()
		{
			for (size_t i = 0; i < this->_size; i++)
			{
				this->_al.destroy(this->_inner_array + i);
			}
			if (this->_capacity)
				this->_al.deallocate(this->_inner_array, this->_capacity);
		}
		value_type*	reallocate_array_with_capacity(size_t new_capacity)
		{
			if (new_capacity <= this->_capacity)
				return (this->_inner_array);
			value_type*	newarray = this->_al.allocate(new_capacity);
			for (size_t i = 0; i < this->_size; i++)
			{
				this->_al.construct(newarray + i, *(this->_inner_array + i));
			}
			delete_all_data_and_deallocate();
			this->_capacity = new_capacity;
			return (newarray);
		}
	};
}

#endif

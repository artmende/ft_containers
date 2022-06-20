/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:51:52 by artmende          #+#    #+#             */
/*   Updated: 2022/06/20 02:46:08 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <algorithm>
# include "iterator.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
/*# include <cstddef>*/



namespace	ft
{
	template<typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef				T													value_type;
		typedef				Alloc												allocator_type;
		typedef typename	allocator_type::reference							reference;
		typedef typename	allocator_type::const_reference						const_reference;
		typedef typename	allocator_type::pointer								pointer;
		typedef typename	allocator_type::const_pointer						const_pointer;
		typedef				std::ptrdiff_t										difference_type;
		typedef				std::size_t											size_type;
		typedef				ft::vector_random_access_iterator<value_type>		iterator;
		typedef				ft::vector_random_access_iterator<const value_type>	const_iterator;
		typedef				ft::reverse_iterator<iterator>						reverse_iterator;
		typedef				ft::reverse_iterator<const_iterator>				const_reverse_iterator;

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

	public:
		////////////////////// CONSTRUCTORS - DESTRUCTOR ///////////////////////

		explicit vector(const allocator_type& alloc = allocator_type()) // default constructor
		: GROWING_FACTOR(2), _al(alloc), _inner_array(NULL), _size(0), _capacity(0)
		{}

		explicit vector(size_type n, const value_type& val = value_type(), // fill constructor
			const allocator_type& alloc = allocator_type())
		: GROWING_FACTOR(2), _al(alloc), _size(n), _capacity(n)
		{
			this->_inner_array = this->_al.allocate(n);
			for (size_t i = 0; i < n; i++)
			{
				this->_al.construct(this->_inner_array + i, val);
			}
		}

		template <class InputIterator>
			vector(InputIterator first, InputIterator last, // range constructor
				const allocator_type& alloc = allocator_type(), typename ft::enable_if< !(ft::is_integral<InputIterator>::value) , InputIterator>::type* = NULL)
		: GROWING_FACTOR(2), _al(alloc), _inner_array(NULL), _size(0), _capacity(0)
		{
			size_type	size_to_allocate = 0;
			for (InputIterator it = first; it != last; ++it)
			{
				++size_to_allocate;
			}
			this->_inner_array = this->_al.allocate(size_to_allocate);
			size_type	i = 0;
			while (first != last)
			{
				this->_al.construct(this->_inner_array + i, *first);
				++first;
				++i;
			}
			this->_capacity = i;
			this->_size = i;
		}

		vector(const vector& x) // copy constructor
		: GROWING_FACTOR(2), _al(allocator_type()), _size(x._size), _capacity(x._capacity)
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


		////////////////////////////// ITERATORS ///////////////////////////////

		iterator	begin()
		{
			return (iterator(this->_inner_array));
		}

		const_iterator	begin() const
		{
			return (const_iterator(this->_inner_array));
		}

		iterator	end() // should i add the const iterator one ?
		{
			return (iterator(this->_inner_array + this->_size));
		}

		const_iterator	end() const // should i add the const iterator one ?
		{
			return (iterator(this->_inner_array + this->_size));
		}

		reverse_iterator	rbegin() const
		{
			return (reverse_iterator(iterator(this->_inner_array + this->_size - 1)));
		}

		reverse_iterator	rend() const
		{
			return (reverse_iterator(iterator(this->_inner_array - 1)));
		}

		/////////////////////////////// CAPACITY ///////////////////////////////

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
				reserve(n > this->_capacity * this->GROWING_FACTOR ? n : this->_capacity * this->GROWING_FACTOR);
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
			if (n <= this->_capacity)
				return ;
			value_type*	newarray = this->_al.allocate(n);
			for (size_t i = 0; i < this->_size; i++)
			{
				this->_al.construct(newarray + i, *(this->_inner_array + i));
			}
			delete_all_data_and_deallocate();
			this->_inner_array = newarray;
			this->_capacity = n;
		}


		///////////////////////////	ELEMENT ACCESS	////////////////////////////

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

		reference	back()
		{
			return ((*this)[this->_size - 1]);
		}

		const_reference	back() const
		{
			return ((*this)[this->_size - 1]);
		}


		///////////////////////////	MODIFIERS	////////////////////////////////


		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last, typename ft::enable_if< !(ft::is_integral<InputIterator>::value) , InputIterator>::type* = NULL) // range
		{
			for (size_t i = 0; i < this->_size; i++)
				this->_al.destroy(this->_inner_array + i);
			size_t	size_to_copy = 0;
			for (InputIterator	temp = first; temp != last; ++temp)
				++size_to_copy;
			if (size_to_copy > this->_capacity) //entering here means size_to_copy is non 0
			{
				delete_all_data_and_deallocate();
				this->_inner_array = this->_al.allocate(size_to_copy);
				this->_capacity = size_to_copy;
			}
			// if size_to_copy is smaller or equal to capacity, it doesnt matter if it's 0 or not. We simply don't touch to the allocation
			for (size_t i = 0; i < size_to_copy; i++)
			{
				this->_al.construct(this->_inner_array + i, *first);
				++first;
			}
			this->_size = size_to_copy;
		}

		void	assign(size_type n, const value_type& val) // fill
		{
			for (size_t i = 0; i < this->_size; i++)
				this->_al.destroy(this->_inner_array + i);
			if (n > this->_capacity) //entering here means size_to_copy is non 0
			{
				delete_all_data_and_deallocate();
				this->_inner_array = this->_al.allocate(n);
				this->_capacity = n;
			}
			for (size_t i = 0; i < n; i++)
				this->_al.construct(this->_inner_array + i, val);
			this->_size = n;
		}

		void	push_back(const value_type& val)
		{
			if (this->_size == this->_capacity) // need to allocate more
				reserve(this->_capacity == 0 ? 1 : this->_capacity * this->GROWING_FACTOR);
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

		iterator	insert(iterator position, const value_type& val) // single element
		{
			size_type	index_position = position - this->begin();
			insert(position, 1, val);
			return (this->begin() + index_position);
		}

		void	insert(iterator position, size_type n, const value_type& val) // fill
		{
			if (this->_size + n > this->_capacity) // need to allocate more, growing factor applied
			{
				size_type	newcapacity = std::max<size_type>(this->_capacity * this->GROWING_FACTOR, this->_size + n);
				value_type*	newarray = this->_al.allocate(newcapacity);
				for (iterator it = this->begin(); it != position; ++it)
					this->_al.construct(newarray + (it - this->begin()), *it);
				for (size_type i = 0; i < n; i++)
					this->_al.construct(newarray + i + (position - this->begin()), val);
				for (iterator it = position; it != this->end(); ++it)
					this->_al.construct(newarray + n + (it - this->begin()), *it);
				delete_all_data_and_deallocate();
				this->_inner_array = newarray;
				this->_capacity = newcapacity;
			}
			else // no need to allocate more
			{
				for (iterator it = this->end() + n - 1; it != position + n - 1; --it)
					*it = *(it - n);
				for (size_type i = 0; i < n; i++)
					this->_al.construct(position.base() + i, val);
			}
			this->_size += n;
		}

/* 		template <class InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if< !(ft::is_integral<InputIterator>::value) , InputIterator>::type* = NULL) // range
		{
			
		} */

//		iterator erase (iterator position);

//		iterator erase (iterator first, iterator last);

//		void swap (vector& x);

//		void clear();

//		allocator_type get_allocator() const;

	};



////////////////////	NON-MEMBER FUNCTION OVERLOADS	////////////////////////

//	template <class T, class Alloc>
//	bool	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

//	template <class T, class Alloc>
//	bool	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

//	template <class T, class Alloc>
//	bool	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

//	template <class T, class Alloc>
//	bool	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

//	template <class T, class Alloc>
//	bool	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

//	template <class T, class Alloc>
//	bool	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

//	template <class T, class Alloc>
//	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

}

#endif

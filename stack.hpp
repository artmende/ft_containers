/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:07:29 by artmende          #+#    #+#             */
/*   Updated: 2022/06/24 18:02:50 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef				T							value_type;
	//	typedef typename	Container					container_type;
		typedef typename	ft::vector<T>				container_type; // delete later
		typedef typename	container_type::size_type	size_type;

	protected:
		container_type	c;

	public:
		explicit stack(const container_type& ctnr = container_type())
		: c(ctnr) {} // does it call copy constructor ?
		
		bool	empty() const
		{
			return (this->c.empty());
		}

		size_type	size() const
		{
			return (this->c.size());
		}

		value_type &	top()
		{
			return (this->c.back()); // If stack is emtpy, it will segfault. That is coherent with the behavior of std::stack
		}

		const value_type &	top() const
		{
			return (this->c.back());
		}

		void	push(const value_type& val)
		{
			this->c.push_back(val);
		}

		void	pop()
		{
			this->c.pop_back();
		}
	private:
		template <class Type, class Cont>
		friend bool	operator==(const stack<Type,Cont>& lhs, const stack<Type,Cont>& rhs);

		template <class Type, class Cont>
		friend bool	operator!=(const stack<Type,Cont>& lhs, const stack<Type,Cont>& rhs);

		template <class Type, class Cont>
		friend bool	operator<(const stack<Type,Cont>& lhs, const stack<Type,Cont>& rhs);

		template <class Type, class Cont>
		friend bool	operator<=(const stack<Type,Cont>& lhs, const stack<Type,Cont>& rhs);

		template <class Type, class Cont>
		friend bool	operator>(const stack<Type,Cont>& lhs, const stack<Type,Cont>& rhs);

		template <class Type, class Cont>
		friend bool	operator>=(const stack<Type,Cont>& lhs, const stack<Type,Cont>& rhs);
	};



	template <class T, class Container>
	bool	operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}

	template <class T, class Container>
	bool	operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c != rhs.c);
	}

	template <class T, class Container>
	bool	operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}

	template <class T, class Container>
	bool	operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c <= rhs.c);
	}

	template <class T, class Container>
	bool	operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c > rhs.c);
	}

	template <class T, class Container>
	bool	operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c >= rhs.c);
	}
}

#endif

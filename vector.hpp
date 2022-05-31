/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:51:52 by artmende          #+#    #+#             */
/*   Updated: 2022/05/31 16:48:46 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>

namespace	ft
{

	template<typename value_type>
	class vector
	{
	private:
		value_type*	_values;
		size_t		_size;
	public:
		vector()
		{}
		~vector(){}

		void	push_back(const value_type& val)
		{
			
		}
	};

}

#endif

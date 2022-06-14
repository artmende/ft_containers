/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:41:22 by artmende          #+#    #+#             */
/*   Updated: 2022/06/14 13:49:39 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft
{
	template <bool, typename T = void>
	struct	enable_if {};

	template <typename T>
	struct	enable_if<true, T>
	{
		typedef	T	type;
	};
}

#endif

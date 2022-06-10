/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfile.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:52:27 by artmende          #+#    #+#             */
/*   Updated: 2022/06/10 17:58:29 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <vector>

#include <string>

#include "vector.hpp"

#include "ClapTrap.hpp"
#include "Array.hpp"


int	main()
{

	ft::vector<int>	v;

	//for (ft::vector<ClapTrap>::size_type i = 0; i < 100; i++)
	//{
	//	std::cout << "Capacity : " << v.capacity() << " | Size : " << v.size() << std::endl;
	//	v.push_back(ClapTrap("Clap number " /* + std::to_string(i) */ ));
	//}

	//std::cout << "BEFORE" << std::endl;
	//v.resize(10);
	//std::cout << "AFTER" << std::endl;

	//std::cout << "Capacity : " << v.capacity() << " | Size : " << v.size() << std::endl;

	//std::cout << "Empty ? " << v.empty() << std::endl;


	//std::cout << v.at(5) << std::endl;

	//ft::vector<ClapTrap>::iterator	it = v.begin();

	//std::cout << *it << std::endl;


	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	ft::vector<int>::const_iterator it = v.begin();








/*	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}*/

//	std::vector<ClapTrap> v2(v);

/*	for (size_t i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i] << std::endl;
	}
	std::cout << "Capacity : " << v2.capacity() << std::endl;*/

//	std::cout << "capacity of v : " << v.capacity() << std::endl;
//	std::cout << "capacity of v2 : " << v2.capacity() << std::endl;





//	system("leaks a.out");

//	ClapTrap	b("Coucou");

//	ft::vector<ClapTrap>	v(1);
/*	v.push_back(ClapTrap("yop"));
	v.push_back(ClapTrap("yoo"));*/
//	std::cout << ((ClapTrap *)(v.get()))[0] << std::endl;

	
	


//	std::cin.get();



//	std::cout << v.capacity() << std::endl;
/*	ClapTrap	b;
	while (true)
	{
		std::cout << "Capacity : " << v.capacity() << " | Size : " << v.size() << std::endl;
		v.push_back(b);
		std::cin.get();
	}*/
	
	

/*	for (size_t i = 0; i < 100; i++)
	{
		std::cout << "Capacity : " << v.capacity() << " | Size : " << v.size() << std::endl;
		v.push_back(ClapTrap());
	}*/

/*
	std::allocator<ClapTrap>	al;

	ClapTrap	*ar = al.allocate(5);

	ClapTrap const & val = ClapTrap("yop");

	for (size_t i = 0; i < 5; i++)
	{
		al.construct(ar + i, val);
	}

	std::cout << ar[3] << std::endl;

*/



/*	ft::vector<ClapTrap>	v(20, ClapTrap("yop"));

	

	ClapTrap	*ar = (ClapTrap *)v.get();

	for (size_t i = 0; i < 20; i++)
	{
		std::cout << *(ar + i) << std::endl;
	}*/






//	std::cin.get();

/*
	v.resize(10, b);
	v.resize(5);
	v.resize(10);

//	system("leaks a.out");
	
	int	a;
	std::cin >> a;

	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
	*/

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:16:33 by artmende          #+#    #+#             */
/*   Updated: 2022/07/13 15:08:26 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <map>
#include <memory>

class Test
{
private:
	std::string _name;
	int const	_some_nbr;

public:
	Test() : _some_nbr(this->gen_nbr()) { std::cout << "default constructor " << this->_name << std::endl; }
	Test(std::string name) : _name(name), _some_nbr(this->gen_nbr()) { std::cout << "string constructor " << this->_name << std::endl; }
	Test(Test const &x) : _name(x._name), _some_nbr(this->gen_nbr()) { std::cout << "copy constructor " << this->_name << std::endl; }
	~Test() {}

	Test &	operator=(Test const &x)
	{
		this->_name = x._name;
		std::cout << "assignment operator " << this->_name << std::endl;
		return (*this);
	}

	bool	operator<(Test const &x) const
	{
		return (this->_name < x._name);
	}

	std::string const &	get_name() const
	{
		return (this->_name);
	}

	int	gen_nbr() const {return 6;} // very random
};

int main()
{

	std::allocator<Test>	al;

	std::map<Test, Test> m;

	Test	*k = al.allocate(sizeof(Test));
	Test	*v = al.allocate(sizeof(Test));

	al.construct(k, "Key");
	al.construct(v, "Value");

	//Test k("Key");
	//Test v("Value");

	std::cout << "\n\n";

	m[*k] = *v;
	m[*v] = *k;

	//m[k] = v;
	//m[v] = k;

	std::cout << "\n\n";

	for (std::map<Test, Test>::iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << (*it).first.get_name() << std::endl;
	}


	return 0;
}

/*class Contclap
{
private:
	ClapTrap	c;

	Contclap();

public:
	Contclap(ClapTrap const & x) //: c(x)
	{
		c = x;
	}

	ClapTrap const &	get_clap() const
	{
		return this->c;
	}
};


int	main()
{
	std::map<int, ClapTrap>	m;

	ClapTrap	jack("jack");



	m.insert(std::pair<int, ClapTrap>(2, jack));

	std::cout << m[2] << std::endl;


	return 0;
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:45:10 by artmende          #+#    #+#             */
/*   Updated: 2022/08/15 15:05:50 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <utility>

#include "pair.hpp"
#include "map.hpp"
#include "bst_iterator.hpp"

# define ft std

int main ()
{

	{
		std::cout << "Testing constructors, assignment operator, iterators and capacity:\n\n";

		ft::map<int, std::string>	temp;
		for (size_t i = 0; i < 5; i++)
		{
			temp[i] = "some string";
		}

		ft::map<int, std::string>::iterator	itmodif = temp.begin();
		++itmodif;
		(*itmodif).second = "yop";

		ft::map<int, std::string>	map_default;
		ft::map<int, std::string>	map_range(temp.begin(), temp.end());
		ft::map<int, std::string>	map_copy(map_range);
		ft::map<int, std::string>	map_assigned;
		map_assigned = map_copy;

		std::cout << "size of map_default : " << map_default.size() << " | size of map_range : " << map_range.size() << " | size of map_copy : " << map_copy.size() << " | size of map_assigned : " << map_assigned.size() << std::endl;
		std::cout << "content of map_assigned : \n";
		for (ft::map<int, std::string>::const_iterator	it = map_assigned.begin(); it != map_assigned.end(); it++)
		{
			std::cout << (*it).first << " --> " << (*it).second << std::endl;
		}

		std::cout << "\niterating through map_range in the reverse order :\n";
		for (ft::map<int, std::string>::const_reverse_iterator it = map_range.rbegin(); it != map_range.rend(); it++)
		{
			std::cout << (*it).first << " --> " << (*it).second << std::endl;
		}

		std::cout << "\nmap_default.empty() : " << map_default.empty() << std::endl;
		std::cout << "map_copy.empty() : " << map_copy.empty() << std::endl;
		std::cout << "Max size of map_default : " << map_default.max_size() << std::endl;

		std::cout << "\n\n";
	}
		//////////////////////////////////////////////
	{
		std::cout << "Testing Element access, modifiers and operations with fresh new maps:\n\n";

		ft::map<int, char>	temp;
		temp[-10] = '~';
		temp[2] = '+';
		temp[17] = '?';

		ft::map<int, char>	my_ascii_letters;
		for (size_t i = 65; i < 75; i++)
		{
			my_ascii_letters[i] = i;
		}
		std::cout << "inserting single element with key 33... Was it already there ? " << !(my_ascii_letters.insert(ft::make_pair<int, char>(33, 33))).second << std::endl; // single element (1)
		std::cout << "inserting single element with key 33... Was it already there ? " << !(my_ascii_letters.insert(ft::make_pair<int, char>(33, 33))).second << std::endl; // second parameter of return of insert single element
		std::cout << "inserting element with key 34 : " << (*(my_ascii_letters.insert(ft::make_pair<int, char>(34, 34)).first)).second << std::endl; // first parameter of return of insert single element
		std::cout << "Inserting element with key 92, then range of elements going from 65 to 75\n";
		my_ascii_letters.insert(my_ascii_letters.begin(), ft::make_pair<int, char>(92, 92)); // with hint (2)
		my_ascii_letters.insert(temp.rbegin(), temp.rend()); // range (3)
		std::cout << "Displaying element with key 200 (It's not there yet)\n";
		std::cout << my_ascii_letters[200] << std::endl; // this create an element with key 200 but the 'second' is set to default value (\0);

		my_ascii_letters.erase(my_ascii_letters.begin()); // erasing first element (key is -10)
		std::cout << "erasing element with key -100... success ? " << my_ascii_letters.erase(-100) << std::endl;
		std::cout << "erasing element with key 66... success ? " << my_ascii_letters.erase(66) << std::endl;

		ft::map<int, char>::iterator	it1, it2;
		it1 = my_ascii_letters.find(71); // find returns an iterator to the found element
		it2 = my_ascii_letters.find(73);

		std::cout << "erasing range from 71 to 73" << std::endl;
		my_ascii_letters.erase(it1, it2);

		std::cout << "\nswapping temp with my_ascii_letters and then clear my_ascii_letters" << std::endl;
		temp.swap(my_ascii_letters);
		my_ascii_letters.clear();
		std::cout << "size of my_ascii_letters : " << my_ascii_letters.size() << std::endl;
		std::cout << "swapping them again..." << std::endl;
		temp.swap(my_ascii_letters);

		std::cout << "\nHow many elements with key 67 ? " << my_ascii_letters.count(67) << std::endl;
		std::cout << "How many elements with key 670 ? " << my_ascii_letters.count(670) << std::endl;

		std::cout << "lower_bound with key 70 : " << (*(it1 = my_ascii_letters.lower_bound(70))).first << " --> " << (*it1).second << std::endl;
		std::cout << "upper_bound with key 70 : " << (*(it1 = my_ascii_letters.upper_bound(70))).first << " --> " << (*it1).second << std::endl;
		ft::pair<ft::map<int, char>::iterator, ft::map<int, char>::iterator>	eqrange = my_ascii_letters.equal_range(34);
		std::cout << "equal_range with key 34 goes from (" << (*(eqrange.first)).first << " --> " << (*(eqrange.first)).second << ") to (" << (*(eqrange.second)).first << " --> " << (*(eqrange.second)).second << ")\n";

		std::cout << "\nDisplaying elements in my_ascii_letters : \n";
		for (ft::map<int, char>::const_iterator	it = my_ascii_letters.begin(); it != my_ascii_letters.end(); it++)
		{
			std::cout << (*it).first << " --> " << (*it).second << std::endl;
		}

		temp[5] = 'j';

		std::cout << "\nmy_ascii_letters == temp ? " << (my_ascii_letters == temp) << std::endl;
		std::cout << "\nmy_ascii_letters != temp ? " << (my_ascii_letters != temp) << std::endl;
		std::cout << "\nmy_ascii_letters > temp ? " << (my_ascii_letters > temp) << std::endl;
		std::cout << "\nmy_ascii_letters < temp ? " << (my_ascii_letters < temp) << std::endl;

		std::cout << "\nmy_ascii_letters == my_ascii_letters ? " << (my_ascii_letters == my_ascii_letters) << std::endl;
		std::cout << "\nmy_ascii_letters != my_ascii_letters ? " << (my_ascii_letters != my_ascii_letters) << std::endl;
		std::cout << "\nmy_ascii_letters <= my_ascii_letters ? " << (my_ascii_letters <= my_ascii_letters) << std::endl;
		std::cout << "\nmy_ascii_letters >= my_ascii_letters ? " << (my_ascii_letters >= my_ascii_letters) << std::endl;
		std::cout << "\nmy_ascii_letters < my_ascii_letters ? " << (my_ascii_letters < my_ascii_letters) << std::endl;
		std::cout << "\nmy_ascii_letters > my_ascii_letters ? " << (my_ascii_letters > my_ascii_letters) << std::endl;


	}

	return 0;
}

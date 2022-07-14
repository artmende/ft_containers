/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_rbt.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:54:25 by artmende          #+#    #+#             */
/*   Updated: 2022/07/14 17:29:33 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "red_black_tree.hpp"
#include "stack.hpp"



template <typename Key, typename T>
void printBT(const std::string& prefix, const ft::red_black_node<Key, T>* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->p.first << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

template <typename Key, typename T>
void printBT(const ft::red_black_node<Key, T>* node)
{
    printBT("", node, false);    
}

// pass the root node of your binary tree




int	main()
{

	std::srand(19);

	ft::stack<int>	st;

	for (size_t i = 0; i < 20; i++)
	{
		st.push(rand() % 200);
	}



	

	ft::red_black_tree<int, int>	rbt;



	while (!st.empty())
	{
		int	temp = st.top();
		ft::pair<const int, int>	pa(temp, temp);
		rbt.insert(pa);
		st.pop();
	}





	printBT(rbt._root);

	std::cout << rbt.find(37)->first << std::endl;

	return 0;
}

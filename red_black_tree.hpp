/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:16:18 by artmende          #+#    #+#             */
/*   Updated: 2022/07/13 15:20:06 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <iostream>
# include <memory>
# include "pair.hpp"

// iterator through the tree : https://stackoverflow.com/questions/2942517/how-do-i-iterate-over-binary-tree

namespace ft
{
	template <typename Key, typename T>
	class red_black_node
	{
	private:
		red_black_node();

		//pair<const Key, T>	init_pair(pair<const Key, T> & x)
		//{
		//	pair<const Key, T>	ret(x.first, T()); // copy constructor for the key
		//	ret.second = x.second; // assignment operator for the value
		//	return ret;
		//}

	public:

		red_black_node(Key const & k)
		: p(pair<const Key, T>(k, T())), left(NULL), right(NULL), parent(NULL), color(false)
		{}

		red_black_node(Key const & k, T & value)
		: p(pair<const Key, T>(k, T())), left(NULL), right(NULL), parent(NULL), color(false)
		{
			this->p.second = value;
		}

		red_black_node(pair<const Key, T> & p_param)
		: /*p(this->init_pair(p)),*/ p(pair<const Key, T>(p_param.first, T())), left(NULL), right(NULL), parent(NULL), color(false)
		{
			this->p.second = p_param.second;
			// node constructor receives a reference to an existing pair. The node doesn't care if that pair is allocated or not.
			// it just initialize the exisiting pair inside the node, to the same value as the reference received
		}

		red_black_node(red_black_node const & x) // template? different template type ?
		: p(x.p), left(NULL), right(NULL), parent(NULL), color(x.color)
		{}

		~red_black_node() {}

		red_black_node &	operator=(red_black_node const & x) // template? different template type ?
		{
			if (&x != this)
			{
				this->v = x.v;
			}
			return (*this);
		}

		pair<const Key, T>		p;
		red_black_node<Key, T>	*left;
		red_black_node<Key, T>	*right;
		red_black_node<Key, T>	*parent;
		bool					color; // true is black, false is red
	};

////////////////////////////////////////////////////////////////////////////////



	//template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > > // probably no need to put = because the type is given by map
	template <class Key, class T, class Compare, class Alloc>
	class red_black_tree
	{
	private:
		red_black_node<Key, T>	*_root;
	//	Alloc	_al;
		std::allocator<red_black_node>	_al;

		red_black_tree(red_black_tree const & x);
		red_black_tree &	operator=(red_black_tree const & x);
	public:
		red_black_tree() : _root(NULL) {}

		~red_black_tree() {}
	
		pair<const Key, T> &	insert(pair<const Key, T> & p) // do i need a function to insert only a key ?
		{
			if (this->_root == NULL)
			{
				this->_root = this->_al.allocate(sizeof(red_black_node<Key, T>));
				this->_al.construct(this->_root, p); // no need to set the parent ptr in the new node, because its the root. it remains NULL
				return ;
			}

			red_black_node<Key, T>	*browse = this->_root;
			red_black_node<Key, T>	*parent;

			while (browse)
			{
				parent = browse; // keeping the parent node
				if (p.first < browse->p.first)
				{
					browse = browse->left;
					continue;
				}
				else if (browse->p.first < p.first)
				{
					browse = browse->right;
					continue;
				}
				else
					return (browse->p);
			}
			// here browse is a NULL pointer. It means its parent is the node that we have to insert under
			if (p.first < parent->p.first)
			{
				parent->left = this->_al.allocate(sizeof(red_black_node<Key, T>));
				this->_al.construct(parent->left, p);
				parent->left->parent = parent;
			}
			else
			{
				parent->right = this->_al.allocate(sizeof(red_black_node<Key, T>));
				this->_al.construct(parent->right, p);
				parent->right->parent = parent;
			}
		}

		pair<const Key, T>	*find(Key const & k)
		{
			red_black_node<Key, T>	*browse = this->_root;

			while (browse)
			{
				if (k < browse->p.first)
				{
					browse = browse->left;
					continue;
				}
				else if (browse->p.first < k)
				{
					browse = browse->right;
					continue;
				}
				else
					return (&(browse->p));
			}
			return NULL;
		}

		void	delete_node(Key const & k);

	};



}


#endif

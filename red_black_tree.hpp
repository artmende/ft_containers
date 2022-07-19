/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:16:18 by artmende          #+#    #+#             */
/*   Updated: 2022/07/19 11:30:38 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <iostream>
# include <memory>
# include "pair.hpp"

// iterator through the tree : https://stackoverflow.com/questions/2942517/how-do-i-iterate-over-binary-tree
// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c



namespace ft
{
	template <typename T>
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

		//red_black_node(Key const & k)
		//: p(pair<const Key, T>(k, T())), left(NULL), right(NULL), parent(NULL), color(false)
		//{}

		//red_black_node(Key const & k, T & value)
		//: p(pair<const Key, T>(k, T())), left(NULL), right(NULL), parent(NULL), color(false)
		//{
		//	this->p.second = value;
		//}

		//red_black_node(pair<const Key, T> & p_param)
		//: /*p(this->init_pair(p)),*/ p(pair<const Key, T>(p_param.first, T())), left(NULL), right(NULL), parent(NULL), color(false)
		//{
		//	this->p.second = p_param.second;
		//	// node constructor receives a reference to an existing pair. The node doesn't care if that pair is allocated or not.
		//	// it just initialize the exisiting pair inside the node, to the same value as the reference received
		//}

		red_black_node(T const & value) : v(value), left(NULL), right(NULL), parent(NULL), color(false)
		{}

		red_black_node(red_black_node const & x) // template? different template type ?
		: v(x.v), left(NULL), right(NULL), parent(NULL), color(x.color)
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

		T					v; // v is a real object that is part of the node. Deleting the node will delete p, no need to worry about something else
		red_black_node<T>	*left;
		red_black_node<T>	*right;
		red_black_node<T>	*parent;
		bool				color; // true is black, false is red
	};

////////////////////////////////////////////////////////////////////////////////



//	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > > // probably no need to put = because the type is given by map
//	template <class Key, class T, class Compare, class Alloc>
	template <typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<red_black_node<T> > >
	class red_black_tree
	{
	public:
	red_black_node<T>	*_root;
	private:
		
	//	Alloc	_al;
		std::allocator<T>	_al;

		red_black_tree(red_black_tree const & x);
		red_black_tree &	operator=(red_black_tree const & x);
	public:
		red_black_tree() : _root(NULL) {}

		~red_black_tree() {}
	
		red_black_node<T>	*insert(T & v) // returns a pointer to the newly added node
		{
			if (this->_root == NULL)
			{
				this->_root = this->_al.allocate(1);
				this->_al.construct(this->_root, v); // no need to set the parent ptr in the new node, because its the root. it remains NULL
				return this->_root;
			}

			red_black_node<T>	*browse = this->_root;
			red_black_node<T>	*parent;

			while (browse)
			{
				parent = browse; // keeping the parent node
				if (v < browse->v)
				{
					browse = browse->left;
					continue;
				}
				else if (browse->v < v)
				{
					browse = browse->right;
					continue;
				}
				else
					return (browse); // this means what we want to insert already exist in the tree. We just return the already existing node
			}
			// here browse is a NULL pointer. It means its parent is the node that we have to insert under
			if (v < parent->v)
			{
				parent->left = this->_al.allocate(1);
				this->_al.construct(parent->left, v);
				parent->left->parent = parent;
				return parent->left;
			}
			else
			{
				parent->right = this->_al.allocate(sizeof(red_black_node<Key, T>));
				this->_al.construct(parent->right, p);
				parent->right->parent = parent;
				return parent->right->p;
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

		void	delete_node(Key const & k)
		{
			// 3 cases : 
			// if delete leaf node, just delete it and put parent ptr to NULL
			// if delete node with only 1 child, connect the child to the parent and delete
			// if delete node with 2 children, take the smallest in the right subtree and make it replace the node to delete


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
				{
					if (browse->left == NULL && browse->right == NULL) // deleting leaf node
					{
						if (browse->parent == NULL)
						{
							this->_root = NULL;
							this->_al.destroy(browse);
							this->_al.deallocate(browse, sizeof(red_black_node<Key, T>));
							return ;
						}
						if (browse->parent->left == browse)
						{
							browse->parent->left = NULL;
							this->_al.destroy(browse);
							this->_al.deallocate(browse, sizeof(red_black_node<Key, T>));
							return ;
						}
						if (browse->parent->right == browse)
						{
							browse->parent->right = NULL;
							this->_al.destroy(browse);
							this->_al.deallocate(browse, sizeof(red_black_node<Key, T>));
							return ;
						}
					}
					if ((browse->left == NULL && browse->right) || (browse->left && browse->right == NULL)) // deleting node with only one child
					{
						red_black_node<Key, T>	*subtree = (browse->left ? browse->left : browse->right);

						subtree->parent = browse->parent;
						if (browse->parent == NULL)
						{
							this->_root = subtree;
							this->_al.destroy(browse);
							this->_al.deallocate(browse, sizeof(red_black_node<Key, T>));
							return ;
						}
						if (browse->parent->left == browse)
						{
							browse->parent->left = subtree;
							this->_al.destroy(browse);
							this->_al.deallocate(browse, sizeof(red_black_node<Key, T>));
							return ;
						}
						if (browse->parent->right == browse)
						{
							browse->parent->right = subtree;
							this->_al.destroy(browse);
							this->_al.deallocate(browse, sizeof(red_black_node<Key, T>));
							return ;
						}
					}
				}
			}
			// k is not in the tree. Nothing to do.


		}

	};



}


#endif

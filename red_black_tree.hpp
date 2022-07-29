/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:16:18 by artmende          #+#    #+#             */
/*   Updated: 2022/07/29 15:51:08 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <iostream>
# include <memory>
# include <functional>


// iterator through the tree : https://stackoverflow.com/questions/2942517/how-do-i-iterate-over-binary-tree
// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c



namespace ft
{
	template <typename T>
	class red_black_node
	{
	private:
		red_black_node();
		red_black_node(red_black_node const & x);
		red_black_node &	operator=(red_black_node const & x);

	public:

		typedef	T	value_type;

		red_black_node(T *value) : v(*value), left(NULL), right(NULL), parent(NULL), color(false)
		{
//			v = value; // cannot because it wouldnt work with const element
		}

		//red_black_node(red_black_node const & x) // template? different template type ?
		//: v(x.v), left(NULL), right(NULL), parent(NULL), color(x.color)
		//{} // I don't think I need it

		~red_black_node()
		{}

		//red_black_node &	operator=(red_black_node const & x) // template? different template type ?
		//{
		//	if (&x != this)
		//	{
		//		this->v = x.v;
		//	}
		//	return (*this);
		//} // I don't think I need it

		T &					v;
		red_black_node<T>	*left;
		red_black_node<T>	*right;
		red_black_node<T>	*parent;
		bool				color; // true is black, false is red // use ENUM
	};

////////////////////////////////////////////////////////////////////////////////



//	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > > // probably no need to put = because the type is given by map
//	template <class Key, class T, class Compare, class Alloc>
	template <typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<red_black_node<T> > >
	class red_black_tree
	{
		typedef typename Alloc::template rebind<red_black_node<T> >::other	allocator_type;
	public:
		red_black_node<T>	*_root;
	private:
		
		allocator_type	_al;
		Compare			_c;
	//	std::allocator<red_black_node<T> >	_al;



	public:
		red_black_tree() : _root(NULL) {}


		red_black_tree(red_black_tree const & x) : _root(NULL), _c(x._c)
		{
			red_black_node<T>	*node = x.find_first_node(x._root);
			while (node)
			{
				this->insert(node->v);
				node = x.find_successor(node);
			}
		}

		red_black_tree &	operator=(red_black_tree const & x) // do i need to copy allocator and compare ?
		{
			if (this != &x)
			{
				while (this->_root)
					this->remove(this->_root);
				const red_black_node<T>	*node = x.find_first_node(x._root);
				while (node)
				{
					this->insert(node->v);
					node = x.find_successor(node);
				}
			}
			return (*this);
		}

		red_black_tree(Compare comp) : _root(NULL), _c(comp) {std::cout << "comp constructor called\n";}

		~red_black_tree()
		{
			while (this->_root)
				this->remove(this->_root);
		}

		static red_black_node<T>	*find_successor(const red_black_node<T> *node)
		{
/*
			Next rule: The successor of a node is:
Next-R rule: If it has a right subtree, the leftmost node in the right subtree.
Next-U rule: Otherwise, traverse up the tree
If you make a right turn (i.e. this node was a left child), then that parent node is the successor
If you make a left turn (i.e. this node was a right child), continue going up.
If you can't go up anymore, then there's no successor
*/

			if (node == NULL)
				return (NULL);
			if (node->right)
			{
				red_black_node<T>	*ret = node->right;
				while (ret->left)
					ret = ret->left;
				return (ret);
			}
			else // no right subtree
			{
				red_black_node<T>	*ret = node->parent;
				while (ret)
				{
					if (ret->right == node) // we did a left turn
					{
						node = ret;
						ret = ret->parent;
					}
					else // we did a right turn
					{
						return (ret);
					}
				}
				return (NULL);
			}
		}

		static red_black_node<T>	*find_predecessor(const red_black_node<T> *node)
		{
			if (node == NULL)
				return (NULL);
			if (node->left)
			{
				red_black_node<T>	*ret = node->left;
				while (ret->right)
					ret = ret->right;
				return (ret);
			}
			else
			{
				red_black_node<T>	*ret = node->parent;
				while (ret)
				{
					if (ret->left == node)
					{
						node = ret;
						ret = ret->parent;
					}
					else
					{
						return (ret);
					}
				}
				return (NULL);
			}
		}

		static red_black_node<T>	*find_first_node(red_black_node<T> *any_node_in_tree) // this one is static and needs to take a node as param
		{ // if it receives NULL, it returns NULL
			while (red_black_tree<T, Compare, Alloc>::find_predecessor(any_node_in_tree))
				any_node_in_tree = red_black_tree<T, Compare, Alloc>::find_predecessor(any_node_in_tree);
			return (any_node_in_tree);
		}

		red_black_node<T>	*find_first_node()
		{
			red_black_node<T>	*ret = this->_root;

			while (this->find_predecessor(ret))
				ret = find_predecessor(ret);
			return (ret);
		}


		red_black_node<T>	*insert(T const & v) // returns a pointer to the newly added node
		{
			// idea : In map, after inserting, use the assignment operator on the mapped type

			typedef typename Alloc::template rebind<T>::other	alloc_value;

			alloc_value	al_value;

			T	*val_to_insert	= al_value.allocate(1);
			al_value.construct(val_to_insert, v);

			if (this->_root == NULL)
			{
				this->_root = this->_al.allocate(1);
				this->_al.construct(this->_root, val_to_insert); // no need to set the parent ptr in the new node, because its the root. it remains NULL
				return this->_root;
			}

			red_black_node<T>	*browse = this->_root;
			red_black_node<T>	*parent;

			while (browse)
			{
				parent = browse; // keeping the parent node
//				if (v < browse->v)
				if (this->_c(v, browse->v)) //////////////////////////
				{
					browse = browse->left;
					continue;
				}
//				else if (browse->v < v)
				else if (this->_c(browse->v, v))
				{
					browse = browse->right;
					continue;
				}
				else
				{
					al_value.destroy(val_to_insert);
					al_value.deallocate(val_to_insert, 1);
					return (browse); // this means what we want to insert already exist in the tree. We just return the already existing node
				}
			}
			// here browse is a NULL pointer. It means its parent is the node that we have to insert under
//			if (v < parent->v)
			if (this->_c(v, parent->v))
			{
				parent->left = this->_al.allocate(1);
				this->_al.construct(parent->left, val_to_insert);
				parent->left->parent = parent;
				return parent->left;
			}
			else
			{
				parent->right = this->_al.allocate(1);
				this->_al.construct(parent->right, val_to_insert);
				parent->right->parent = parent;
				return parent->right;
			}
		}

		red_black_node<T>	*find(T const & v) // not const because returned ptr can be used to edit the node
		{
			red_black_node<T>	*browse = this->_root;

			while (browse)
			{
//				if (v < browse->v)
				if (this->_c(v, browse->v))
				{
					browse = browse->left;
					continue;
				}
//				else if (browse->v < v)
				else if (this->_c(browse->v, v))
				{
					browse = browse->right;
					continue;
				}
				else // means we found it
					return (browse);
			}
			return NULL; // means we didnt find it
		}

		void	remove(T const & v)
		{
			this->remove(this->find(v));
		}

		void	remove(red_black_node<T> *to_delete)
		{

			typedef typename Alloc::template rebind<T>::other	alloc_value;

			alloc_value	al_value;

						// 3 cases : 
			// if delete leaf node, just delete it and put parent ptr to NULL
			// if delete node with only 1 child, connect the child to the parent and delete
			// if delete node with 2 children, take the smallest in the right subtree and make it replace the node to delete

			if (to_delete == NULL) // if the node was not in the tree, nothing to do
				return;

			if (to_delete->left == NULL && to_delete->right == NULL) // deleting leaf node
			{
				if (to_delete->parent == NULL) // deleting root node
				{
					this->_root = NULL;
					al_value.destroy(&(to_delete->v));
					al_value.deallocate(&(to_delete->v), 1);
					this->_al.destroy(to_delete);
					this->_al.deallocate(to_delete, 1);
					return;
				}
				if (to_delete->parent->left == to_delete)
				{
					to_delete->parent->left = NULL;
					al_value.destroy(&(to_delete->v));
					al_value.deallocate(&(to_delete->v), 1);
					this->_al.destroy(to_delete);
					this->_al.deallocate(to_delete, 1);
					return;
				}
				if (to_delete->parent->right == to_delete)
				{
					to_delete->parent->right = NULL;
					al_value.destroy(&(to_delete->v));
					al_value.deallocate(&(to_delete->v), 1);
					this->_al.destroy(to_delete);
					this->_al.deallocate(to_delete, 1);
					return;
				}
			}
			else if ((to_delete->left == NULL && to_delete->right) || (to_delete->left && to_delete->right == NULL)) // deleting node with only one child
			{
				red_black_node<T>	*subtree = (to_delete->left ? to_delete->left : to_delete->right);

				subtree->parent = to_delete->parent;
				if (to_delete->parent == NULL)
				{
					this->_root = subtree;
					al_value.destroy(&(to_delete->v));
					al_value.deallocate(&(to_delete->v), 1);
					this->_al.destroy(to_delete);
					this->_al.deallocate(to_delete, 1);
					return;
				}
				if (to_delete->parent->left == to_delete)
				{
					to_delete->parent->left = subtree;
					al_value.destroy(&(to_delete->v));
					al_value.deallocate(&(to_delete->v), 1);
					this->_al.destroy(to_delete);
					this->_al.deallocate(to_delete, 1);
					return;
				}
				if (to_delete->parent->right == to_delete)
				{
					to_delete->parent->right = subtree;
					al_value.destroy(&(to_delete->v));
					al_value.deallocate(&(to_delete->v), 1);
					this->_al.destroy(to_delete);
					this->_al.deallocate(to_delete, 1);
					return;
				}
			}
			else // deleting node with 2 children
			{
				red_black_node<T>	*smallest_in_right_subtree = to_delete->right;

				while (smallest_in_right_subtree->left)
					smallest_in_right_subtree = smallest_in_right_subtree->left; // finding smallest in right sub
			
				if (smallest_in_right_subtree->right)
					smallest_in_right_subtree->right->parent = smallest_in_right_subtree->parent; // connecting his child to the parent

				if (smallest_in_right_subtree->parent->left == smallest_in_right_subtree)
					smallest_in_right_subtree->parent->left = smallest_in_right_subtree->right;
				else
					smallest_in_right_subtree->parent->right = smallest_in_right_subtree->right; // connecting new parent to child

				smallest_in_right_subtree->parent = to_delete->parent;
				smallest_in_right_subtree->left = to_delete->left;
				smallest_in_right_subtree->right = to_delete->right;

				if (to_delete->parent)
				{
					if (to_delete->parent->left == to_delete)
						to_delete->parent->left = smallest_in_right_subtree;
					else
						to_delete->parent->right = smallest_in_right_subtree;
				}
				else
					this->_root = smallest_in_right_subtree;

				if (to_delete->left)
					to_delete->left->parent = smallest_in_right_subtree;
				if (to_delete->right)
					to_delete->right->parent = smallest_in_right_subtree;
				al_value.destroy(&(to_delete->v));
				al_value.deallocate(&(to_delete->v), 1);
				this->_al.destroy(to_delete);
				this->_al.deallocate(to_delete, 1);
				return;

				// smallest in right subtree can only have 1 child max, and it has to be right child (because left would be smaller)
				// right child has to become child of parent of smallest (can be NULL but doesnt matter)
				// parent and children of to_delete has to become parent and children of smallest

				
			}
		}




	};



}


#endif

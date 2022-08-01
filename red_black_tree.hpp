/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:16:18 by artmende          #+#    #+#             */
/*   Updated: 2022/08/01 16:31:44 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <iostream>
# include <memory>
# include <functional>
# include "bst_iterator.hpp"


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

		//typedef	T	value_type;

		T &					v;
		red_black_node<T>	*left;
		red_black_node<T>	*right;
		red_black_node<T>	*parent;
		bool				color; // true is black, false is red // use ENUM
		bool				empty;

		red_black_node(T *value, bool empty) : v(*value), left(NULL), right(NULL), parent(NULL), color(false), empty(empty) {}
		~red_black_node() {}

		red_black_node<T>	*find_successor() const
		{
/*
			Next rule: The successor of a node is:
Next-R rule: If it has a right subtree, the leftmost node in the right subtree.
Next-U rule: Otherwise, traverse up the tree
If you make a right turn (i.e. this node was a left child), then that parent node is the successor
If you make a left turn (i.e. this node was a right child), continue going up.
If you can't go up anymore, then there's no successor
*/
			if (this->right)
			{
				red_black_node<T>	*ret = this->right;
				while (ret->left)
					ret = ret->left;
				return (ret);
			}
			else // no right subtree
			{
				red_black_node<T>	*ret = this->parent;
				const red_black_node<T>	*temp_child = this;
				while (ret)
				{
					if (ret->right == temp_child) // we did a left turn
					{
						temp_child = ret;
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

		red_black_node<T>	*find_predecessor() const
		{
			if (this->left)
			{
				red_black_node<T>	*ret = this->left;
				while (ret->right)
					ret = ret->right;
				return (ret);
			}
			else
			{
				red_black_node<T>	*ret = this->parent;
				const red_black_node<T>	*temp_child = this;
				while (ret)
				{
					if (ret->left == temp_child)
					{
						temp_child = ret;
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

		const red_black_node<T>	*find_first_node() const
		{
			const red_black_node<T>	*ret = this;
			while (ret->find_predecessor())
				ret = ret->find_predecessor();
			return (ret);
		}

		const red_black_node<T>	*find_last_node() const
		{
			const red_black_node<T>	*ret = this;
			while (ret->find_successor())
				ret = ret->find_successor();
			return (ret);
		}
	};

////////////////////////////////////////////////////////////////////////////////

	template <typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<red_black_node<T> > >
	class red_black_tree
	{
		typedef typename	Alloc::template rebind<red_black_node<T> >::other	allocator_type;
		typedef typename	Alloc::template rebind<T>::other					alloc_value;
	public:
		typedef				bst_iterator<T, red_black_node<T> >					iterator;
		typedef				bst_iterator<const T, red_black_node<T> >			const_iterator;


		red_black_node<T>	*_root;
	private:
		
		allocator_type	_al;
		alloc_value		al_value;
		Compare			_c;

	public:
		red_black_tree() : _root(create_empty_node()) {} // problem to put _root to NULL, because we neet to be able to initiate iterator on an empty tree. It has to point somewhere.
		// so we need a special node that will exist only when the tree is empty, and will be deleted as soon as we insert something

		red_black_tree(Compare comp) : _root(create_empty_node()), _c(comp) {std::cout << "comp constructor called\n";} // remove the message later

		red_black_tree(red_black_tree const & x) : _root(NULL), _c(x._c)
		{
			*this = x;
		}

		red_black_tree &	operator=(red_black_tree const & x)
		{
			
			if (this != &x)
			{
				while (this->_root)
					this->remove(this->_root);
				const red_black_node<T>	*node = x.find_first_node();
				while (node)
				{
					this->insert(node->v);
					node = node->find_successor();
				}
			}
			return (*this);
		}

		~red_black_tree()
		{
			while (this->_root && this->_root->empty == false)
				this->remove(this->_root);
			destroy_and_deallocate_node(this->_root); // Necessary because when the last node is removed, an empty node takes its place
		}

		iterator	begin()
		{
			iterator	ret(this->_root->find_first_node());
			if (this->_root->empty == true)
				++ret;
			return (ret);
		}

		iterator	end()
		{
			iterator	ret(this->_root->find_last_node());
			++ret;
			return (ret);
		}


		const red_black_node<T>	*find_first_node() const
		{
			return (this->_root->find_first_node());
		}

		const red_black_node<T>	*find_last_node() const
		{
			return (this->_root->find_last_node());
		}

		red_black_node<T>	*insert(T const & v) // returns a pointer to the newly added node
		{
			// idea : In map, after inserting, use the assignment operator on the mapped type

			T	*val_to_insert	= al_value.allocate(1);
			this->al_value.construct(val_to_insert, v);

			if (this->_root == NULL || this->_root->empty == true) // if root is null, second part will not be evaluated
			{
				this->destroy_and_deallocate_node(this->_root); // Ok to be called on a NULL pointer. This will get rid of the empty node
				this->_root = this->_al.allocate(1);
				this->_al.construct(this->_root, val_to_insert, false); // no need to set the parent ptr in the new node, because its the root. it remains NULL
				return this->_root;
			}

			red_black_node<T>	*browse = this->_root;
			red_black_node<T>	*parent;

			while (browse)
			{
				parent = browse; // keeping the parent node
				if (this->_c(v, browse->v))
				{
					browse = browse->left;
					continue;
				}
				else if (this->_c(browse->v, v))
				{
					browse = browse->right;
					continue;
				}
				else
				{
					this->al_value.destroy(val_to_insert);
					this->al_value.deallocate(val_to_insert, 1);
					return (browse); // this means what we want to insert already exist in the tree. We just return the already existing node
				}
			}
			// here browse is a NULL pointer. It means its parent is the node that we have to insert under
			if (this->_c(v, parent->v))
			{
				parent->left = this->_al.allocate(1);
				this->_al.construct(parent->left, val_to_insert, false);
				parent->left->parent = parent;
				return parent->left;
			}
			else
			{
				parent->right = this->_al.allocate(1);
				this->_al.construct(parent->right, val_to_insert, false);
				parent->right->parent = parent;
				return parent->right;
			}
		}

		red_black_node<T>	*find(T const & v) // not const because returned ptr can be used to edit the node
		{
			red_black_node<T>	*browse = this->_root;

			while (browse)
			{
				if (this->_c(v, browse->v))
				{
					browse = browse->left;
					continue;
				}
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
						// 3 cases : 
			// if delete leaf node, just delete it and put parent ptr to NULL
			// if delete node with only 1 child, connect the child to the parent and delete
			// if delete node with 2 children, take the smallest in the right subtree and make it replace the node to delete

			if (to_delete == NULL) // if the node was not in the tree, nothing to do
				return;

			if (to_delete->left == NULL && to_delete->right == NULL) // deleting leaf node, can i do only one destroy and deallocate at the end ?
			{
				if (to_delete->parent == NULL) // deleting root node
					this->_root = NULL;
				else if (to_delete->parent->left == to_delete) // to_delete is a left child
					to_delete->parent->left = NULL;
				else // to_delete is a right child
					to_delete->parent->right = NULL;
			}
			else if ((to_delete->left == NULL && to_delete->right) || (to_delete->left && to_delete->right == NULL)) // deleting node with only one child
			{
				red_black_node<T>	*subtree = (to_delete->left ? to_delete->left : to_delete->right);

				subtree->parent = to_delete->parent;
				if (to_delete->parent == NULL) // deleting root node
					this->_root = subtree;
				else if (to_delete->parent->left == to_delete) // to_delete is a left child
					to_delete->parent->left = subtree;
				else // to_delete is a right child
					to_delete->parent->right = subtree;
			}
			else // deleting node with 2 children
			{
				red_black_node<T>	*smallest_in_right_subtree = to_delete->right;

				while (smallest_in_right_subtree->left)
					smallest_in_right_subtree = smallest_in_right_subtree->left; // finding smallest in right sub
			
				if (smallest_in_right_subtree->right)
					smallest_in_right_subtree->right->parent = smallest_in_right_subtree->parent; // connecting his child to the parent

				if (smallest_in_right_subtree->parent->left == smallest_in_right_subtree) // smallest_in_right_subtree can only have a right child, the left child is always NULL
					smallest_in_right_subtree->parent->left = smallest_in_right_subtree->right; // it makes its right child (NULL or not) replace himself for his parent
				else // that would mean smallest_in_right_subtree is the direct right child of to_delete
					smallest_in_right_subtree->parent->right = smallest_in_right_subtree->right; // connecting new parent to child

				smallest_in_right_subtree->parent = to_delete->parent;
				smallest_in_right_subtree->left = to_delete->left;
				smallest_in_right_subtree->right = to_delete->right;

				// now smallest_in_right_subtree has replaced to_delete, 

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

				// smallest in right subtree can only have 1 child max, and it has to be right child (because left would be smaller)
				// right child has to become child of parent of smallest (can be NULL but doesnt matter)
				// parent and children of to_delete has to become parent and children of smallest
			}
			this->destroy_and_deallocate_node(to_delete);
			if (this->_root == NULL)
				this->_root = create_empty_node();
		}

		void	destroy_and_deallocate_node(red_black_node<T> *to_delete)
		{
			if (to_delete == NULL)
				return ;
			this->al_value.destroy(&(to_delete->v));
			this->al_value.deallocate(&(to_delete->v), 1);
			this->_al.destroy(to_delete);
			this->_al.deallocate(to_delete, 1);
		}

		red_black_node<T>	*create_empty_node()
		{
			T	*val_to_insert	= al_value.allocate(1);
			this->al_value.construct(val_to_insert, T());
			red_black_node<T>	*ret = this->_al.allocate(1);
			this->_al.construct(ret, val_to_insert, true);
			return (ret);
		}

	};



}


#endif

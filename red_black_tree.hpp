/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:16:18 by artmende          #+#    #+#             */
/*   Updated: 2022/08/08 18:49:08 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <iostream>
# include <memory>
# include <functional>
# include "bst_iterator.hpp"

# define RED false
# define BLACK true

// iterator through the tree : https://stackoverflow.com/questions/2942517/how-do-i-iterate-over-binary-tree
// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c

// NEED TO CHANGE THE INSERT FUNCTION TO HAVE ONLY ONE RETURN AND MAKE SURE THE ROOT IS PROPERLY SAVED INSIDE NULLNODE

namespace ft
{
	template <typename T>
	class red_black_node // all node contains a bool indicating if they are nullnode or not. Parent of nullnode can always be the root
	{
	private:
		red_black_node();
		


	public:

		//typedef	T	value_type;

		T &					v;
		red_black_node<T>	*left;
		red_black_node<T>	*right;
		red_black_node<T>	*parent;
		red_black_node<T>	*nullnode;
		bool				color; // true is black, false is red // use ENUM
		bool				is_nullnode;
		bool				is_temp_node;

		red_black_node(T *value, bool color, bool is_nullnode = false, bool is_temp_node = false)
		: v(*value), left(NULL), right(NULL), parent(NULL), nullnode(NULL), color(color), is_nullnode(is_nullnode), is_temp_node(is_temp_node) {}
		red_black_node(red_black_node const & x)
		: v(x.v), left(x.left), right(x.right), parent(x.parent), nullnode(x.nullnode), color(x.color), is_nullnode(x.is_nullnode), is_temp_node(x.is_temp_node) {}
		~red_black_node() {}

		red_black_node &	operator=(red_black_node const & x) // this should be private
		{
			if (this != &x)
			{
				this->v = x.v; // that's not okay. It will call the assignation operator on v
				this->left = x.left;
				this->right = x.right;
				this->parent = x.parent;
				this->nullnode = x.nullnode;
				this->color = x.color; // do i need this ? 
				this->is_nullnode = x.is_nullnode;
			}
			return (*this);
		}


/*
	Successor of nullnode will look at the root. if the root exist, it will return the find_first_node from the root. if the root doesnt exist, it will return itself
*/

		const red_black_node<T>	*find_successor() const
		{
/*
			Next rule: The successor of a node is:
Next-R rule: If it has a right subtree, the leftmost node in the right subtree.
Next-U rule: Otherwise, traverse up the tree
If you make a right turn (i.e. this node was a left child), then that parent node is the successor
If you make a left turn (i.e. this node was a right child), continue going up.
If you can't go up anymore, then there's no successor
*/
			if (this->is_nullnode)
			{
				if (this->parent)
					return (this->parent->find_first_node());
				else
					return (this);
			}
			else if (this->right)
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
				return (this->nullnode);
			}
		}

		const red_black_node<T>	*find_predecessor() const
		{
			if (this->is_nullnode)
			{
				if (this->parent)
					return (this->parent->find_last_node());
				else
					return (this);
			}
			else if (this->left)
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
				return (this->nullnode);
			}
		}

		const red_black_node<T>	*find_first_node() const
		{
			const red_black_node<T>	*ret = this;
			while (ret->find_predecessor()->is_nullnode == false)
				ret = ret->find_predecessor();
			return (ret);
		}

		const red_black_node<T>	*find_last_node() const
		{
			const red_black_node<T>	*ret = this;
			while (ret->find_successor()->is_nullnode == false)
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


		red_black_node<T>	*_root; // do those need to be public ?
		red_black_node<T>	*_nullnode;
	private:
		
		allocator_type	_al;
		alloc_value		al_value;
		Compare			_c;
		size_t			_size;

	public:
		red_black_tree() : _root(NULL), _nullnode(create_nullnode()), _size(0) {} // problem to put _root to NULL, because we neet to be able to initiate iterator on an empty tree. It has to point somewhere.
		// so we need a special node that will exist only when the tree is empty, and will be deleted as soon as we insert something

		red_black_tree(Compare comp) : _root(NULL), _nullnode(create_nullnode()), _c(comp), _size(0) {}

		red_black_tree(red_black_tree const & x) : _root(NULL), _nullnode(create_nullnode()), _c(x._c), _size(0)
		{
			*this = x;
		}

		red_black_tree &	operator=(red_black_tree const & x)
		{
			
			if (this != &x)
			{
				// maybe better to go from the root first to the left, and then to the right. instead of inserting from first node to last node.
				while (this->_root)
					this->remove(this->_root);
				const red_black_node<T>	*node = x.find_first_node();
				while (node->is_nullnode == false)
				{
					this->insert(node->v);
					node = node->find_successor();
				}
			}
			return (*this);
		}

		~red_black_tree()
		{
			// no need to balance the tree when deleting here
			while (this->_root)
				this->remove(this->_root);
			destroy_and_deallocate_node(this->_nullnode);
		}

		void	swap(red_black_tree & x)
		{
			size_t				size_temp = x._size;
			red_black_node<T>	*root_temp = x._root;
			red_black_node<T>	*nullnode_temp = x._nullnode;

			x._size = this->_size;
			x._root = this->_root;
			x._nullnode = this->_nullnode;

			this->_size = size_temp;
			this->_root = root_temp;
			this->_nullnode = nullnode_temp;
		}

		size_t	size() const
		{
			return (this->_size);
		}

		size_t	max_size() const
		{
			return (this->_al.max_size());
		}

		iterator	begin()
		{
			iterator	ret(this->_nullnode->find_first_node());
			return (ret);
		}

		const_iterator	begin() const
		{
			const_iterator	ret(this->_nullnode->find_first_node());
			return (ret);
		}

		iterator	end() // just return null node
		{
			iterator	ret(this->_nullnode);
			return (ret);
		}

		const_iterator	end() const // just return null node
		{
			const_iterator	ret(this->_nullnode);
			return (ret);
		}

		const red_black_node<T>	*find_first_node() const
		{
			return (this->_nullnode->find_first_node()); // need to optimize this !
		}

		const red_black_node<T>	*find_last_node() const
		{
			return (this->_nullnode->find_last_node()); // need to optimize this !
		}

		void	left_rotate(red_black_node<T> *pivot)
		{
			if (pivot->right == NULL)
				return;
			red_black_node<T>	*right_child_of_pivot = pivot->right; // pivot will become its left child
			red_black_node<T>	*left_child_of_right_child_of_pivot = pivot->right->left; // will become right child of pivot
			red_black_node<T>	*parent_of_pivot = pivot->parent; // will become parent of right child of pivot

			right_child_of_pivot->parent = parent_of_pivot;
			right_child_of_pivot->left = pivot;
			pivot->parent = right_child_of_pivot;
			pivot->right = left_child_of_right_child_of_pivot;
			if (left_child_of_right_child_of_pivot)
				left_child_of_right_child_of_pivot->parent = pivot;

			if (right_child_of_pivot->parent == NULL)
				this->_root = right_child_of_pivot;
			else
			{
				if (parent_of_pivot->right == pivot)
					parent_of_pivot->right = right_child_of_pivot;
				else
					parent_of_pivot->left = right_child_of_pivot;
			}
			this->_nullnode->parent = this->_root;
		}

		void	right_rotate(red_black_node<T> *pivot)
		{
			if (pivot->left == NULL)
				return;
			red_black_node<T>	*left_child_of_pivot = pivot->left; // pivot will become its right child
			red_black_node<T>	*right_child_of_left_child_of_pivot = pivot->left->right; // will become left child of pivot
			red_black_node<T>	*parent_of_pivot = pivot->parent; // will become parent of left child of pivot

			left_child_of_pivot->parent = parent_of_pivot;
			left_child_of_pivot->right = pivot;
			pivot->parent = left_child_of_pivot;
			pivot->left = right_child_of_left_child_of_pivot;
			if (right_child_of_left_child_of_pivot)
				right_child_of_left_child_of_pivot->parent = pivot;

			if (left_child_of_pivot->parent == NULL)
				this->_root = left_child_of_pivot;
			else
			{
				if (parent_of_pivot->right == pivot)
					parent_of_pivot->right = left_child_of_pivot;
				else
					parent_of_pivot->left = left_child_of_pivot;
			}
			this->_nullnode->parent = this->_root;
		}

		void	recolor_node(red_black_node<T> *node)
		{
			if (node == NULL)
				return;
			if (node->color == BLACK)
				node->color = RED;
			else
				node->color = BLACK;
		}

		void	replace_node_by_another_in_tree(red_black_node<T> *to_delete, red_black_node<T> *replacement)
		{
		// this function does not affect previous family of replacement
			// connecting parent of to_delete to replacement
			if (to_delete->parent == NULL)
				this->_root = replacement;
			else if (to_delete->parent->left == to_delete)
				to_delete->parent->left = replacement;
			else
				to_delete->parent->right = replacement;
			// connecting children of to_delete to replacement
			if (to_delete->left)
				to_delete->left->parent = replacement;
			if (to_delete->right)
				to_delete->right->parent = replacement;
			// connecting replacement to its new parent and children
			replacement->parent = to_delete->parent;
			replacement->left = to_delete->left;
			replacement->right = to_delete->right;
		}

		red_black_node<T>	*get_replacement_in_subtree(red_black_node<T> *node)
		{
			red_black_node<T>	*ret;
			if (node->left)
			{
				ret = node->left;
				while (ret->right)
					ret = ret->right;
			}
			else if (node->right)
			{
				ret = node->right;
				while (ret->left)
					ret = ret->left;
			}
			else
				ret = NULL;
			return (ret);
		}

		red_black_node<T>	*get_uncle(red_black_node<T> *node) /*const*/ // probably cannot put const here because the pointer received can be use to recolor
		{
			if (node == NULL || node->parent == NULL || node->parent->parent == NULL || node->is_nullnode == true)
				return (NULL);
			if (node->parent->parent->left == node->parent)
				return (node->parent->parent->right);
			else
				return (node->parent->parent->left);
		}

		bool	three_nodes_form_a_line(red_black_node<T> *node, red_black_node<T> *parent, red_black_node<T> *grand_parent) /*const*/
		{
			if (node == NULL || parent == NULL || grand_parent == NULL)
				return (false);
			return ((grand_parent->left == parent && grand_parent->left->left == node) || (grand_parent->right == parent && grand_parent->right->right == node));
		}

		red_black_node<T>	*fix_rbt_insert(red_black_node<T> *inserted_node)
		{
			if (inserted_node == NULL || inserted_node->parent == NULL || inserted_node->parent->color == BLACK || inserted_node->is_nullnode == true)
				return (inserted_node);
			// here the parent can only be non null and RED
			red_black_node<T>	*uncle = this->get_uncle(inserted_node);
			if (uncle && uncle->color == RED)
			{
				this->recolor_node(inserted_node->parent);
				this->recolor_node(uncle);
				// inserted_node->parent is non NULL and is RED. That means it's not the root. Its parent must be non NULL too
				if (inserted_node->parent->parent->parent != NULL) // recolor grand parent only if it's not the root
					this->recolor_node(inserted_node->parent->parent);
				fix_rbt_insert(inserted_node->parent->parent); // we have to check from grand parent now
			}
			else // uncle is black or NULL
			{
				red_black_node<T>	*original_parent = inserted_node->parent;
				red_black_node<T>	*original_grand_parent = original_parent->parent; // the only one that is guaranteed to not move
				if (false == this->three_nodes_form_a_line(inserted_node, original_parent, original_grand_parent))
				{ // we need to rotate parent in direction opposite to inserted_node
					if (inserted_node->parent->left == inserted_node)
						this->right_rotate(inserted_node->parent);
					else
						this->left_rotate(inserted_node->parent);
				}
				// here they form a line
				if (original_grand_parent->left == original_parent || original_grand_parent->left == inserted_node)
				{
					this->recolor_node(original_grand_parent);
					this->recolor_node(original_grand_parent->left);
					this->right_rotate(original_grand_parent);
				}
				else
				{
					this->recolor_node(original_grand_parent);
					this->recolor_node(original_grand_parent->right);
					this->left_rotate(original_grand_parent);
				}
			}
			//this->_nullnode->parent = this->_root; // no need because rotation already take care of it
			return (inserted_node);
		}


		red_black_node<T>	*insert(T const & v) // returns a pointer to the newly added node
		{

			T	*val_to_insert	= al_value.allocate(1);
			this->al_value.construct(val_to_insert, v);
			this->_size++; //////////////////////////////

			if (this->_root == NULL)
			{
				this->_root = this->_al.allocate(1);
				red_black_node<T>	n(val_to_insert, BLACK/*, false*/); // temporary object to pass 3 parameters to node constructor
				this->_al.construct(this->_root, n); // no need to set the parent ptr in the new node, because its the root. it remains NULL
				this->_root->nullnode = this->_nullnode; //////////////////////////////////////////
				this->_nullnode->parent = this->_root; // from the nullnode, following the parent pointer brings to the root of the tree
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
					this->_size--; ////////////////////////////
					return (browse); // this means what we want to insert already exist in the tree. We just return the already existing node
				}
			}
			// here browse is a NULL pointer. It means its parent is the node that we have to insert under
			red_black_node<T>	n(val_to_insert, RED/*, false*/); // temporary object to pass 3 parameters to node constructor
			if (this->_c(v, parent->v))
			{
				parent->left = this->_al.allocate(1);
				this->_al.construct(parent->left, n);
				parent->left->nullnode = this->_nullnode; //////////////////////
				parent->left->parent = parent;
			//	return parent->left;
				return (this->fix_rbt_insert(parent->left));
			}
			else
			{
				parent->right = this->_al.allocate(1);
				this->_al.construct(parent->right, n);
				parent->right->nullnode = this->_nullnode;/////////////////////
				parent->right->parent = parent;
			//	return parent->right;
				return (this->fix_rbt_insert(parent->right));
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

		const red_black_node<T>	*find(T const & v) const
		{
			const red_black_node<T>	*browse = this->_root;

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

		iterator	lower_bound(T const & v)
		{
			red_black_node<T>	*browse = this->_root;

			while (browse)
			{
				if (this->_c(v, browse->v)) // the v that we are looking for is smaller than current node
				{
					if (browse->left == NULL)
						return (iterator(browse));
					browse = browse->left;
					continue;
				}
				else if (this->_c(browse->v, v)) // the v that we are looking for is bigger than current node
				{
					if (browse->right == NULL)
					{
						iterator	ret(browse);
						++ret;
						return (ret);
					}
					browse = browse->right;
					continue;
				}
				else // means we fount it
					return (iterator(browse));
			}
			return (this->end()); // in case the tree is empty
		}

		const_iterator	lower_bound(T const & v) const
		{
			const red_black_node<T>	*browse = this->_root;

			while (browse)
			{
				if (this->_c(v, browse->v)) // the v that we are looking for is smaller than current node
				{
					if (browse->left == NULL)
						return (const_iterator(browse));
					browse = browse->left;
					continue;
				}
				else if (this->_c(browse->v, v)) // the v that we are looking for is bigger than current node
				{
					if (browse->right == NULL)
					{
						const_iterator	ret(browse);
						++ret;
						return (ret);
					}
					browse = browse->right;
					continue;
				}
				else // means we fount it
					return (const_iterator(browse));
			}
			return (this->end()); // in case the tree is empty
		}

		iterator	upper_bound(T const & v)
		{
			if (this->_root == NULL)
				return (this->end());
			else
			{
				iterator	ret = this->lower_bound(v);
				if (ret != this->end() && !(this->_c(v, *ret) || this->_c(*ret, v)))
					++ret;
				return (ret);
			}
		}

		const_iterator	upper_bound(T const & v) const
		{
			if (this->_root == NULL)
				return (this->end());
			else
			{
				const_iterator	ret = this->lower_bound(v);
				if (ret != this->end() && !(this->_c(v, *ret) || this->_c(*ret, v)))
					++ret;
				return (ret);
			}
		}




		void	remove(T const & v)
		{
			this->remove(this->find(v));
		}

		void	remove(red_black_node<T> *to_delete)
		{
						// 3 cases : NOPEE
			// if delete leaf node, just delete it and put parent ptr to NULL - ONLY IF NODE IS RED OR IS ROOT
			// if delete node with only 1 child, connect the child to the parent and delete - ONLY IF NODE IS RED OR IS ROOT
			// if delete node with 2 children, take the smallest in the right subtree and make it replace the node to delete

			if (to_delete == NULL) // if the node was not in the tree, nothing to do
				return;

			if (to_delete->left == NULL && to_delete->right == NULL) // deleting leaf node
			{
				if (to_delete == this->_root) // root doesnt have parent, null node will be updated at the end of remove function
					this->_root = NULL;
				else if (to_delete->color == RED)
				{
					if (to_delete->parent->left == to_delete)
						to_delete->parent->left = NULL;
					else
						to_delete->parent->right = NULL;
				}
				else // to_delete is black
				{
					T	*double_black_val = al_value.allocate(1);
					this->al_value.construct(double_black_val, T());
					red_black_node<T>	double_black_temp(double_black_val, BLACK, false, true);
					red_black_node<T>	*double_black = this->_al.allocate(1);
					this->_al.construct(double_black, double_black_temp);
					if (to_delete->parent->left == to_delete)
						to_delete->parent->left = double_black;
					else
						to_delete->parent->right = double_black;
					// here need to call function for steps for double black
				}
			}
			else // to_delete is not leaf node
			{
				red_black_node<T>	*replacement = this->get_replacement_in_subtree(to_delete);
				if (replacement->left || replacement->right) // replacement has a child
				{
					if (replacement->left) // replacement has a left child
					{
						replacement->left->color = BLACK;
						replacement->parent->right = replacement->left; // the replacement can only have a child in the opposite direction of itself (or it wouln't be the replacement)
						replacement->left->parent = replacement->parent;
					}
					else // replacement has a right child
					{
						replacement->right->color = BLACK;
						replacement->parent->left = replacement->right;
						replacement->right->parent = replacement->parent;
					}
					replace_node_by_another_in_tree(to_delete, replacement);
				}
				else // replacement does not have a child
				{
					
				}

			}


			//if ((to_delete == this->_root || to_delete->color == RED) && to_delete->left == NULL && to_delete->right == NULL) // deleting leaf node
			//{
			//	if (to_delete->parent == NULL) // deleting root node
			//		this->_root = NULL;
			//	else if (to_delete->parent->left == to_delete) // to_delete is a left child
			//		to_delete->parent->left = NULL;
			//	else // to_delete is a right child
			//		to_delete->parent->right = NULL;
			//}
			//else if ((to_delete->color == RED || to_delete == this->_root) && ((to_delete->left == NULL && to_delete->right) || (to_delete->left && to_delete->right == NULL))) // deleting node with only one child
			//{
			//	// red node cannot have only 1 child
			//	// root with one child can only happen in a tree with 2 nodes
			//	// let's just delete this whole section
			//	red_black_node<T>	*subtree = (to_delete->left ? to_delete->left : to_delete->right);

			//	subtree->parent = to_delete->parent;
			//	if (to_delete->parent == NULL) // deleting root node
			//	{
			//		this->_root = subtree;
			//		subtree->color = BLACK; // root has to be black. It doesnt change anything to the subtree
			//	}
			//	else if (to_delete->parent->left == to_delete) // to_delete is a left child
			//		to_delete->parent->left = subtree;
			//	else // to_delete is a right child
			//		to_delete->parent->right = subtree;
			//}
			//else // deleting node with 2 children
			//{
			//	red_black_node<T>	*smallest_in_right_subtree = to_delete->right;

			//	while (smallest_in_right_subtree->left)
			//		smallest_in_right_subtree = smallest_in_right_subtree->left; // finding smallest in right sub
			
			//	if (smallest_in_right_subtree->right)
			//		smallest_in_right_subtree->right->parent = smallest_in_right_subtree->parent; // connecting his child to the parent

			//	if (smallest_in_right_subtree->parent->left == smallest_in_right_subtree) // smallest_in_right_subtree can only have a right child, the left child is always NULL
			//		smallest_in_right_subtree->parent->left = smallest_in_right_subtree->right; // it makes its right child (NULL or not) replace himself for his parent
			//	else // that would mean smallest_in_right_subtree is the direct right child of to_delete
			//		smallest_in_right_subtree->parent->right = smallest_in_right_subtree->right; // connecting new parent to child

			//	smallest_in_right_subtree->parent = to_delete->parent;
			//	smallest_in_right_subtree->left = to_delete->left;
			//	smallest_in_right_subtree->right = to_delete->right;

			//	// now smallest_in_right_subtree has replaced to_delete, 

			//	if (to_delete->parent)
			//	{
			//		if (to_delete->parent->left == to_delete)
			//			to_delete->parent->left = smallest_in_right_subtree;
			//		else
			//			to_delete->parent->right = smallest_in_right_subtree;
			//	}
			//	else
			//		this->_root = smallest_in_right_subtree;

			//	if (to_delete->left)
			//		to_delete->left->parent = smallest_in_right_subtree;
			//	if (to_delete->right)
			//		to_delete->right->parent = smallest_in_right_subtree;

			//	// smallest in right subtree can only have 1 child max, and it has to be right child (because left would be smaller)
			//	// right child has to become child of parent of smallest (can be NULL but doesnt matter)
			//	// parent and children of to_delete has to become parent and children of smallest
			//}



			this->destroy_and_deallocate_node(to_delete);
			this->_nullnode->parent = this->_root;
			this->_size--;
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

		red_black_node<T>	*create_nullnode()
		{
			T	*val_to_insert = al_value.allocate(1);
			this->al_value.construct(val_to_insert, T());
			red_black_node<T>	*ret = this->_al.allocate(1);
			red_black_node<T>	n(val_to_insert, BLACK, true); // temporary object to pass 3 parameters to node constructor
			this->_al.construct(ret, n);
		//	this->_al.construct(ret, val_to_insert, true);
			ret->nullnode = ret; ///////////////////////////////////////////////
			return (ret);
		}

	};



}

# undef RED
# undef BLACK

#endif

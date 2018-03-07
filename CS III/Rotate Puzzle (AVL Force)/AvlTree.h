#pragma once
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "AvlGameState.h"

#include <algorithm>
#include <iostream> 
#include <cassert>


// AvlTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert(x)       --> Insert x
// void remove(x)       --> Remove x (unimplemented)
// bool contains(x)     --> Return true if x is present
// Comparable findMin()  --> Return smallest item
// Comparable findMax()  --> Return largest item
// boolean isEmpty()     --> Return true if empty; else false
// void makeEmpty()      --> Remove all items
// void printTree()      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class AvlTree
{
public:
	AvlTree() : root{ nullptr }	//constructor
	{ }

	AvlTree(const AvlTree & rhs) : root{ nullptr }	//custom constructor 
	{
		root = clone(rhs.root); //checks if the node passed is null and, if not, creates an AvlNode with same data
	}

	AvlTree(AvlTree && rhs) : root{ rhs.root }
	{
		rhs.root = nullptr; //sets root to zero
	}

	~AvlTree()		//destructor for the whole tree
	{
		makeEmpty();	//clears the whole tree passed
	}

	/**
	* Deep copy.
	*/
	AvlTree & operator=(const AvlTree & rhs)		//overloads the '=' symbol to swap a copy of passed Node with *this and returns it
	{
		AvlTree copy = rhs;
		std::swap(*this, copy);
		return *this;
	}

	/**
	* Move.
	*/
	AvlTree & operator=(AvlTree && rhs)
	{
		std::swap(root, rhs.root);		//overloads the '=' symbol to swap the root with the rightHandTree.root
		return *this;
	}

	/**
	* Find the smallest item in the tree.
	* Abort if empty.
	*/

	void toString()
	{
		std::string indent = "";
		toStringFull(root, indent);
	}


	/*void remove(const Comparable & x)
	{
		remove(x, root);
	}*/
	void removeMin()
	{
		remove(findMin());
		balance(root);
	}

	void removeMinComplex()
	{
		removeMinComplexFull(root);
		//balance(root);
	}
	

	const Comparable & findMin() const
	{
		assert(!isEmpty());				//first check if the tree is empty and either aborts or continues
		return findMin(root)->element;	//recursively searches through the AVL to find the smallest item in the tree
	}

	/**
	* Find the largest item in the tree.
	* Abortif empty.
	*/
	const Comparable & findMax() const
	{
		assert(!isEmpty());;			//first check if the tree is empty and either aborts or continues
		return findMax(root)->element;	//recursively searches through the AVL to find the largest item in the tree
	}

	/**
	* Returns true if x is found in the tree.
	*/
	bool contains(const Comparable & x) const
	{
		return contains(x, root);		//checks to see if the passed 'x' is even there and then returns a true if it's there.
	}

	/**
	* Test if the tree is logically empty.
	* Return true if empty, false otherwise.
	*/
	bool isEmpty() const
	{
		return root == nullptr;		//if the root is a nullptr returns true, returns false otherwise.
	}

	/**
	* Print the tree contents in sorted order.
	*/
	void printTree() const
	{
		if (isEmpty())
			std::cout << "Empty tree" << std::endl;		//checks for empty
		else
			printTree(root);	//recursively prints root
	}

	/**
	* Make the tree logically empty.
	*/
	void makeEmpty()
	{
		makeEmpty(root);
	}

	/*
	* Insert x into the tree; duplicates are allowed
	*/
	void insert(const Comparable & x)
	{
		insert(x, root);		//doesn't check for repeats, just inserts the value.
	}

	/**
	* Insert x into the tree; duplicates are allowed
	*/
	void insert(Comparable && x)
	{
		insert(std::move(x), root);		// a
	}

	/**
	* Remove x from the tree. Nothing is done if x is not found.
	*/
	void remove(const Comparable & x)
	{
		remove(x, root);
	}


//======================================================================================================================//
	//------------------------------------------------------------------------------------------------------------------------//
//======================================================================================================================//
   	//------------------------------------------------------------------------------------------------------------------------//
//======================================================================================================================//
	//------------------------------------------------------------------------------------------------------------------------//
//======================================================================================================================//
	//------------------------------------------------------------------------------------------------------------------------//
//======================================================================================================================//
	//------------------------------------------------------------------------------------------------------------------------//
//======================================================================================================================//


private:
	struct AvlNode
	{
		Comparable element;
		AvlNode   *leftHandTree;
		AvlNode   *rightHandTree;
		int       height;

		AvlNode(const Comparable & element, AvlNode *lTree, AvlNode *rTree, int height = 0)
			: element{ element }, leftHandTree{ lTree }, rightHandTree{ rTree }, height{ height } { }

		AvlNode(Comparable && element, AvlNode *lTree, AvlNode *rTree, int height = 0)
			: element{ std::move(element) }, leftHandTree{ lTree }, rightHandTree{ rTree }, height{ height } { }
	};

	AvlNode *root;

	/*int BinaryTree<Etype>::size(TreeNode<Etype> *t) const*/
	void toStringFull(AvlNode *t, std::string indent)
	{
		if (t == NULL || t->element < 0) return;	//if the pointer is NULL or is dramatically lower than 0 (in case your machine fills it with garbage values like mine)
		toStringFull(t->rightHandTree, indent + "  ");
		if (t->element != NULL)
			std::cout << indent << t->element << std::endl; // "(" << t->parent->element << ")" << endl;
		else
			std::cout << indent << t->element << "(no value)" << std::endl;
		toStringFull(t->leftHandTree, indent + "  ");
	}

	void removeMinComplexFull(AvlNode *& t)
	{
		while (t->leftHandTree != nullptr)
		{
			t = t->leftHandTree;
		}
		AvlNode *oldNode = t;	//oldNode now contains the passedNode to set as essentially a dummy
		t = (t->leftHandTree != nullptr) ? t->leftHandTree : t->rightHandTree;	//if t->leftHandTree doesn't exist, insert 't' into leftHandTree, otherwise enter into t->rightHandTree
		oldNode = nullptr;
		delete oldNode;
		balance(t);

	}

	/*
	* Internal method to insert into a subtree.
	* x is the item to insert.
	* t is the node that roots the subtree.
	* Set the new root of the subtree.
	*/
	void insert(const Comparable & x, AvlNode * & t)
	{
		//std::cout << "insert &" << x << std::endl;
		if (t == nullptr)
		{
			t = new AvlNode{ x, nullptr, nullptr };
		}
		//else if (x < t->element)
		else if (x <= t->element)
		{
			insert(x, t->leftHandTree);
		}
		else if (t->element < x)
		{
			insert(x, t->rightHandTree);
		}
		balance(t);	//balances the tree to make sure everything works fine.
	}

	/*
	* Internal method to insert into a subtree.
	* x is the item to insert.
	* t is the node that roots the subtree.
	* Set the new root of the subtree.
	*/
	void insert(Comparable && x, AvlNode * & t)
	{
		//std::cout << "insert &&" << x << std::endl;

		if (t == nullptr)		//if the root is non-existent, then it inserts it here.
		{
			t = new AvlNode{ std::move(x), nullptr, nullptr }; //creates the new Node
		}
		else if (x <= t->element) //if the element is less than the current node, insert it to the leftHandTree 
		{
			insert(std::move(x), t->leftHandTree);
		}
		else if (t->element < x)	//if the element is greater than, insert to the rightHandTree
		{
			insert(std::move(x), t->rightHandTree);
		}
		balance(t);	//balance the tree
	}

	/**
	* Internal method to remove from a subtree.
	* x is the item to remove.
	* t is the node that roots the subtree.
	* Set the new root of the subtree.
	*/
	void remove(const Comparable & x, AvlNode * & t)	//pass a Comparable and a Node
	{
		if (t == nullptr) return;   // Item not found; do nothing

		if (x < t->element)		//if the Comparable is less than t's, remove leftHandTree
		{
			remove(x, t->leftHandTree);		
		}
		else if (t->element < x)	//pass a Comparable, if it is greater than t's, remove rightHandTree
		{
			remove(x, t->rightHandTree);
		}
		else if (t->leftHandTree != nullptr && t->rightHandTree != nullptr) // Two children
		{
			t->element = findMin(t->rightHandTree)->element;	//if there are two children, the t->element is the fmallest number in the rightHandTree subtree
			remove(t->element, t->rightHandTree);	//remove the t->element found
		}
		else
		{
			AvlNode *oldNode = t;	//oldNode now contains the passedNode to set as essentially a dummy
			t = (t->leftHandTree != nullptr) ? t->leftHandTree : t->rightHandTree;	//if t->leftHandTree doesn't exist, insert 't' into leftHandTree, otherwise enter into t->rightHandTree
			delete oldNode;
		}
		balance(t);		//balance the tree
	}

	static const int ALLOWED_IMBALANCE = 1;

	// Assume t is balanced or within one of being balanced
	void balance(AvlNode * & t)
	{
		if (t == nullptr)
			return;

		if (height(t->leftHandTree) - height(t->rightHandTree) > ALLOWED_IMBALANCE)	//check to see if the AVL tree is actually an AVL
			if (height(t->leftHandTree->leftHandTree) >= height(t->leftHandTree->rightHandTree))	//leftHandTree->leftHandTree is greater than leftHandTree->rightHandTree, rotate leftHandTree at t
				rotateWithLeftChild(t);
			else
				doubleWithLeftChild(t);	//do a double rotation on leftHandTree child
		else
			if (height(t->rightHandTree) - height(t->leftHandTree) > ALLOWED_IMBALANCE)
				if (height(t->rightHandTree->rightHandTree) >= height(t->rightHandTree->leftHandTree))
					rotateWithRightChild(t);
				else
					doubleWithRightChild(t);

		t->height = max(height(t->leftHandTree), height(t->rightHandTree)) + 1;
	}

	/**
	* Internal method to find the smallest item in a subtree t.
	* Return node containing the smallest item.
	*/
	AvlNode * findMin(AvlNode *t) const 
	{ 
		if (t == nullptr)
			return nullptr; 
		if (t->leftHandTree == nullptr)
			return t; 
		return findMin(t->leftHandTree); }

	/**
	* Internal method to find the largest item in a subtree t.
	* Return node containing the largest item.
	*/
	AvlNode * findMax(AvlNode *t) const
	{
		if (t != nullptr)
			while (t->rightHandTree != nullptr)
				t = t->rightHandTree;
		return t;
	}


	/**
	* Internal method to test if an item is in a subtree.
	* x is item to search for.
	* t is the node that roots the tree.
	*/
	bool contains(const Comparable & x, AvlNode *t) const
	{
		if (t == nullptr)
			return false;
		else if (x < t->element)
			return contains(x, t->leftHandTree);
		else if (t->element < x)
			return contains(x, t->rightHandTree);
		else
			return true;    // Match
	}
	/****** NONRECURSIVE VERSION*************************
	bool contains( const Comparable & x, AvlNode *t ) const
	{
	while( t != nullptr )
	if( x < t->element )
	t = t->leftHandTree;
	else if( t->element < x )
	t = t->rightHandTree;
	else
	return true;    // Match

	return false;   // No match
	}
	*****************************************************/

	/**
	* Internal method to make subtree empty.
	*/
	void makeEmpty(AvlNode * & t)
	{
		if (t != nullptr)
		{
			makeEmpty(t->leftHandTree);
			makeEmpty(t->rightHandTree);
			delete t;
		}
		t = nullptr;
	}

	/**
	* Internal method to print a subtree rooted at t in sorted order.
	*/
	void printTree(AvlNode *t) const
	{
		if (t != nullptr)
		{
			printTree(t->leftHandTree);
			std::cout  << t->element << " ";
			printTree(t->rightHandTree);
		}
	}

	/**
	* Internal method to clone subtree.
	*/
	AvlNode * clone(AvlNode *t) const
	{
		if (t == nullptr)
			return nullptr;
		else
			return new AvlNode{ t->element, clone(t->leftHandTree), clone(t->rightHandTree), t->height };
	}
	// Avl manipulations
	/**
	* Return the height of node t or -1 if nullptr.
	*/
	int height(AvlNode *t) const
	{
		return t == nullptr ? -1 : t->height;
	}

	int max(int leftHandTree, int rightHandTree) const
	{
		return leftHandTree > rightHandTree ? leftHandTree : rightHandTree;
	}

	/**
	* Rotate binary tree node with leftHandTree child.
	* For AVL trees, this is a single rotation for case 1.
	* Update heights, then set new root.
	*/
	void rotateWithLeftChild(AvlNode * & key2)
	{
		AvlNode *key1 = key2->leftHandTree;
		key2->leftHandTree = key1->rightHandTree;
		key1->rightHandTree = key2;
		key2->height = max(height(key2->leftHandTree), height(key2->rightHandTree)) + 1;
		key1->height = max(height(key1->leftHandTree), key2->height) + 1;
		key2 = key1;
	}

	/**
	* Rotate binary tree node with rightHandTree child.
	* For AVL trees, this is a single rotation for case 4.
	* Update heights, then set new root.
	*/
	void rotateWithRightChild(AvlNode * & key)
	{
		AvlNode *k2 = key->rightHandTree;
		key->rightHandTree = k2->leftHandTree;
		k2->leftHandTree = key;
		key->height = max(height(key->leftHandTree), height(key->rightHandTree)) + 1;
		k2->height = max(height(k2->rightHandTree), key->height) + 1;
		key = k2;
	}

	/**
	* Double rotate binary tree node: first leftHandTree child.
	* with its rightHandTree child; then node key with new leftHandTree child.
	* For AVL trees, this is a double rotation for case 2.
	* Update heights, then set new root.
	*/
	void doubleWithLeftChild(AvlNode * & key)
	{
		rotateWithRightChild(key->leftHandTree);
		rotateWithLeftChild(key);
	}

	/*
	* Double rotate binary tree node: first rightHandTree child.
	* with its leftHandTree child; then node key with new rightHandTree child.
	* For AVL trees, this is a double rotation for case 3.
	* Update heights, then set new root.
	*/
	void doubleWithRightChild(AvlNode * & key)
	{
		rotateWithLeftChild(key->rightHandTree);
		rotateWithRightChild(key);
	}

};

#endif

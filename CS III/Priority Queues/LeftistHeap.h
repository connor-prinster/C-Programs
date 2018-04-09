#pragma once
#include "Node.h"
#include "ItemType.h"

class LeftistHeap
{
public:
	static const int KIDS = 2;
	LeftistHeap(std::string, int physicalSize);	//constructor
	LeftistHeap(LeftistHeap &rhs);	//copy constructor
	~LeftistHeap();	//destructor
	bool isEmpty();	//bool to check if there is nothing in the heap
	bool isFull();	//bool that probably won't be used and potentially not implemented
	ItemType & findMin();	//find the min value and return it's value
	void insert(ItemType &x);
	ItemType deleteMin();	//will be called in the 
	//ItemType & deleteMin(ItemType &minItem);
	void makeEmpty();
	void merge(LeftistHeap &rhs);
	LeftistHeap & operator=(LeftistHeap &rhs);
	int getSize() {return size;};
	std::string name;
private:
	Node * root;	//pretty obvious, it's the root...
	Node *merge(Node * h1, Node * h2);	//merge function for one set of characteristics
	Node *merge1(Node *h1, Node *h2);	//					the other set of characteristics
	void swapChildren(Node * t);	//for when the right is bigger than the left, the children will be swapped.
	void hardDeleteNode(Node * t);	//internal call that makeEmpty will make
	Node * clone(Node * t);
	int physicalSize;	//the size of the heap, not sure if necessary but I'll keep it anyways.
	int npl;
	int size = 0;
};

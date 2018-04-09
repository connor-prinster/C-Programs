#include "LeftistHeap.h"

LeftistHeap::LeftistHeap(std::string name, int physicalSize)	//Construct the leftist heap
{
	this->name = name;
	size = 0;
	root = NULL;
	this->physicalSize = physicalSize;
	npl = 0;
}

LeftistHeap::LeftistHeap(LeftistHeap &rhs)	//copy constructor
{
	root = NULL;
	*this = rhs;
	npl = 0;
}

LeftistHeap::~LeftistHeap()	//Destruct the leftist heap
{
	makeEmpty();
}

void LeftistHeap::merge(LeftistHeap & rhs) //merge rhs into the priority queue
{
	if (this == &rhs) return;
	root = merge(root, rhs.root);
	rhs.root = NULL;
}

Node * LeftistHeap::merge(Node * h1, Node * h2)
{
	if (h1 == NULL) 
		return h2;
	if (h2 == NULL) 
		return h1;
	if (h1->element.priority < h2->element.priority) 
		return merge1(h1, h2);
	else 
		return merge1(h2, h1);
}

Node * LeftistHeap::merge1(Node * h1, Node * h2)
{
	if (h1->left == NULL) 
		h1->left = h2;
	else
	{
		h1->right = merge(h1->right, h2);
		if (h1->left->element.word < h1->right->element.word)
			swapChildren(h1);
	}
	return h1;
}

void LeftistHeap::swapChildren(Node * t)
{
	Node * tmp = t->left;
	t->left = t->right;
	t->right = tmp;
}

void LeftistHeap::insert(ItemType &x)
{
	root = merge(new Node(x), root);
	size++;
}

ItemType &LeftistHeap::findMin()
{
	return root->element;
}

//void LeftistHeap::deleteMin()
ItemType LeftistHeap::deleteMin()
{
	assert(!isEmpty());
	Node * oldRoot = root;
	root = merge(root->left, root->right);
	//ItemType item = oldRoot->element;
	delete oldRoot;
	size--;
	ItemType minItem = findMin();
	return minItem;
}

bool LeftistHeap::isEmpty()
{
	return root == NULL;
}

bool LeftistHeap::isFull()	//this is more of a "hey, let's make it in case something goes wrong"
{
	return false;
}

void LeftistHeap::makeEmpty()
{
	hardDeleteNode(root);
	root = NULL;
}

LeftistHeap & LeftistHeap::operator=(LeftistHeap & rhs)
{
	if (this != &rhs)
	{
		makeEmpty();
		root = clone(rhs.root);
	}

	return *this;
}

void LeftistHeap::hardDeleteNode(Node * t)
{
	if (t != NULL)
	{
		hardDeleteNode(t->left);
		hardDeleteNode(t->right);
		delete t;
	}
}

Node * LeftistHeap::clone(Node * t)
{
	if (t == NULL)
		return NULL;
	else
		return new Node(t->element, clone(t->left), clone(t->right));
}
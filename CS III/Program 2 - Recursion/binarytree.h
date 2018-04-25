#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <stack>  

using namespace std;

template <class Etype>
class TreeNode
{
public:
	Etype element;  // value in node
	TreeNode *left;  // left child
	TreeNode *right; // right child
	TreeNode *parent; // parent of node
	TreeNode(Etype e = 0, TreeNode *l = NULL, TreeNode *r = NULL, TreeNode *p = NULL) :
		element(e), left(l), right(r), parent(p) { }
	TreeNode(int data) : element(data), left(NULL), right(NULL), parent(NULL) { }
};

template <class Etype>
class BinaryTree
{
protected:
	TreeNode<Etype> *root;  // root of tree
	Etype LOW;   // Smallest possible value stored in tree
	Etype HIGH;  // Largest possible value stored in tree
	bool insert(Etype & x, TreeNode<Etype> * & t, TreeNode<Etype>*  p);
	void printTree(TreeNode<Etype> * t, std::string indent, int currDepth = 0, int maxDepth = numeric_limits<int>::max());
	TreeNode<Etype> * findFirst(TreeNode<Etype> * t) const;
	TreeNode<Etype> * find(TreeNode<Etype> * curr, Etype value)const;
	int size(TreeNode<Etype> *t) const;
	TreeNode <Etype>* currentNode;
	void printShortFull(TreeNode<Etype> *passNode);
	void fallFull(TreeNode<Etype> *passNode);
	void removeSubtree(TreeNode<Etype> *nodeToDestroy);
	TreeNode<Etype> * successorFull(TreeNode<Etype> * root, TreeNode<Etype> * p);
	vector<Etype> findPath(TreeNode<Etype> * passedNode);
	TreeNode<Etype> * closestCommonFull(TreeNode<Etype> * node1, TreeNode<Etype> * node2);
	int widthFull(TreeNode<Etype> * passedNode);
	void mirrored(TreeNode<Etype> * passedNode);

public:
	/* Return the leftmost value in the tree.  Set a local currentNode to that node.*/
	BinaryTree(Etype low = 0, Etype high = 0) : root(NULL)
	{
		LOW = low;
		HIGH = high;
	}
	Etype getFirst()
	{
		currentNode = findFirst(root);
		if (currentNode == NULL) return LOW;
		return currentNode->element;
	}

	bool isBST()
	{
		return true;
	}

	void makeEmpty()
	{

	}

	//find the successor to currentNode.  Change currentNode to point to the successor.
	void printShort(std::string message)
	{
		this->getFirst();
		cout << message << endl;
		printShortFull(this->root);
		cout << endl;
	}

	void fall()
	{
		fallFull(this->root);
	}

	void successor()
	{
		currentNode = successorFull(root, currentNode);
	}

	string closestCommon(Etype t1, Etype t2)
	{
		int closestCommon = 0;
		this->getCurrNodeValue();
		TreeNode<Etype> * node1 = NULL;
		TreeNode<Etype> * node2 = NULL;
		node1 = find(this->currentNode, t1);
		node2 = find(this->currentNode, t2);
		if (closestCommonFull(node1, node2) != nullptr)
		{
			closestCommon = closestCommonFull(node1, node2)->element;
			return to_string(closestCommon);
		}
		else
		{
			return "No common ancestors";
		}
	}
	
	int width()
	{
		int l = widthFull(root->left);
		int r = widthFull(root->right);
		int treeWidth = l + r + 1;
		int treeHeight = (max(l, r) + 1);

		return max(treeHeight, treeWidth);
	}

	void flip() 
	{
		mirrored(root);
	}

	//void buildFromPreorder(Etype list[]) 
	//{
	//	buildFromPreorderFull(list, 0, 18);
	//}

	//TreeNode<Etype> * buildFromPreorderFull(int preOrder[], int inStrt, int inEnd)
	//{
	//	/*TreeNode(Etype e = 0, TreeNode *l = NULL, TreeNode *r = NULL, TreeNode *p = NULL) :
	//		element(e), left(l), right(r), parent(p) { }*/
	//	static int preIndex = 0;
	//	if (inStrt > inEnd) return NULL;
	//	TreeNode<int> * tNode = new TreeNode<int>(preOrder[preIndex++], NULL, NULL, NULL);
	//	if(inStrt == inEnd) return tNode;

	//	tNode->left = buildFromPreorderFull(preOrder, inStrt, inEnd);
	//}

	void perfectBalance(Etype *list, int beg, int final) { return true; }

	void getMaxCompleteSubtree() {}

	//Print the tree preceeded by the "msg".
	// Print the tree to depth "depth"
	// Print the whole tree if no depth is specified
	void  printTree(std::string msg, int depth = numeric_limits<int>::max())
	{
		std::cout << std::endl << msg << std::endl;
		printTree(root, "", 0, depth);
	}

	//Insert item x into the tree using BST ordering
	virtual bool insert(Etype & x) { return insert(x, root, NULL); }

	/*Return the value of the currentNode */
	Etype getCurrNodeValue( )
	{
		if (currentNode == NULL) return LOW;
		return currentNode->element;
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// return the number of nodes in the tree rooted at t
template <class Etype>
int BinaryTree<Etype>::size(TreeNode<Etype> *t) const
{
	if (t == NULL) return 0;
	return (1 + size(t->left) + size(t->right));
}


//Print the contents of tree t
// Indent the tree bby the string "indent"
// Print the tree to a depth of "depth" given "currdepth" is the depth of t
template <class Etype>
void BinaryTree<Etype>::printTree(TreeNode<Etype> *t, std::string indent, int currdepth, int depth)
{
	if (t == NULL || currdepth>depth || t->element < 0) return;
	printTree(t->right, indent + "  ", currdepth + 1, depth);
	if (t->parent != NULL)
		cout << indent << t->element << "(" << t->parent->element << ")" << endl;
	else
		cout << indent << t->element << "(no parent)" << endl;
	printTree(t->left, indent + "  ", currdepth + 1, depth);
}

// insert inserts data into the tree rooted at t
// parent is the parent of t
// Returns true if insertion is successful 
// Code is O(log n) for a balanced tree as each level is accessed once
// This inserts as if we wanted to created a binary search tree.
template <class Etype>
bool BinaryTree<Etype>::insert(Etype & data, TreeNode<Etype> * & t, TreeNode<Etype> *  parent)
{
	if (t == NULL)
	{  // cout << "inserting " << data << endl;
		t = new TreeNode<Etype>(data, NULL, NULL, parent);
		if (t == NULL) return false;
		return true;
	}
	if (data < t->element) return insert(data, t->left, t);
	return insert(data, t->right, t);
}
// find seaches for data in the tree rooted at curr
// Returns the node if the find is successful, NULL otherwise
// Code is O(log n) for a balanced tree as each level is accessed once


// Find the leftmost node in a tree rooted at t.
template <class Etype>
TreeNode<Etype> * BinaryTree<Etype>::findFirst(TreeNode<Etype> * t) const
{
	if (t == nullptr) return t;
	TreeNode<Etype>* s = t;
	for (; s->left != NULL; s = s->left)
		;
	return s;
}

template <class Etype>
void BinaryTree<Etype>::printShortFull(TreeNode<Etype> *passNode)
{
	if (passNode == nullptr) return;
	printShortFull(passNode->left);
	cout << passNode->element << " ";
	printShortFull(passNode->right);
	cout << passNode->element << " ";
}

template <class Etype>
void BinaryTree<Etype>::fallFull(TreeNode<Etype> *passNode)
{
	if (passNode == nullptr) return;
	if (passNode->left == nullptr && passNode->right == nullptr)
	{
		removeSubtree(passNode);
		cout << "Deleted a tree\n";
		return;
	}
	fallFull(passNode->left);
	fallFull(passNode->right);
}

template <class Etype>
void BinaryTree<Etype>::removeSubtree(TreeNode<Etype> *nodeToDestroy)
{
	if (!nodeToDestroy)
	{
		return;
	}
	removeSubtree(nodeToDestroy->left);
	removeSubtree(nodeToDestroy->right);
	nodeToDestroy->element = NULL;
	nodeToDestroy->left = nullptr;
	nodeToDestroy->right = nullptr;
	nodeToDestroy->parent = nullptr;
	delete nodeToDestroy;
}

template <class Etype>
TreeNode<Etype> * BinaryTree<Etype>::successorFull(TreeNode<Etype> * root, TreeNode<Etype> * p)
{
	if (p->right)
	{
		TreeNode<Etype> *tp = p->right;
		while (tp->left)
		{
			tp = tp->left;
		}
		return tp;
	}
	//if there's no right sub tree, just find the nearest node from whose left side that we can find p
	else
	{
		TreeNode<Etype>*tp = root;
		TreeNode<Etype> *parent = NULL;
		while (tp != p)
		{
			if (tp->element> p->element)
			{
				parent = tp;
				tp = tp->left;
			}
			else
			{
				tp = tp->right;
			}
		}
		return parent;
	}
}

//TreeNode<Etype> * find(TreeNode<Etype> * curr, Etype value)const;
template <class Etype>
TreeNode<Etype> * BinaryTree<Etype>::find(TreeNode<Etype> * passedNode, Etype value)const
{
	TreeNode<Etype> * tree = root;
	TreeNode<Etype> * nullTree = NULL;
	while (tree)
	{
		if (tree->element == value)
		{
			return tree;
		}
		else if (value < tree->element)
		{
			tree = tree->left;
		}
		else
		{
			tree = tree->right;
		}
	}
	return nullTree;
}

template <class Etype>
vector<Etype> BinaryTree<Etype>::findPath(TreeNode<Etype> * passedNode)
{
	TreeNode<Etype> * editableNode = passedNode;
	vector<Etype> pathToRoot = {};
	while (editableNode->parent != NULL)
	{
		pathToRoot.push_back(editableNode->parent->element);
		editableNode = editableNode->parent;
	}
	return pathToRoot;
}

template <class Etype>
TreeNode<Etype> * BinaryTree<Etype>::closestCommonFull(TreeNode<Etype> * node1, TreeNode<Etype> * node2)
{
	int commonElement = 0;
	if (node1 == NULL || node2 == NULL)
	{
		return NULL;
	}
	vector<Etype> path1; //= new vector<TreeNode<Etype>>(0);
	vector<Etype> path2; //= new vector<TreeNode<Etype>>(0);

	path1 = findPath(node1);
	path2 = findPath(node2);
	//reverse(path1.begin(), path1.end());
	//reverse(path2.begin(), path2.end());
	int smallestVec = NULL;
	if (path1.size() < path2.size())
	{
		smallestVec = path1.size();
	}
	else
	{
		smallestVec = path2.size();
	}

	bool found = false;
	for (unsigned int i = 0; i < path1.size(); i++)
	{
		for (unsigned int j = 0; j < path2.size(); j++)
		{
			if (path1[i] == path2[j])
			{
				if (!found)
				{
					commonElement = path1[i];
				}
				found = true;
			}
		}
	}
	return find(node1, commonElement);
}
template <class Etype>
int BinaryTree<Etype>::widthFull(TreeNode<Etype> * passedNode)
{
	if (passedNode == nullptr || passedNode->element < 0) return 0;
	else
	{
		int l = widthFull(passedNode->left);
		int r = widthFull(passedNode->right);
		return (max(l, r) + 1);
	}
}

template<class Etype>
void BinaryTree<Etype>::mirrored(TreeNode<Etype> * passedNode)
{
	if (passedNode == NULL || passedNode->element < 0) return;
	else
	{
		mirrored(passedNode->left);
		mirrored(passedNode->right);

		TreeNode<Etype> * temp = passedNode->left;
		passedNode->left = passedNode->right;
		passedNode->right = passedNode->left;
	}
}
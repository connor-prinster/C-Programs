#pragma once

template <typename T>
class binarySearchTree
{
private:
	struct TreeNode
	{
		std::string value;
		TreeNode *left;
		TreeNode *right;
		TreeNode(std::string value1, 
			TreeNode *left1 = nullptr, 
			TreeNode *right1 = nullptr)
		{
			value = value1;
			left = left1;
			right = right1;
		}
	};

	TreeNode *root;

	bool insert(TreeNode *& tree, T word)
	{
		bool willBeInserted = false;
		if (!tree)
		{
			tree = new TreeNode(word);
		}
		if (word == tree->value)
		{
			return true;
		}
		else if (word < tree->value)
		{
			insert(tree->left, word);
			willBeInserted = true;
			return false;
		}
		else if (word > tree->value)
		{
			insert(tree->right, word);
			return false;
		}
	}
	void destroySubtree(TreeNode *tree)
	{
		if (!tree)
		{
			return;
		}
		destroySubtree(tree->left);
		destroySubtree(tree->right);
		delete tree;
	}
	void remove(TreeNode *&tree, T word)
	{
		if (tree == nullptr)
		{
			return;
		}

		if (word < tree->value)
		{
			remove(tree->left, word);
		}
		else if (word > tree->value)
		{
			remove(tree->right, word);
		}
		else
		{
			makeDeletion(tree);
		}
	}
	void makeDeletion(TreeNode *&tree)
	{
		TreeNode *nodeToBeWiped = tree;
		TreeNode *attachPoint;

		if (tree->right == nullptr)
		{
			tree = tree->left;
		}
		else if (tree->left == nullptr)
		{
			tree = tree->right;
		}
		else
		{
			attachPoint = tree->right;

			while (attachPoint->left != nullptr)
			{
				attachPoint = attachPoint->left;
			}

			attachPoint->left = tree->left;

			tree = tree->right;
		}

		delete nodeToBeWiped;
	}

	void displayInOrder(TreeNode *tree) const
	{
		if (tree)
		{
			displayInOrder(tree->left);
			std::cout << tree->value << "  ";
			displayInOrder(tree->right);
		}
	}

	int countTheNodes(TreeNode *root)
	{
		int c = 1;
		if (root == NULL)
		{
			return 0;
		}
		else
		{
			c += countTheNodes(root->left);
			c += countTheNodes(root->right);
			return c;
		}
	}
	int countTheLeaves(TreeNode *root)
	{
		if (root == NULL)
		{
			return 0;
		}
		if (root->left == NULL && root->right == NULL)
		{
			return 1;
		}
		else
		{
			return countTheLeaves(root->left) + countTheLeaves(root->right);
		}
	}
	int countTheHeights(TreeNode *root)
	{
		if (root == NULL)
		{
			return 0;
		}
		else
		{
			int leftHeight = countTheHeights(root->left);
			int rightHeight = countTheHeights(root->right);
			if (leftHeight > rightHeight)
			{
				return(leftHeight + 1);
			}
			else
			{
				return(rightHeight + 1);
			}
		}
	}

public:
	binarySearchTree()
	{
		root = nullptr;
	}

	~binarySearchTree()
	{
		destroySubtree(root);
	}

	bool insert(T value)
	{
		return insert(root, value);
	}

	void remove(T value)
	{
		remove(root, value);
	}
	bool search(T word)
	{
		TreeNode *tree = root;

		while (tree)
		{
			if (tree->value == word)
			{
				return true;
			}
			else if (word < tree->value)
			{
				tree = tree->left;
			}
			else
			{
				tree = tree->right;
			}
		}
		return false;
	}
	void display()
	{
		displayInOrder(this->root);
	}
	unsigned int numberNodes()
	{
		return countTheNodes(this->root);
	}
	unsigned int numberLeafNodes()
	{
		return countTheLeaves(this->root);
	}
	unsigned int height()
	{
		return countTheHeights(this->root);
	}
};
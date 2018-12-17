#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include "binarySearchTree.hpp"

void testTree();

int main()
{
	////////////////////////////////////////////////////////////////////////////////////////////////////
	binarySearchTree<std::string> treeFile;
	//READ IN DICTIONARY.TXT
	
	std::ifstream fin1;
	std::ifstream fileDic("Dictionary.txt");
	std::string line;
	std::vector<std::string> wordsInDictionary;
	if (fileDic)
	{
		while (std::getline(fileDic, line))
		{
			wordsInDictionary.push_back(line);
		}
	}
	std::random_shuffle(wordsInDictionary.begin(), wordsInDictionary.end());

	for (int i = 0; i < wordsInDictionary.size(); i++)
	{
		treeFile.insert(wordsInDictionary[i]);
	}

	std::cout << "--Tree Stats--" << std::endl;
	std::cout << "Total Nodes: " << treeFile.numberNodes() << std::endl;
	std::cout << "Leaf Nodes: " << treeFile.numberLeafNodes() << std::endl;
	std::cout << "Tree Height: " <<treeFile.height() << std::endl;
	testTree();
	////////////////////////////////////////////////////////////////////////////////////////////////////

	std::cout << std::endl << "--Misspelled Words in Letter.txt--" << std::endl;
	
	std::ifstream letter("letter.txt", std::ifstream::in);
	while (!letter.eof())
	{
		std::ifstream fin2;
		std::string line;
		std::getline(letter, line);
		int linelength = line.length();
		for (int i = 0; i < linelength; i++)
		{
			char character = line[i];
			if (character == ',' || character == ';' || character == ':' || character == '.' || character == '!' || character == '?' || character == '(' || character == ')')
			{
				line.erase(line.begin() + i);
				linelength = line.length();
			}
		}

		std::istringstream iss(line);
		std::string word;

		while (iss >> word)
		{
			std::string orig = word;
			std::transform(word.begin(), word.end(), word.begin(), ::tolower);
			if (!treeFile.search(word))
			{
				std::cout << orig << std::endl;
			}
		}
	}
	std::cin.get();
}

void testTree()
{
	binarySearchTree<std::string> tree;
	//
	// Add a bunch of values to the tree
	tree.insert("Olga");
	tree.insert("Tomeka");
	tree.insert("Benjamin");
	tree.insert("Ulysses");
	tree.insert("Tanesha");
	tree.insert("Judie");
	tree.insert("Tisa");
	tree.insert("Santiago");
	tree.insert("Chia");
	tree.insert("Arden");

	//
	// Make sure it displays in sorted order
	tree.display();

		//
		// Try to add a duplicate
	std::cout << std::endl << "---- adding a duplicate ----" << std::endl;
	if (tree.insert("Tomeka"))
	{
		std::cout << "oops, shouldn't have returned true from the insert" << std::endl;
	}
	tree.display();

		//
		// Remove an existing value from the tree
	std::cout << std::endl << "---- removing an existing value ----" << std::endl;
	tree.remove("Olga");
	tree.display();

	//
	// Remove a value that was never in the tree, hope it doesn't crash!
	tree.remove("Karl");

		//
	// Check the tree stats
	std::cout << std::endl << "---- checking the tree stats ----" << std::endl;
	std::cout << "Expecting 9 nodes, found " << tree.numberNodes() << std::endl;
	std::cout << "Expecting 4 leaf nodes, found " << tree.numberLeafNodes() << std::endl;
	std::cout << "Expecting height of 6, found " << tree.height() << std::endl;
}
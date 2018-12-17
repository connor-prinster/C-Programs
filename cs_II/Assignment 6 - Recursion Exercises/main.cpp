#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "TestCases.hpp"

std::string collapseSpaces(std::string s);
std::vector<std::string> split(std::string s);
void quickSort(std::vector<int>& data, int start, int end);

// ------------------------------------------------------------------
//
// Provided code to remove spaces from a string (and capitalize it)
//
// ------------------------------------------------------------------
std::string collapseSpaces(std::string s)
{
	s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());
	std::transform(s.begin(), s.end(), s.begin(), toupper);	// Capitalize all
	return s;
}

// ------------------------------------------------------------------
//
// Solution string split code
//
// ------------------------------------------------------------------
std::vector<std::string> split(std::string s)
{
	std::istringstream is(s);
	std::vector<std::string> words;

	do
	{
		std::string word;
		is >> word;
		if (word.length() > 0)
		{
			words.push_back(word);
		}
	} while (is);

	return words;
}

// ------------------------------------------------------------------
//
// Provided quicksort partition code
//
// ------------------------------------------------------------------
int partition(std::vector<int>& data, int start, int end)
{
int middle = (start + end) / 2;
std::swap(data[start], data[middle]);
int pivotIndex = start;
int pivotValue = data[start];
for (int scan = start + 1; scan <= end; scan++)
{
	if (data[scan] < pivotValue)
	{
		pivotIndex++;
		std::swap(data[scan], data[pivotIndex]);
	}
}

std::swap(data[pivotIndex], data[start]);

return pivotIndex;
}

//----------------------------------------------------------------//
//MY SELECTION SORT
//----------------------------------------------------------------//
void selectionSort(std::vector<int>& data, int size)
{
	int startScan, minIndex, minValue;
	
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = data[startScan];

		for (int index = (startScan + 1); index < size; index++)
		{
			if (data[index] < minValue)
			{
				minValue = data[index];
				minIndex = index;
			}
		}
		data[minIndex] = data[startScan];
		data[startScan] = minValue;
	}
}
//----------------------------------------------------------------//
//----------------------------------------------------------------//

// ------------------------------------------------------------------
//
// Provided quicksort code
//
// ------------------------------------------------------------------
void quickSort(std::vector<int>& data, int start, int end)
{
	//if(end - start) > 10)
	if ((end - start) > 10)
	{
		int pivot = partition(data, start, end);
		quickSort(data, start, pivot - 1);
		quickSort(data, pivot + 1, end);
	}
	else
	{
		selectionSort(data, (end - start + 1));
	}
}

//
///
////programs to be written
bool isPalindrome(std::string word, int start, int end)
{
	int wordLength = word.size();
	if (wordLength % 2 != 0)
	{
		//in case the word is only one char long
		if (start == end)
		{
			return true;
		}
		//if there is even one non-match at a given spot, then return false
		if (word[start] != word[end])
		{
			return false;
		}
		//if the characters at the given indices are equal, but it isn't a single char yet
		if (word[start] == word[end])
		{
			//'shrinks' the word
			return isPalindrome(word, start + 1, end - 1);
		}
	}
	else
	{
		int middle = (word.size() / 2);
		if ((end == middle) && (word[start] == word[end]))
		{
			return true;
		}
		//if there is even one non-match at a given spot, then return false
		if (word[start] != word[end])
		{
			return false;
		}
		//if the characters at the given indices are equal, but it isn't a single char yet
		if (word[start] == word[end])
		{
			//'shrinks' the word
			return isPalindrome(word, start + 1, end - 1);
		}
	}
}

bool isWordSymmetric(const std::vector<std::string>& words, int start, int end)
{
	//checks to see if the start == end because if it hasn't already returned a false, it's true
	if (start == end)
	{
		return true;
	}
	//if the words aren't equal, it ends right there
	if (words[start] != words[end])
	{
		return false;
	}
	//if start != end, but the array positions are equal, starts the function again
	if (words[start] == words[end])
	{
		return isWordSymmetric(words, start + 1, end - 1);
	}
}

long vectorSum(const std::vector<int>& data, unsigned int position)
{
	if (position < data.size())
	{
		return (data[position] + vectorSum(data, (position + 1)));
	}
	return 0;
}

int vectorMin(const std::vector<int>& data, unsigned int position)
{
	if (position == data.size() - 1)
	{
		return data[position];
	}

	double val = vectorMin(data, position + 1);

	if (data[position] < val)
		return data[position];
	else
		return val;
}

////end of programs to be written
///
//

int main()
{
	TestCases::runTestCases();

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Program finished. Press 'enter' to exit...";
	std::cin.get();
}


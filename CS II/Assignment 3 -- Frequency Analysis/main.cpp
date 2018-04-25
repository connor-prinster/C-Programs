#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <utility>
#include <vector>
#include <string>

#include "Record.hpp"
#include "TestCases.hpp"

//=======================
std::vector<unsigned int> readNumbersFromFile(std::string fileName);
std::vector<Record*> createVectorOfRecordsFromVectorOfNumbers(std::vector<unsigned int> numbers);
std::vector<Record*>  sortByFrequency(std::vector<Record*> &records);
std::vector<Record*>  reportFrequencies(std::vector<Record*> &records);
int binarySearch(std::vector<Record*> &records, size_t numberToBeSearchedFor);
//=======================

int main()
{
	std::vector<unsigned int> numbers = readNumbersFromFile("input.txt");
	std::vector<Record*> records = createVectorOfRecordsFromVectorOfNumbers(numbers);

	sortByFrequency(records);
	reportFrequencies(records);
	//cleanDynamicMemory(records);	// Function stub found in TestCases.cpp

	//// Test cases
	//executeFreqTest(FreqTestCase1, createVectorOfRecordsFromVectorOfNumbers, "Frequency Test Case 1");
	///*
	//executeFreqTest(FreqTestCase2, createVectorOfRecordsFromVectorOfNumbers, "Frequency Test Case 2");
	//executeSortTest(SortTestCase1, sortByFrequency, "Sort Test Case 1");
	//executeSortTest(SortTestCase2, sortByFrequency, "Sort Test Case 2");
	//*/

	std::cout << "Press 'enter' to exit program..." << std::endl;
	std::cin.get();
	return 0;
}

std::vector<unsigned int> readNumbersFromFile(std::string fileName)
{
	using namespace std;

	ifstream fin("input.txt");
	int newReadValue;
	vector<unsigned int> numbers;

	if (!fin)
	{
		cout << "Unable to open " << fileName << ", please make sure it exists.";
	}
	else
	{
		cout << "File exists and is open" << endl;
		int firstValue = 0;
		fin >> firstValue;
		//cout << "This is the read number: " << firstValue << endl;

		for (int i = 0; i < firstValue; i++)
		{
			fin >> newReadValue;
			numbers.push_back(newReadValue);
			//cout << "the index at " << i << " is: " << numbers[i] << endl;
		}
		cout << "File's contents now fed into program" << endl;
	}

	return numbers;
}

std::vector<Record*> createVectorOfRecordsFromVectorOfNumbers(std::vector<unsigned int> numbers)
{
	using namespace std; 
	vector<Record*> vectorOfRecords; //created vector of records
	int initialValueInNumbersVector = numbers[0];
	Record* initialRecordObject = new Record(initialValueInNumbersVector);
	vectorOfRecords.insert(vectorOfRecords.begin(), initialRecordObject);
	int result;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		int numberToBeSearchedFor = numbers[i];
		result = binarySearch(vectorOfRecords, numberToBeSearchedFor);
		if (result != -1)
		{
			vectorOfRecords[result]->incrementFrequency();
		}
	}

	return vectorOfRecords;
}


int binarySearch(std::vector<Record*> &records, size_t numberToBeSearchedFor)
{
	using namespace std;

	size_t sizeRecordVector = records.size();
	size_t first = 0;
	size_t last = 0;
	size_t middle = 0;

	bool foundAMatch = false;
	bool increasedVectorSize = false;

	int position;

	for (size_t j = 0; j < sizeRecordVector; j++)
	{
		last = (sizeRecordVector - 1);
		foundAMatch = false;
		while (!foundAMatch && first <= last)
		{
			middle = ((first + last) / 2);

			if (numberToBeSearchedFor == records[j]->getNumber())
			{
				foundAMatch = true;
				position = middle;
				records[position]->incrementFrequency();
				return position;
			}

			else if (numberToBeSearchedFor > records[j]->getNumber())
			{
				last = middle + 1;
			}
			else if (numberToBeSearchedFor < records[j]->getNumber())
			{
				first = middle - 1;
			}


			if (numberToBeSearchedFor < middle)
			{
				Record* newRecord = new Record(numberToBeSearchedFor);
				records.insert(records.begin() + middle, newRecord);
				return -1;
			}
			else
			{
				Record* newRecord = new Record(numberToBeSearchedFor);
				records.insert((records.begin() + (middle + 1)), newRecord);
				return -1;
			}
		}
	}
}

std::vector<Record*>  sortByFrequency(std::vector<Record*> &records)
{
	using namespace std;

	int recordsSize = records.size();

	int minimumPos;
	Record* tempVal;

	for (int i = 0; i < (recordsSize - 1); i++)
	{
		minimumPos = i; //set pos_min to the current index of array

		for (int j = i + 1; j < recordsSize; j++)
		{
			if (records[j]->getFrequency() < records[minimumPos]->getFrequency())
			{
				minimumPos = j;
			}
		}

		if (minimumPos != i) //if minimumPos no longer equals 'i,' values are swapped 
		{
			tempVal = records[i];
			records[i] = records[minimumPos];
			records[minimumPos] = tempVal;
		}
		//cout << "the record rn has a frequency of: " << records[i]->getFrequency() << endl;
	}	//--ends selection function--//
	return records;
}

std::vector<Record*>  reportFrequencies(std::vector<Record*> &records)
{
	using namespace std;

	size_t sizeOfVector = records.size();
	size_t currentFrequency;

	int currentFreq;
	size_t temp;
	int j = 0;

	for (size_t i = 0; i < sizeOfVector; i++)
	{
		currentFreq = records[i]->getFrequency();

		cout << "A total of" << " ---- " << "numbers with a count of " << currentFreq << endl;

	}

	return records;
}

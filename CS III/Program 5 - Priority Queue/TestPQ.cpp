#include "PQHeap.h"
#include "LeftistHeap.h"

#include <time.h>

//Insert limit elements of the file finMax into heap.
void insertNextMax(PQ & pq, std::ifstream & fin, int limit = 0)
{
	if (limit == 0)
		limit = std::numeric_limits<int>::max();
	std::string word;
	int ct;
	for (int i = 0; i <= limit && !fin.eof(); i++)
	{
		fin >> word >> ct;
		//std::cout << "inserting " << word << ct << std::endl;
		ItemType item(word, ct);
		pq.insert(item);
	}
}

void insertNextMin(LeftistHeap & lh, std::ifstream & fin, int limit = 0)
{
	if (limit == 0)
		limit = std::numeric_limits<int>::max();
	std::string word;
	int ct;
	for (int i = 0; i <= limit && !fin.eof(); i++)
	{
		fin >> word >> ct;
		//std::cout << "inserting " << word << " " << ct << std::endl;
		ItemType item(word, ct);
		lh.insert(item);
	}
}

void dynamicMedian()
{
	PQHeap smallerHeap("smaller", 6000);
	LeftistHeap largerHeap("larger", 6000);
	std::ifstream finDyn("Prog5In.txt");

	std::string word;
	int priority;
	finDyn >> word >> priority;
	ItemType currMed = ItemType(word, priority);
	
	int ct100 = 100;
	while (!finDyn.eof())
	{
		if (ct100 == 100)
		{
			std::cout << currMed.toString() << std::endl;		//every 100 is spits out the object's toString() value
			ct100 = 0;
		}
		finDyn >> word >> priority;	//create a new word based on the next line
		ItemType compMed = ItemType(word, priority);

		if (compMed.priority > currMed.priority)
		{
			largerHeap.insert(compMed);	//if the compMed is higher than the orig, push into the min heap
		}
		else if(compMed.priority < currMed.priority)
		{
			smallerHeap.insert(compMed);	//if the compMed is lower than the orig, push into the max heap
		}

		//-----------------------------------------------------------	
		//this one is weird as it's all about balance. If the size 
		//of one outweighs the other by 2 it pulls the topmost value 
		//of the overweight heaps assigns it as the currMed and inserts
		//the previous currMed
		//-----------------------------------------------------------
		if (smallerHeap.getSize() > (largerHeap.getSize() + 2))
		{
			currMed = smallerHeap.deleteMax();
			largerHeap.insert(currMed);
			//std::cout << currMed.toString() << std::endl;
		}
		else if ((smallerHeap.getSize() + 2) < largerHeap.getSize())
		{
			currMed = largerHeap.deleteMin();
			smallerHeap.insert(currMed);
			//std::cout << currMed.toString() << std::endl;
		}
		//-----------------------------------------------------------
		ct100++;	//increments counter
	}
}

int main()
{
	clock_t start = clock();
	int const DELETE_CT = 20;
	int const PRINTSIZE = 30;
	int const HOWMANY = 100;

	PQHeap pqMax("Max Binary Heap", 6000);
	LeftistHeap lhMin("Min Heap", 6000);
	
	std::ifstream finMax;
	std::ifstream finMin;
	finMax.open("Prog5In.txt");
	finMin.open("Prog5In.txt");
	assert(finMax);
	assert(finMin);

	//-------------------------------------------------------------------------------
	std::cout << "\n" << lhMin.name << "\n";
	std::cout << "===================================\n";
	for(int i = 0; i < 60; i++)
	{
		insertNextMin(lhMin, finMin, HOWMANY);
		//std::cout << lhMin.deleteMin().toString() << std::endl;	//CAN BE IMPLEMENTED. IF UNCOMMENTED IT WILL OUTPUT A MIN HEAP
	}
	clock_t timeMin = clock() - start;
	std::cout << "\nLeftist Queue Elapsed time = " << ((float)timeMin) / CLOCKS_PER_SEC << std::endl;
	//-------------------------------------------------------------------------------
	std::cout << "\n" << pqMax.name << "\n";
	std::cout << "===================================\n";
	for (int i = 0; i < 60; i++)
	{
		insertNextMax(pqMax, finMax, HOWMANY);
		std::cout << pqMax.deleteMax().toString() << std::endl;	//cout the max-iest of all of them while deleting them
	}
	clock_t timeMax = clock() - start;	//clock for this specific function
	std::cout << "\nMax Binary Heap Elapsed time = " << ((float)timeMax) / CLOCKS_PER_SEC << std::endl;
	//-------------------------------------------------------------------------------
	std::cout << "\nDyanmic Median Testing\n";
	std::cout << "===================================\n";
	
	finMax.close(); //close everything just in case
	finMin.close();	//close everything just in case
	dynamicMedian();

	clock_t timeDyn = clock() - start;	//clock for this specific function
	std::cout << "\nMax Binary Heap Elapsed time = " << ((float)timeDyn) / CLOCKS_PER_SEC << std::endl;
	//-------------------------------------------------------------------------------

	std::cout << "\nPress 'Enter' to Continue";
	std::cin.ignore();
}
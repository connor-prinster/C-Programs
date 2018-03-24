#include "PQHeap.h"
#include <time.h>
//#include "SkewHeap.h"
//#include "Leftist.h"

//Insert limit elements of the file fin into heap.
void insertNext(PQ & pq,std::ifstream & fin,int limit=0) 
{	if (limit ==0) 
		limit = std::numeric_limits<int>::max();	//don't understand this one, will research when internet is available
	std::string word;	//initializes the string "word" for later insertion.
	int ct;		//initializes the int "ct" for later insertion
	for (int i =0; i <= limit && !fin.eof(); i++)
	{
		fin >> word >> ct;
		//std::cout << "inserting " << word << ct << std::endl;
		ItemType item(word, ct);	//creates the object of ItemType
		pq.insert(item);	//inserts the item with aword = word and count = ct
	}
}

int main()
{   clock_t start = clock();	//"start" now equals the current time
	int const DELETE_CT=20;
	int const PRINTSIZE=30;
	int const HOWMANY = 100;  

	PQHeap pqMax("MaxHeap",6000);	//create PQ object

	std::ifstream fin;	//create ifstream var
	fin.open("Prog5In.txt");	//open the supposedly existant file
	assert(fin);	//if "fin" does not exist, stop the program with an obvious error

	for (int i = 0; i < 60; i++)
	{
		insertNext(pqMax, fin, HOWMANY);	//uses a method here to access the insert method contained in the PQHeap (kinda sneaky-sneaks if you ask me)
		std::cout << pqMax.deleteMax().toString() << std::endl;	//toString()-ifies the max value in the heap. This object has already been deleted but a temporary object has been created as a reference to it. This object no longer exists in the heap
	}


	clock_t time = clock() - start;	//"time" now represents the starting time - end time
	std::cout << "Elapsed time = " << ((float) time)/CLOCKS_PER_SEC << std::endl;	//couts the total time elapsed.
	std::cin.ignore();	//finishes program.
}



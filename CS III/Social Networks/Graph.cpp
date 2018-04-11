#include "Graph.h"

Graph::Graph()
{
	fillNameVec();	//just to make sure
	edgeVec = fillEdgeVector();	//call the method to, well, fill the vector of EdgeNodes
}

Graph::~Graph(){}

//filling vectors
//===================================================================================================================
//===================================================================================================================
std::vector<EdgeNode*> Graph::fillEdgeVector()
{
	for (int i = 0; i < MEMBER_COUNT; i++)
	{
		edgeVec.push_back(new EdgeNode(nameVec[i], i));	//will create a vector of EdgeNodes with an identifying integer (0 - 1000) and a string containing a name just for fun
	}
	return edgeVec;	//return the initalized 1000 long vector
}

void Graph::fillNameVec()
{
	std::string filename = "names.txt";	//easier to hardcode a filename imho
	std::ifstream fin(filename);	//set fin to open the hardcoded filename
	std::string word;	//kind of a dummy variable
	while (!fin.eof())
	{
		fin >> word;	//the first word on the line (should be a name) will be stored in "word"
		nameVec.push_back(word);	//the current "word" is now in the name vector for when we build the EdgeNodes
	}
}
//===================================================================================================================
//===================================================================================================================

void Graph::toStringComplex()
{
	for (unsigned int i = 0; i < edgeVec.size(); i++)
	{
		std::cout << "-----------------" << std::endl;
		std::cout << "---Node Report---" << std::endl;
		std::cout << "-----------------" << std::endl;
		std::cout << "Faux Name: " << edgeVec[i]->nameForFun << std::endl;
		std::cout << "Parent Node: " << edgeVec[i]->parentIdx << std::endl;
		std::cout << "Current Node: " << edgeVec[i]->selfVal << std::endl;
		std::cout << "Rank: " << edgeVec[i]->rank << std::endl;
	}
}

void Graph::toString()
{
	std::cout << "\n==================================\n";
	std::cout << "        ---GRAPH READOUT---        ";
	std::cout << "\n==================================";
	std::cout << "\nNumber of Days Passed:       " << numDays;
	std::cout << "\nNumber of Successful Unions: " << successfulUnions;
	std::cout << "\nNumber of Find() Calls:      " << numFinds;
	std::cout << "\n==================================\n";
}

bool Graph::isAllConnected()
{
	if (successfulUnions == MEMBER_COUNT - 1)
		return true;
	else
		return false;
}

void Graph::performAllUnions()
{
	UnionFind uf;
	int ctr = 0;
	srand(time(NULL));
	while (!isAllConnected())	//while not all connected do the below
	{
		//random number generators
		//-------------------------------------
		int spot1 = rand() % MEMBER_COUNT;	//spot one to be passed to Union
		int spot2 = rand() % MEMBER_COUNT;	//spot two to be passed to union
		while (spot1 == spot2)	//make sure spot2 and spot1 does not equal each other. Keep going through and reseting spot2 until they don't match. Probably shouldn't take more than once or twice
		{
			spot2 = rand() % MEMBER_COUNT;	//reset spot2 to make sure it doesn't equal spot1
		}
		//checking if successful union
		//-------------------------------------
		bool unionRes = uf.Union(spot1, spot2, edgeVec);
		if (unionRes)	//if success, it was both a successful union AND a day
		{
			incrementDayCount();
			incrementFindCount();
			incrementSuccessfulUnionCount();
		}
		else	//if failure, it was a day but not successful and two find()s were called
		{
			incrementDayCount();
			incrementFindCount();
		}
		if (ctr % 10 == 0)
		{
			toString();
		}
		ctr++;
	}
	toString();
}

//================================================================================================
//================================================================================================
//--------------------------//
//     Setter Functions     //
//--------------------------//
void Graph::incrementSuccessfulUnionCount()
{
	successfulUnions++;
}

void Graph::incrementFindCount()
{
	numFinds+=2;	//since each Union call will use find at least twice, increment it by 2
}

void Graph::incrementDayCount()
{
	numDays++;
}
//================================================================================================
//================================================================================================


#include "PQHeap.h"

//Create a heap with maximum size "physicalSize" 
PQHeap::PQHeap(std::string name, int physicalSize)
{
	this->name = name;
	size = 0;
	heap = new ItemType[physicalSize];
	this->physicalSize = physicalSize;
}



// insert element and re-heapify
void PQHeap::insert(ItemType &newVal)
{
	int curr = size;
	assert(size < physicalSize);
	int parent = (curr - 1) / KIDS; // round down
	while (curr>0 && newVal.priority >heap[parent].priority) {
		heap[curr] = heap[parent];
		curr = parent;
		parent = (curr - 1) / KIDS;
	}
	heap[curr] = newVal;
	size++;
}

void PQHeap::heapify(int index)
{
	int child[KIDS + 1];	//this is treated as an array of kids. It's a representation of how each node could look like an array of nodes
	while (1)	//essentially just pushes through until there is a break function
	{
		for (int i = 1; i <= KIDS; i++)	//fills up the indices of the child[] array
		{
			if ((KIDS *index + i) < size)
			{
				child[i] = (KIDS*index + i);
			}
			else
			{
				child[i] = -1;
			}
		}

		ItemType max("leaf", -1);	//essentially a filler/temp/dummy variable
		int maxIndex;	//uninitialized but useful

		for (int i = 1; i <= KIDS; i++)	//for the length of the child[] array run through and keep track of if the value of one is bigger than the other. The biggest child will be assigned to ItemType max()
		{
			if (child[i] != -1 && heap[child[i]].priority > max.priority)
			{
				maxIndex = child[i];
				max = heap[child[i]];
			}
		}

		if (max.priority == -1) break;	//when the leaf node hits it'll break

		if (heap[index].priority < heap[maxIndex].priority)
		{
			std::swap(heap[index], heap[maxIndex]);	//swap if the key of the max is greater than the key of the node, otherwise don't bother
		}

		index = maxIndex;
	}
}

// Delete maximum value, re-heapify, and return max element
ItemType PQHeap::deleteMax()
{
	if (size == 0)
		return ItemType("error", -1);	//honestly the best thing, saved a ton of debugging time
	ItemType toReturn = heap[0];
	size--;
	heap[0] = heap[size - 1];
	heapify(0);	//the call to the specialized deletion function
	return toReturn;
}

// merge second into current  heap
void PQHeap::merge(PQ * second)
{
	for (int i = 0; i < second->getSize(); i++)
		insert(dynamic_cast<PQHeap*>(second)->heap[i]);
	second->makeEmpty();
}

// Convert first "size: elements of PQ to a string.
std::string PQHeap::toString(int maxSize) const
{
	const int PERLINE = 5;
	std::stringstream out;
	out << name << "  current size=" << size;
	if (maxSize > size)
		maxSize = size;

	for (int i = 0; i <maxSize; i++)
	{
		if (i%PERLINE == 0) out << std::endl;
		out << heap[i].toString() << "\t";
	}
	out << std::endl;
	return out.str();
}
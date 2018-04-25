// PQHeap.cpp - wdg 2008
#ifndef PQHeap_H
#define PQHeap_H

#include "PQ.h"

class PQHeap : public PQ
{
public:
	static const int KIDS = 4;	//this used to be 2, but for the d-ary implementation I switched it the arbitrary value of 4
	PQHeap(std::string name, int size);	//constructor
	void insert(ItemType &);  //    virtual void insert(ItemType & x )=0 ;
	ItemType deleteMax();	//deletes the max value and returns a copy of it
	void merge(PQ *h);  // merges h into current heap  
	std::string toString(int size) const;
	void heapify(int index);	//the only real change necessary. It just changes the way that deletion occurs.
private:
	ItemType * heap;   // Heap Array
	int physicalSize;  // Physical size of heap
};


#endif
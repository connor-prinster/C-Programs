#include "UnionFind.h"

bool UnionFind::Union(int x, int y, std::vector<EdgeNode*> edgeVec)	//union by rank
{
	int xroot = find(x, edgeVec);
	int yroot = find(y, edgeVec);

	if (xroot == yroot)
		return false;

	if (edgeVec[xroot]->selfVal == edgeVec[yroot]->parentIdx || edgeVec[xroot]->parentIdx == edgeVec[yroot]->selfVal)
		return false;

	if (edgeVec[xroot]->rank < edgeVec[yroot]->rank)	//if y has a greater rank
	{
		edgeVec[xroot]->rank++;
		edgeVec[xroot] = edgeVec[y];
	}
	else if(edgeVec[xroot]->rank > edgeVec[yroot]->rank)	//if x has a greater rank
	{
		edgeVec[yroot]->rank++;
		edgeVec[yroot] = edgeVec[x];
	}
	else
	{
		if (edgeVec[xroot] == edgeVec[yroot])
			edgeVec[xroot]->rank++;
		edgeVec[yroot]->parentIdx = xroot;
	}
	return true;
}

int UnionFind::find(int i, std::vector<EdgeNode *> edgeVec)// const
{
	if (edgeVec[i]->parentIdx < 0)
	{
		return i;
	}
	if (edgeVec[i]->parentIdx != i)
	{
		edgeVec[i]->parentIdx = find(edgeVec[i]->parentIdx, edgeVec);
	}
	return edgeVec[i]->parentIdx;
}
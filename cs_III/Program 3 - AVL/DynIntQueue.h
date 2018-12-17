#pragma once
#include "GameState.h"

class OldDynIntQueue
{
	struct QueueNode
	{
		OldGameState value;
		QueueNode *next;
		QueueNode(OldGameState value1, QueueNode *next1 = nullptr)
		{
			value = value1;
			next = next1;
		}
	};
	QueueNode *front;
	QueueNode *rear;

public:
	OldDynIntQueue();
	~OldDynIntQueue();

	void enqueue(OldGameState);
	void dequeue(OldGameState &);
	bool isEmpty() const;
	void clear();
};


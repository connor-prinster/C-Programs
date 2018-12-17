#pragma once
#include "GameState.h"

class DynIntQueue
{
	struct QueueNode
	{
		GameState value;
		QueueNode *next;
		QueueNode(GameState value1, QueueNode *next1 = nullptr)
		{
			value = value1;
			next = next1;
		}
	};
	QueueNode *front;
	QueueNode *rear;

public:
	DynIntQueue();
	~DynIntQueue();

	void enqueue(GameState);
	void dequeue(GameState &);
	bool isEmpty() const;
	void clear();
};


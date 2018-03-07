#include "DynIntQueue.h"

OldDynIntQueue::OldDynIntQueue()
{
	front = nullptr;
	rear = nullptr;
}

OldDynIntQueue::~OldDynIntQueue()
{
	QueueNode * garbage = front;
	while (garbage != nullptr)
	{
		front = front->next;
		garbage->next = nullptr;
		delete garbage;
		garbage = front;
	}
}

void OldDynIntQueue::enqueue(OldGameState gamer)
{
	if (isEmpty())
	{
		front = new QueueNode(gamer);
		rear = front;
	}
	else
	{
		rear->next = new QueueNode(gamer);
		rear = rear->next;
	}
}

void OldDynIntQueue::dequeue(OldGameState &gamer)
{
	QueueNode *temp = nullptr;
	if (isEmpty())
	{
		exit(1);
	}
	else
	{
		gamer = front->value;
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool OldDynIntQueue::isEmpty() const
{
	if (front == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void OldDynIntQueue::clear()
{
	OldGameState gamer;

	while (!isEmpty())
	{
		dequeue(gamer);
	}
}

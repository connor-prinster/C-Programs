#include "DynIntQueue.h"

DynIntQueue::DynIntQueue()
{
	front = nullptr;
	rear = nullptr;
}

DynIntQueue::~DynIntQueue()
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

void DynIntQueue::enqueue(GameState gamer)
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

void DynIntQueue::dequeue(GameState &gamer)
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

bool DynIntQueue::isEmpty() const
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

void DynIntQueue::clear()
{
	GameState gamer;

	while (!isEmpty())
	{
		dequeue(gamer);
	}
}

#pragma once
#include "Node.h"
#include "ListInterface.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList
{
public:
	LinkedList();

	~LinkedList();

	void insert(int index, T entry);

	void remove(int index);

	void clear();

	T getEntry(int index) const;

	void setEntry(int index, T entry);

	int getSize() const;

	Node<T>* getFront() const;

	void printList() const;

	void setFront(Node<T>* newFront);

	void setSize(int size);

	bool doesCycle();

	void cycleList();

	void unCycle();

	Node<T>* reverseList();

private:
	Node<T>* m_front = nullptr;
	int m_size;

};
#include "LinkedList.tpp"
#endif

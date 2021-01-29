#pragma once
#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H

template <typename T>
class ListInterface
{
public:
	virtual ~ListInterface() {}

	virtual void insert(int index, T entry) = 0;

	virtual void remove(int index) = 0;

	virtual void clear() = 0;

	virtual T getEntry(int index) const = 0;

	virtual void setEntry(int index, T entry) = 0;

	virtual int getSize() const = 0;

	virtual Node<T>* getFront() const = 0;

	virtual void setFront(Node<T>* newFront) = 0;

	virtual void printList() const = 0;

	virtual void setSize(int size) = 0;

	virtual bool doesCyle() = 0; //dailyByte

	virtual void cycleList() = 0;

	virtual void unCycle() = 0;

	virtual Node<T>* findCylceStart() = 0; //not implemented

	virtual Node<T>* reverseList() = 0; //dailyByte
};
#endif
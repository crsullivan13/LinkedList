#include <iostream>

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:
	T m_entry;
	Node<T>* m_next;


public:

	Node<T>(T entry);

	T getEntry() const;

	void setEntry(T entry);

	Node<T>* getNext() const;

	void setNext(Node<T>* next);



};
#include "Node.tpp"
#endif



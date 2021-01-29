#include <iostream>
#include <stdexcept>
#include "ListInterface.h"

template<typename T>
LinkedList<T>::LinkedList()
{
	m_front = nullptr;
	m_size = 0;
}

template<typename T>
void LinkedList<T>::setSize(int size)
{
	m_size = size;
}

template<typename T>
Node<T>* LinkedList<T>::reverseList()
{
	Node<T>* previous = nullptr;
	Node<T>* current = m_front;
	Node<T>* next = m_front;
	m_front = nullptr;

	while(next != nullptr){
		next = current->getNext();
		current->setNext(previous);
		previous = current;
		current = next;
	}

	m_front = previous;

	return previous;

}

template<typename T>
bool LinkedList<T>::doesCycle()
{
	Node<T>* temp1 = m_front;
	Node<T>* temp2 = m_front;

	while(temp2 != nullptr && temp2->getNext() != nullptr){
		temp1 = temp1->getNext();
		temp2 = temp2->getNext();
		temp2 = temp2->getNext();
		if(temp1 == temp2){
			return true;
		}
	}

	return false;

}

template<typename T>
void LinkedList<T>::unCycle()
{
	Node<T>* temp = m_front;

	if(doesCycle() == true){
		for(int i = 1; i < m_size; i++){
			temp = temp->getNext();
		}

		temp->setNext(nullptr);

	} else {
		throw(std::runtime_error("Attempted to unCycle a non cyclic list"));
	}


}

template<typename T>
void LinkedList<T>::cycleList()
{
	Node<T>* temp = m_front;

	if(doesCycle() == false){
		for(int i = 1; i < m_size; i ++){
			temp = temp->getNext();
		}
	
		temp->setNext(m_front);
	
	} else {
		throw(std::runtime_error("Attempted to cylce a list that already cycles."));
	}

}

template<typename T>
void LinkedList<T>::setFront(Node<T>* newFront)
{
	m_front = newFront;
}

template<typename T>
int LinkedList<T>::getSize() const
{
	return m_size;
}

template<typename T>
Node<T>* LinkedList<T>::getFront() const
{
	return m_front;
}

template<typename T>
void LinkedList<T>::printList() const
{
	Node<T>* temp = m_front;
	while(temp != nullptr){
		std::cout << temp->getEntry() << "->";
		temp = temp->getNext();
	}
}

template<typename T>
void LinkedList<T>::insert(int index, T entry)
{
	m_size++;
	if(index > 0 && index <= m_size){
		
		if(index == 1){
			Node<T>* newVal = new Node<T>(entry);
			newVal -> setNext(m_front);
			m_front = newVal;
		} else {
			Node<T>* temp = m_front;
			for(int i = 1; i < index - 1; i++){
				temp = temp->getNext();
			}
			Node<T>* newVal = new Node<T>(entry);
			newVal->setNext(temp->getNext());
			temp->setNext(newVal);
		}
	} else {
		throw(std::runtime_error("Attempted to insert at an invalid index."));
	}
}


template<typename T>
void LinkedList<T>::remove(int index)
{

	Node<T>* temp1 = m_front;
	Node<T>* temp2 = nullptr;

	if(index > 0 && index <= m_size){
		
		if(index == 1){
			m_front = m_front->getNext();
			delete temp1;
		} else if(index != 1) {
			for(int i = 1; i < index - 1; i++){
				temp1 = temp1->getNext();
			}
			temp2 = temp1->getNext();
			temp1->setNext(temp2->getNext());
			delete temp2;
		}
		m_size--;
	} else {
		throw(std::runtime_error("Attempted to remove at an invalid index."));
	}

}

template<typename T>
void LinkedList<T>::clear()
{
	if(doesCycle() == true){
		unCycle();
		while(m_size != 0){
			remove(1);
		}
	} else {
		while(m_size != 0){
			remove(1);
		}
	}
}

template<typename T>
T LinkedList<T>::getEntry(int index) const
{
	if(index > 0 && index <= m_size){
		if(index == 1){
			return (m_front->getEntry());
		} else {
			Node<T>* temp = m_front;
			for(int i = 1; i < index; i++){
				temp = temp->getNext();
			}
			return(temp->getEntry());
		}
	} else {
		throw(std::runtime_error("Attempted to get the entry of an invalid index"));
	}
}

template<typename T>
void LinkedList<T>::setEntry(int index, T entry)
{
	if(index > 0 && index <= m_size){
		if(index == 1){
			m_front->setEntry(entry);
		} else {
			Node<T>* temp = m_front;
			for(int i = 1; i < index; i++){
				temp = temp->getNext();
			}
			temp->setEntry(entry);
		}
	} else {
		throw(std::runtime_error("Attempted to set at and invalid index"));
	}

}

template<typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}
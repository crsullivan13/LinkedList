#include <iostream>
#include "Node.h"
#include "LinkedList.h"


void mergeIntLists(Node<int>* list1, Node<int>* list2) {
	Node<int>* temp1 = list1;
	Node<int>* temp2 = list2;
	LinkedList<int> merged;
	int index = 0;

	while (temp1 != nullptr && temp2 != nullptr) {
		index++;
		if (temp1->getEntry() < temp2->getEntry()) {
			merged.insert(index, temp1->getEntry());
			temp1 = temp1->getNext();
		}
		else {
			merged.insert(index, temp2->getEntry());
			temp2 = temp2->getNext();
		}
	}

	if (temp1 == nullptr) {
		while (temp2 != nullptr) {
			index++;
			merged.insert(index, temp2->getEntry());
			temp2 = temp2->getNext();
		}
	}
	else if (temp2 == nullptr) {
		while (temp1 != nullptr) {
			index++;
			merged.insert(index, temp1->getEntry());
			temp1 = temp1->getNext();
		}
	}

	merged.printList();
	std::cout << "\n";


	return;
}

Node<int>* removeNLast(Node<int>* list, int n, int size) {
	Node<int>* dummyPtr = new Node<int>(0);
	dummyPtr->setNext(list);
	Node<int>* temp1 = dummyPtr->getNext();
	Node<int>* temp2 = dummyPtr;

	while (n > 0) {
		n--;
		temp1 = temp1->getNext();
	}

	while (temp1 != nullptr) {
		temp1 = temp1->getNext();
		temp2 = temp2->getNext();
	}


	Node<int>* tempDel = temp2->getNext();
	temp2->setNext((tempDel->getNext()));
	delete tempDel;

	list = dummyPtr->getNext();
	delete dummyPtr;
	temp1 = list;

	for (int i = 0; i < size - 1; i++) {
		std::cout << temp1->getEntry() << "->";
		temp1 = temp1->getNext();
	}

	std::cout << "\n";

	return list;

}

Node<int>* removeValue(Node<int>* list, int value, int size)
{
	Node<int>* temp1 = list;
	Node<int>* temp2 = list;
	int removals = 0;

	while (temp2 != nullptr && temp1->getEntry() == value) {
		temp2 = temp2->getNext();
		list = temp2;
		delete temp1;
		temp1 = temp2;
		removals++;
	}

	while (temp1->getNext() != nullptr) {
		temp2 = temp2->getNext();
		if (temp2->getEntry() == value) {
			temp1->setNext(temp2->getNext());
			delete temp2;
			temp2 = temp1;
			removals++;
		}
		else {
			temp1 = temp1->getNext();
		}
	}

	temp1 = list;

	for (int i = 0; i < size - removals; i++) {
		std::cout << temp1->getEntry() << "->";
		temp1 = temp1->getNext();
	}
	
	std::cout << "\n";

	return list;
}

int returnMiddle(Node<int>* list)
{
	int middle;
	int counter = 0;
	Node<int>* temp1 = list;
	Node<int>* temp2 = list;

	while (temp1 != nullptr) {
		temp1 = temp1->getNext();
		counter++;
	}

	counter = counter / 2;

	for (int i = 0; i < counter; i++) {
		temp2 = temp2->getNext();
	}

	middle = temp2->getEntry();

	return middle;
}

Node<int>* findCycleStart(Node<int>* list) {
	Node<int>* temp1 = list;
	Node<int>* temp2 = list;

	while (temp2 != nullptr && temp2->getNext() != nullptr) {
		temp1 = temp1->getNext();
		temp2 = temp2->getNext();
		temp2 = temp2->getNext();
		if (temp2 == temp1) {
			break;
		}
	}

	if (temp2 == nullptr || temp2->getNext() == nullptr) {
		return nullptr;
	}

	temp1 = list;

	while (temp1 != temp2) {
		temp1 = temp1->getNext();
		temp2 = temp2->getNext();
	}

	return temp1;

}

int main() {
	/*
	Node<int> myNode(5);

	std::cout << myNode.getEntry() << "\n";

	LinkedList<int> myList;

	myList.insert(1, 5);
	std::cout << myList.getEntry(1) << "\n";
	myList.insert(2, 4);
	std::cout << myList.getEntry(2) << "\n";
	*/

	LinkedList<int> list1;
	LinkedList<int> list2;
	LinkedList<int> list3;
	LinkedList<int> list4;
	LinkedList<int> list5;

	list1.insert(1, 1);
	list1.insert(2, 2);
	list1.insert(3, 3);

	list2.insert(1, 1);
	list2.insert(2, 5);
	list2.insert(3, 6);

	list3.insert(1,1);
	list3.insert(2, 1);
	list3.insert(3, 1);
	list3.insert(4, 4);
	list3.insert(5, 12);

	list4.insert(1, 2);
	list4.insert(2, 2);
	list4.insert(3, 3);
	list4.insert(4, 4);

	list5.insert(1, 1);
	list5.insert(2, 2);
	list5.insert(3, 3);

	Node<int>* temp1 = list1.getFront();
	Node<int>* temp2 = list2.getFront();
	Node<int>* temp3 = list3.getFront();
	Node<int>* temp4 = list4.getFront();
	Node<int>* temp5 = list5.getFront();

	mergeIntLists(temp1, temp2);

	list3.setFront(removeValue(temp3, 1, list3.getSize()));
	list3.setSize(2);

	list1.setFront(removeNLast(temp1, 2, list1.getSize()));
	list1.setSize(2);

	std::cout << returnMiddle(temp4) << "\n";

	list5.reverseList();
	list5.printList();

	std::cout << "\n";

	list4.cycleList();
	std::cout << list4.doesCycle() << "\n";

	if (findCycleStart(temp4) != nullptr) {
		std::cout << findCycleStart(temp4)->getEntry() << "\n";
	}
	else {
		std::cout << "nullptr\n";
	}
	return(0);
}
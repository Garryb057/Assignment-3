//Name: Gurekpal Bhullar
//Email: gsbzm8@umsystem.edu
#include "queue.h"
#include <iostream>
#include <stdexcept>

//Default constructor
Queue::Queue() {
	headPtr = nullptr;										//Initializes headPtr to nullptr
	tailPtr = nullptr;										//Initializes tailPtr to nullptr
	num_items = 0;											//Initializes num_Items to 0
}

//Function to add to the queue
void Queue::enQueue(const int& item) {
	Node* newNode = new Node;								//Sets a pointer of Node type to a new Node
	newNode->data = item;									//Sets the data of the newNode to the item
	newNode->nextptr = nullptr;								//Sets the nextptr of the newNode to nullptr

	if (tailPtr == nullptr) {								//If the tailPtr is null
		headPtr = newNode;									//Sets headPtr to the newNode
		tailPtr = newNode;									//Sets tailPtr to the newNode
	}
	else {													//If the tailPtr is not null
		tailPtr->nextptr = newNode;							//Sets the current tailPtr's nextPtr to the newNode
		tailPtr = newNode;									//Sets tailPtr to the newNode
	}	
	num_items++;											//Increments num_items
}

//Function to remove the first item from the queue
int Queue::deQueue() {
	if (isEmpty()) {										//If the queue is empty
		throw std::runtime_error("Queue is empty");			//Throw an error
	}

	Node* temp = headPtr;									//Sets a pointer of type Node to headPtr
	int item = temp->data;									//Sets item to temp's data
	headPtr = headPtr->nextptr;								//Sets headPtr to the current heads' nextptr
	delete temp;											//Deletes the temp

	if (headPtr == nullptr) {								//If the headPtr is nullptr
		tailPtr = nullptr;									//Sets tailPtr to nullptr
	}

	num_items--;											//Decrements num_Items
	return item;											//Returns the data of the item that was removed
}

//Function to return what is at the front of the queue
int Queue::front() const {									
	if (isEmpty()) {										//If the queue is empty
		throw std::runtime_error("Queue is empty");			//Throws an error
	}

	return headPtr->data;									//Returns the data of the headPtr
}

//Function to determine if the queue is empty
bool Queue::isEmpty() const {											
	return headPtr == nullptr;								//Returns if the headPtr is nullptr or is not
}

//Function to get the size of the queue
int Queue::getSize() const {	
	return num_items;										//Return num_items
}
//Name: Gurekpal Bhullar
//Email: gsbzm8@umsystem.edu
#pragma once

//Sets the Queue class
class Queue {
private:
	//This is the structure for the Node that has the data and the pointer to what's next in the queue
	struct Node {
		int data;
		Node* nextptr;
	};

	Node* headPtr;						//Sets a headPtr for the front of the queue
	Node* tailPtr;						//Sets a tailPtr for the rear of the queue
	int num_items;						//Sets an int for the number of items in the queue

public:
	Queue();							//Default Constructor
		
	void enQueue(const int& item);		//Function to add to the queue
	int deQueue();						//Function to remove from the queue
	int front() const;					//Function to print what's at the front of the queue
	bool isEmpty() const;				//Function to see if the queue is empty
	int getSize() const;				//Function to get the number of items in the queue
};
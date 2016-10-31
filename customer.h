#pragma once
#ifndef customer_h
#define	customer_h

#include <iostream>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;



typedef int dataType;


//////////////////		Customer	Class		////////////////////////////
class Customer {
public:
	class Node {
	public:
		dataType id;
		dataType enqueue_Time;
		dataType dequeue_Time;
		Node *next;
		Node() {
			// Node constructor					
			id = 0;
			enqueue_Time = 0;
			dequeue_Time = 0;
			next = NULL;
		}
	}; //--- end of Node class 

	typedef Node *NodePointer;
	//Default constructor		
	Customer();

	void enqueue(dataType& a, dataType &b);

	void dequeue();


	NodePointer front()
	{
		if (first) {
			NodePointer ptr = first;
			return ptr;
		}
	}
	//Return size of the queue		
	int getSize();

	//Return arrive time
	dataType enqueueTime(NodePointer p) {
		return p->enqueue_Time;
	}
	dataType dequeueTime(NodePointer p) {
		return p->dequeue_Time;
	}
	int  getId(NodePointer p) {
		return p->id;
	}

	//Destructor		
	~Customer();
private:
	Node *first;
	Node *last;
	int mySize;
};



Customer::Customer() {
	mySize = 0;
	first = NULL;
	last = NULL;
}

//The queue simlulates a line of customers.
//Using a linked list we can implement a queue and use a LIFO implmentation.


void Customer::enqueue(dataType &a, dataType &b)
{
	NodePointer nPtr = new Node();
	nPtr->id = a; //Assign name to customer
	nPtr->enqueue_Time = b; //Assign queue time to customer

	NodePointer predPtr = first;
	if (first == NULL) { //Insert if queue is empty		
		nPtr->next = first;
		first = nPtr;
	}
	else { //Insert into the queue at the end		
		while (predPtr->next) {
			predPtr = predPtr->next;
		}
		predPtr->next = nPtr;
	}
	mySize++;
	last = nPtr;
}

////////////////	Dequeue Customer   /////////////
//	Delete pointer to free memory after customer is served.

void Customer::dequeue() {
	if (first) {
		NodePointer dPtr = first;
		first = first->next; //Set first to the second node in the list		
		delete dPtr; //Delete the node that has been dequeued	
	}
	mySize--;
}


int Customer::getSize() {
	return mySize;
}

///////////////			Customer Deconstructor		///////////////
Customer::~Customer() {
	if (first)
	{
		NodePointer current = first;
		NodePointer temp = first;
		temp = current->next;
		delete current;
		current = temp;
	}
}

#endif
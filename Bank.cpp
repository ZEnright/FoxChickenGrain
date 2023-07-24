/*****************************************************************
	Title:  	Bank.cpp - Class Implementation File for 
				Bank Class
	Date:  		7-23-2023
	Author: 	Zack Enright
	Purpose:	A Singly-Linked List implemented to hold the
    position of the characters.
******************************************************************/

#include <iostream>  
#include "Bank.h"
using namespace std;


// isEmpty returns true if the list has no nodes and false if it does
bool BankList::isEmpty()
{
    if(!head)
        return true;
    else
        return false;
}


//getLength() returns the number of nodes in the list.
int BankList::getLength()
{
	int counter = 0;
	BankNode *nodePtr;
	
	nodePtr = head;
	
	while(nodePtr != tail)
	{
		counter++;
		nodePtr = nodePtr->next;
		if (nodePtr == tail)
			counter++;
	}
	return counter;
}


//returns the node value at a given integer position
int BankList::getNodeValue(int position)
{
	BankNode *nodePtr;
	if(!head)
		return -1;
	else
	{
		if(position == 0)
			return head->value;
		nodePtr = head;
		int currentPos = 0;
		while(nodePtr != NULL && position >= currentPos)
		{
			if(position == currentPos)
				return nodePtr->value;
			currentPos++;
			nodePtr = nodePtr->next;				
		}
	}
	return -1;
}


//**************************************************
// appendNode appends a node containing the        *
// value passed into num, to the end of the list.   *
//**************************************************
void BankList::appendNode(int num)
{
	BankNode *newNode;  // To point to a new node

	// Allocate a new node and store num there.
	newNode = new BankNode;
	newNode->value = num;
	newNode->next = NULL;

	//If there are no nodes in the list make newNode the first node.
	if (!head) 
	{
		head = newNode;
		tail = newNode;
	}
	else  // Otherwise, insert newNode at end.
	{
		//set the current last node's next pointer to the new node
		tail->next = newNode;
		
		//now the tail is the new node
		tail = newNode;
	}
}

//insert a new node at the integer position passed to this function
void BankList::insertNode(int position, int num)
{
	BankNode *nodePtr;
	BankNode *newNode;
	
	newNode = new BankNode;
	newNode->value = num;
	
	if(!head)
	{
		if(position != 0)
		{
			//can't insert node at position (>0) if there is not already a node
			cout << "\n\nUnable to insert a node at position " << position << " because there are currently no nodes in the list.  I am going to insert this node at position 0.\n\n";
		}
		head = newNode;
		tail = newNode;
	}
	else
	{
		nodePtr = head;
		int nodeCount = 0;
		if(position == 0)
		{
			newNode->next = head->next;
			head = newNode;
		}
		while(nodePtr != tail && nodeCount < position)
		{
			nodeCount++;
			if(nodeCount == position)
				break;
			nodePtr = nodePtr->next;
		}
		
		//now nodePtr is positioned 1 node BEFORE the node we want to insert
		if(nodePtr->next == NULL) //we are appending this node to the end
			tail = newNode;
			
		newNode->next = nodePtr->next;
		nodePtr->next = newNode;
		
	}
	
}


//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************
void BankList::displayList() const
{
	BankNode *nodePtr;  // To move through the list

	if(head != NULL)
	{
		// Position nodePtr at the head of the list.
		nodePtr = head;
		// While nodePtr points to a node, traverse the list.
		while (nodePtr)
		{
			// Display the value in this node.
			switch(nodeptr->value)
            {
                case: 0
                    cout << "Fox/n";
                    break;
                case: 1
                    cout << "Chicken/n";
                    break;
                case: 2
                    cout << "Grain/n";
                    break;
            }

			// Move to the next node.
			nodePtr = nodePtr->next;
		}
	}
	else
		cout << "<Empty>" << endl;
}


//**************************************************
// The deleteNode function searches for a node     *
// with num as its value. The node, if found, is   *
// deleted from the list and from memory.          *
//**************************************************
void BankList::deleteNode(int num)
{
	BankNode *nodePtr;       // To traverse the list
	BankNode *previousNode;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is 
		// not equal to num.
		while (nodePtr != NULL && nodePtr->value != num)
		{  
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list, 
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			if(nodePtr == tail)
			{
				tail = previousNode;
			}
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}


//searches for a value (num) and returns the position or -1 if can't be found
int BankList::search(int num)
{
	BankNode *nodePtr;  // To move through the list
	int position;

	// Position nodePtr at the head of the list.
	nodePtr = head;
	position = 0;

	// While nodePtr points to a node, traverse the list.
	while (nodePtr)
	{
		//see if this node matches the value
		if(nodePtr->value == num)
			return position;
		
		//increment position
		position++;

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
	return -1; //node couldn't be found
}


//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// Similar to a typical list function RemoveAll    *
//**************************************************
BankList::~BankList()
{
	BankNode *nodePtr;   // To traverse the list
	BankNode *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != NULL)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}


void FarmerLocation(int pos)
{
	if(pos == 0)
		cout << "The farmer is on the south bank." << endl;
	else
		cout << "The farmer is on the north bank." << endl;
}

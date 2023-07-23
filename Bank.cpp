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
double BankList::getNodeValue(int position)
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
void BankList::appendNode(double num)
{
	BankNode *newNode;  // To point to a new node

	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = NULL;

	// If there are no nodes in the list make newNode the first node.
	if (!head ) 
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
void BankList::insertNode(int position, double num)
{
	BankNode *nodePtr;
	BankNode *newNode;
	
	newNode = new ListNode;
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

/*****************************************************************
	Title:  	Bank.h - Class Specification File for 
				Bank Class
	Date:  		7-23-2023
	Author: 	Zack Enright
	Purpose:	A Singly-Linked List implemented to hold the
    position of the characters.
******************************************************************/

#ifndef Bank_H
#define Bank_H
/*****************************************************************
							Bank Class
******************************************************************/
class BankList
{
	private:
		// Declare a structure for the Bank list
		struct BankNode
		{
			int value; 
			struct BankNode *next;  	// To point to the next node
		}; 

		BankNode *head;		//Bank List head pointer
		BankNode *tail;		//Bank List tail pointer

	public:
		// Constructor
		BankList()
		{ 
			head = NULL; 
			tail = NULL;
		}

		// Destructor (deallocates all nodes)
		~BankList();

		// Bank list operations
		bool isEmpty();
		int getLength();
		int getNodeValue(int);
		void appendNode(int);
		void insertNode(int, int);
		void deleteNode(int);
        std::string displayList();
		bool GameChecker(int);
};

// Function that prints the farmers location
void FarmerLocation(int, std::ostream&);

#endif
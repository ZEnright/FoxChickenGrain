/*****************************************************************
	Title:  	Driver.cpp
	Date:  		7-23-2023
	Author: 	Zack Enright
	Purpose:	To demonstrate a Singly-Linked List solution for
    the fox chicken and grain puzzle game
******************************************************************/

#include <iostream>
#include "Bank.h"
using namespace std;

int main()
{
    bool keepPlaying = true, gameLost = false;
    BankList southBank;
    BankList northBank;
    
    

    while(keepPlaying)
    {
        int farmerPos = 0;
        //Fill the south bank with the characters
        for(int i = 0; i < 3; i++)
        {
            southBank.appendNode(i);
        }
        
        
        //Print the welcome statment / game explination
        cout <<"        Welcome to Fox, Chicken, and Grain" << endl;
        cout << endl;
        cout << "A farmer must get his fox, chicken, and grain safely" << endl;
        cout << "across a river from the south bank to the north bank." << endl;
        cout << "The farmer can take at most one thing with him when" << endl;
        cout << "he makes a trip across. Unfortunately, if the farmer"  << endl;
        cout << "leaves the fox and the chicken together, the fox will " << endl;
        cout << "eat the chicken. If the farmer leaves the chicken " << endl;
        cout << "and the grain together, the chicken will eat the grain." << endl;
        cout << endl;
        cout << "Help the farmer by entering the name of what you " << endl;
        cout << "want him to carry on his next trip to the opposite bank." << endl;
        cout << "If you want the farmer to cross the river without " << endl;
        cout << "carrying anything, enter 'nothing' at the prompt." << endl;

        //Display both the South and North Bank contents
        cout << "South Bank:/n" << southBank.displayList() << endl;
        cout << "North Bank:/n" << northBank.displayList() << endl;

        while(!gameLost)
        {
            string input;
            FarmerLocation(farmerPos);
            cout << "What should the farmer take?: ";
            cin >> input;
            
        }

    }




    return 0;
}
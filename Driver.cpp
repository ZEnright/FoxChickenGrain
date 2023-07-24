/*****************************************************************
    Title:      Driver.cpp
    Date:       7-23-2023
    Author:     Zack Enright
    Purpose:    To demonstrate a Singly-Linked List solution for
    the fox chicken and grain puzzle game
******************************************************************/

#include <iostream>
#include <string>
#include "Bank.h"
using namespace std;

int main()
{
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
        

    BankList southBank;
    BankList northBank;

    //fill the list with the starting characters
    southBank.appendNode(0);
    southBank.appendNode(1);
    southBank.appendNode(2);

    //set/print farmer location
    FarmerLocation(0);

    string userInput;
    bool playAgain = true;
    int turnCount = 0;

    //The repeatable part of the game is put into a loop
    while (playAgain)
    {
        //print both starting lists
        cout << "\nSouth bank:\n";
        cout << southBank.displayList() << "\n\n";
        cout << "North bank:\n";
        cout << northBank.displayList() << "\n\n";

        //prompt user and store data into userInput
        cout << "What should the farmer take?: ";
        getline(cin, userInput);

        if (userInput == "nothing")
        {
            cout << "\nThe farmer takes nothing.\n";
        }
        else
        {
            if(userInput == "fox")
            {
                southBank.deleteNode(0);
                northBank.appendNode(0);
            }
            else if(userInput == "chicken")
            {
                southBank.deleteNode(1);
                northBank.appendNode(1);
            }
            else
            {
                southBank.deleteNode(2);
                northBank.appendNode(2);
            }
            cout << "\nThe farmer takes the " << userInput << " with him.\n";
        }

        //Moves the farmer between banks
        if(turnCount == 0)
            FarmerLocation(1);
        if(turnCount % 2 == 0)
            FarmerLocation(1);
        else
            FarmerLocation(0);

        //checks if you lost by calling GameChecker()
        if (southBank.GameChecker() || northBank.GameChecker())
        {
            cout << "\n";
            if (userInput == "nothing")
                cout << "The fox";
            else
                cout << "The " << userInput;
            
            //prompts user that they lost and asks if they want to play again
            cout << " ate the chicken! You lost!\n\n";   
            cout << "Play again? (y/n): ";
            getline(cin, userInput);

            //checks if they want to play again, if not stops loop
            if (userInput != "y")
                playAgain = false;

            //reset both banks
            southBank.deleteNode(1);
            southBank.deleteNode(0);
            southBank.deleteNode(2);
            northBank.deleteNode(1);
            northBank.deleteNode(0);
            northBank.deleteNode(2);
            southBank.appendNode(0);
            southBank.appendNode(1);
            southBank.appendNode(2);
            FarmerLocation(0);
        }
        //checks if the north bank has all three characters in it
        else if (northBank.getLength() == 3)
        {
            //prompts user that they won and asks if they want to play again
            cout << "\nCongratulations! You safely transported all the items to the north bank!\n\n";
            cout << "Play again? (y/n): ";
            getline(cin, userInput);

            //checks if they want to play again, if not stops loop
            if (userInput != "y")
                playAgain = false;

            //reset both banks
            southBank.deleteNode(1);
            southBank.deleteNode(0);
            southBank.deleteNode(2);
            northBank.deleteNode(1);
            northBank.deleteNode(0);
            northBank.deleteNode(2);
            southBank.appendNode(0);
            southBank.appendNode(1);
            southBank.appendNode(2);
            FarmerLocation(0);
        }
    }

    return 0;
}